#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int type;
    struct node *nextptr;
    union{
        int a;
        float b;
        char c[16];

    }center;

}arr;
void change(arr *temp,char temp1){//call by reference
    char inputchar[16];//�Ȧs�r��Ŷ����ܼ�
    if (temp1=='i'){//���A�����
        temp->type=1;//�������A�����
        scanf("%d",&(temp->center).a);//�N��J��Ʀs�i���c��a
        temp->nextptr=NULL;
        return;
    }
    else if(temp1=='f'){//���A���p��
        temp->type=2;//���A���p��
        scanf("%f",&(temp->center).b);//�N��J��Ʀs�i���c��b
        temp->nextptr=NULL;
        return;
    }
    else {
        temp->type=3;//���A���r��
        scanf("%s",&inputchar);//��J
        strcpy((temp->center).c,inputchar);//copy�i���c��c
        temp->nextptr=NULL;
        return;
    }

}

int main(){
    arr *data,*crtdata;//���е��c
    data=NULL;
    crtdata=NULL;
    int i;
    int input;//��ܥ\��A��J�����
    char inputtype;//��ƫ��A

    while(1){
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&input);
        if(input>2){//���b
            printf("��J���~!");
            continue;
        }
        if (input==0){//��0�����{��

            free(data);
            break;
        }
        switch(input){
            case 1:
                if(data==NULL){//�s�W�O����Ŷ�
                    data=malloc(sizeof(arr));
                    crtdata=data;
                }

                else{
                    crtdata->nextptr=malloc(sizeof(arr));
                    crtdata=crtdata->nextptr;
                }


                printf("�������:(i = int/f = float/s = char[16]):");
                getchar();
                scanf("%c",&inputtype);//��J����
                if ((inputtype!='i')&&(inputtype!='f')&&(inputtype!='s')){//���b
                    printf("��J���~!\n");
                    continue;
                }
                printf("��J���:");
                if (inputtype=='i'){//���
                    change(crtdata,inputtype);
                }
                else if (inputtype=='f'){//�p��
                    change(crtdata,inputtype);
                }
                else{//�r��
                   change(crtdata,inputtype);
                }
                break;
            case 2:
                crtdata=data;
                while(crtdata!=NULL){//�L�X�Ҧs�����
                    if (crtdata->type==1)
                        printf("%d\n",crtdata->center.a);

                    else if (crtdata->type==2)
                        printf("%f\n",crtdata->center.b);
                    else
                        printf("%s\n",crtdata->center.c);

                    crtdata=crtdata->nextptr;


                }
                break;
        }

    }

}


