#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **array;
    array = malloc(ch_ar10*sizeof(char*));
    int input;//輸入
    int length;
    int ch_ar10 = 10;//10個空間
    int big = 0;//判斷是否大於10
    int i;

    while(1){
        scanf("%d",&input);
        if(input == 1){
            if(big  > ch_ar10){
                ch_ar10 += 5;
                array = realloc(array,ch_ar10*sizeof(char*));
            }
            else{
            char names[100];
            gets(names);
            length = strlen(names);
            array[big] = malloc((length+ 1)*sizeof(char));
            strcpy(array[big],names);
            big ++;
            }
        }
        else if(input == 2){
            for(i = 0; i <big; i++){
                puts(array[i]);//列出來所有名字
            }
        }
        else if(input == 3){
        }
        else if(input == 4){
            for(i = 0;i < big; i++){
                free(array[i]);//釋放記憶體空間
            }
            free(array);//釋放記憶體空間
            break;
        }
    }
    return 0 ;
}
