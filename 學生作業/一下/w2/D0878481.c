#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **name;//�s�W�r
    char temp[50];//�Ȧs�m�W
    char *name_temp;
    int choice,i,j,k;
    int length=0;//�r�����
    int num=0;//�O���X�����
    int a=2;
    name=malloc(10*sizeof(char*));//�t�@���j�p��10��char
    while(1){
        scanf("%d",&choice);//��ܥ\��
        getchar();
        switch(choice){
            case 1:
                gets(temp);//�s�W�W�r
                length=strlen(temp);//�����r��j�p
                if (num>5*a){//��@���Ŷ��j��10�A�h���t�h���ӪŶ�
                    name=realloc(name,(5*(a+1))*sizeof(char*));
                    a++;
                }

                name[num]=calloc((length+1),sizeof(char));//�]�G���Ŷ����r��j�p�[�@�A�]����'\0'
                for (i=0;i<=length;i++){
                    name[num][i]=temp[i];//���ȿ�J�i�ʺA�G���}�C��
                }
                num++;

                break;
            case 2:
                for(i=0;i<num;i++)//�L�X�W�r
                    printf("%s\n",name[i]);

                break;
            case 3:

                for(i=0;i<num;i++){//��w�Ƨ�
                    for (j=i;j<num;j++){
                        k=strcmp(name[j],name[i]);//�O�_�۵��A���۵��h�洫
                        if (k==0){
                            continue;
                        }
                        else if (k==-1){

                            name_temp=name[j];//�Χ}�洫
                            name[j]=name[i];
                            name[i]=name_temp;

                        }
                    }
                }
                break;


        }
        if (choice==4){
            for (i=0;i<num;i++){//����G��
                free(name[num]);
            }
            free(name);//����@��
            break;
        }
    }





}
