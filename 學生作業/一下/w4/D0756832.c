#include<stdio.h>
#include<math.h>

struct Fractional{
    int num;//だ
    int den;//だダ
};

struct Fractional reduction(struct Fractional answer){//だ程虏(ぃ度 タ璽计и硂柑矪瞶 ┮穦struct笲衡ぃノ踞み璽计竚
    int t;//
    int ans_num = answer.num;
    int ans_den = answer.den;
    if(ans_den<0){//盢ㄢ计跑タ计 穦璶―程そ计
        ans_den = ans_den * -1;
    }
    if(ans_num<0){//盢ㄢ计跑タ计 穦璶―程そ计
        ans_num = ans_num * -1;
    }
    if(ans_num<ans_den){//パ逼
        t=ans_num;
        ans_num=ans_den;
        ans_den=t;
    }
    while(ans_num%ans_den!=0){//⊿埃爱瞓杠 埃 ex:1/3 硂t=1 だ琌=3 だダ=1 程そ计琌だダ=t 碞埃荷
        t=ans_num%ans_den;
        ans_num=ans_den;
        ans_den=t;
    }

    answer.num=answer.num/ans_den;//埃程そ计
    answer.den=answer.den/ans_den;//埃程そ

    if(answer.den<0){
        answer.num=answer.num*-1;//セ盢跑タ计璶跑ㄓ
        answer.den=answer.den*-1;//
    }
    return answer;
};
struct Fractional add(struct Fractional first,struct Fractional second){//猭(first=a/b;second=c/d

    first.num=first.num*second.den;//盢计硄だだ1/2 3/4
    second.num=second.num*first.den;//だダゲ斗
    first.den=first.den*second.den;
    second.den=first.den;//玡だダ碞琌硄だ
    struct Fractional answer;
    answer.num=first.num+second.num;//氮だ
    answer.den=first.den;//氮だダ
    return reduction(answer);
};
struct Fractional subb(struct Fractional first,struct Fractional second){//搭猭
    first.num=first.num*second.den;//
    second.num = second.num * first.den;
    first.den=first.den*second.den;
    second.den=first.den;
    struct Fractional answer;
    answer.num=first.num-second.num;
    answer.den=first.den;
    return reduction(answer);
};
struct Fractional mult(struct Fractional first,struct Fractional second){//猭

    struct Fractional answer;
    answer.num=first.num*second.num;
    answer.den=first.den*second.den;
    return reduction(answer);
};
struct Fractional div(struct Fractional first,struct Fractional second){//埃猭
    struct answer;
    //盢材Αだだダ癸秸(埃猭だダ琌だ计ㄓ璶计)
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
        printf("匡拒(1./2.搭/3./4.埃/0.瞒秨):");
        scanf("%d",&choose);
        if(choose>4||choose<0){
            printf("块岿粇\n");
        }
        if(choose==0){
            break;
        }
        else if(choose==1){
            printf("a/b + c/d叫匡拒 a b c d :");
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
            printf("a/b - c/d叫匡拒 a b c d :");
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
            printf("a/b * c/d叫匡拒 a b c d :");
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
            printf("a/b / c/d叫匡拒 a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=div(first,second);
            if(answer.den==0){
                printf("だダぃ0\n");
            }
            else if(answer.num==0){
                printf("埃计ぃ0\n");
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
