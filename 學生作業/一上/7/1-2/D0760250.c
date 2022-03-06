#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,columns,rows;

    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf("%d",&n);
    while(n!=3&&n!=5&&n!=7&&n!=9){
        printf("輸入錯誤!\n輸入菱形對角線長度(3、5、7、9):");
        scanf("%d",&n);
    }

    printf("輸入行數(2~10):");
    scanf("%d",&columns);
    while(columns<2||columns>10){
        printf("輸入錯誤!\n輸入行數(2~10):");
        scanf("%d",&columns);
    }

    printf("輸入列數(2~10):");
    scanf("%d",&rows);
    while(rows<2||rows>10){
        printf("輸入錯誤!\n輸入列數(2~10):");
        scanf("%d",&rows);
    }

    for(int i=0;i<rows;i++){//印出每一列菱形
    printf("\n");//上下相鄰的菱形相隔一行
        for(int k=1;k<=(n+1)/2;k++){//印出每一列菱形中的上半部+中間的每一列
            for(int j=0;j<columns;j++){//印出每一列菱形中的每一個菱形的上半部+中間
                for(int m=0;m<(n+1)/2-k;m++){//印出每一列菱形中的每一個菱形的上半部+中間的左邊空白
                    printf(" ");
                }
                for(int p=0;p<k*2-1;p++){//印出每一列菱形中的每一個菱形的上半部+中間的星星部分
                    printf("*");
                }
                for(int m=0;m<(n+1)/2-k;m++){//印出每一列菱形中的每一個菱形的上半部+中間的右邊空白
                    if(j<columns-1){//每一列最後一個菱形的右邊空白不用印
                    printf(" ");
                    }
                }
            if(j<columns-1){//每一個左右相鄰的菱形相隔一個空白(最後一個不用)
                printf(" ");
            }
            }
                printf("\n");//印完一列菱形的一列後換行
        }
        for(int k=1;k<=(n+1)/2-1;k++){//印出每一列菱形中的下半部的每一列
            for(int j=0;j<columns;j++){//印出每一列菱形中的每一個菱形的下半部
                for(int m=0;m<k;m++){//印出每一列菱形中的每一個菱形的下半部的左邊空白
                    printf(" ");
                }
                for(int p=0;p<n-k*2;p++){//印出每一列菱形中的每一個菱形的下半部的星星
                    printf("*");
                }
                for(int m=0;m<k;m++){//印出每一列菱形中的每一個菱形的下半部的右邊空白
                    if(j<columns-1){//每一列的最後一個菱形的右邊空白不用印
                    printf(" ");
                    }
                }
            if(j<columns-1){//每一個左右相鄰的菱形相隔一個空白(最後一個不用)
                printf(" ");
            }
            }
        if(k!=(n+1)/2-1||i!=rows-1){//印完一列菱形的一列後換行(印最後一列菱形的最底下一列時不換行)
        printf("\n");
        }
        }

    }

    return 0;
}




