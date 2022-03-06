#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char temp2[10000];
    int choo,temp=10,stu_num=0;
    char** stu_list;
    stu_list=calloc(temp,sizeof(char *));
    while(scanf("%d",&choo)!=EOF){
        getchar();
        if(choo==1){ //輸入
            gets(temp2); //輸入名子
            stu_list[stu_num]=calloc(strlen(temp2)+1,sizeof(char));
            strcpy(stu_list[stu_num],temp2);
            stu_num++;
            if(stu_num>10){ //若學生超過10人
                temp+=5;
                stu_list=realloc(stu_list,temp*sizeof(char *)); //重制大小
            }
        }
        if(choo==2){ //印出
            for(int i=0;i<stu_num;i++){

                printf("%s",stu_list[i]);

                printf("\n");
            }
        }
        if(choo==3){ //排序
            for(int i=0;i<stu_num;i++){
                for(int k=0;k<stu_num-i-1;k++){
                    if(strcmp(stu_list[k],stu_list[k+1])>0){ //若前者較大
                        char* name= stu_list[k];
                        stu_list[k]=stu_list[k+1];
                        stu_list[k+1]=name;
                    }
                }
            }
            for(int i=0;i<stu_num;i++){ //印出排序結果
                printf("%s",stu_list[i]);
                printf("\n");
            }

        }
        if(choo==4){ //離開
            for(int i=0;i<stu_num;i++){
                free(stu_list[i]);
            }
            free(stu_list);
            return 0;
        }
    }
    return 0;
}
