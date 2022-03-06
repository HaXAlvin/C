#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubblesort(char** name,int num){
    int i,j;
    char* tmp;//因為name[j]是一維陣列
    for(i = 0; i < num-1; i++){//氣泡排序法
        for (j = 0;j < num-1;j++){
            if (strcmp(name[j],name[j+1]) > 0){//name[j] >> 大
                tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }
        }
    }
    return;
}

int main(){
    int opt,n=0,space=10,num=0,i=0;
    char** name;
    char str[100];
    name = malloc(space * sizeof(char));//一維
    name = realloc(name,space*sizeof(char*));//二維

    while(opt != 4) {
        do{
            n = 0;
            printf("1.新增 2.印出 3.排序 4.離開\n");
            scanf("%d",&opt);
            if (opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("輸入錯誤\n");
                n = 0;
            }
        }while (n == 1);
        if (opt == 4){//釋放全部記憶體，結束程式
            for (i = 0;i < space;i++){//釋放二維
                free(name[i]);
            }
            free(name);//釋放一維
            return 0;
        }
        else if (opt == 1){
            getchar();
            gets(str);
            name[num] = malloc((strlen(str)+1) * sizeof(char));
            strcpy(name[num],str);//將str中的字串存到name陣列中
            printf("姓名:%s\n",name[num]);
            num++;//num初始為0
            if (num+1 > space) space += 5;//超過10個加5空間
        }
        else if (opt == 2){
            for(i = 0;i < num;i++){
                printf("%s\n",name[i]);
            }
        }
        else if (opt == 3){
            bubblesort(name,num);
            for(i = 0;i < num;i++){
                printf("%s\n",name[i]);
            }
        }
    }
}

