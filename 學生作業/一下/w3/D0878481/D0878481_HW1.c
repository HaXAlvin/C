#include<stdio.h>
#include<string.h>
int add(int a, int b){
    return a+b;
} //�[�k
int sub(int a, int b){
    return a-b;
} //��k
int multi(int a, int b){
    return a*b;
} //���k
int divide(int a, int b){
    return a/b;
} //���k
int mod(int a, int b){
    return a%b;
} //���l��
int main(){
    int (*opt[])(int, int)={ add, sub, multi, divide, mod};
    while(1){

        int n;
        int x,y;
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}:");
        scanf("%d",&n);//��ܹB��覡
        if (n==0){//�p�G��J0�h���X
            break;
        }
        getchar();
        printf("�п�J��Ӿ��:");
        scanf("%d %d",&x,&y);
        printf("%d\n", opt[n-1](x,y));//�i�J�ҿ�Ƶ{���æL�X���G


    }

}
