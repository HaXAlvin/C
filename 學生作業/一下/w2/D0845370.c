#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int choose=0,i,j,space=10;
    char** name = calloc(space , sizeof(char*));
    int name_num=0;
    printf("歡迎來到學生姓名登記系統\n\n");
    while(1){
		printf("請選擇功能(1.新增 2.印出 3.排序 4.離開)：");
        scanf("%d", &choose); //輸入欲使用的功能
        if(choose < 1 || choose > 4) //輸入非1-4
        	continue;
        else if(choose == 1){
            char tmp[500] = {0};
            printf("新增名字：");
            getchar();
            gets(tmp); //先將輸入存在暫存
            int len = strlen(tmp);
            if(name_num == space){ //若空間不足，新增5個空間
            	space += 5;
                name = realloc(name, space * sizeof(char*));
            }
            name[name_num] = malloc((len+1) * sizeof(char)); //根據輸入建立空間
            for(i=0;i<=len;i++) //將輸入存入name列表
            	name[name_num][i] = tmp[i];
			name_num += 1;
			printf("\n");
        }
        else if(choose == 2){
        	for(i=0;i<name_num;i++) //將目前輸入的名字印出
        		printf("%d. %s\n",i+1,name[i]);
			printf("\n");
		}
		else if(choose == 3){
			for(i=name_num-1;i>0;i--){ //將所有名字由小到大排列
				for(j=0;j<i;j++){
					if(strcmp(name[j],name[j+1]) == 1){ //若前大於後，前後交換
					    char* tmp1 = name[j];
					    char* tmp2 = name[j+1];
                        name[j+1] = tmp1;
					    name[j] = tmp2;
					}
				}
			}
			printf("排序完成\n\n");
		}
		else if(choose == 4){ //釋放所有空間
			printf("離開系統\n");
			for(i=0;i<space;i++)
				free(name[i]);
			free(name);
			return 0;
		}
    }
}
