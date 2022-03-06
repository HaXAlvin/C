#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fraction{
    int deno;//分母
    int mole;//分子
};

int gcd(int num1, int num2){//找公因數
    int tmp;
    while(num2 != 0){
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}

struct fraction sum(struct fraction ans_1, struct fraction ans_2){//加
    struct fraction outcome;//結果
    outcome.deno = ans_1.deno * ans_2.deno;//結果的分母為輸入的相乘
    outcome.mole = (ans_1.mole * ans_2.deno) + (ans_2.mole * ans_1.deno);//兩分數的分子乘對方的分母並相加
    int space_deno = outcome.deno, space_mole = outcome.mole;//儲存分母和分子
    outcome.deno /= gcd(space_deno, space_mole);//除最大公因數
    outcome.mole /= gcd(space_deno, space_mole);//除最大公因數
    return outcome;
};

struct fraction sub(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.deno;//結果的分母為輸入分母的相乘
    outcome.mole = (ans_1.mole * ans_2.deno) - (ans_2.mole * ans_1.deno);//兩分數的分子乘對方的分母並相減
    int space_deno = outcome.deno, space_mole = outcome.mole;
    outcome.deno /= gcd(space_deno, space_mole);
    outcome.mole /= gcd(space_deno, space_mole);
    return outcome;
};

struct fraction multi(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.deno;//結果的分子和分母為輸入的分子和分母的相乘
    outcome.mole = ans_1.mole * ans_2.mole;
    int space_deno = outcome.deno, space_mole = outcome.mole;
    outcome.deno /= gcd(space_deno, space_mole);
    outcome.mole /= gcd(space_deno, space_mole);
    return outcome;
};

struct fraction divi(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.mole;//乘倒數
    outcome.mole = ans_1.mole * ans_2.deno;
    int space_deno = outcome.deno, space_mole = outcome.mole;
    outcome.deno /= gcd(space_deno, space_mole);
    outcome.mole /= gcd(space_deno, space_mole);
    return outcome;
};

int main(){
    int choice;
    struct fraction fraction1;
    struct fraction fraction2;
    struct fraction fraction3;
    while(1){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開) : ");
        scanf("%d", &choice);
        if((choice < 0) || (choice > 4))//輸入只能為0到4
            printf("輸入錯誤\n\n");
        if(choice == 1){
            printf("a/b + c/d，請輸入a b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//輸入4個分子和分母
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//分母不可為0判斷
                printf("分母不可為0\n\n");
                continue;
            }
            fraction3 = sum(fraction1, fraction2);//加法結構
            printf("%d/%d + %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//如果分母小於0，分子分母同乘-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 2){
            printf("a/b - c/d，請輸入a b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//輸入4個分子和分母
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//分母不可為0判斷
                printf("分母不可為0\n\n");
                continue;
            }
            fraction3 = sub(fraction1,fraction2);//減法結構
            printf("%d/%d - %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//如果分母小於0，分子分母同乘-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 3){
            printf("a/b * c/d，請輸入a b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//輸入4個分子和分母
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//分母不可為0判斷
                printf("分母不可為0\n\n");
                continue;
            }
            fraction3 = multi(fraction1,fraction2);//乘法結構
            printf("%d/%d * %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//如果分母小於0，分子分母同乘-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 4){
            printf("a/b / c/d，請輸入a b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//輸入4個分子和分母
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//分母不可為0的判斷
                printf("分母不可為0\n\n");
                continue;
            }
            if(fraction2.mole ==0){
                printf("除數不可為0\n\n");
                continue;
            }
            fraction3 = divi(fraction1,fraction2);//除法結構
            printf("%d/%d / %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//如果分母小於0，分子分母同乘-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//結果為整數的情況
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 0){
            break;
        }
    }
    return 0;
}
