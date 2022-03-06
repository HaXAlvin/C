#include<stdio.h>
int main(){
    int row; //列 -
    int col; //行 |
    int n; //菱形對角線長度
    int p = 1; //flag:分別依序進入三個迴圈
    while(p){ //決定菱形對角線長度
        printf("輸入菱形對角線長度(3、5、7、9): ");
        scanf("%d", &n);
        switch (n){ //符合3、5、7、9
            case 3:
            case 5:
            case 7:
            case 9:
                p = 0; //輸入正確，離開對角線長度迴圈
                break;
            default: //輸入錯誤
                printf("輸入錯誤！\n");
        }
    }
    p = 1; //進入輸入行迴圈
    while(p){ //決定行數
        printf("輸入行數(2~10): ");
        scanf("%d", &col);
        if(col>=2 && col<=10){ //行範圍在2~10之間
            p = 0; //輸入正確，離開行迴圈
        }
        else{ //輸入錯誤
            printf("輸入錯誤！\n");
        }
    }
    p = 1; //進入輸入列迴圈
    while(p){ //決定列數
        printf("輸入列數(2~10): ");
        scanf("%d", &row);
        if(row>=2 && row <=10){ //列範圍在2~10之間
            p = 0; //輸入正確，離開列迴圈
        }
        else{ //輸入錯誤
            printf("輸入錯誤！\n");
        }
    }
    int i; //列數菱形
    int j; //行數菱形
    int k; //單菱形之列
    int m; //單菱形之行
    for(i=1; i<=row; i++){ //重複印出列數個菱形
        for(j=1; j<=n*row+(row-1); j++){ //每個菱形上下隔一列
            printf(" ");
        }
        printf("\n");
        for(j=1; j<=n; j++){ //重複印出行數的菱形-上半部
            for(k=1; k<=col; k++){ //印出列個菱形上半部
                for(m=1; m<=(n-j); m++){ //上半部須空格數，遞減
                        printf(" ");
                }
                for(m=1; m<=(2*j - 1); m++){ //上半部星型數，遞增
                    printf("*");
                }
                if(k!=col){ //每個菱形右邊格一行，最右不要隔
                    for(m=1; m<=(n-j)+1; m++){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        for(j=n-1; j>=1; j--){ //重複印出行數的菱形-下半部
            for(k=1; k<=col; k++){ //印出列個菱形下半部
                for(m=n-j; m>=1; m--){ //下半部須空格數，遞增
                    printf(" ");
                }
                for(m=1; m<=(2*j-1); m++){ //下半部星型數，遞減
                    printf("*");
                }
                if(k!=col){ //每個菱形右邊格一行，最右不要隔
                    for(m=(n-j)+1; m>=1; m--){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
