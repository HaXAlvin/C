#include<stdio.h>
#include<stdlib.h>

typedef struct div{
    int mole,deno;//分子分母
}Div;
Div add(Div fra1,Div fra2){//加
    Div ans;
    if (fra1.deno != fra2.deno){//分母不同
        ans.deno = fra1.deno * fra2.deno;
        ans.mole = fra1.mole * fra2.deno + fra2.mole * fra1.deno;
    }
    else {//分母相同
        ans.deno = fra1.deno;
        ans.mole = fra1.mole + fra2.mole;
    }

    return ans;
}
Div sub(Div fra1,Div fra2){//減
    Div ans;
    if (fra1.deno != fra2.deno){//分母不同
        ans.deno = fra1.deno * fra2.deno;
        ans.mole = fra1.mole * fra2.deno - fra2.mole * fra1.deno;
    }
    else {//分母相同
        ans.deno = fra1.deno;
        ans.mole = fra1.mole - fra2.mole;
    }
    return ans;
};
Div multi(Div fra1,Div fra2){//乘
    Div ans;
    ans.deno = fra1.deno * fra2.deno;
    ans.mole = fra1.mole * fra2.mole;
    return ans;
};
Div divide(Div fra1,Div fra2){//除
    Div ans;
    ans.deno = fra1.deno * fra2.mole;
    ans.mole = fra1.mole * fra2.deno;
    return ans;
};
Div gcd(Div ans){//約分--輾轉相除法
    int m,d,c,k,i;
    m = ans.mole;
    d = ans.deno;
    if (m < 0) m*=(-1);
    if (d < 0) d*=(-1);
    for (i = 0;c > 0;i++){
        c = d % m;
        d = m;
        k = m;
        m = c;
    }
    ans.mole /= k;
    ans.deno /= k;
    return ans;
};
int main(){
    int opt,n;
    Div fra1;
    Div fra2;
    Div ans;
    char sign[] = "+-*/";//運算符號
    while (opt != 0){
        do{
            n = 0;
            do{
                n = 0;
                printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
                scanf("%d",&opt);
                if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 0){//選項防呆
                    printf("輸入錯誤\n\n");
                    n = 1;
                }
            }while(n == 1);
            if (opt == 0) return 0;
            printf("a/b %c c/d，請輸入a b c d:",sign[opt-1]);
            scanf("%d %d %d %d",&fra1.mole,&fra1.deno,&fra2.mole,&fra2.deno);
            if (opt == 4 && fra2.mole == 0){//分子防呆
                printf("除數不可為0\n\n");
                n = 1;
            }
            else if (fra2.deno == 0){
                printf("分母不可為0\n\n");//分母防呆
                n = 1;
            }
        }while (n == 1);

        switch(opt){
            case 1:
                ans = add(fra1,fra2);//加
                ans = gcd(ans);
                if (ans.deno < 0){//負號在分子
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 2:
                ans = sub(fra1,fra2);//減
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 3:
                ans = multi(fra1,fra2);//乘
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 4:
                ans = divide(fra1,fra2);//除
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=-1;
                    ans.deno*=(-1);
                }
                break;
        }
        printf("%d/%d %c %d/%d = ",fra1.mole,fra1.deno,sign[opt-1],fra2.mole,fra2.deno);
        if (ans.deno == 1) printf("%d\n",ans.mole);//整數
        else printf("%d/%d\n",ans.mole,ans.deno);//分數
        printf("\n");
    }
}
