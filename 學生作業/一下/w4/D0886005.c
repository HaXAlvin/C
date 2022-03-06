#include<stdio.h>
#include<stdlib.h>

struct score{
    int a,b;
};

int simplify(int k , int p ,int y){
    while((k%y==0)&&(p%y==0)){ //最簡分數
        k=k/y ,p=p/y;
    }
     if((k>0&&p<0)||(k<0&&p<0)){
        k*=(-1);
        p*=(-1);
    }
    int u=k%p;
    if(u==0){
        printf("%d\n",(k/p));

    }
    else if(k==0){
        printf("0\n");
    }
    else{
       if(k<0){
            printf("%d/",k);
        }
        if(k>0){
            printf("%d/",k);
        }

        printf("%d\n",p);

    }
}

int gcd(int a,int b){ //最大公因用輾轉相除法
    while(b!=0){
        int k= a % b;
        a=b;
        b=k;
    }
    return a;

}

int lcm(int a,int b){ //最小公倍
    return a * b / gcd(a,b);
}

int add(int a,int b,int c,int d){ //先做通分再化簡
    int p=lcm(b,d);
    int w1=p/b;
    int w2=p/d;
    int k=(w1*a)+(w2*c);
    int y=gcd(k,p);
    simplify(k,p,y);

}

int sub(int a,int b,int c,int d){ //先做通分再化簡
    int p=lcm(b,d);
    int w1=p/b;
    int w2=p/d;
    int k=(w1*a)-(w2*c);
    int y=gcd(k,p);
    simplify(k,p,y);
}

int multi(int a,int b,int c,int d){ //相乘後再找最大公因數
    int k=a*c ,p= b*d ;
    int y=gcd(k,p);
    simplify(k,p,y);
}

int divide(int a,int b,int c,int d){ //相乘後再找最大公因數
    int k=a*d ,p=b*c ;
    int y=gcd(k,p);
    simplify(k,p,y);
}

int main(){
    int choo;
    struct score num1;
    struct score num2;
    do{
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&choo);        //改成函式呼叫
        if(choo==0){
            return 0;
        }
        if(choo==1){
            printf("a/b + c/d ，請輸入a b c d :");
            scanf("%d %d %d %d",&num1.a,&num1.b,&num2.a,&num2.b);
            if(num1.b==0||num2.b==0){
                printf("分母不可為0\n");
            }

            else{
                printf("%d/%d + %d/%d = ",num1.a,num1.b,num2.a,num2.b);
                add(num1.a,num1.b,num2.a,num2.b);
            }
        }
        if(choo==2){
            printf("a/b - c/d ，請輸入a b c d :");
            scanf("%d %d %d %d",&num1.a,&num1.b,&num2.a,&num2.b);
            if(num1.b==0||num2.b==0){
                printf("分母不可為0\n");
            }

            else{
                 printf("%d/%d - %d/%d = ",num1.a,num1.b,num2.a,num2.b);
                sub(num1.a,num1.b,num2.a,num2.b);
            }
        }
        if(choo==3){
            printf("a/b * c/d ，請輸入a b c d :");
            scanf("%d %d %d %d",&num1.a,&num1.b,&num2.a,&num2.b);
            if(num1.b==0||num2.b==0){
                printf("分母不可為0\n");
            }
            else{
                printf("%d/%d * %d/%d = ",num1.a,num1.b,num2.a,num2.b);
                multi(num1.a,num1.b,num2.a,num2.b);
            }
        }
        if(choo==4){
           printf("a/b / c/d ，請輸入a b c d :");
           scanf("%d %d %d %d",&num1.a,&num1.b,&num2.a,&num2.b);
            if(num1.b==0||num2.b==0){
                printf("分母不可為0\n");
            }
            else if(num2.a==0){
                printf("除數不可為0\n");
            }
            else{
                printf("%d/%d / %d/%d = ",num1.a,num1.b,num2.a,num2.b);
                divide(num1.a,num1.b,num2.a,num2.b);
            }
        }
        if(choo>4){
           printf("輸入錯誤\n");
        }
    }while(choo!=EOF);
    return 0;
}
