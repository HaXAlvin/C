#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int maxnum=10;
    int count=0;
    char** namelist=calloc(maxnum,sizeof(char*));
    int input;
    int true_or_flase;
    //宣告變數maxnum、count、input、true_or_flase及namelist的指標和它的記憶體配置
    do{
        printf("1.新增 2.印出 3.排序 4.離開\n");
        //印出1.新增 2.印出 3.排序 4.離開
        scanf("%d", &input);
        //輸入input
        if(input==1){
            char *temname=calloc(100,sizeof(char));
            getchar();
            gets(temname);
            *(namelist+count)=calloc((strlen(temname)+1),sizeof(char));
            *(namelist+count)=temname;
            count++;
            if(count>9){
                maxnum+=5;
            }
            true_or_flase=0;
        }

        /* 如果input輸入的為1，則作以下的事
           宣告指標變數temname及它的記憶體配置，輸入a，
           使(namelist+count)的記憶體配置為長度temname+1的char大小
           也使(namelist+count)為a
           使count加1，如果count大於9，則使 maxnum再加5，
           使true_or_flase為0*/

        else if(input==2){
            for(int temcount=0;temcount<count;temcount++){
                printf("%s\n", namelist[temcount]);
            }
            true_or_flase=0;
        }
        /* 如果input輸入的為2，則作以下的事
           使用for迴圈temcount從0到temcount小於count，temcount加1
           印出namelist[temcount]內的字串
           使true_or_flase為0*/
        else if(input==3){
            char* temp;
            for (int temcount=0;temcount<count;temcount++){
                for(int temcount1=0;temcount1<=temcount;temcount1++){
                    if(  strcmp(namelist[temcount1],namelist[temcount])>0 ){
                        temp=namelist[temcount];
                        namelist[temcount]=namelist[temcount1];
                        namelist[temcount1]=temp;
                    }
                }
            }
            true_or_flase=0;
        }
        /* 如果input輸入的為3，則作以下的事
           宣告指標變數temp
           使用兩個for迴圈，一個從temcount從0到temcount小於count，temcount加1、另一個temcount1從0到temcount1小於temcount，temcount1加1
           使兩個陣列去作比較，如果後者比前者大，則交換順序
           使true_or_flase為0
           */
        else if(input==4){
            for (int temcount=0;temcount<maxnum;temcount++){
                free(namelist[temcount]);
            }
            free(namelist);
            true_or_flase=1;
        }
        /* 如果input輸入的為4，則釋放記憶體空間
           使true_or_flase為1*/
        else{
            printf("輸入錯誤請重新輸入\n");
            true_or_flase=0;
        }
        /* 否則，印出輸入錯誤請重新輸入
            使true_or_flase為0*/
    }while(true_or_flase==0);
    return 0;
}
