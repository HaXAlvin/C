#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct frac{//分數格式=分子+分母
    int mole;//分子
    int deno;//分母
};

void reduction(struct frac ans){//約分
    int neg = 1;//正負flag
    int end = 0;//約到底
    if(ans.mole<0&&ans.deno<0){//分子分母兩者都為負時，兩者取絕對值
        ans.mole=abs(ans.mole);
        ans.deno=abs(ans.deno);
    }
    else if(ans.mole<0||ans.deno<0){//分子分母其一為負時，取絕對值、存負號
        neg=-1;
        ans.mole=abs(ans.mole);
        ans.deno=abs(ans.deno);
    }

    if(ans.mole>ans.deno)//比大小
        end=ans.deno;
    else
        end=ans.mole;

    if(ans.mole==0)//答案分子為零時，印整數0
        printf("0\n\n");
    else if(ans.deno%ans.mole==0&&ans.mole==ans.deno){//分子分母相等時，印整數1
        printf("%d\n\n",neg);
    }
    else if(ans.deno%ans.mole==0){//分母為分子的整數n倍時，印正負1/n
        ans.deno /= ans.mole;
        ans.mole=neg;
        printf("%d/%d\n\n",ans.mole,ans.deno);
    }
    else if(ans.mole%ans.deno==0){//分子為分母的整數n倍時，印正負n
        printf("%d\n\n",ans.mole / ans.deno * neg);
    }
    else{//真假分數約分
        for(int factor = 2;factor<end;factor++){
            if(ans.mole%factor==0&&ans.deno%factor==0){
                ans.mole /= factor;
                ans.deno /= factor;
                factor--;
            }
        }
        printf("%d/%d\n\n",ans.mole * neg,ans.deno);
    }
}

struct frac add(struct frac a_b,struct frac c_d){//加法
    int mole = (a_b.mole * c_d.deno)+(c_d.mole * a_b.deno);//axd+cxb
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d + %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
};

struct frac minus(struct frac a_b,struct frac c_d){//減法
    int mole = (a_b.mole * c_d.deno)-(c_d.mole * a_b.deno);//axd-cxd
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d - %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

struct frac multi(struct frac a_b,struct frac c_d){//乘法
    int mole = (a_b.mole * c_d.mole);//axc
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d * %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

struct frac divide(struct frac a_b,struct frac c_d){//除法
    int mole = (a_b.mole * c_d.deno);//axd
    int deno = (a_b.deno * c_d.mole);//bxc
    struct frac answer = {mole,deno};
    printf("%d/%d / %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

int main(){
    int option = 0;
    while(1){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開):");
        scanf("%d",&option);
        if(option==0)
            return 0;
        else if(option==1||option==2||option==3||option==4){
            struct frac ab;//a/b
            struct frac cd;//c/d
            struct frac answer;

            switch(option){
            case 1:
                printf("a/b + c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                answer=add(ab,cd);
                reduction(answer);
                break;
            case 2:
                printf("a/b - c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                answer=minus(ab,cd);
                reduction(answer);
                break;
            case 3:
                printf("a/b * c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                answer=multi(ab,cd);
                reduction(answer);
                break;
            case 4:
                printf("a/b / c/d，請輸入a b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("分母不可為0\n\n");
                    break;
                }
                else if(cd.mole==0){
                    printf("除數不可為0\n\n");
                    break;
                }
                answer=divide(ab,cd);
                reduction(answer);
                break;
            }
        }
        else
            printf("輸入錯誤\n\n");
    }
}
