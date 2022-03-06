#include <stdio.h>
int main () {
    int long1, column,row;
    //輸入對角線長度 3 or 5or 7or 9
    for(; ;) {
        printf("輸入菱形對角線長度(3,5,7,9):");
        scanf("%d",&long1);
        if(long1!=3&&long1!=5&&long1!=7&&long1!=9) {
            printf("輸入錯誤!");
            continue;

        }
        break;
    }
    for(; ;) {
        printf("輸入行數:");
        scanf("%d",&column);
        if(column!=2&&column!=3&&column!=4&&column!=5&&column!=6&&column!=7&&column!=8&&column!=9) {
            printf("輸入錯誤!");
            continue;
        }
        break;

    }
    //輸入列數 2~9
    for(; ;) {
        printf("輸入列數:");
        scanf("%d",&row);
        if(row!=2&&row!=3&&row!=4&&row!=5&&row!=6&&row!=7&&row!=8&&row!=9) {
            printf("輸入錯誤!");
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

        for(i=long1/2; i>=1; i--) {           /*列印下三角，（不包括中間行）*/
            for(k=1; k<=column; k++) {
                for(j=1; j<=long1/2+i; j++) {      /*這個for迴圈與上三角一致 */
                    if(j>=long1/2-i+2)
                        printf("*");
                    else
                        printf(" ");
                }
                for(j=1; j<=long1/2+i+2; j++) {      /*這個for迴圈與上三角一致 */
                    if(j<=long1/2-i+2)
                        printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

}














