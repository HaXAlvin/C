#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Number{
    int a,b,c,d,e,f;
}num;

//輾轉相除法找最大公因數
int GCD(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    if(a==0){
        return b;
    }else{
        return a;
    }
}


num add(num ADD){ //加法
    ADD.e = ADD.a*ADD.d + ADD.c*ADD.b;
    ADD.f = ADD.b*ADD.d;
    //紀錄原本的正負後先轉正再取餘數
    int negative_e = 0;
    int negative_f = 0;
    if(ADD.f<0){
        ADD.f = ADD.f * (-1);
        negative_f++;
    }
    if(ADD.e<0){
        ADD.e = ADD.e * (-1);
        negative_e++;
    }
    //g = 最大公因數
    int g = GCD(ADD.e,ADD.f);
    //約分
    ADD.e = ADD.e / g;
    ADD.f = ADD.f / g;
    //加上負號
    if(negative_e==1){
        ADD.e = ADD.e * (-1);
    }
    if(negative_f==1){
        ADD.e = ADD.e * (-1);
    }
    return ADD;
}

num sub(num SUB){ //減法
    SUB.e = SUB.a*SUB.d - SUB.c*SUB.b;
    SUB.f = SUB.b*SUB.d;
    //紀錄原本的正負後先轉正再取餘數
    int negative_e = 0;
    int negative_f = 0;
    if(SUB.f<0){
        SUB.f = SUB.f * (-1);
        negative_f++;
    }
    if(SUB.e<0){
        SUB.e = SUB.e * (-1);
        negative_e++;
    }
    //g = 最大公因數
    int g = GCD(SUB.e,SUB.f);
    //約分
    SUB.e = SUB.e / g;
    SUB.f = SUB.f / g;
    //加上負號
    if(negative_e==1){
        SUB.e = SUB.e * (-1);
    }
    if(negative_f==1){
        SUB.e = SUB.e * (-1);
    }
    return SUB;
}
num multi(num MULTI){ //乘法
    MULTI.e = MULTI.a * MULTI.c;
    MULTI.f = MULTI.b * MULTI.d;
    //紀錄原本的正負後先轉正再取餘數
    int negative_e = 0;
    int negative_f = 0;
    if(MULTI.f<0){
        MULTI.f = MULTI.f * (-1);
        negative_f++;
    }
    if(MULTI.e<0){
        MULTI.e = MULTI.e * (-1);
        negative_e++;
    }
    //g = 最大公因數
    int g = GCD(MULTI.e,MULTI.f);
    //約分
    MULTI.e = MULTI.e / g;
    MULTI.f = MULTI.f / g;
    //加上負號
    if(negative_e==1){
        MULTI.e = MULTI.e * (-1);
    }
    if(negative_f==1){
        MULTI.e = MULTI.e * (-1);
    }
    return MULTI;
}
num divide(num DIVIDE){ //除法
    DIVIDE.e = DIVIDE.a * DIVIDE.d;
    DIVIDE.f = DIVIDE.b * DIVIDE.c;
    //紀錄原本的正負後先轉正再取餘數
    int negative_e = 0;
    int negative_f = 0;
    if(DIVIDE.f<0){
        DIVIDE.f = DIVIDE.f * (-1);
        negative_f++;
    }
    if(DIVIDE.e<0){
        DIVIDE.e = DIVIDE.e * (-1);
        negative_e++;
    }
    //g = 最大公因數
    int g = GCD(DIVIDE.e,DIVIDE.f);
    //約分
    DIVIDE.e = DIVIDE.e / g;
    DIVIDE.f = DIVIDE.f / g;
    //加上負號
    if(negative_e==1){
        DIVIDE.e = DIVIDE.e * (-1);
    }
    if(negative_f==1){
        DIVIDE.e = DIVIDE.e * (-1);
    }
    return DIVIDE;
}

int main(){
    int WhatToDo;
    num num = {
        0,0,0,0,0,0
    };
    while(1){
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/5.取餘數/0.離開)：");
        while(scanf("%d",&WhatToDo)){
            if(WhatToDo==0){
                return 0;
            }
            if(WhatToDo!=0&&WhatToDo!=1&&WhatToDo!=2&&WhatToDo!=3&&WhatToDo!=4){
                printf("輸入錯誤\n\n");
            }
            if(WhatToDo==1){
                printf("a/b + c/d，請輸入a b c d：");
                scanf("%d %d %d %d",&num.a,&num.b,&num.c,&num.d);
                if((num.b==0)||(num.d==0)){
                    printf("分母不可為0");
                    break;
                }
                printf("%d/%d + %d/%d = ",num.a,num.b,num.c,num.d);
                num = add(num);
                if((num.e)%(num.f)==0){
                    printf("%d\n",(num.e)/(num.f));
                }else{
                    printf("%d/%d\n",num.e,num.f);
                }
            }
            if(WhatToDo==2){
                printf("a/b - c/d，請輸入a b c d：");
                scanf("%d %d %d %d",&num.a,&num.b,&num.c,&num.d);
                if((num.b==0)||(num.d==0)){
                    printf("分母不可為0");
                    break;
                }
                printf("%d/%d - %d/%d = ",num.a,num.b,num.c,num.d);
                num = sub(num);
                if((num.e)%(num.f)==0){
                    printf("%d\n",(num.e)/(num.f));
                }else{
                    printf("%d/%d\n",num.e,num.f);
                }
            }
            if(WhatToDo==3){
                printf("a/b * c/d，請輸入a b c d：");
                scanf("%d %d %d %d",&num.a,&num.b,&num.c,&num.d);
                if((num.b==0)||(num.d==0)){
                    printf("分母不可為0");
                    break;
                }
                printf("%d/%d * %d/%d = ",num.a,num.b,num.c,num.d);
                num = multi(num);
                if((num.e)%(num.f)==0){
                    printf("%d\n",(num.e)/(num.f));
                }else{
                    printf("%d/%d\n",num.e,num.f);
                }
            }
            if(WhatToDo==4){
                printf("a/b / c/d，請輸入a b c d：");
                scanf("%d %d %d %d",&num.a,&num.b,&num.c,&num.d);
                if((num.b==0)||(num.d==0)){
                    printf("分母不可為0\n\n");
                    break;
                }
                if(num.c==0){
                    printf("除數不可為0\n\n");
                    break;
                }
                printf("%d/%d / %d/%d = ",num.a,num.b,num.c,num.d);
                num = divide(num);
                if((num.e)%(num.f)==0){
                    printf("%d\n",(num.e)/(num.f));
                }else{
                    printf("%d/%d\n",num.e,num.f);
                }
            }
            break;
        }
    }
}
