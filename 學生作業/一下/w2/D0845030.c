#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //設立變數
    char **firstArr,*tmp;
    int n = 10, choice, num = 0, i, j, ans;
    char a[100] = {0};
    firstArr = malloc(n * sizeof(char **));//一維
    printf("學生姓名登記系統\n");

    while(1){
        printf("1.新增 2.印出 3.排序 4.離開\n");
        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            gets(a);
            firstArr[num] = calloc(strlen(a) + 1, sizeof(char));//配置二維
            strcpy(firstArr[num], a);//將字串儲存
            num ++;
            if(num == n){
                n + 5;
            }
        }
        else if(choice == 2){
            for(i = 0; i < num; i ++)//依序印出
                puts(firstArr[i]);
        }
        else if(choice == 3){
            for(i = num - 1; i > 0; i --){//泡沫排序法
                for(j = 0; j < i; j ++){
                    ans = strcmp(firstArr[j], firstArr[j + 1]);
                    if(ans > 0){
                        tmp = firstArr[j];
                        firstArr[j] = firstArr[j + 1];
                        firstArr[j + 1] = tmp;
                    }
                }
            }
        }
        else if(choice == 4){
            for(i = 0; i < num; i ++){//釋放
                free(firstArr[i]);
            }
            free(firstArr);
            return 0;
        }
    }
}
