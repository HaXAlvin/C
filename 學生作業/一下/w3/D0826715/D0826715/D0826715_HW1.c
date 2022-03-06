#include<stdio.h>

int add(int a,int b){//add function
    return a+b;
}
int sub(int a,int b){//subtraction function
    return a-b;
}
int multi(int a,int b){//multiplication function
    return a*b;
}
int divide(int a,int b){//division function
    return a/b;
}
int mod(int a,int b){//mod function
    return a%b;
}
int main(){
    int num_1,num_2;
    int choose;
    char symbol[] = {'+','-','*','/','%'};//print out symbol using array
    int (*opt[])(int,int) = {add,sub,multi,divide,mod};//call function
    while(1){
        printf("Please Choose(1.Add/2.Subtration/3.Multiplication/4.Division/5.Mod/0.Leave) : ");
        scanf("%d",&choose);
        if(choose != 0){
            printf("Insert 2 Integer : ");
            scanf("%d %d",&num_1,&num_2);//input 2 number
            printf("%d %c %d = %d",num_1,symbol[choose - 1],num_2, opt[choose - 1](num_1,num_2));
            printf("\n");
        }
        if(choose == 0)
            return 0;

    }
}
