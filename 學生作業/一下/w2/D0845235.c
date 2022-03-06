#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    //1.新增 2.印出 3.排序 4.離開
    char **name_table;//配置10個空間
    char names[100];
    int count_name=0;
    int choose=0;
    name_table=calloc(10,sizeof(char*));
    while(1235) {
        printf("1.新增\n2.印出\n3.排序\n4.離開\n");
        printf("請輸入：");
        scanf("%d",&choose);
        while((choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)){//輸入不是1.2.3.4則印出輸入錯誤
            printf("—輸入錯誤，請重新輸入—\n");
            printf("1.新增\n2.印出\n3.排序\n4.離開\n");
            scanf("%d",&choose);
        }
        if(choose==1) {
            printf("\n【新增】\n");//一次新增5個char*大小的空間
            printf("請輸入：");
            if((count_name>=10)&&(count_name%5==0)) { //10個都滿了後才會再釋出5個
                name_table = realloc(name_table,(count_name+5)*sizeof(char*));//當10個空間都滿了後重新再釋出5個空間
            }
            getchar();
            gets(names);
            printf("\n");
            name_table[count_name]= malloc((strlen(names)+1)*sizeof(char));
            strcpy(name_table[count_name],names);//存入
            count_name++;//計算幾個資料
            printf("\n");
        } else if(choose==2) {
            printf("\n【印出】\n");
            for(int j=0 ; j<count_name ; j++) {
                printf("Case%d：%s\n",j+1,name_table[j]);
            }
            printf("\n");
        } else if(choose==3) {
            printf("\n【排序】\n");
            for(int i=count_name-1 ; i>=0 ; i--) {
                for(int j=0 ; j<i ; j++) {
                    if(strcmp(name_table[j],name_table[j+1])==1){//利用泡沫排序法將指標排序
                        char *temp1=name_table[j];
                        char *temp2=name_table[j+1];
                        name_table[j+1]= temp1;
                        name_table[j]= temp2;
                    }
                }
            }
            printf("\n");
        } else if(choose==4) {
            printf("【離開此系統，歡迎下次再來】\n");
            free(name_table);
            return 0;
        }
    }

}
