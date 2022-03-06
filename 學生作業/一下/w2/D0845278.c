#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void sort(char **name_table,int len) {
    int i,j;
    for(i=len-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(strcmp(name_table[j],name_table[j+1])==1) {//泡沫排序
                char *temp1 =name_table[j];//存取字串位置
                char *temp2 =name_table[j+1];
                name_table[j]=temp2;//交換位置
                name_table[j+1]=temp1;//交換兩指標位置
            }
        }
    }
}
int main() {
    int input_num;
    int i;
    char **name_table;
    int big=0;//姓名數量
    char tmp_name[500];//姓名暫存
    name_table = malloc(10*sizeof(char*));
    printf("WELCOME ! \n\n");
    printf("功能選項:\n1.新增\n2.印出\n3.排序\n4.離開\n你的選擇是:");
    while(scanf("%d",&input_num)!=EOF) {
        if(input_num<1||input_num>4) {
            printf("輸入錯誤!\n");
            printf("功能選項:\n1.新增\n2.印出\n3.排序\n4.離開\n你的選擇是:");
            continue;
        }
        if(input_num==1) {//新增
            printf("\n");
            printf("Input Name:");
            getchar();
            gets(tmp_name);//姓名輸入暫存
            int name_len = strlen(tmp_name)+1;//+\0
            name_table[big]= malloc(name_len*sizeof(char));//配置存入陣列
            strcpy(name_table[big],tmp_name);//複製字串過去
            big++;//計算個數
            printf("\n");
            if(big>=10&&big%5==0) {
                name_table=realloc(name_table,big+5*sizeof(char*));//一到5的倍數每次增加5個char *大小的空間
            }
        } else if(input_num==2) {//印出
            printf("\n");
            int flag=1;
            for(i=0; i<big; i++) {
                printf("%d. %s\n",flag,name_table[i]);
                flag++;
            }
            printf("\n");
            flag=1;
        } else if(input_num==3) {//排序
            sort(name_table,big);
            printf("\n排序完成!\n\n");
        } else if(input_num==4) {//離開
            printf("\n離開程式.\n");
            for(i=0; i<big; i++) {
                free(name_table[i]);
            }
            free(name_table);
            return 0;
        }
        printf("功能選項:\n1.新增\n2.印出\n3.排序\n4.離開\n你的選擇是:");
    }
}
