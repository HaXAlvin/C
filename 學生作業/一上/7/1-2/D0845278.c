#include <stdio.h>
int center_long; //�٧Τ��u����
int i;  //�٧ΰj��p��
int j;  //*�p��
int k;  //�ťխp��
int c;  //�p����
int r;  //�p��C��
int diagonal; //�﨤�u����
int main() {
    do {
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&diagonal);
        if(diagonal!=3&diagonal!=5&diagonal!=7&diagonal!=9) { //�@���ϥΪ̿�J���~��ܿ��~
            printf("��J���~!\n");
        }
    } while(diagonal!=3&diagonal!=5&diagonal!=7&diagonal!=9);
    int columns;//���
    int rows;//�C��
    do {  //�@���ϥΪ̿�J���~��ܿ��~
        printf("��J���(2~10):");
        scanf("%d",&columns);
        if(columns<2||columns>10) {
            printf("��J���~!\n");
        }
    } while(columns<2||columns>10);
    do {  //�@���ϥΪ̿�J���~��ܿ��~
        printf("��J�C��(2~10):");
        scanf("%d",&rows);
        if(rows<2||rows>10) {
            printf("��J���~!\n");
        }
    } while(rows<2||rows>10);
    for(r=1; r<=rows; r++) { //�L�X�C��
        //�L�X�٧�
        center_long = (diagonal+1)/2;
        for(i=1; i<=center_long; i++) {
            for(c=1; c<=columns; c++) {
                //�٧ΤW�b��
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                for(j=1; j<=(2*i)-1; j++) {
                    printf("*");
                }
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                printf(" "); //�٧θ�٧Τ������@�ӪŮ�
            }
            printf("\n");
        }
        for(i=center_long-1; i>0; i--) {
            //�٧ΤU�b��
            for(c=1; c<=columns; c++) {
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                for(j=1; j<=(i*2)-1; j++) {
                    printf("*");
                }
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");   //�W�U�٧ΪŤ@��
    }
    return 0;
}
