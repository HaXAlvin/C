#include<stdio.h>
#include<stdlib.h>

int main(){
    int leng, col, row;//變數:長度、行數、列數
    int i, j, k, m;

    //輸入對角線長度
    do{
        printf("輸入菱形對角線長度(3、5、7、9)：");
        scanf("%d",&leng);
        if(leng ==3 || leng ==5 || leng ==7 || leng ==9)
            break;//輸入正確則跳出迴圈
        else{
            printf("輸入錯誤!\n");
            continue;//輸入錯誤則再次輸入
        }
    }while(1);

    //輸入行數
    do{
        printf("輸入行數(2 ~ 10)：");
        scanf("%d",&col);
        if(col >=2 && col <=10)
            break;//輸入正確則跳出迴圈
        else{
            printf("輸入錯誤!\n");
            continue;//輸入錯誤則再次輸入
        }
    }while(1);

    //輸入列數
    do{
        printf("輸入列數(2 ~ 10)：");
        scanf("%d",&row);
        if(row >=2 && row <=10)
            break;//輸入正確則跳出迴圈
        else{
            printf("輸入錯誤!\n");
            continue;//輸入錯誤則再次輸入
        }
    }while(1);

    //菱形從中間算起的上半部
    for(i=1; i<=row; i++){//列數
            for(k=1; k<=(leng/2+1); k++){//上半部包含中間行
            	for(j=1; j<=col; j++){//行數
                    for(m=1; m<=(leng-1-k) ;m++){//上半部星號左邊空格
                        printf(" ");
                    }
                    for(m=1; m<=(2*k-1); m++){//上半部星號
                        printf("*");
                    }
                    for(m=1; m<=(leng-1-k) ;m++){//上半部星號右邊空格
                        printf(" ");
                    }
                }
                printf("\n");//每行印出後換行
            }
            //菱形下半部

            for(k=(leng/2); k>=1; k--){//下半部不含中間行
            	for(j=col; j>=1; j--){//行數
                    for(m=(leng-1-k); m>=1 ;m--){//下半部空格
                        printf(" ");
                    }
                    for(m=(2*k-1); m>=1; m--){//下半部星號
                        printf("*");
                    }
                    for(m=(leng-1-k); m>=1 ;m--){//下半部空格
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
    }
    return 0;
}
