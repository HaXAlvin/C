#include <stdio.h>
#include<stdlib.h>

typedef union {
    int num;//計數字
    float f_num;//計小數
    char word[16];//計字串
} Save;

typedef struct {
    Save save;//union
    char input;//類型輸入
} Data;

void save_data(Data *aa) {
    Data new;
    while(1) {
        printf("選擇類型:(i:int/f:float/s:char[16]):");
        getchar();
        scanf("%c",&(aa->input));//輸入指向Data類型輸入
        if(aa->input == 'i') {
            printf("輸入資料:");
            scanf("%d",&aa->save.num);//存入union
            break;
        } else if(aa->input == 'f') {
            printf("輸入資料:");
            scanf("%f",&aa->save.f_num);//存入union
            break;
        } else if(aa->input == 's') {
            printf("輸入資料:");
            scanf("%s",aa->save.word);//存入union
            break;
        } else {//防呆
            printf("輸入錯誤!\n");
            continue;
        }
    }
}

int main() {
    printf("選擇:(1.新增/2.印出/0.結束):");
    int choice;
    Data *ans = malloc(1*sizeof(Data));//動態陣列
    int i=0,time=1;
    while(scanf("%d",&choice)!=EOF) {
        if(choice==0) {//結束
            printf("結束程式\n");
            free(ans);//釋放記憶體
            return 0;
        } else if(choice!=0&&choice!=1&&choice!=2) {//防呆
            printf("輸入錯誤!\n");
            printf("選擇:(1.新增/2.印出/0.結束):");
            continue;
        } else if(choice==1) { //新增
            ans = realloc(ans,time*sizeof(Data));//變更大小
            save_data(&ans[i]);
            i++;
            time++;
            printf("選擇:(1.新增/2.印出/0.結束):");
        } else if(choice==2) { //印出
            int j;
            for(j=0; j<i; j++) {//分辨類型並印出
                if(ans[j].input == 'i') {
                    printf("%d\n",ans[j].save.num);
                } else if(ans[j].input == 'f') {
                    printf("%f\n",ans[j].save.f_num);
                } else if(ans[j].input == 's') {
                    printf("%s\n",ans[j].save.word);
                }
            }
            printf("選擇:(1.新增/2.印出/0.結束):");
        }
    }
}

