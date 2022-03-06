#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char table[53] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

int cmp1(char *str_1, char *str_2) {  //ASCII
	if (strcmp(str_1, str_2) > 0) {  //�n�����ܦ^��1�A�_�h0
		return 1;
	}
	return 0;
}

int cmp2(char* str_1, char* str_2) {  //�r��
	for (int k = 0;; k++)
	{
		int one = 0;
		int two = 0;
		if (str_1 == '\0' && str_2 == '\0')
			break;
		if (str_1[k]==str_2[k])
			continue;
		if (isalpha(str_1[k]) && isalpha(str_2[k]))
		{
			for (int m = 0; m < 52; m++)
			{
				if (str_1[k] == table[m])
					one = m;
				if (str_2[k] == table[m])
					two = m;
			}
			return	one > two;
		}
		else
			return str_1[k] > str_2[k];
	}
	return 0;
}

void sort(char** str, int str_num, int (*cmp)(char*, char*)) {
	int i, j;
	char* temp;
	for (i = 0; i < str_num - 1; i++) {
		for (j = 0; j < str_num - i - 1; j++) {
			if (cmp(str[j], str[j + 1])) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int main() {
	int str_num;  //����J�r���
	int choose;  //��ܱƧ�
	int i, j;
	int cmp_temp;

	while (1) {
		printf("�п�J�r���(��J0����)�G");
		scanf("%d", &str_num);
		if (str_num == 0) {  //��J0�����}
			break;
		}

		//�ЫذʺA�G���ʺA�}�C
		char** str = calloc(str_num, sizeof(char*));
		for (i = 0; i < str_num; i++) {
			str[i] = calloc(100, sizeof(char));
		}

		//��J���w�r���
		for (i = 0; i < str_num; i++) {
			scanf("%s", str[i]);
		}
		while (1) {
			printf("��ƧǤ覡(1.�HASCII / 2.�H�r��Ƨ�)�G");
			scanf("%d", &choose);
			if (choose == 1) {  //ASCII
				sort(str, str_num, cmp1);
			}
			else if (choose == 2) {  //�r��
				sort(str, str_num, cmp2);
			}
			else {  //���s��J
				continue;
			}
			break;
		}
		for (i = 0; i < str_num; i++)
		{
			printf("%s\n", str[i]);
		}
		for (i = 0; i < str_num; i++)
		{
			free(str[i]);
		}
		free(str);
	}
	return 0;
}