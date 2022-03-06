#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fraction { 
    int fraction; 
    int denominator;
} Fraction;

Fraction add(Fraction a, Fraction b); //加法
Fraction sub(Fraction a, Fraction b); //減法
Fraction multi(Fraction a, Fraction b); //乘法
Fraction divide(Fraction a, Fraction b); //除法
Fraction leave(Fraction a, Fraction b); //離開

void getUserInput();
void checkUserInput(int actionCode);
void checkIfDenominatorIsZero(int a, int b);
int calculateGCD(int fraction, int denominator);

int main() {
    printf("請選擇（1.加/2.減/3.乘/4.除/0.離開):");
    getUserInput();
    return 0;
}

void getUserInput() {
    Fraction fractionA, fractionB, result;
    Fraction (*opt[5]) (Fraction a, Fraction b) = {leave, add, sub, multi, divide};
    int a, b, c, d, actionCode, gcd;
    char instructionString[] = "請選擇（1.加/2.減/3.乘/4.除/0.離開):";
    char *operators[] = {"lol", "+", "-", "*", "/"};
    
    while (scanf("%d", &actionCode)) {
        checkUserInput(actionCode);

        if (actionCode == 0) {
            printf("離開\n");
            break;
        }

        printf("a/b %s c/d ,請輸入a b c d:", operators[actionCode]);
        scanf("%d %d %d %d", &fractionA.fraction, &fractionA.denominator, &fractionB.fraction, &fractionB.denominator);
        checkIfDenominatorIsZero(fractionA.denominator, fractionB.denominator);

        result = (*opt[actionCode]) (fractionA, fractionB);
        gcd = calculateGCD(result.fraction, result.denominator);

        // 3 guard statements corresponding to 3 different output styles
        if (result.fraction % result.denominator == 0) {
            // When fraction equals denominator
            printf("%d/%d %s %d/%d = %d\n", fractionA.fraction, fractionA.denominator, operators[actionCode], fractionB.fraction, fractionB.denominator, result.fraction / result.denominator);
        } else {
            if (result.denominator < 0) {
                // When denominator is negative
                printf("%d/%d %s %d/%d = %d/%d\n", fractionA.fraction, fractionA.denominator, operators[actionCode], fractionB.fraction, fractionB.denominator, (result.fraction / gcd) * -1, abs(result.denominator / gcd));
            } else {
                // Normal style
                printf("%d/%d %s %d/%d = %d/%d\n", fractionA.fraction, fractionA.denominator, operators[actionCode], fractionB.fraction, fractionB.denominator, result.fraction / gcd, result.denominator / gcd);
            }
        }
        printf("%s", instructionString);
    }
}

// Calculating functions //
Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.fraction = a.fraction * b.denominator + a.denominator * b.fraction;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction sub(Fraction a, Fraction b) {
    Fraction result;
    result.fraction = a.fraction * b.denominator - b.fraction * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction multi(Fraction a, Fraction b) {
    Fraction result;
    result.fraction = a.fraction * b.fraction;
    result.denominator = a.denominator * b.denominator;
    return result;
}

Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    result.fraction = a.fraction * b.denominator;
    result.denominator = a.denominator * b.fraction;
    return result;
}

Fraction leave(Fraction a, Fraction b) {
    return a;
}

// Input checking functions //
void checkUserInput(int actionCode) {
    if (!(actionCode == 0 || actionCode == 1 || actionCode == 2 || actionCode == 3 || actionCode == 4)) {
        printf("輸入錯誤\n請選擇（1.加/2.減/3.乘/4.除/0.離開):");
        getUserInput();
    }
}

void checkIfDenominatorIsZero(int a, int b) {
    if (a == 0 || b == 0) {
        printf("分母不可為0\n請選擇（1.加/2.減/3.乘/4.除/0.離開):");
        getUserInput();
    }
}

// Get the greatest common divisor for reducing fraction
int calculateGCD(int fraction, int denominator) {
	int gcd, remainder;
	while (fraction != 0) {
		remainder = denominator % fraction;
		denominator = fraction;
		fraction = remainder;
	}
	gcd = denominator;
	return gcd;
}