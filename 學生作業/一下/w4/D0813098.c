#include<stdio.h>
typedef struct div
{
    int up;
    int down;
}div;//一個關於分數的結構的副程式
int gcd(int up,int down)
{
    if(down==0){
        return up;
    }
    else{
        return gcd(down,up%down);
    }
}//求出最大公因數的副程式
div add(div a,div b, div divtem)
{
    divtem.up=a.up*b.down+a.down*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//關於加法的副程式
div multi(div a,div b, div divtem)
{
    divtem.up=a.up*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//關於減法的副程式
div sub(div a,div b, div divtem)
{
    divtem.up=a.up*b.down-a.down*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//關於乘法的副程式
div divide(div a,div b, div divtem)
{
    divtem.up=a.up*b.down;
    divtem.down=a.down*b.up;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//關於除法的副程式
int main()
{
    int input;
    while(1){
        struct div div1;
        struct div div2;
        struct div div3={0,0};//宣告結構div1、div2、div3
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");//印出選擇(1.加/2.減/3.乘/4.除/0.離開):
        scanf("%d", &input);
        if (input==0){
            break;
        }//如果輸入是0，則停止
        else if(input==1){
            printf("a/b +  c/d，請輸入a b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("分母不能為0\n");
            }
            else {
                div3=add(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//否則如果是1，則開始用加法，使用到加法的副程式
        else if(input==2){
            printf("a/b -  c/d，請輸入a b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("分母不能為0\n");
            }
            else {
                div3=sub(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//否則如果是2，則開始用減法，使用到減法的副程式
        else if(input==3){
            printf("a/b *  c/d，請輸入a b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("分母不能為0\n");
            }
            else {
                div3=multi(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//否則如果是3，則開始用乘法，使用到乘法的副程式
        else if(input==4){
            printf("a/b /  c/d，請輸入a b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("分母不能為0\n");
            }
            else if( (div2.up*div2.down) ==0){
                printf("除數不能為0\n");
            }
            else {
                div3=divide(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//否則如果是4，則開始用除法，使用到除法的副程式
        else {
            printf("輸入錯誤，請重新輸入\n");
        }//否則印出輸入錯誤，請重新輸入
    }
    return 0;
}
