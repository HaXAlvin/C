#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int type;
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
        return;
    }
    else if(temp1=='f'){//���A���p��
        temp->type=2;//���A���p��
        scanf("%f",&(temp->center).b);//�N��J��Ʀs�i���c��b
        return;
    }
    else {
        temp->type=3;//���A���r��
        scanf("%s",&inputchar);//��J
        strcpy((temp->center).c,inputchar);//copy�i���c��c
    }

}

int main(){
    arr *data;//���е��c
    int i;
    int count=0;//�����ĴX�ո��
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
            for (i=0;i<count;i++){
                free(data);
            }
            break;
        }
        switch(input){
            case 1:
                if(count==0)//�s�W�O����Ŷ�
                    data=malloc(1*sizeof(arr));

                else
                    data=realloc(data,(count+1)*sizeof(arr));//�ĤG����ƥH�᪺�Ŷ��Х�

                printf("�������:(i = int/f = float/s = char[16]):");
                getchar();
                scanf("%c",&inputtype);//��J����
                if ((inputtype!='i')&&(inputtype!='f')&&(inputtype!='s')){//���b
                    printf("��J���~!\n");
                    continue;
                }
                printf("��J���:");
                if (inputtype=='i'){//���
                    change(data+count,inputtype);
                }
                else if (inputtype=='f'){//�p��
                    change(data+count,inputtype);
                }
                else{//�r��
                   change(data+count,inputtype);
                }

                count++;//�p�ƥ[1
                break;
            case 2:

                for (i=0;i<count;i++){//�L�X�Ҧs�����
                    if (data[i].type==1){//����ƪ���
                        printf("%d\n",data[i].center.a);
                    }
                    else if (data[i].type==2){//���p�ƪ���
                        printf("%f\n",data[i].center.b);
                    }
                    else{//���r�ꪺ��
                        printf("%s\n",data[i].center.c);
                    }

                }
                break;
        }

    }

}


