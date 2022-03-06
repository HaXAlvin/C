#include<stdio.h>
#include<stdlib.h>

typedef struct _all{
    int flag;
    union _data{
        int num_i;
        float num_f;
        char num_c[16];
    }data;
}all;

int main(){
    int choose;//第一個選項
    int count=0;//數有幾個數據
    all*list=malloc(sizeof(all));

    while(1){
        char temp[50]={0};//第二個選項
        char choose_c;
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d",&choose);
        getchar();
        if(choose==1){
            if(count!=0){
                list=realloc(list,(count+1)*sizeof(all));
            }
            while(temp[0]!='i'&&temp[0]!='f'&&temp[0]!='s'){
                printf("選擇型態:(i:int/f:float/s:char[16]):");
                scanf("%s",temp);
                getchar();
                choose_c=temp[0];
                if(choose_c!='i'&&choose_c!='f'&&choose_c!='s'){
                    printf("輸入錯誤\n");
                }
            }
            list[count].flag=choose_c;
            if(choose_c=='i'){
                list[count].flag=1;
            }
            else if(choose_c=='f'){
                list[count].flag=2;
            }
            else if(choose_c=='s'){
                list[count].flag=3;
            }
            printf("輸入資料:");
            if(choose_c=='i'){
                scanf("%d",&list[count].data.num_i);
            }
            else if(choose_c=='f'){
                scanf("%f",&list[count].data.num_f);
            }

            else if(choose_c=='s'){
                scanf("%s",list[count].data.num_c);
            }
            count++;

        }
        else if(choose==2){
            for(int i = 0 ; i < count ; i++){
                if(list[i].flag==1){
                    printf("%d\n",list[i].data.num_i);
                }
                else if(list[i].flag==2){
                    printf("%f\n",list[i].data.num_f);
                }
                else if(list[i].flag==3){
                    printf("%s\n",list[i].data.num_c);
                }

            }
        }
        if(choose==0){
            printf("結束程式\n");
            free(list);
            break;
        }
    }
    return 0;
}
