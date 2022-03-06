#include <stdio.h>

int add(int a, int b) { //加法
	return a + b;
}

int sub(int a, int b) { //減法
	return a - b;
}

int multi(int a, int b) { //乘法
	return a * b;
}

int divide(int a, int b) { //除法
	return a / b;
}

int mod(int a, int b) { //取餘數
	return a % b;
}

int main(int argc, char *argv[]) {
	int (*opt[5])(int, int) = {add, sub, multi, divide, mod};
	int choice = 0;
	int A, B;

	while (1) {
		// Input 1
		fputs("請選擇運算子 (1. + | 2. - | 3. * | 4. / | 5. % | 0. 離開)：", stdout);
		scanf("%i", &choice);
		if (choice == 0)
			return 0;
		if (choice > 0 && choice < 6) {
			// Input 2
			fputs("請輸入2個整數：", stdout);
			scanf("%i %i", &A, &B);
			// Output 1
			printf("%i %c %i = %i\n",
				A,
				(choice == 1) ? '+' : (choice == 2) ? '-' : (choice == 3) ? '*' : (choice == 4) ? '/' : '%',
				B,
				opt[choice - 1](A, B)
			);
			continue;
		}
	}

	return 0;
}