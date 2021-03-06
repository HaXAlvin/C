#include<stdio.h>
#include<stdlib.h>

struct fraction {
    int mole;//だ
    int deno;//だダ
    int ans;//程だ计俱计
};

struct fraction add(struct fraction f1,struct fraction f2) { //猭
    struct fraction result;//砞肚result
    result.mole = f1.mole*f2.deno + f1.deno*f2.mole;//だ计肚だa*c + b*d
    result.deno = f1.deno*f2.deno;//だ计肚だダb*d
    int x = result.mole;//砞既だ计肚だ
    int y = result.deno;//砞既だ计肚だダ
    if((result.mole%result.deno)==0){//狦だ埃だダ緇计0
        result.ans = result.mole/result.deno;//砞俱计肚
    }
    if(result.deno<0){//狦だダ璽计玥璶эΘだ璽计
        result.deno = -result.deno;
        result.mole = -result.mole;
    }

    while(x%y!=0){//―程そ计ノㄓだ
        int temp = y;
        y = x%y;//y程そ计
        x= temp;
    }
    if(y<0){//狦程そ计璽计玥锣传タ
        y=-y;
    }
    result.mole = result.mole/y;//だ计肚だ
    result.deno = result.deno/y;//だ计肚だ
    return result;
};

struct fraction sub(struct fraction f1,struct fraction f2) { //搭猭
    struct fraction result;//砞肚result
    result.mole = f1.mole*f2.deno - f1.deno*f2.mole;//だ计肚だa*d - b*c
    result.deno = f1.deno*f2.deno;//だ计肚だダb*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0){
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//狦だダ璽计玥璶эΘだ璽计
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//―程そ计ノㄓだ
        int temp = y;
        y = x%y;//y程そ计
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//だ计肚だ
    result.deno = result.deno/y;//だ计肚だ
    return result;
};

struct fraction mult(struct fraction f1,struct fraction f2) { //猭
    struct fraction result;//砞肚result
    result.mole = f1.mole*f2.mole;//だ计肚だa*c
    result.deno = f1.deno*f2.deno;//だ计肚だダb*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//―程そ计ノㄓだ
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){
        int temp = y;
        y = x%y;//y程そ计
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//だ计肚だ
    result.deno = result.deno/y;//だ计肚だ
    return result;
};

struct fraction divide(struct fraction f1,struct fraction f2) { //埃猭
    struct fraction result;//砞肚result
    result.mole = f1.mole*f2.deno;//だ计肚だa*d
    result.deno = f1.deno*f2.mole;//だ计肚だダb*c
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//狦だダ璽计玥璶эΘだ璽计
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//―程そ计ノㄓだ
        int temp = y;
        y = x%y;//y程そ计
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//だ计肚だ
    result.deno = result.deno/y;//だ计肚だ
    return result;
};

int main() {
    struct fraction frac1;
    struct fraction frac2;
    int choose=0;
    struct fraction result;
    while(1235) {
        printf("匡拒(1. / 2.搭 / 3. / 4.埃 / 0.瞒秨):");
        scanf("%d",&choose);//叫块匡拒
        if((choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)&&(choose!=0)) { //璝块ぃ1,2,3,4,0玥穝块
            printf("块岿粇叫穝块\n\n");
            continue;
        }
        if(choose==0) { //0.瞒秨
            printf("瞒秨╰参");
            return 0;
        }
        else if(choose==1) { //1.匡拒笲衡
            printf("a/b + c/d叫块a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("だダぃ0\n");
            } else {
                result = add(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d + %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==2) { //2.匡拒搭笲衡
            printf("a/b - c/d叫块a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("だダぃ0\n");
            } else {
                result = sub(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d - %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==3) { //匡拒笲衡
            printf("a/b * c/d叫块a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("だダぃ0\n");
            } else {
                result = mult(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d * %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==4) { //匡拒埃笲衡
            printf("a/b / c/d叫块a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)||(frac2.deno==0)) {
                printf("だダぃ0\n");
            } else if(frac2.mole==0) {
                printf("埃计ぃ0\n");
            } else {
                result = divide(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d / %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
    }


}



