#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int multi(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a / b;
}
int mod(int a, int b){
    return a % b;
}
int main(){
    //�]���ܼ�
    int choice, a, b;
    int (*opt[])(int ,int) = {add, sub, multi, divide, mod};//�N�禡�s���禡���а}�Copt
    printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
    while(scanf("%d", &choice) && choice != 0){
        if(choice == 1){
            //�[�k
            printf("�п�J2�Ӿ�� : ");
            scanf("%d %d", &a, &b);
            printf("%d + %d = ", a, b);
            printf("%d\n", opt[0](a, b));//�I�sadd
            printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
        }
        if(choice == 2){
            //��k
            printf("�п�J2�Ӿ�� : ");
            scanf("%d %d", &a, &b);
            printf("%d - %d = ", a, b);
            printf("%d\n", opt[1](a, b));//�I�ssub
            printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
        }
        if(choice == 3){
            //���k
            printf("�п�J2�Ӿ�� : ");
            scanf("%d %d", &a, &b);
            printf("%d * %d = ", a, b);
            printf("%d\n", opt[2](a, b));//�I�smulti
            printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
        }
        if(choice == 4){
            //���k
            printf("�п�J2�Ӿ�� : ");
            scanf("%d %d", &a, &b);
            printf("%d / %d = ", a, b);
            printf("%d\n", opt[3](a, b));//�I�sdivide
            printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
        }
        if(choice == 5){
            //���l��
            printf("�п�J2�Ӿ�� : ");
            scanf("%d %d", &a, &b);
            printf("%d %% %d = ", a, b);
            printf("%d\n", opt[4](a, b));//�I�smod
            printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}) : ");
        }
    }
    return 0;
}
