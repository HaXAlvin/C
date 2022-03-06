#include<stdio.h>
int main()
{   int len,line,row;
    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf("%d",&len);
    while(len!=3&&len!=5&&len!=7&&len!=9){
        printf("輸入錯誤!\n");
        printf("輸入菱形對角線長度(3、5、7、9):");
        scanf("%d",&len);
    }
    printf("輸入行數(2~10):");
    scanf("%d",&line);
    while(line<2||line>10){
        printf("輸入錯誤!\n");
        printf("輸入行數(2~10):");
        scanf("%d",&line);
    }
    printf("輸入列數(2~10):");
    scanf("%d",&row);
    while(row<2||row>10){
        printf("輸入錯誤!\n");
        printf("輸入行數(2~10):");
        scanf("%d",&row);
    }
    printf("\n");
    int i,j,k,cl,l;
    cl=(len+1)/2;
    for(l=1;l<=row;l++){//等第一行的菱形印完後再重複印
        for(i=1;i<=cl;i++){//菱形上半部要印幾行
            for(j=1;j<=line;j++){//每一行需要印幾個
                for(k=cl-i;k>0;k--){
                    printf(" ");//前面的空白
                }
            for(k=1;k<=2*i-1;k++){
                printf("*");//星星
            }
            for(k=cl-i;k>0;k--){
                printf(" ");//後面的空白
            }
            printf(" ");//菱形之間的空白
            }
            printf("\n");
        }
        for(i=cl-1;i>0;i--){//菱形下半部要印幾行
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
    printf("\n");//每一列的菱形之間的空白
}
    return 0;
}

