#include<stdio.h>
#include<stdlib.h>
struct div{
    int a,b;
};
int test(int x,int y){//劣锣埃猭
    x=abs(x);
    y=abs(y);
    while((x!=0)&&(y!=0)){//讽x,y常ぃ箂
        if (x>y){
            x=x%y;//埃緇计
        }
        else {
            y=y%x;
        }
    }
    if (x==0){//Τ兜箂玥程そ计玥兜
        return y;
    }
    else{
        return x;
    }


}

void addandsub(int first,int second,int third,int forth,int i){
    int temp1,temp2,gcd,k=0;
    struct div answer;
    third=third*second;
    first=first*forth;
    if (i==1){//璝猭
        answer.a=first+third;
    }
    else {//搭猭
        answer.a=first-third;
        if (answer.a<0){
            k=1;
        }
    }
    answer.b=second*forth;
    temp1=answer.a;
    temp2=answer.b;
    gcd=test(answer.a,answer.b);//т程そ计
    if (k==0){//ぃ璽计
        if (temp2/gcd!=1)//だダぃ
            printf(" %d/%d\n\n",temp1/gcd,temp2/gcd);
        else//だダ
            printf(" %d\n\n",temp1/gcd);
    }
    else {//璝璽计だ璽腹
        if (temp2/gcd!=1)//だダぃ
            printf(" -%d/%d\n\n",temp1/gcd,abs(temp2/gcd));
        else//だダ
            printf(" -%d\n\n",temp1/gcd);
    }
    return;
}

void multianddiv(int first,int second,int third,int forth,int i){
    struct div answer;
    int temp[4];//块计
    int x;//璸衡Τ碭璽计
    int gcd,temp1,temp2,temp3;
    temp[0]=first;
    temp[1]=second;
    temp[2]=third;
    temp[3]=forth;
    for (int k=0;k<4;k++){
        if (temp[k]<0){
            x++;//魁Τ碭璽计
        }
    }

    if (i==4){//璝埃猭玥斗盢材兜暗计
        temp3=forth;
        forth=third;
        third=temp3;

    }
    answer.a=first*third;//癘魁だ计挡篶柑

    answer.b=second*forth;

    gcd=test(answer.a,answer.b);//―程そ计

    if (x%2==0){//璝璽计案计
        if (answer.b/gcd!=1)//安だダぃ
            printf(" %d/%d\n\n",abs(answer.a/gcd),abs(answer.b/gcd));
        else
            printf(" %d\n\n",abs(answer.a/gcd));
    }
    else {//璽计计
        if (answer.b/gcd!=1)//安だダぃ
            printf(" -%d/%d\n\n",abs(answer.a/gcd),abs(answer.b/gcd));
        else
            printf(" -%d\n\n",abs(answer.a/gcd));
    }
    return;
}

int main(){
    struct div num[2];
    int input;
    while(1){
        printf("叫匡拒(1.猭/2.搭猭/3.猭/4.埃猭/0.瞒秨):");
        scanf("%d",&input);
        getchar();
        if (input==0){
            break;
        }
        if (input>4){//ň
            printf("块岿粇\n\n");
            continue;
        }
        switch(input){//匡拒搭埃
            case 1:
                printf("a/b + c/d块a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 2:
                printf("a/b - c/d块a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 3:
                printf("a/b * c/d块a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 4:
                printf("a/b / c/d块a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            }
        if ((num[0].b==0)||(num[1].b==0)){//ň
            printf("だダぃ0\n\n");
            continue;
        }
        else if ((input==4)&&(num[1].a==0)){//ň
            printf("埃计ぃ0\n\n");
            continue;
        }
        else {
            if (input==1){//肚搭猭捌祘Α
                printf("%d/%d + %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==2){
                printf("%d/%d - %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==3){//肚埃猭捌祘Α
                printf("%d/%d * %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);

            }
            else {//肚埃猭捌祘Α
                printf("%d/%d / %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }

        }

    }



}
