#include<stdio.h>

int main(){
    int diagonal,columns,rows,temp_count;//宣告 對角線長度 行數 列數 計算同列重複的flag
    //輸入對角線長度
    while(1){//輸入對角線長度錯誤重來的迴圈(1)
        printf("輸入對角線長度(3、5、7、9):");
        scanf("%d",&diagonal);
        if(diagonal==3||diagonal==5||diagonal==7||diagonal==9){
            break;//輸入正確跳出迴圈(1)
        }
        else{
            printf("輸入錯誤!\n");//顯示錯誤繼續跑迴圈(1)
        }
    }
    //輸入行數
    while(1){//輸入行數錯誤重來的迴圈(2)
        printf("輸入行數(2~10):");
        scanf("%d",&columns);
        if(columns>=2&&columns<=10){
            break;//輸入正確跳出迴圈(2)
        }
        else{
            printf("輸入錯誤!\n");//顯示錯誤繼續跑迴圈(2)
        }
    }
    //輸入列數
    while(1){//輸入列數錯誤重來的迴圈(3)
        printf("輸入列數(2~10):");
        scanf("%d",&rows);
        if(rows>=2&&rows<=10){
            break;//輸入正確跳出迴圈(3)
        }
        else{
            printf("輸入錯誤!\n");//顯示錯誤繼續跑迴圈(3)
        }
    }
    printf("\n");
    //開始print菱型
    for(int i=1;i<=rows;i++){//最後處理列數重複的第一層for迴圈[1]
        for(int j=1;j<=diagonal/2;j++){//處理每行菱型的第二層for迴圈[1-1]
            //菱型上半的三角形
            temp_count=columns;//重製temp_count
            do{//處理重複幾行的do迴圈[1-1-1]
                for(int k=diagonal/2-j+1;k>=1;k--){//菱型左上的小三角空白的第四層for迴圈[1-1-1-1]
                    printf(" ");
                }
                for(int k=1;k<=2*j-1;k++){//菱型的三角*的第四層for迴圈[1-1-1-2]
                    printf("*");
                }
                for(int k=diagonal/2-j+1;k>=1;k--){//菱型右上的小三角空白的第四層for迴圈[1-1-1-3]
                    printf(" ");
                }
                printf(" ");//每個菱型間的空格
                temp_count--;//減少temp_count
            }while(temp_count>=1);//透過temp_count來判斷重複幾次
            printf("\n");//每行換行
        }
        //菱型中間的那排
        temp_count=columns;//重製temp_count
        do{//處理重複幾次的do迴圈[1-2]
            for(int j=1;j<=diagonal;j++){//菱型中間的那排*的第三層for迴圈[1-2-1]
                printf("*");
            }
            printf(" ");//每個菱形間的空白
            temp_count--;//減少temp_count
        }while(temp_count>=1);//透過temp_count來判斷重複幾次
        printf("\n");
        //菱型下半的三角形
        for(int j=diagonal/2;j>=1;j--){//處理每行菱型的第二層for迴圈[1-3]
            temp_count=columns;//重製temp_count
            do{//處理重複幾行的do迴圈[1-3-1]
                for(int k=diagonal/2-j+1;k>=1;k--){//菱型左下的小三角空白的第四層for迴圈[1-3-1-1]
                    printf(" ");
                }
                for(int k=1;k<=2*j-1;k++){//菱型的三角*的第四層for迴圈[1-3-1-2]
                    printf("*");
                }
                for(int k=diagonal/2-j+1;k>=1;k--){//菱型右下的小三角空白的第四層for迴圈[1-3-1-3]
                    printf(" ");
                }
                printf(" ");//每個菱型間的空格
                temp_count--;//減少temp_count
            }while(temp_count>=1);//透過temp_count來判斷重複幾次
            printf("\n");//每行換行
        }
    printf("\n");//換列隔\n
    }
    //程式結束
    return 0;
}

