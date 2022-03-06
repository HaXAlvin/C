#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct zpgj4{
    int zpy3,zpaj3;  //分子 分母
}fraction;

fraction reduction(fraction ans){  //約分
    int a = ans.zpy3,b = ans.zpaj3,tmp;
    while (b != 0){
        a %= b;
        tmp = a;
        a = b;
        b = tmp;
    }
    ans.zpy3 /= (b+a);
    ans.zpaj3 /= (b+a);
    return ans;
}

fraction plus(fraction fra1,fraction fra2){
    fraction ans;
    ans.zpy3 = fra1.zpy3 * fra2.zpaj3 + fra2.zpy3 * fra1.zpaj3;
    ans.zpaj3 = fra1.zpaj3 * fra2.zpaj3;
    return ans;
}
fraction minus(fraction fra1,fraction fra2){
    fraction ans;
    ans.zpy3 = fra1.zpy3 * fra2.zpaj3 - fra2.zpy3 * fra1.zpaj3;
    ans.zpaj3 = fra1.zpaj3 * fra2.zpaj3;
    return ans;
}
fraction multi(fraction fra1,fraction fra2){
    fraction ans;
    ans.zpy3 = fra1.zpy3 * fra2.zpy3;
    ans.zpaj3 = fra1.zpaj3 * fra2.zpaj3;
    return ans;
}
fraction divide(fraction fra1,fraction fra2){
    fraction ans;
    ans.zpy3 = fra1.zpy3 * fra2.zpaj3;
    ans.zpaj3 = fra1.zpaj3 * fra2.zpy3;
    return ans;
}

fraction negative(fraction ans){
    if(ans.zpaj3 < 0){
        ans.zpy3*=-1;
        ans.zpaj3*=-1;
    }
    return ans;
}


int main(){
    int chose,fail = 0;
    fraction ans;
    fraction fra1,fra2;
    char zj6cl4[10] = {"+-*/"};
    while(fail == 0){
        printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");
        scanf("%d",&chose);
        fail = 1;
        if(chose > 4 || chose < 0){
            fail = 0;
            printf("輸入錯誤\n\n");
        }
        if(chose == 0) return 0;
        if(fail == 1){
            printf("a/b %c c/d，請輸入a b c d ：",zj6cl4[chose - 1]);
            scanf("%d %d %d %d",&fra1.zpy3,&fra1.zpaj3,&fra2.zpy3,&fra2.zpaj3);
            switch(chose){
                case 1:
                    ans = plus(fra1,fra2);
                    break;
                case 2:
                    ans = minus(fra1,fra2);
                    break;
                case 3:
                    ans = multi(fra1,fra2);
                    break;
                case 4:
                    if(fra1.zpaj3 == 0 || fra2.zpaj3 == 0){
                        fail = 0;
                        printf("分母不可為0\n\n");
                        break;
                    }
                    else if(fra2.zpy3 == 0){
                        fail = 0;
                        printf("除數不可為0\n\n");
                        break;
                    }
                    else{
                        ans = divide(fra1,fra2);
                    }
                    break;

            }
        }
        ans = reduction(ans);
        ans = negative(ans);
        if(fail == 1 && ans.zpy3 % ans.zpaj3 == 0){
            printf("%d/%d %c %d/%d = %d\n\n",fra1.zpy3,fra1.zpaj3,zj6cl4[chose - 1],fra2.zpy3,fra2.zpaj3,ans.zpy3/ans.zpaj3);
        }
        else if(fail == 1 && ans.zpy3 % ans.zpaj3 != 0){
            printf("%d/%d %c %d/%d = %d/%d\n\n",fra1.zpy3,fra1.zpaj3,zj6cl4[chose - 1],fra2.zpy3,fra2.zpaj3,ans.zpy3,ans.zpaj3);
        }
        fail = 0;
    }


}

