#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct tem{//分子分母
    int Den;
    int Mol;
}tem;
tem add(tem n,tem m){//加法
    int a,b;
    tem ans;
    ans.Mol=n.Mol*m.Den+m.Mol*n.Den;
    ans.Den=n.Den*m.Den;
    if(ans.Den<0){//負號擺分子
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem reduce(tem n,tem m){//減法
    tem ans;
    ans.Den=n.Den*m.Den;
    ans.Mol=n.Mol*m.Den-m.Mol*n.Den;
        if(ans.Den<0){//負號擺分子
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem multiply(tem n,tem m){//乘法
    tem ans;
    ans.Den=n.Den*m.Den;
    ans.Mol=n.Mol*m.Mol;
        if(ans.Den<0){//負號擺分子
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem divide(tem n,tem m){//除法
    tem ans;
    ans.Den=n.Den*m.Mol;
    ans.Mol=n.Mol*m.Den;
        if(ans.Den<0){//負號擺分子
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
int main()
{
    int i;
    tem n;
    tem m;
    tem ans;

    while(i){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");//選擇
        scanf("%d",&i);
        if(i==0){
            break;
        }
        else if(i==1){//加法
            printf("a/b + c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//分母為0就重來
                printf("分母不可為0\n");
                continue;
            }
            ans=add(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==2){//減法
            printf("a/b - c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//分母為0就重來
                printf("分母不可為0\n");
                continue;
            }
            ans=reduce(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==3){//乘法
            printf("a/b * c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//分母為0就重來
                printf("分母不可為0\n");
                continue;
            }
            ans=multiply(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==4){//除法
            printf("a/b / c/d，請輸入a b c d：");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Mol==0){//除數為0就重來
                printf("除數不可為0\n");
                continue;
            }
            if(m.Den==0){//分母為0就重來
                printf("分母不可為0\n");
                continue;
            }
            ans=divide(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else//輸入別的數字會出現
            printf("輸入錯誤\n");
    }
    return 0;
}
