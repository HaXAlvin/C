#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){//�[�k
    return a + b;
}
int sub(int a, int b){//��k
    return a - b;
}
int multi(int a, int b){//���k
    return a * b;
}
int divide(int a, int b){//���k
    return a / b;
}
int mod(int a, int b){ //���l��
    return a % b;
}


int main(){
    int chose,a,b;
    char op[] = {"+-*/%"};//�Ÿ���
    int (*opt[])(int ,int) = {add,sub,multi,divide,mod};
    while(1){
        puts("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���})�G");
        scanf("%d",&chose);
        if(!chose){
            printf("exit\n");
            break;
        }
        else if(chose>5 || chose<0){
            printf("error\n");
            continue;
        }
        printf("�п�J��Ӿ�ơG");
        scanf("%d %d",&a,&b);
        printf("%d %c %d = %d\n",a,op[chose - 1],b,opt[chose - 1](a , b));
    }


}
