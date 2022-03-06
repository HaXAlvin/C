#include<stdio.h>
#include<stdlib.h>

typedef struct Array{
    union _A{
        int digit;
        float decimal;
        char letter[16];
    }A;
    char choice;
}array;
void input(array *B,int *num){
    int n;
    do{
        n = 0;
        printf("�������:(i : int/f : float/s : char[16]):");
        scanf("%c",&(*B).choice);
        getchar();
        if ((*B).choice == 'i'){
            printf("��J���:");
            scanf("%d",&(B[*num].A.digit));
        }
        else if ((*B).choice == 'f'){
            printf("��J���:");
            scanf("%f",&(B[*num].A.decimal));
        }
        else if ((*B).choice == 's'){
            printf("��J���:");
            scanf("%s",&(B[*num].A.letter));
        }
        else {
            printf("��J���~!\n");
            n = 1;
        }
        getchar();
        *num++;
    }while (n == 1);
}

int main(){
    array *B = malloc(sizeof(array));
    int opt,n,i,num=0;
    char type;
    while (opt != 0){
        do{
            n = 0;
            printf("���:(1.�s�W/2.�L�X/0.����):");
            scanf("%d",&opt);
            if (opt != 1 && opt != 2 && opt != 0){//�ﶵ���b
                printf("��J���~!\n");
                n = 1;
            }
        }while (n == 1);
        if (opt == 0) {
            printf("�����{��\n");
            free(B);
            return 0;
        }
        getchar();
        if (opt == 1){
            input(B,&num);
            B = realloc(B,(num+1) * sizeof(array));
        }
        else if (opt == 2){
            for (i = 0;i < num;i++){
                if ((*B).choice == 'i'){
                    printf("%d\n",B[i].A.digit);
                }
                else if ((*B).choice == 'f'){
                    printf("%f\n",B[i].A.decimal);
                }
                else if ((*B).choice == 's'){
                    printf("%s\n",B[i].A.letter);
                }
            }
        }
    }
}
