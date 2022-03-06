#include<stdio.h>
#include<stdlib.h>
struct div{
    int a,b;
};
int test(int x,int y){//輾轉相除法
    x=abs(x);
    y=abs(y);
    while((x!=0)&&(y!=0)){//當x,y都不為零時
        if (x>y){
            x=x%y;//相除取餘數
        }
        else {
            y=y%x;
        }
    }
    if (x==0){//如有一項為零時，則最大公因數則為另一項
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
    if (i==1){//若為加法
        answer.a=first+third;
    }
    else {//減法
        answer.a=first-third;
        if (answer.a<0){
            k=1;
        }
    }
    answer.b=second*forth;
    temp1=answer.a;
    temp2=answer.b;
    gcd=test(answer.a,answer.b);//找最大公因數
    if (k==0){//不為負數
        if (temp2/gcd!=1)//分母不為一
            printf(" %d/%d\n\n",temp1/gcd,temp2/gcd);
        else//分母為一
            printf(" %d\n\n",temp1/gcd);
    }
    else {//若為負數，在分子加上負號
        if (temp2/gcd!=1)//分母不為一
            printf(" -%d/%d\n\n",temp1/gcd,abs(temp2/gcd));
        else//分母為一
            printf(" -%d\n\n",temp1/gcd);
    }
    return;
}

void multianddiv(int first,int second,int third,int forth,int i){
    struct div answer;
    int temp[4];//存輸入數字
    int x;//計算有幾個負數
    int gcd,temp1,temp2,temp3;
    temp[0]=first;
    temp[1]=second;
    temp[2]=third;
    temp[3]=forth;
    for (int k=0;k<4;k++){
        if (temp[k]<0){
            x++;//紀錄有幾個為負數
        }
    }

    if (i==4){//若為除法則須將第一項值做倒數
        temp3=forth;
        forth=third;
        third=temp3;

    }
    answer.a=first*third;//記錄到分數結構裡

    answer.b=second*forth;

    gcd=test(answer.a,answer.b);//求出最大公因數

    if (x%2==0){//若負數為偶數
        if (answer.b/gcd!=1)//假如分母不為一
            printf(" %d/%d\n\n",abs(answer.a/gcd),abs(answer.b/gcd));
        else
            printf(" %d\n\n",abs(answer.a/gcd));
    }
    else {//負數為奇數
        if (answer.b/gcd!=1)//假如分母不為一
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
        printf("請選擇(1.加法/2.減法/3.乘法/4.除法/0.離開):");
        scanf("%d",&input);
        getchar();
        if (input==0){
            break;
        }
        if (input>4){//防呆
            printf("輸入錯誤\n\n");
            continue;
        }
        switch(input){//選擇加減乘除
            case 1:
                printf("a/b + c/d，輸入a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 2:
                printf("a/b - c/d，輸入a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 3:
                printf("a/b * c/d，輸入a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 4:
                printf("a/b / c/d，輸入a b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            }
        if ((num[0].b==0)||(num[1].b==0)){//防呆
            printf("分母不可為0\n\n");
            continue;
        }
        else if ((input==4)&&(num[1].a==0)){//防呆
            printf("除數不可為0\n\n");
            continue;
        }
        else {
            if (input==1){//傳入加減法副程式
                printf("%d/%d + %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==2){
                printf("%d/%d - %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==3){//傳入乘除法副程式
                printf("%d/%d * %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);

            }
            else {//傳入乘除法副程式
                printf("%d/%d / %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }

        }

    }



}
