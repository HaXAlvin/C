#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char kind;
    union{
        int   num;
        float flo;
        char  s[16];
    }store;
}list;

void setlist(list* memory_size,char chooo,int* k){
    printf("��J���:");
    if(chooo=='i'){
        scanf("%d",&(memory_size[*k].store.num)); //��J
        memory_size[*k].kind='i';

    }
    else if(chooo=='f'){
        scanf("%f",&(memory_size[*k].store.flo));
        memory_size[*k].kind='f';

    }
    else if(chooo=='s'){
        scanf("%s",&(memory_size[*k].store.s));
       memory_size[*k].kind='s';

    }
}


int main(){
    int choo, k=0;
    char chooo;

    list* memory_size=malloc(1*sizeof(list));
    do{
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&choo);
        getchar();
        if(choo==1){
            printf("�������:(i:int/f:float/s:char[16]):");
            scanf("%c",&chooo);
            if((chooo=='i')||(chooo=='f')||(chooo=='s')){
                setlist(memory_size,chooo,&k);
                k++;
            }
            else{
                printf("��J���~!\n");
            }

            memory_size=realloc(memory_size,sizeof(list)); //����O����j�p
        }
        else if(choo==2){
            for(int i=0;i<k;i++){
                if(memory_size[i].kind=='i'){
                    printf("%d\n",memory_size[i].store.num);
                }
                else if(memory_size[i].kind=='f'){
                    printf("%f\n",memory_size[i].store.flo);
                }
                else if(memory_size[i].kind=='s'){
                    printf("%s\n",memory_size[i].store.s);
                }
            }
        }
        else if(choo==0){
            printf("�����{��\n");
            free(memory_size);

        }
        else{
            printf("��J���~\n");
        }
    }while(choo!=0);
    return 0;
}
