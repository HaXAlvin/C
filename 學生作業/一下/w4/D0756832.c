#include<stdio.h>
#include<math.h>

struct Fractional{
    int num;//分子
    int den;//分母
};

struct Fractional reduction(struct Fractional answer){//約分約到最簡(不僅如此 正負數我也在這裡處理 所以待會的struct運算不用擔心負數的位置
    int t;//佔存
    int ans_num = answer.num;
    int ans_den = answer.den;
    if(ans_den<0){//先將兩數變為正數 因為待會要求出最大公因數
        ans_den = ans_den * -1;
    }
    if(ans_num<0){//先將兩數變為正數 因為待會要求出最大公因數
        ans_num = ans_num * -1;
    }
    if(ans_num<ans_den){//先由小排到大
        t=ans_num;
        ans_num=ans_den;
        ans_den=t;
    }
    while(ans_num%ans_den!=0){//沒除乾淨的話 一直除 ex:1/3 這時的t=1 分子是=3 分母=1 最大公因數是分母的值=t 就除盡了
        t=ans_num%ans_den;
        ans_num=ans_den;
        ans_den=t;
    }

    answer.num=answer.num/ans_den;//除最大公因數
    answer.den=answer.den/ans_den;//除最大公因

    if(answer.den<0){
        answer.num=answer.num*-1;//原本將他變為正數要變回來
        answer.den=answer.den*-1;//同上
    }
    return answer;
};
struct Fractional add(struct Fractional first,struct Fractional second){//加法(first=a/b;second=c/d

    first.num=first.num*second.den;//先將數字通分才能分子相加1/2 3/4
    second.num=second.num*first.den;//分母必須相同
    first.den=first.den*second.den;
    second.den=first.den;//此時的前者分母就是通分後的了
    struct Fractional answer;
    answer.num=first.num+second.num;//答案的分子
    answer.den=first.den;//答案的分母
    return reduction(answer);
};
struct Fractional subb(struct Fractional first,struct Fractional second){//減法
    first.num=first.num*second.den;//同上
    second.num = second.num * first.den;
    first.den=first.den*second.den;
    second.den=first.den;
    struct Fractional answer;
    answer.num=first.num-second.num;
    answer.den=first.den;
    return reduction(answer);
};
struct Fractional mult(struct Fractional first,struct Fractional second){//乘法

    struct Fractional answer;
    answer.num=first.num*second.num;
    answer.den=first.den*second.den;
    return reduction(answer);
};
struct Fractional div(struct Fractional first,struct Fractional second){//除法
    struct answer;
    //將第二式的分子分母對調(除法分母是分數拿上來要倒數)
    int t;
    t=second.num;
    second.num=second.den;
    second.den=t;
    struct Fractional answer;
    answer=mult(first,second);
    return reduction(answer);
};
int main(){
    int choose;
    struct Fractional answer;
    struct Fractional first;
    struct Fractional second;
    while(1){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&choose);
        if(choose>4||choose<0){
            printf("輸入錯誤\n");
        }
        if(choose==0){
            break;
        }
        else if(choose==1){
            printf("a/b + c/d，請選擇 a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=add(first,second);
            if(answer.num%answer.den==0){
                printf("%d/%d + %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d + %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==2){
            printf("a/b - c/d，請選擇 a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=subb(first,second);
            if(answer.num%answer.den==0){
                printf("%d/%d - %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d - %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==3){
            printf("a/b * c/d，請選擇 a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=mult(first,second);
            if(answer.num%answer.den==0){

                printf("%d/%d * %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d * %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==4){
            printf("a/b / c/d，請選擇 a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=div(first,second);
            if(answer.den==0){
                printf("分母不可為0\n");
            }
            else if(answer.num==0){
                printf("除數不可為0\n");
            }
            else if(answer.num%answer.den==0){
                printf("%d/%d / %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d / %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
    }
    return 0;
}
