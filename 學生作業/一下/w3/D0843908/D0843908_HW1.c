#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int a, int b){ //�[�k
    return a+b;
}
int sub(int a, int b){ //��k
    return a-b;
}
int multi(int a, int b){ //���k
    return a*b;
}
int divide(int a, int b){ //���k
    return a/b;
}
int mod(int a, int b){ //���l��
    return a%b;
}

int main(){
    int (*opt[])(int,int)={add,sub,multi,divide,mod};
    int WhatToDo;
    while(1){
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���})�G");
        while(scanf("%d",&WhatToDo)){
            if(WhatToDo==0){
                return 0;
            }
            int num1,num2;
            printf("�п�J��Ӿ�ơG");
            scanf("%d %d",&num1,&num2);
            if(WhatToDo==1){
                printf("%d + %d = %d\n",num1,num2,opt[0](num1,num2));
            }
            if(WhatToDo==2){
                printf("%d - %d = %d\n",num1,num2,opt[1](num1,num2));
            }
            if(WhatToDo==3){
                printf("%d * %d = %d\n",num1,num2,opt[2](num1,num2));
            }
            if(WhatToDo==4){
                printf("%d / %d = %d\n",num1,num2,opt[3](num1,num2));
            }
            if(WhatToDo==5){
                printf("%d �H %d = %d\n",num1,num2,opt[4](num1,num2));
            }
            break;
        }
    }
}
