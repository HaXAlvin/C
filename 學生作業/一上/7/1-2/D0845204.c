#include<stdio.h>
int main()
{   int len,line,row;
    printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
    scanf("%d",&len);
    while(len!=3&&len!=5&&len!=7&&len!=9){
        printf("��J���~!\n");
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&len);
    }
    printf("��J���(2~10):");
    scanf("%d",&line);
    while(line<2||line>10){
        printf("��J���~!\n");
        printf("��J���(2~10):");
        scanf("%d",&line);
    }
    printf("��J�C��(2~10):");
    scanf("%d",&row);
    while(row<2||row>10){
        printf("��J���~!\n");
        printf("��J���(2~10):");
        scanf("%d",&row);
    }
    printf("\n");
    int i,j,k,cl,l;
    cl=(len+1)/2;
    for(l=1;l<=row;l++){//���Ĥ@�檺�٧ΦL����A���ƦL
        for(i=1;i<=cl;i++){//�٧ΤW�b���n�L�X��
            for(j=1;j<=line;j++){//�C�@��ݭn�L�X��
                for(k=cl-i;k>0;k--){
                    printf(" ");//�e�����ť�
                }
            for(k=1;k<=2*i-1;k++){
                printf("*");//�P�P
            }
            for(k=cl-i;k>0;k--){
                printf(" ");//�᭱���ť�
            }
            printf(" ");//�٧Τ������ť�
            }
            printf("\n");
        }
        for(i=cl-1;i>0;i--){//�٧ΤU�b���n�L�X��
            for(j=1;j<=line;j++){
                for(k=cl-i;k>0;k--){
                printf(" ");
                }
                for(k=1;k<=2*i-1;k++){
                printf("*");
                }
                for(k=cl-i;k>0;k--){
                printf(" ");
                }
                printf(" ");
            }
        printf("\n");
    }
    printf("\n");//�C�@�C���٧Τ������ť�
}
    return 0;
}

