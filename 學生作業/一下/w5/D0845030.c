#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Origin{
    char ityp;
    union tagB{//�Ψ��x�s���
        int i;
        float f;
        char s[16];
    }Save;
};
void setO(struct Origin *input){
    int type;//��J����
    do{
        printf("������� : (1 : int/2 : float/3 : char[16]) : ");
        scanf("%d", &type);
        if(type < 1 || type > 3)
            printf("��J���~!\n");
    }while(type < 1 || type > 3);
    printf("��J��� : ");
    if(type == 1){//int
        scanf("%d", &(input -> Save).i);
        (*input).ityp = 'I';//���D�{���P�_��J���A
    }
    else if(type == 2){//float
        scanf("%f", &(input -> Save).f);
        (*input).ityp = 'F';//���D�{���P�_��J���A
    }
    else if(type == 3){//char[16]
        scanf("%s", (input -> Save).s);
        (*input).ityp = 'S';//���D�{���P�_��J���A
    }
}
int main(){
    int choice;//���
    int i;
    struct Origin sArray[100];
    struct Origin *sa = malloc(sizeof(struct Origin));//�ϥΰʺA�}�C�t�m�N�ʺA�}�C�W�[1��struct�j�p���O����Ŷ�
    int count = 0;
    while(1){
        printf("��� : (1.�s�W/2.�L�X/0.����) : ");
        scanf("%d", &choice);
        if(choice < 0 || choice > 2)
            printf("��J���~!\n");
        if(choice == 1){
            setO(sa);//call by reference
            sArray[count] = *sa;
            sa = realloc(sa, sizeof(struct Origin));//�W�[�O����Ŷ�
            count++;
        }
        else if(choice == 2){
           for(i = 0; i < count; i++){//�L�X�H��J�����
                if(sArray[i].ityp == 'I'){//�P�_��J���A
                    printf("%d\n", sArray[i].Save.i);
                }
                else if(sArray[i].ityp == 'F'){//�P�_��J���A
                    printf("%.6f\n", sArray[i].Save.f);
                }
                else if(sArray[i].ityp == 'S'){//�P�_��J���A
                    printf("%s\n", sArray[i].Save.s);
                }
           }
        }
        else if(choice == 0){
            printf("�����{��");
            free(sa);//����ʺA�t�m�O����
            break;
        }
    }
    return 0;
}
