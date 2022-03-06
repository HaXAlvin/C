#include <stdio.h>
#include <stdlib.h>

// 分數結構
typedef struct {
	long int son;
	long int mother;
} fraction;

// 用於剖析用戶輸入，儲存轉換後資料的結構
typedef struct {
	fraction f1, f2;
	char method;
} expression;

// 於指定字串中尋找指定pattern並返回其index, 若找不到則返回-1
int _pattern(const char *expr, const char *pattern) {
	// 遍歷字串
	for (int n = 0; expr[n] != '\0'; ++n) {
		// 比對pattern
		for (int i = 0; pattern[i] != '\0'; ++i) {
			if (expr[n] == pattern[i])
				return n;
		}
	}
	return -1;
}

// 轉換並儲存一組由指定pattern分隔的數字，若找不到或轉換失敗則返回NULL
char *_patch_convert(char *expr, const char *pattern, long int *store) {
	int found_index;
	char *endptr;
	char *exprbak = expr; // 備份字串的起始位置
	found_index = _pattern(expr, pattern);	// 儲存由_pattern()找到的pattern index
	if (found_index == -1) // _pattern()異常處理
		return NULL;
	expr += found_index + 1; // 將字串起始位置設為下一組數字的起始位置 (找到的pattern的下一字元)
	char found_pattern = *(expr - 1); // 備份由_pattern()找到的pattern，作為等等切割字串後還原用途
	*(expr - 1) = '\0'; // 將前一組數字的結尾設為'\0'，讓strtol()自動轉換該組數字
	*store = strtol(exprbak, &endptr, 0); // 開始轉換
	if (endptr == exprbak) // strtol()異常處理
		return NULL;
	*(expr - 1) = found_pattern; // 復原剛剛被設為'\0'的字元
	return expr;
}

// 剖析用戶輸入的表達式，若失敗則返回NULL
void *_parser(char *expr, expression *data) { // 表達式正則：\d+\/\d+\ *[+-*\/]\ *\d+\/\d+\n?
	// 傳遞參數給_patch_convert()轉換並儲存結果，若_patch_convert()有錯誤則返回NULL
	expr = _patch_convert(expr, "/", &data->f1.son);
	if (expr == NULL)
		return NULL;
	// 防止第一個分數的分母為負，導致剖析失敗，e.g. -11/-22+-33/-44
	int negative_flag = 0;
	if (*expr == '-') { // 事先偵測，若為負號(-)開頭則先跳過負號，將negative_flag設為1
		++expr;
		negative_flag = 1;
	}
	expr = _patch_convert(expr, "+-*/", &data->f1.mother);
	if (expr == NULL)
		return NULL;
	if (negative_flag == 1) { // 若negative_flag為1，補回被跳過的負號(-)
		data->f1.mother = -(data->f1.mother);
	}
	data->method = *(expr - 1);
	expr = _patch_convert(expr, "/", &data->f2.son);
	if (expr == NULL)
		return NULL;
	// 最後一組數字(第二個分數分母)的格式與前幾組不同，改用手動轉換
	char *endptr;
	data->f2.mother = strtol(expr, &endptr, 0); // strtol()會自動處理gets()帶來的'\n'
	if (endptr == expr) // strtol()異常處理
		return NULL;
	return data;
}

// 用以快速求得最大公因數的gcd
long int _gcd(long int a, long int b) {
	// 任何一者為0則直接退出
	if (a == 0 || b == 0)
		return 0;
	// 兩者絕對值化
	a = (a > 0) ? a : -a;
	b = (b > 0) ? b : -b;

	// 標準gcd
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	// 返回最大公因數
	return a;
}

// 最簡化分數
void _simplify(fraction *F) {
	// 取得分子分母最大公因數
	long int base = _gcd(F->son, F->mother);
	// 若兩者互質(最大公因數為1)則略過，為0則代表gcd錯誤同樣略過
	if (base != 1 && base != 0) {
		// 分子分母同除最大公因數
		F->son /= base;
		F->mother /= base;
	}
	// 若分母為負則整個分數取反
	if (F->mother < 0) {
		F->son = -(F->son);
		F->mother = -(F->mother);
	}
}

