#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char **str,int now){
    int i,j;
    char *tmp;
    for(i = 0;i < now-1;i++){
        for(j = 0;j < now-i-1;j++){
            if(strcmp(str[j],str[j+1]) > 0){
                tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;
            }
        }
    }
}

int main(){
    int chose = 1,space = 10,now = 0,i,fail = 0;
    char **name = calloc(space,sizeof(char*)),tmp[100];
    while(chose != 4){
        fail = 0;
        printf("1.新增 2.印出 3.排序 4.離開\n");//now = %d,space = %d\n
        scanf("%d",&chose);
        if(chose > 4||chose < 1) fail = 1;
        if(fail == 0){
            switch (chose){
                case 1:
                    if(now == space){//若超出10個名字 要擴充記憶體
                        space += 5;
                        name = realloc(name,space * sizeof(char*));
                    }
                    getchar();
                    gets(tmp);//名字可能包含空白 使用gets
                    name[now] = calloc(strlen(tmp)+1,sizeof(char));
                    strcpy(name[now],tmp);
                    //printf("%s\n",name[now]);

                    now++;
                    break;
                case 2:
                    for(i = 0;i < now;i++){
                        printf("%s\n",name[i]);
                    }
                    break;
                case 3:
                    bubble(name,now);
//                    for(i = 0;i < now;i++){
//                        printf("%s\n",name[i]);
//                    }
                    break;
                case 4:
                    for(i = 0;i < now;i++){
                        free(name[i]);
                    }
                    free(name);
                    break;
            }
        }

    }


}
