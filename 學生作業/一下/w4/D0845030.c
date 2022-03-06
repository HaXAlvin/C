#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fraction{
    int deno;//����
    int mole;//���l
};

int gcd(int num1, int num2){//�䤽�]��
    int tmp;
    while(num2 != 0){
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}

struct fraction sum(struct fraction ans_1, struct fraction ans_2){//�[
    struct fraction outcome;//���G
    outcome.deno = ans_1.deno * ans_2.deno;//���G����������J���ۭ�
    outcome.mole = (ans_1.mole * ans_2.deno) + (ans_2.mole * ans_1.deno);//����ƪ����l����誺�����ìۥ[
    int space_deno = outcome.deno, space_mole = outcome.mole;//�x�s�����M���l
    outcome.deno /= gcd(space_deno, space_mole);//���̤j���]��
    outcome.mole /= gcd(space_deno, space_mole);//���̤j���]��
    return outcome;
};

struct fraction sub(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.deno;//���G����������J�������ۭ�
    outcome.mole = (ans_1.mole * ans_2.deno) - (ans_2.mole * ans_1.deno);//����ƪ����l����誺�����ì۴�
    int space_deno = outcome.deno, space_mole = outcome.mole;
    outcome.deno /= gcd(space_deno, space_mole);
    outcome.mole /= gcd(space_deno, space_mole);
    return outcome;
};

struct fraction multi(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.deno;//���G�����l�M��������J�����l�M�������ۭ�
    outcome.mole = ans_1.mole * ans_2.mole;
    int space_deno = outcome.deno, space_mole = outcome.mole;
    outcome.deno /= gcd(space_deno, space_mole);
    outcome.mole /= gcd(space_deno, space_mole);
    return outcome;
};

struct fraction divi(struct fraction ans_1, struct fraction ans_2){
    struct fraction outcome;
    outcome.deno = ans_1.deno * ans_2.mole;//���˼�
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
        printf("���(1.�[/2.��/3.��/4.��/0.���}) : ");
        scanf("%d", &choice);
        if((choice < 0) || (choice > 4))//��J�u�ର0��4
            printf("��J���~\n\n");
        if(choice == 1){
            printf("a/b + c/d�A�п�Ja b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//��J4�Ӥ��l�M����
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//�������i��0�P�_
                printf("�������i��0\n\n");
                continue;
            }
            fraction3 = sum(fraction1, fraction2);//�[�k���c
            printf("%d/%d + %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//�p�G�����p��0�A���l�����P��-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 2){
            printf("a/b - c/d�A�п�Ja b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//��J4�Ӥ��l�M����
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//�������i��0�P�_
                printf("�������i��0\n\n");
                continue;
            }
            fraction3 = sub(fraction1,fraction2);//��k���c
            printf("%d/%d - %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//�p�G�����p��0�A���l�����P��-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 3){
            printf("a/b * c/d�A�п�Ja b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//��J4�Ӥ��l�M����
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//�������i��0�P�_
                printf("�������i��0\n\n");
                continue;
            }
            fraction3 = multi(fraction1,fraction2);//���k���c
            printf("%d/%d * %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//�p�G�����p��0�A���l�����P��-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                printf("%d\n\n", fraction3.mole / fraction3.deno);
            }
            else{
                printf("%d/%d\n\n", fraction3.mole, fraction3.deno);
            }
        }
        if(choice == 4){
            printf("a/b / c/d�A�п�Ja b c d :");
            scanf("%d %d %d %d", &fraction1.mole, &fraction1.deno, &fraction2.mole, &fraction2.deno);//��J4�Ӥ��l�M����
            if((fraction1.deno == 0) || (fraction2.deno == 0)){//�������i��0���P�_
                printf("�������i��0\n\n");
                continue;
            }
            if(fraction2.mole ==0){
                printf("���Ƥ��i��0\n\n");
                continue;
            }
            fraction3 = divi(fraction1,fraction2);//���k���c
            printf("%d/%d / %d/%d = ", fraction1.mole, fraction1.deno, fraction2.mole, fraction2.deno);
            if(fraction3.deno < 0){//�p�G�����p��0�A���l�����P��-1
                int save_deno = fraction3.deno * -1;
                int save_mole = fraction3.mole * -1;
                if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
                    printf("%d\n\n", save_mole / save_deno);
                }
                else{
                    printf("%d/%d\n\n", save_mole, save_deno);
                }
            }
            else if(fraction3.mole % fraction3.deno == 0){//���G����ƪ����p
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
