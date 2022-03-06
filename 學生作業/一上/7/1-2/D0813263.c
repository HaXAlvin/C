#include<stdio.h>

int main(){
    int length,columns,rows;//長度,行數,列數
    int n=0;

    do{
        n=0;
        printf("輸入菱形對角線長度(3、5、7、9):");
        scanf("%d",&length);
        if (length!=3&&length!=5&&length!=7&&length!=9){
            printf("輸入錯誤!\n");
            n=1;
        }
    }while (n==1);
    do{
        n=0;
        printf("輸入行數(2~10):");
        scanf("%d",&columns);
        if (columns<2||columns>10){
            printf("輸入錯誤!\n");
            n=1;
        }
    }while (n==1);
    do{
        n=0;
        printf("輸入列數(2~10):");
        scanf("%d",&rows);
        if (rows<2||rows>10){
            printf("輸入錯誤!\n");
            n=1;
        }
    }while (n==1);

    for (int m=1;m<=rows;m++){//列數
        for(int i=1;i<=length/2+1;i++){
            for (int k=1;k<=columns;k++){//行數
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
            for (int k=1;k<=columns;k++){//行數
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

