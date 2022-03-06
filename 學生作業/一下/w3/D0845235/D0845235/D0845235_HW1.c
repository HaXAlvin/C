#include<stdlib.h>
#include<stdio.h>

int add(int a,int b){//加法
    return a + b;
}

int sub(int a,int b){//減法
    return a - b;
}

int multi(int a,int b){//乘法
    return a * b;
}

int divide(int a,int b){//除法
    return a / b;
}

int mod(int a,int b){//取餘數
    return a % b;
}

int main(){
    while(1235){
        int num=0,a=0,b=0,(*opt[6])(int,int)={add,sub,multi,divide,mod,};

        printf("請選擇（1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開）：");
        scanf("%d",&num);//輸入選擇。
        if(num==0){//0.離開
            printf("離開此系統，歡迎下次再來");
            return 0;
        }
        while((num>5)||(num<0)){
            printf("輸入錯誤，請重新輸入\n");//輸入不為1,2,3,4,5,0，則重新輸入。
            printf("請選擇（1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開）：");
            scanf("%d",&num);//輸入選擇
        }
        printf("請輸入2個整數：");
        scanf("%d %d",&a,&b);//輸入a,b
        if(num==1){//1.加法
            printf("%d + %d = %d\n",a,b,opt[0](a,b));
        }
        else if(num==2){//2.減法
            printf("%d - %d = %d\n",a,b,opt[1](a,b));
        }
        else if(num==3){//3.乘法
            printf("%d * %d = %d\n",a,b,opt[2](a,b));
        }
        else if(num==4){//4.除法
            printf("%d / %d = %d\n",a,b,opt[3](a,b));
        }
        else if(num==5){//5.取餘數
            printf("%d %% %d = %d\n",a,b,opt[4](a,b));
        }
    }


}
