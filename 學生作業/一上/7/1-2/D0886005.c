#include <stdio.h>
int main(){
    int longg,columns,rows; //���� ��� �C��
    int iden=0;//��J���~
    do{
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&longg);
        if(longg==3||longg==5||longg==7||longg==9){
            iden=1;
        }
        else{
            printf("��J���~!\n");
            iden=0;
        }
    }while(iden==0);
    do{
        printf("��J���(2~10):");
        scanf("%d",&columns);
        if(columns>1&&columns<11){
            iden=1;
        }
        else{
            printf("��J���~!\n");
            iden=0;
        }
    }while(iden==0);
    do{
        printf("��J�C��(2~10):");
        scanf("%d",&rows);
        if(rows>1&&rows<11){
            iden=1;
        }
        else{
            printf("��J���~!\n");
            iden=0;
        }
    }while(iden==0);
    printf("\n");
    while(rows>0){
        rows=rows-1;
        for(int a=0;(a<longg/2.);a++){   //�T���ΤW�b��
            for(int e=columns;e>0;e--){
                for(int b=a+1;2*b<longg;b++){
                    printf(" ");
                }
                for(int c=0;c<2*a+1;c++){
                    printf("*");
                }
                printf(" ");
                for(int b=a+1;2*b<longg;b++){
                    printf(" ");
                }
            }
            printf("\n");
        }
        for(int a=1;a<longg-1;a=a+2){ //�T���ΤU�b��
            for(int e=columns;e>0;e--){
                for(int c=0;c<a;c=c+2){
                    printf(" ");
                }
                for(int b=a+2;b<=longg;b++){
                    printf("*");
                }
                printf(" ");
                for(int c=0;c<a;c=c+2){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}


