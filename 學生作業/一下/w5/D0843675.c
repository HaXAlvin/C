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
};

struct array add(struct array* Ptr,int* times){
    char wordtype;
    while(1){
        printf("�������:(i:int/f:float/s:char[16]:");
        scanf("%c%*c",&wordtype);
        if(wordtype=='i'||wordtype=='f'||wordtype=='s')
            break;
        printf("��J���~!\n");
    }
    if(wordtype=='i'){//��J��P�O
        printf("��J���:");
        scanf("%d",&Ptr[*times].kind.num);
        Ptr[*times].t=I;
    }
    else if(wordtype=='f'){
        printf("��J���:");
        scanf("%f",&Ptr[*times].kind.numwithdot);
        Ptr[*times].t=F;
    }
    else if(wordtype=='s'){
        printf("��J���:");
        getchar();
        gets(Ptr[*times].kind.word);
        Ptr[*times].t=S;
    }
}

int main(){
    int times = 0;//�_�l�s
    int* timesPtr = &times;
    int option = 0;//�ﶵ
    struct array* Ptr;//�ŧi�ʺA�}�C

    while(1){
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d%*c",&option);
        if(option==0){//free(struct)
            printf("�����{��\n");
            free(Ptr);
            return 0;
        }
        else if(option==1){
            if(times==0){//�_�l�s
                Ptr = malloc(1*sizeof(struct array));
            }
            else{//�s�W
                Ptr = realloc(Ptr,(times+1)*sizeof(struct array));
            }
            add(Ptr,timesPtr);//callbyreference
            times++;//���ƥ[
        }
        else if(option==2){//�C�L
            for(int a = 0;a<times;a++){
                if(Ptr[a].t==I)//�P�O
                    printf("%d\n",Ptr[a].kind.num);
                else if(Ptr[a].t==F)
                    printf("%f\n",Ptr[a].kind.numwithdot);
                else if(Ptr[a].t==S)
                    puts(Ptr[a].kind.word);
            }
        }
        else//���b
            printf("��J���~!\n");
    }
}
