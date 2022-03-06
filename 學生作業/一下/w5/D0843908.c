#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _Struct{
    union Union{
        int save_int;
        float save_float;
        char save_s[16];
    }Union;
    char save;
}Struct;

int main(){
    //宣告陣列
    Struct str[0];
    Struct *ptr = &str[0];
    //第一次配置空間
    ptr = malloc(sizeof(struct _Struct));
    //while第 num 次執行
    int num = 1;
    while(1){
        //選擇
        int what;
        //選擇動作與防呆
        while(1){
            printf("選擇：(1.新增/2.印出/0.結束)：");
            scanf("%d%*c",&what);
            if(what!=1 && what!=2 && what!=0){
                printf("輸入錯誤!\n");
                continue;
            }
            break;
        }
        if(what==0){
            printf("結束程式");
            free(ptr);
            return 0;
        }
        //選擇儲存類型與儲存
        if(what==1){
            while(1){
                printf("選擇類型：(i：int/f：float/s：char[16])：");
                scanf("%c%*c",&str[num].save);
                if(str[num].save!='i'&&str[num].save!='f'&&str[num].save!='s'){
                    printf("輸入錯誤!\n");
                    continue;
                }
                if(str[num].save=='i'){
                    printf("輸入資料：");
                    scanf("%d",&str[num].Union.save_int);
                }
                if(str[num].save=='f'){
                    printf("輸入資料：");
                    scanf("%f",&str[num].Union.save_float);
                }
                if(str[num].save=='s'){
                    printf("輸入資料：");
                    scanf("%s",&str[num].Union.save_s);
                }
                break;
            }
        }
        //印出
        if(what==2){
            for(int i=1;i<=num;i++){
                if(str[i].save=='i'){
                    printf("%d\n",str[i].Union.save_int);
                }else if(str[i].save=='f'){
                    printf("%f\n",str[i].Union.save_float);
                }else if(str[i].save=='s'){
                    printf("%s\n",str[i].Union.save_s);
                }
            }
        }
        num++;
        //配置新空間
        ptr = realloc(ptr, (num+1) * sizeof(struct _Struct));
    }
}
