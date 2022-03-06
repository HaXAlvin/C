#include <stdio.h>

int main(){

    int L,rows,columns,failed;
    int i,j,k,m;
    do{ //輸入對角線長度
        failed = 0;
        printf("輸入菱形對角線長度(3、5、7、9)：");
        scanf("%d",&L);
        if (L!=3&&L!=5&&L!=7&&L!=9){
            printf("輸入錯誤!\n");
            failed = 1;
        }
    }while(failed == 1);

    do{ //輸入行數
        failed = 0;
        printf("輸入行數(2~10)：");
        scanf("%d",&columns);
        if (columns<2||columns>10){
            printf("輸入錯誤!\n");
            failed = 1;
        }
    }while(failed == 1);

    do{ //輸入列數
        failed = 0;
        printf("輸入列數(2~10)：");
        scanf("%d",&rows);
        if (rows<2||rows>10){
            printf("輸入錯誤!\n");
            failed = 1;
        }
    }while(failed == 1);


    for (i = 1; i <= rows; i++){

        for (int i = 1; i <= (L+1)/2;i++){  //菱形上半部

            for(int m = 1;m <= columns; m++){  //行數

                for (int j = (L+1)/2-i;j > 0;j--){
                    printf(" ");
                }

                for (int k = 1;k <=(i*2-1);k++){
                    printf("*");
                }

                for (int j = (L+1)/2-i;j > 0;j--){
                    printf(" ");
                }

                printf(" ");

            }

            printf("\n");

        }

        for (int i = 1; i <= ((L-1)/2);i++){  //菱形下半部

            for(int m = 1;m <= columns; m++){  //行數
                for (int j = 1;j <= i ;j++){
                    printf(" ");
                }

                for (int k = (L-(i*2));k >= 1;k--){
                    printf("*");
                }

                for (int j = 1;j <= i ;j++){
                    printf(" ");
                }
                printf(" ");

            }

            printf("\n");
        }

        printf("\n");
    }

}

