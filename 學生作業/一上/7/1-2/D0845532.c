#include <stdio.h>
int main () {
    int long1, column,row;
    //��J�﨤�u���� 3 or 5or 7or 9
    for(; ;) {
        printf("��J�٧ι﨤�u����(3,5,7,9):");
        scanf("%d",&long1);
        if(long1!=3&&long1!=5&&long1!=7&&long1!=9) {
            printf("��J���~!");
            continue;

        }
        break;
    }
    for(; ;) {
        printf("��J���:");
        scanf("%d",&column);
        if(column!=2&&column!=3&&column!=4&&column!=5&&column!=6&&column!=7&&column!=8&&column!=9) {
            printf("��J���~!");
            continue;
        }
        break;

    }
    //��J�C�� 2~9
    for(; ;) {
        printf("��J�C��:");
        scanf("%d",&row);
        if(row!=2&&row!=3&&row!=4&&row!=5&&row!=6&&row!=7&&row!=8&&row!=9) {
            printf("��J���~!");
            continue;
        }
        break;

    }
    int i,j,k,l;//count
    for(l=1; l<=row; l++) {


        for(i=1; i<=long1/2+1; i++) {
            for(k=1; k<=column; k++) {
                for(j=1; j<=long1/2+i; j++) {
                    if(j>=long1/2-i+2)
                        printf("*");
                    else
                        printf(" ");
                }
                for(j=1; j<=long1/2+i; j++) {
                    if(j<=long1/2-i+2)
                        printf(" ");
                }
            }
            printf("\n");
        }

        for(i=long1/2; i>=1; i--) {           /*�C�L�U�T���A�]���]�A������^*/
            for(k=1; k<=column; k++) {
                for(j=1; j<=long1/2+i; j++) {      /*�o��for�j��P�W�T���@�P */
                    if(j>=long1/2-i+2)
                        printf("*");
                    else
                        printf(" ");
                }
                for(j=1; j<=long1/2+i+2; j++) {      /*�o��for�j��P�W�T���@�P */
                    if(j<=long1/2-i+2)
                        printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

}














