#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b){//�[
    return a + b;
}
int sub(int a, int b){//��
    return a - b;
}
int multi(int a, int b){//��
    return a * b;
}
int divide(int a, int b){//��
    return a / b;
}
int mod(int a, int b){//���l��
    return a % b;
}

int main(){
    int a,b,n;
    int (*opt[])(int,int) = {add,sub,multi,divide,mod};//�ϥ�opt[n]�I�s�Ƶ{��
    while (n != 0){
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}):");
        scanf("%d",&n);
        if (n == 0) return 0;
        printf("�п�J2�Ӿ��:");
        scanf("%d %d",&a,&b);
        switch (n){
            case 1:
                printf("%d + %d = %d\n",a,b,opt[0](a,b));
                break;
            case 2:
                printf("%d - %d = %d\n",a,b,opt[1](a,b));
                break;
            case 3:
                printf("%d * %d = %d\n",a,b,opt[2](a,b));
                break;
            case 4:
                printf("%d / %d = %d\n",a,b,opt[3](a,b));
                break;
            case 5:
                printf("%d %% %d = %d\n",a,b,opt[4](a,b));
                break;
        }
    }
}
