#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�w�qunion
typedef union _total{
    int Int;
    float Float;
    char member[16];
}total;

//�w�qstruct
typedef struct _save{
    total con;
    char n;
}save;

//�s���禡
void saver(save *a)
{
    while(1){
        printf("�������:(i:int/f:float/s:char[16]):");
        scanf("%*c%c",&(a->n)); //�s�����ӧΦ�
        //�p�G��int
        if (a->n == 'i'){
            printf("��J���:");
            scanf("%d",&a->con.Int);
            break;
        }
        //�p�G�Ofloat
        else if (a->n == 'f'){
            printf("��J���:");
            scanf("%f",&a->con.Float);
            break;
        }
        //�p�G�Ostring
        else if (a->n == 's'){
            printf("��J���:");
            scanf("%s",a->con.member);
            break;
        }
        else
            printf("��J���~!\n");
    }
}

int main()
{
    int n,i=0,count=1;//n�O�s�n�����@�Ӱʧ@�Ai�O�}�C�ĴX�ӡAcount�O���X�Ӱ}�C
    save *input = malloc(1*sizeof(save));
    while(1){
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&n); //�s�n�����@�Ӱʧ@
        //�P�_�s���ΦL�X
        switch(n){
            //�s
            case 1:
                //���}�C�j�p
                input = realloc(input,count*sizeof(save));
                saver(&input[i]);
                i++;
                count++;
                break;
            //�L
            case 2:
                //�L�X���j��
                for (int j=0;j<i;j++){
                    //�P�_�O���@�ӫ��A
                    if (input[j].n == 'i'){
                        printf("%d\n",input[j].con.Int);
                    }
                    else if (input[j].n == 'f'){
                        printf("%f\n",input[j].con.Float);
                    }
                    else if (input[j].n == 's'){
                        printf("%s\n",input[j].con.member);
                    }
                }
                break;
        }
        //����������
        if (n==0){
            free(input);
            printf("�����{��");
            break;
        }
        //���b
        else if (n!=0 && n!=1 && n!=2)
            printf("��J���~!\n");
    }
}
