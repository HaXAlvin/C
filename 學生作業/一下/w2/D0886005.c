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
        if(choo==1){ //��J
            gets(temp2); //��J�W�l
            stu_list[stu_num]=calloc(strlen(temp2)+1,sizeof(char));
            strcpy(stu_list[stu_num],temp2);
            stu_num++;
            if(stu_num>10){ //�Y�ǥͶW�L10�H
                temp+=5;
                stu_list=realloc(stu_list,temp*sizeof(char *)); //����j�p
            }
        }
        if(choo==2){ //�L�X
            for(int i=0;i<stu_num;i++){

                printf("%s",stu_list[i]);

                printf("\n");
            }
        }
        if(choo==3){ //�Ƨ�
            for(int i=0;i<stu_num;i++){
                for(int k=0;k<stu_num-i-1;k++){
                    if(strcmp(stu_list[k],stu_list[k+1])>0){ //�Y�e�̸��j
                        char* name= stu_list[k];
                        stu_list[k]=stu_list[k+1];
                        stu_list[k+1]=name;
                    }
                }
            }
            for(int i=0;i<stu_num;i++){ //�L�X�Ƨǵ��G
                printf("%s",stu_list[i]);
                printf("\n");
            }

        }
        if(choo==4){ //���}
            for(int i=0;i<stu_num;i++){
                free(stu_list[i]);
            }
            free(stu_list);
            return 0;
        }
    }
    return 0;
}
