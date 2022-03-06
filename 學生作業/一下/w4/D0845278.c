#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct fraction {
    int up,down;//分子,分母
} A,B,ans;

void output(struct fraction ans,int choise) { //輸出
    if(ans.down==1)//整數
    printf("%d/%d + %d/%d = %d\n",A.up,A.down,B.up,B.down,ans.up);
    else if(ans.up==0)//0
    printf("%d/%d + %d/%d = 0\n",A.up,A.down,B.up,B.down);
    else if(ans.down<0) { //如果分數為負，負號放到分子上
        if(ans.up>0) {
            if(choise == 1)
                printf("%d/%d + %d/%d = -%d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 2)
                printf("%d/%d - %d/%d = -%d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 3)
                printf("%d/%d * %d/%d = -%d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 4)
                printf("%d/%d / %d/%d = -%d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
        } else if(ans.up<0) {
            if(choise == 1)
                printf("%d/%d + %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 2)
                printf("%d/%d - %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 3)
                printf("%d/%d * %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
            else if(choise == 4)
                printf("%d/%d / %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,abs(ans.up),abs(ans.down));
        }
    } else//正常情況
        if(choise == 1)
                printf("%d/%d + %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,ans.up,ans.down);
            else if(choise == 2)
                printf("%d/%d - %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,ans.up,ans.down);
            else if(choise == 3)
                printf("%d/%d * %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,ans.up,ans.down);
            else if(choise == 4)
                printf("%d/%d / %d/%d = %d/%d \n",A.up,A.down,B.up,B.down,ans.up,ans.down);
}

int gcd(int num1,int num2) { //找最大公因數
    int temp;
    while(num1 != 0) {
        temp = num2 % num1;
        num2 = num1;
        num1 = temp;
    }
    return num2;
}

struct fraction simply(struct fraction ans) { //化簡
    int gcd_num = gcd(ans.up,ans.down);
    ans.up /= gcd_num;
    ans.down /= gcd_num;
    return ans;
}

struct fraction add(struct fraction A,struct fraction B) { //加
    A.up *= B.down;//交叉相乘
    B.up *= A.down;
    struct fraction ans = {
        A.up + B.up,
        A.down * B.down
    };
    ans = simply(ans);//化簡
    return ans;
}

struct fraction sub(struct fraction A,struct fraction B) { //減
    A.up *= B.down;//交叉相乘
    B.up *= A.down;
    struct fraction ans = {
        A.up - B.up,
        A.down * B.down
    };
    ans = simply(ans);//化簡
    return ans;
}

struct fraction multi(struct fraction A,struct fraction B) { //乘
    struct fraction ans = {//直接乘
        A.up * B.up,
        A.down * B.down
    };
    ans = simply(ans);//化簡
    return ans;
}

struct fraction divide(struct fraction A,struct fraction B) { //除
    struct fraction ans = {//第二個分數交換再乘
        A.up * B.down,
        A.down * B.up
    };
    ans = simply(ans);//化簡
    return ans;
}

int main() {
    printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
    int choise;
    while(scanf("%d",&choise)!=EOF) {
        if(choise>4||choise<0) { //防呆
            printf("輸入錯誤!\n\n");
            printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
            continue;
        }
        if(choise==1) { //加
            printf("a/b + c/d ，請輸入a b c d:");
            scanf("%d %d %d %d",&A.up,&A.down,&B.up,&B.down);
            if(A.down==0||B.down==0) {//防呆
                printf("分母不可為0\n\n");
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                continue;
            }
            ans = add(A,B);//丟進函式
        } else if(choise==2) { //減
            printf("a/b - c/d ，請輸入a b c d:");
            scanf("%d %d %d %d",&A.up,&A.down,&B.up,&B.down);
            if(A.down==0||B.down==0) {//防呆
                printf("分母不可為0\n\n");
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                continue;
            }
            ans = sub(A,B);//丟進函式
        } else if(choise==3) { //乘
            printf("a/b * c/d ，請輸入a b c d:");
            scanf("%d %d %d %d",&A.up,&A.down,&B.up,&B.down);
            if(A.down==0||B.down==0) {//防呆
                printf("分母不可為0\n\n");
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                continue;
            }
            ans = multi(A,B);//丟進函式
        } else if(choise==4) { //除
            printf("a/b / c/d ，請輸入a b c d:");
            scanf("%d %d %d %d",&A.up,&A.down,&B.up,&B.down);
            if(A.down==0||B.down==0) {//防呆
                printf("分母不可為0\n\n");
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                continue;
            }
            if(B.up==0||B.down==0) {//防呆
                printf("除數不可為0\n\n");
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                continue;
            }
            ans = divide(A,B);//丟進函式
        } else if(choise==0)
            return 0;
        output(ans,choise);//輸出
        printf("\n選擇(1.加/2.減/3.乘/4.除/0.離開):");
    }
}
