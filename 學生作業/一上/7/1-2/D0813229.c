#include<stdio.h>
#include<stdlib.h>
int main() {
    int input;
    int col;
    int row;
    int i;
    int j;
    int k;


    printf("��J�٧ι﨤�u����(3,5,7,9):");
    scanf("%d",&input);
    while(input<3||input>9||input%2==0) {
        printf("��J���~!\n");
        printf("��J�٧ι﨤�u����(3,5,7,9):");
        scanf("%d",&input);
    }
    printf("��J���(2~10):");
    scanf("%d",&col);
    while(col<2||col>10) {
        printf("��J���~!\n");
        printf("��J���(2~10):");
        scanf("%d",&col);
    }
    printf("��J�C��(2~10):");
    scanf("%d",&row);
    while(row<2||row>10) {
        printf("��J���~!\n");
        printf("��J�C��(2~10):");
        scanf("%d",&row);
    }
    printf("\n");
    printf(" ");
    printf("\n");

    for(int a=1; a<=row; a++) {
        for( i=1; i<=(input+1)/2; i++) { //�T���Ϊ���
            for(int b=1; b<=col; b++) { //�L�٧Ϊ��W�b��
                for(j=(input+1)/2; j>i; j--) { //�T���Ϋe���ҪŪ����
                    printf(" ");
                }
                for(k=0; k<2*i-1; k++) { //�P��

                    printf("*");
                }
                for(j=(input+1)/2; j>=i; j--) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for(i=(input-1)/2; i>=1; i--) {
            for(int b=1; b<=col; b++) {
                for(j=i; j<=(input-1)/2; j++) {
                    printf(" ");
                }
                for(k=0; k<2*i-1; k++) {
                    printf("*");
                }
                for(j=1; j<=(input-1)-i; j++) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf(" ");
        printf("\n");
    }







    return 0;
}
