#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union dic{//��ơB�p�ơB�r���}�C
    int num;
    float numwithdot;
    char word[16];
};

enum type{//��ơB�p�ơB�r���}�C
    I,F,S,
};

struct array{//message�B���O
    union dic kind;
    enum type t;
    struct array* next;
};

struct array add(struct array* Ptr){
    char wordtype;
    struct array* currentPtr = Ptr;
    while(currentPtr->next){//findEnd
        currentPtr=currentPtr->next;
    }
    struct array* tempPtr = calloc(1,sizeof(struct array));
    currentPtr->next=tempPtr;

    while(1){
        printf("�������:(i:int/f:float/s:char[16]:");
        scanf("%c%*c",&wordtype);
        if(wordtype=='i'||wordtype=='f'||wordtype=='s')
            break;
        printf("��J���~!\n");
    }
    if(wordtype=='i'){//��J��P�O
        printf("��J���:");
        scanf("%d",&tempPtr->kind.num);
        tempPtr->t=I;
    }
    else if(wordtype=='f'){
        printf("��J���:");
        scanf("%f",&tempPtr->kind.numwithdot);
        tempPtr->t=F;
    }
    else if(wordtype=='s'){
        printf("��J���:");
        gets(tempPtr->kind.word);
        tempPtr->t=S;
    }
}

void freeArray(struct array* currentPtr){//���j
    if(currentPtr->next){
        freeArray(currentPtr->next);
    }
    free(currentPtr);
}

int main(){
    int times = 0;//�_�l�s
    int option = 0;//�ﶵ
    struct array* headPtr = calloc(1,sizeof(struct array));//�ŧi�Ĺs�ӵ��c
    while(1){
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d%*c",&option);
        if(option==0){//free(struct)
            printf("�����{��\n");
            freeArray(headPtr);
            return 0;
        }
        else if(option==1){//�s�W
            add(headPtr);
        }
        else if(option==2){//�C�L
            struct array* currentPtr = headPtr->next;//�q�Ĥ@�Ӷ}�l�L
            while(currentPtr){
                if(currentPtr->t==I){//�P�O
                    printf("%d\n",currentPtr->kind.num);
                }
                else if(currentPtr->t==F){
                    printf("%f\n",currentPtr->kind.numwithdot);
                }
                else if(currentPtr->t==S){
                    puts(currentPtr->kind.word);
                }
                currentPtr=currentPtr->next;
            }
        }
        else//���b
            printf("��J���~!\n");
    }
}
