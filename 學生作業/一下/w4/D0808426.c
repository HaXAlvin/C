#include <stdio.h>
#include <stdlib.h>

// ���Ƶ��c
typedef struct {
	long int son;
	long int mother;
} fraction;

// �Ω��R�Τ��J�A�x�s�ഫ���ƪ����c
typedef struct {
	fraction f1, f2;
	char method;
} expression;

// ����w�r�ꤤ�M����wpattern�ê�^��index, �Y�䤣��h��^-1
int _pattern(const char *expr, const char *pattern) {
	// �M���r��
	for (int n = 0; expr[n] != '\0'; ++n) {
		// ���pattern
		for (int i = 0; pattern[i] != '\0'; ++i) {
			if (expr[n] == pattern[i])
				return n;
		}
	}
	return -1;
}

// �ഫ���x�s�@�եѫ��wpattern���j���Ʀr�A�Y�䤣����ഫ���ѫh��^NULL
char *_patch_convert(char *expr, const char *pattern, long int *store) {
	int found_index;
	char *endptr;
	char *exprbak = expr; // �ƥ��r�ꪺ�_�l��m
	found_index = _pattern(expr, pattern);	// �x�s��_pattern()��쪺pattern index
	if (found_index == -1) // _pattern()���`�B�z
		return NULL;
	expr += found_index + 1; // �N�r��_�l��m�]���U�@�ռƦr���_�l��m (��쪺pattern���U�@�r��)
	char found_pattern = *(expr - 1); // �ƥ���_pattern()��쪺pattern�A�@���������Φr����٭�γ~
	*(expr - 1) = '\0'; // �N�e�@�ռƦr�������]��'\0'�A��strtol()�۰��ഫ�ӲռƦr
	*store = strtol(exprbak, &endptr, 0); // �}�l�ഫ
	if (endptr == exprbak) // strtol()���`�B�z
		return NULL;
	*(expr - 1) = found_pattern; // �_����Q�]��'\0'���r��
	return expr;
}

// ��R�Τ��J����F���A�Y���ѫh��^NULL
void *_parser(char *expr, expression *data) { // ��F�����h�G\d+\/\d+\ *[+-*\/]\ *\d+\/\d+\n?
	// �ǻ��ѼƵ�_patch_convert()�ഫ���x�s���G�A�Y_patch_convert()�����~�h��^NULL
	expr = _patch_convert(expr, "/", &data->f1.son);
	if (expr == NULL)
		return NULL;
	// ����Ĥ@�Ӥ��ƪ��������t�A�ɭP��R���ѡAe.g. -11/-22+-33/-44
	int negative_flag = 0;
	if (*expr == '-') { // �ƥ������A�Y���t��(-)�}�Y�h�����L�t���A�Nnegative_flag�]��1
		++expr;
		negative_flag = 1;
	}
	expr = _patch_convert(expr, "+-*/", &data->f1.mother);
	if (expr == NULL)
		return NULL;
	if (negative_flag == 1) { // �Ynegative_flag��1�A�ɦ^�Q���L���t��(-)
		data->f1.mother = -(data->f1.mother);
	}
	data->method = *(expr - 1);
	expr = _patch_convert(expr, "/", &data->f2.son);
	if (expr == NULL)
		return NULL;
	// �̫�@�ռƦr(�ĤG�Ӥ��Ƥ���)���榡�P�e�X�դ��P�A��Τ���ഫ
	char *endptr;
	data->f2.mother = strtol(expr, &endptr, 0); // strtol()�|�۰ʳB�zgets()�a�Ӫ�'\n'
	if (endptr == expr) // strtol()���`�B�z
		return NULL;
	return data;
}

// �ΥH�ֳt�D�o�̤j���]�ƪ�gcd
long int _gcd(long int a, long int b) {
	// ����@�̬�0�h�����h�X
	if (a == 0 || b == 0)
		return 0;
	// ��̵���Ȥ�
	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;

	// �з�gcd
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	// ��^�̤j���]��
	return a;
}

// ��²�Ƥ���
void _simplify(fraction *F) {
	// ���o���l�����̤j���]��
	long int base = _gcd(F->son, F->mother);
	// �Y��̤���(�̤j���]�Ƭ�1)�h���L�A��0�h�N��gcd���~�P�˲��L
	if (base != 1 && base != 0) {
		// ���l�����P���̤j���]��
		F->son /= base;
		F->mother /= base;
	}
	// �Y�������t�h��Ӥ��ƨ���
	if (F->mother < 0) {
		F->son = -(F->son);
		F->mother = -(F->mother);
	}
}

