#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //�ܼ�
    int input1=0;
    int arrlong=10,arr_full=0,strlong;
    char input_name[100];
    int bigsmall;
    char* temp;
    char **name;//�ŧi
    name = malloc ( arrlong * sizeof(char*) );//�@������
    do{
        printf("\n�ǥͩm�W�n�O�t��\n��J�H�~��\n 1.�s�W\n 2.�L�X\n 3.�Ƨ�\n 4.���}\n\n");
        scanf("%d",&input1);
        if(input1==1){
            if(arr_full==10||(arr_full-10)%5==0&&arr_full!=0&&arr_full!=5){
                printf("hihi\n");
                arrlong+=5;
                name = realloc ( name , arrlong * sizeof(char*) );//�@��10 15 20�ɥ[5
            }
            printf("\n�s�W�m�W:");
            getchar();
            gets(input_name);//scanf�t�ť�
            strlong=strlen(input_name)+1;
            name[arr_full] = calloc (strlong , sizeof(char));//�ĤG��
            strcpy(name[arr_full],input_name);//�ƻs�i�}�C
            arr_full++;//�p�����++
        }
        else if(input1==2){
            printf("\n�m�W�C��:\n");
            for(int i=0;i<arr_full;i++){
                printf("%s\n",name[i]);
            }
        }
        else if(input1==3){
                //�w�j�ƧǪk
            for(int i=0;i<arr_full-2;i++){
                for(int j=i+1;j<arr_full;j++){
                    bigsmall=strcmp(name[i],name[j]);
                    if(bigsmall==1){
                        //�洫
                        temp=name[i];
                        name[i]=name[j];
                        name[j]=temp;
                    }
                }
            }
            printf("\n�Ƨǧ���\n");
        }
    }while(input1!=4);
    //����O����
    for(int i=0;i<arrlong;i++){
        free(name[i]);
    }
    free(name);
}
