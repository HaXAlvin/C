#include<stdio.h>

int main(){
    int length,columns,rows;//����,���,�C��
    int n=0;

    do{
        n=0;
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&length);
        if (length!=3&&length!=5&&length!=7&&length!=9){
            printf("��J���~!\n");
            n=1;
        }
    }while (n==1);
    do{
        n=0;
        printf("��J���(2~10):");
        scanf("%d",&columns);
        if (columns<2||columns>10){
            printf("��J���~!\n");
            n=1;
        }
    }while (n==1);
    do{
        n=0;
        printf("��J�C��(2~10):");
        scanf("%d",&rows);
        if (rows<2||rows>10){
            printf("��J���~!\n");
            n=1;
        }
    }while (n==1);

    for (int m=1;m<=rows;m++){//�C��
        for(int i=1;i<=length/2+1;i++){
            for (int k=1;k<=columns;k++){//���
                for(int j=1;j<=length-i-((length-1)/2);j++){
                    printf(" ");
                }
                for(int j=1;j<=i*2-1;j++){
                    printf("*");
                }
                for(int j=1;j<=length-i-((length-1)/2);j++){
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        for(int i=1;i<length/2+1;i++){
            for (int k=1;k<=columns;k++){//���
                for(int j=1;j<=i;j++){
                    printf(" ");
                }
                for(int j=1;j<=length-2*i;j++){
                    printf("*");
                    }
                for(int j=1;j<=i;j++){
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

