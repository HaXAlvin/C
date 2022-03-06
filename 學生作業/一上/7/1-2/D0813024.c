#include<stdio.h>

int main()
{
    int length,rows,columns; //宣告 長度 行 列
    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf("%d",&length); //輸入對角線長度
        while(1){
            if(length !=3 && length !=5 && length !=7 && length !=9){//輸入對角線錯誤重來的迴圈
                printf("輸入錯誤!\n");
                printf("輸入菱形對角線長度(3、5、7、9):");
                scanf("%d",&length);
            }
            else break; //輸入正確跳出迴圈
        }
    printf("輸入行數(2~10):");
        scanf("%d",&rows); //輸入行數
        while(1){
            if(rows<2 || rows>10){//輸入行數錯誤重來的迴圈
                printf("輸入錯誤!\n");
                printf("輸入行數(2~10):");
                scanf("%d",&rows);
            }
            else break;//輸入正確跳出迴圈
        }
    printf("輸入列數(2~10):");
        scanf("%d",&columns); //輸入列數
        while(1){
            if(columns<2 || columns>10){//輸入列數錯誤重來的迴圈
                printf("輸入錯誤!\n");
                printf("輸入列數(2~10):");
                scanf("%d",&columns);
            }
            else break;//輸入正確跳出迴圈
        }
        printf("\n");
        int i,j,k,m,n,p; //宣告各層的計數器迴圈
        //第一列菱形的上半部
        for(m=1;m<=columns;m++){//列數的迴圈
            for(i=1;i<=length;i+=2){ // 上半部的菱形(包括中間)
                for(j=length;j>i;j-=2){ //菱形左上角的空白
                    printf(" ");
                }
                    for(k=1;k<=i;k++){ //補上星號
                        printf("*");
                    }
                    printf(" "); //第一行菱形間的空白
                        //補上2~9行的上半部
                        for(n=1;n<=rows-1;n++){
                            for(j=length;j>i;j-=2){ //菱形右上角的空白
                                printf(" ");
                            }
                                for(j=length;j>i;j-=2){ //新的菱形的左上角空白
                                    printf(" ");
                                }
                                    for(k=1;k<=i;k++){ //補上星號
                                        printf("*");
                                    }
                        printf(" ");//再補上下一行間隔菱形的空白
                        }
            printf("\n");//上半部結束換行
            }
                //下半部菱形(不包括中間)
                for(i=1;i<length;i+=2){
                    for(j=1;j<=i;j+=2){//左下角菱形的空白
                        printf(" ");
                    }
                        for(k=length-2;k>=i;k--){//補上星號
                            printf("*");
                        }
                        printf(" ");//第一行的下半部菱形間隔
                            //補上2~9行的下半部
                            for(p=1;p<=rows-1;p++){
                                for(j=1;j<=i;j+=2){//右下角的空白
                                    printf(" ");
                                }
                                    for(j=1;j<=i;j+=2){//新的菱形左下角空白
                                        printf(" ");
                                    }
                                        for(k=length-2;k>=i;k--){//補上星號
                                            printf("*");
                                        }
                            printf(" ");//每個菱形間的間隔
                            }
                printf("\n");//下半部結束換航
                }
        printf("\n");//每個菱形的上下間隔
        }
    return 0;
}






