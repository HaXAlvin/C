#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b){//�[�k
    return a+b;
}

int sub(int a, int b){//��k
    return a-b;
}

int multi(int a, int b){//���k
    return a*b;
}

int divide(int a, int b){//���k
    return a/b;
}

int mob(int a, int b){//���l��
    return a%b;
}

int main(){
    int a = 0;
    int b = 0;
    int option = 0;
    int (*opt[])(int,int) = {add,sub,multi,divide,mob};
    while(1){
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
        scanf("%d",&option);
        if(option==0)
            return 0;
        printf("�п�J2�Ӿ��:");
        scanf("%d %d",&a,&b);

        switch(option){
            case 1:
                printf("%d + %d = ",a,b);
                break;
            case 2:
                printf("%d - %d = ",a,b);
                break;
            case 3:
                printf("%d * %d = ",a,b);
                break;
            case 4:
                printf("%d / %d = ",a,b);
                break;
            case 5:
                printf("%d %% %d = ",a,b);
                break;
        }
        printf("%d\n",opt[option-1](a,b));
    }
}