// ���ƥ[/��k
fraction add(fraction A, fraction B) {
	fraction F; // �B�⵲�G
	long int base = _gcd(A.mother, B.mother); // ���o��������̤j���]��
	F.mother = A.mother / base * B.mother; // �������̤p������
	F.son = (B.mother / base * A.son) + (A.mother / base * B.son); // ���l�q����ۥ[
	_simplify(&F); // ��²��&�M�z���G
	return F;
}

// ���ƭ�/���k
fraction mul(fraction A, fraction B) {
	fraction F; // �B�⵲�G
	if (A.son == 0 || B.son == 0) // �B�z���l��0�����p
		return (fraction) {0, 0};
	// ���o���l������e���̤j���]��
	long int base1 = _gcd(A.son, B.mother);
	long int base2 = _gcd(B.son, A.mother);
	// �ۭ���e��²�᪺����
	F.son = (A.son / base1) * (B.son / base2);
	F.mother = (A.mother / base2) * (B.mother / base1);
	_simplify(&F); // ��²��&�M�z���G
	return F;
}

int main(void) {
	char expr[128];	// �ѥΤ��J��F�����r��buffer
	expression data; // �Ω��x�s_parser��^�����

	// ��ܻ���
	printf(
		"The program accepts the following formats of expressions: a/b (+-*/) c/d (0 = exit)\n"
		"E.g. 3/5 + -2/3 | 1/-2 -1/2 | 4/6* -3/7 | -1/-3/-2/5\n"
		"--------------------------------------------------------\n"
	);
	// �}�l�B�@
	while (1) {
		printf("> ");
		gets(expr);
		if (expr[0] == '0' && expr[1] == '\0') // �Τ��J0�h���}
			break;

		// _parser()���`�B�z
		if (_parser(expr, &data) == NULL) {
			printf("Wrong Format!!\n");
			continue;
		}

		/* NEW: �w�䴩���l��0���B��
		// ���l��0�i���B�z��������
		if (data.f1.son == 0 || data.f2.son == 0) {
			printf("���l���i��0\n");
			continue;
		}*/

		// �Ĥ@�Ӥ��Ƥ�����0�h����
		if (data.f1.mother == 0) {
			printf("�Ĥ@�Ӥ��Ƥ������i��0\n");
			continue;
		}

		// ���k�H�~�A�ĤG�Ӥ��Ƥ�����0�h����
		if (data.method != '/' && data.f2.mother == 0) {
			printf("�ϥ�%c�k�ɡA�ĤG�Ӥ��Ƥ������i��0\n", data.method);
			continue;
		}

		// �Y�����k�A�ĤG�Ӥ��Ƥ��l��0�h����
		if (data.method == '/' && data.f2.son == 0) {
			printf("�ϥΰ��k�ɡA�ĤG�Ӥ��ƪ����l���i��0\n");
			continue;
		}

		// �ھڹB��l�I�s�����B��禡
		fraction result;
		switch (data.method) {
			case '+':
				result = add(data.f1, data.f2);
			break;
			case '-':
				result = add(data.f1, (fraction) {-data.f2.son, data.f2.mother}); // �ǰѬۤϼ�
			break;
			case '*':
				result = mul(data.f1, data.f2);
			break;
			case '/':
				result = mul(data.f1, (fraction) {data.f2.mother, data.f2.son}); // �ǰѭ˼�
			break;
			default:
				printf("Wrong Format!!\n");
			continue;
		}

		// ��ܥΤ��J�í�R�᪺�B�⦡
		printf(
			"> %li/%li %c %li/%li = ",
			data.f1.son,
			data.f1.mother,
			data.method,
			data.f2.son,
			data.f2.mother
		);

		// �ھڱ��p��ܹ����B�⵲�G
		if (result.mother == 1) // ������1�A�N����ơA�u����ܤ��l
			printf("%li\n", result.son);
		else if (result.son == 0) // ���l��0�A�N����Ƥ�²�ᥲ�w��0�A�������0
			printf("0\n");
		else // ���`���
			printf("%ld/%li\n", result.son, result.mother);
	}

	// ����
	return 0;
}
