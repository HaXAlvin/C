#include <stdio.h>
int center_long; //菱形中線長度
int i;  //菱形迴圈計數
int j;  //*計數
int k;  //空白計數
int c;  //計算行數
int r;  //計算列數
int diagonal; //對角線長度
int main() {
    do {
        printf("輸入菱形對角線長度(3、5、7、9):");
        scanf("%d",&diagonal);
        if(diagonal!=3&diagonal!=5&diagonal!=7&diagonal!=9) { //一旦使用者輸入錯誤顯示錯誤
            printf("輸入錯誤!\n");
        }
    } while(diagonal!=3&diagonal!=5&diagonal!=7&diagonal!=9);
    int columns;//行數
    int rows;//列數
    do {  //一旦使用者輸入錯誤顯示錯誤
        printf("輸入行數(2~10):");
        scanf("%d",&columns);
        if(columns<2||columns>10) {
            printf("輸入錯誤!\n");
        }
    } while(columns<2||columns>10);
    do {  //一旦使用者輸入錯誤顯示錯誤
        printf("輸入列數(2~10):");
        scanf("%d",&rows);
        if(rows<2||rows>10) {
            printf("輸入錯誤!\n");
        }
    } while(rows<2||rows>10);
    for(r=1; r<=rows; r++) { //印出列數
        //印出菱形
        center_long = (diagonal+1)/2;
        for(i=1; i<=center_long; i++) {
            for(c=1; c<=columns; c++) {
                //菱形上半部
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                for(j=1; j<=(2*i)-1; j++) {
                    printf("*");
                }
                for(k=center_long-i; k>0; k--) {
                    printf(" ");
                }
                printf(" "); //菱形跟菱形之間夾一個空格
            }
            printf("\n");
        }
        for(i=center_long-1; i>0; i--) {
            //菱形下半部
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
        printf("\n");   //上下菱形空一排
    }
    return 0;
}
