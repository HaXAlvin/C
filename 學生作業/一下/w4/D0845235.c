#include<stdio.h>
#include<stdlib.h>

struct fraction {
    int mole;//分子
    int deno;//分母
    int ans;//最後的分數為一個整數
};

struct fraction add(struct fraction f1,struct fraction f2) { //加法
    struct fraction result;//設一個回傳值result
    result.mole = f1.mole*f2.deno + f1.deno*f2.mole;//分數回傳值的分子為a*c + b*d
    result.deno = f1.deno*f2.deno;//分數回傳值的分母為b*d
    int x = result.mole;//設一個暫存存分數回傳值的分子
    int y = result.deno;//設一個暫存存分數回傳值的分母
    if((result.mole%result.deno)==0){//如果分子除以分母的餘數為0
        result.ans = result.mole/result.deno;//另外設一個整數回傳值
    }
    if(result.deno<0){//如果分母為負數，則要改成分子為負數
        result.deno = -result.deno;
        result.mole = -result.mole;
    }

    while(x%y!=0){//求最大公因數用來約分
        int temp = y;
        y = x%y;//y為最大公因數
        x= temp;
    }
    if(y<0){//如果最大公因數為負數則轉換為正
        y=-y;
    }
    result.mole = result.mole/y;//分數回傳值約分
    result.deno = result.deno/y;//分數回傳值約分
    return result;
};

struct fraction sub(struct fraction f1,struct fraction f2) { //減法
    struct fraction result;//設一個回傳值result
    result.mole = f1.mole*f2.deno - f1.deno*f2.mole;//分數回傳值的分子為a*d - b*c
    result.deno = f1.deno*f2.deno;//分數回傳值的分母為b*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0){
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//如果分母為負數，則要改成分子為負數
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//求最大公因數用來約分
        int temp = y;
        y = x%y;//y為最大公因數
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//分數回傳值約分
    result.deno = result.deno/y;//分數回傳值約分
    return result;
};

struct fraction mult(struct fraction f1,struct fraction f2) { //乘法
    struct fraction result;//設一個回傳值result
    result.mole = f1.mole*f2.mole;//分數回傳值的分子為a*c
    result.deno = f1.deno*f2.deno;//分數回傳值的分母為b*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//求最大公因數用來約分
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){
        int temp = y;
        y = x%y;//y為最大公因數
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//分數回傳值約分
    result.deno = result.deno/y;//分數回傳值約分
    return result;
};

struct fraction divide(struct fraction f1,struct fraction f2) { //除法
    struct fraction result;//設一個回傳值result
    result.mole = f1.mole*f2.deno;//分數回傳值的分子為a*d
    result.deno = f1.deno*f2.mole;//分數回傳值的分母為b*c
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//如果分母為負數，則要改成分子為負數
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//求最大公因數用來約分
        int temp = y;
        y = x%y;//y為最大公因數
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//分數回傳值約分
    result.deno = result.deno/y;//分數回傳值約分
    return result;
};

int main() {
    struct fraction frac1;
    struct fraction frac2;
    int choose=0;
    struct fraction result;
    while(1235) {
        printf("選擇(1.加 / 2.減 / 3.乘 / 4.除 / 0.離開):");
        scanf("%d",&choose);//請輸入選擇
        if((choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)&&(choose!=0)) { //若輸入不為1,2,3,4,0，則重新輸入
            printf("輸入錯誤，請重新輸入\n\n");
            continue;
        }
        if(choose==0) { //0.離開
            printf("離開此系統");
            return 0;
        }
        else if(choose==1) { //1.選擇加的運算
            printf("a/b + c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("分母不可為0\n");
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
        else if(choose==2) { //2.選擇減的運算
            printf("a/b - c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("分母不可為0\n");
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
        else if(choose==3) { //選擇乘的運算
            printf("a/b * c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("分母不可為0\n");
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
        else if(choose==4) { //選擇除的運算
            printf("a/b / c/d，請輸入a b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)||(frac2.deno==0)) {
                printf("分母不可為0\n");
            } else if(frac2.mole==0) {
                printf("除數不可為0\n");
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



