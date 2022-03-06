#include<stdio.h.>
#include<stdlib.h>
#include<string.h>

int main(){
    char**name;
    name = malloc(10 * sizeof(char*));
    //紀錄幾個已新增幾個名字
    int i = 0;
    int newchar = 0;
    while(1){
        printf("1.新增\n2.印出\n3.排序\n4.離開\n請輸入:");
        int num = 0;
        scanf("%d%*c",&num);
        if(num!=1&&num!=2&&num!=3&&num!=4){
            printf("\n輸入錯誤\n\n");
            continue;
        }
        if(num==1){
            //超過10個名字要加空間
            if(i==(10+5*newchar)){
                    printf("new\n");
                name = realloc(name,(i+5*(newchar+1))*sizeof(char*));
                newchar++;
            }
            //名字暫存
            char tempname[500];
            //char*tempname_point;
            printf("\n請輸入:");
            scanf("%s",&tempname);
            //名字長度
            int tempname_length = strlen(tempname);
            //分配空間給名字
            name[i] = malloc(((tempname_length)+1) * sizeof(char));
            //存入名字
            strcpy(name[i],tempname);
            //free(tempname_point);
            i++;
            printf("\n");
        }
        if(num==2){
            printf("\n");
            //印出所有名字
            int o=0;
            while(o<i){
                int p=0;
                while(name[o][p]!='\0'){
                    printf("%c",name[o][p]);
                    p++;
                }
                printf("\n");
                o++;
            }
            printf("\n");
        }
        if(num==3){
            //泡沫排序
            for(int j=i-1;j>0;j--){
                for(int k=0;k<j;k++){
                    if(strcmp(name[k],name[k+1])>0){
                        char*temp1 = name[k];
                        char*temp2 = name[k+1];
                        name[k] = temp2;
                        name[k+1] = temp1;
                    }
                }
            }
            printf("\n");
        }
        if(num==4){
            //清空動態記憶體 結束程式
            for(int j=0;j<(9+5*newchar);j++){
                free(name[i]);
            }
            free(name);
            return 0;
        }
    }
}
