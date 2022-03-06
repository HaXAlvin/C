#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
    printf("1.新增\n");
    printf("2.印出\n");
    printf("3.排序\n");
    printf("4.離開\n");

    ///case 1變數
    char **list;
    list = calloc(10, sizeof(char*));
    int stu_count = 0;  //學生目前數量
    int list_count = 0;  //清單數量
    char name[100];  //暫存名字
    int name_len;  //計算名字長度
    ///case 2變數
    int i;
    ///case 3變數
    int j;

    int choose;
    while (1){
        scanf("%d", &choose);  //選擇要執行的選項
        getchar();


        switch (choose){
            case 1:  //新增
                //scanf("%s", name);
                fgets(name, sizeof(name), stdin);
                for(int i=0;i<=strlen(name);i++){
                    printf("da:%d\n",name[i]);
                }

                //如果清單用完，每次新增五個
                if (stu_count>=10 && (stu_count+1)%5==0){
                    list = realloc(list, stu_count+5 * sizeof(char *));
                }

                //開一個大小符合名字長度的第二維空間，存進去
                name_len = strlen(name);
                list[stu_count] = calloc(name_len, sizeof(char));
                strcpy(list[stu_count], name);

                stu_count++;

                break;
            case 2:
                for (i=0; i<stu_count; i++){
                    printf("%s", list[i]);
                }
                break;
            case 3:  //泡沫排序
                for (i=0; i<stu_count-1; i++){
                    for (j=0; j<stu_count-i-1; j++){
                        if (strcmp(list[j], list[j+1]) > 0){
                            char* temp;
                            temp = list[j];
                            list[j] = list[j+1];
                            list[j+1] = temp;
                        }
                    }
                }
                break;
            case 4:
                for (i=0; i<stu_count; i++){
                    free(list[i]);
                }
                free(list);
                return 0;
        }
    }
    return 0;
}