// 分數加/減法
fraction add(fraction A, fraction B) {
	fraction F; // 運算結果
	long int base = _gcd(A.mother, B.mother); // 取得兩分母之最大公因數
	F.mother = A.mother / base * B.mother; // 分母為最小公倍數
	F.son = (B.mother / base * A.son) + (A.mother / base * B.son); // 分子通分後相加
	_simplify(&F); // 最簡化&清理結果
	return F;
}

// 分數乘/除法
fraction mul(fraction A, fraction B) {
	fraction F; // 運算結果
	if (A.son == 0 || B.son == 0) // 處理分子為0之狀況
		return (fraction) {0, 0};
	// 取得分子分母交叉的最大公因數
	long int base1 = _gcd(A.son, B.mother);
	long int base2 = _gcd(B.son, A.mother);
	// 相乘交叉化簡後的分數
	F.son = (A.son / base1) * (B.son / base2);
	F.mother = (A.mother / base2) * (B.mother / base1);
	_simplify(&F); // 最簡化&清理結果
	return F;
}

int main(void) {
	char expr[128];	// 供用戶輸入表達式之字串buffer
	expression data; // 用於儲存_parser返回的資料

	// 顯示說明
	printf(
		"The program accepts the following formats of expressions: a/b (+-*/) c/d (0 = exit)\n"
		"E.g. 3/5 + -2/3 | 1/-2 -1/2 | 4/6* -3/7 | -1/-3/-2/5\n"
		"--------------------------------------------------------\n"
	);
	// 開始運作
	while (1) {
		printf("> ");
		gets(expr);
		if (expr[0] == '0' && expr[1] == '\0') // 用戶輸入0則離開
			break;

		// _parser()異常處理
		if (_parser(expr, &data) == NULL) {
			printf("Wrong Format!!\n");
			continue;
		}

		/* NEW: 已支援分子為0的運算
		// 分子為0懶的處理直接報錯
		if (data.f1.son == 0 || data.f2.son == 0) {
			printf("分子不可為0\n");
			continue;
		}*/

		// 第一個分數分母為0則報錯
		if (data.f1.mother == 0) {
			printf("第一個分數分母不可為0\n");
			continue;
		}

		// 除法以外，第二個分數分母為0則報錯
		if (data.method != '/' && data.f2.mother == 0) {
			printf("使用%c法時，第二個分數分母不可為0\n", data.method);
			continue;
		}

		// 若為除法，第二個分數分子為0則報錯
		if (data.method == '/' && data.f2.son == 0) {
			printf("使用除法時，第二個分數的分子不可為0\n");
			continue;
		}

		// 根據運算子呼叫對應運算函式
		fraction result;
		switch (data.method) {
			case '+':
				result = add(data.f1, data.f2);
			break;
			case '-':
				result = add(data.f1, (fraction) {-data.f2.son, data.f2.mother}); // 傳參相反數
			break;
			case '*':
				result = mul(data.f1, data.f2);
			break;
			case '/':
				result = mul(data.f1, (fraction) {data.f2.mother, data.f2.son}); // 傳參倒數
			break;
			default:
				printf("Wrong Format!!\n");
			continue;
		}

		// 顯示用戶輸入並剖析後的運算式
		printf(
			"> %li/%li %c %li/%li = ",
			data.f1.son,
			data.f1.mother,
			data.method,
			data.f2.son,
			data.f2.mother
		);

		// 根據情況顯示對應運算結果
		if (result.mother == 1) // 分母為1，代表為整數，只需顯示分子
			printf("%li\n", result.son);
		else if (result.son == 0) // 分子為0，代表分數化簡後必定為0，直接顯示0
			printf("0\n");
		else // 正常顯示
			printf("%ld/%li\n", result.son, result.mother);
	}

	// 結束
	return 0;
}
