#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **array;
    array = malloc(ch_ar10*sizeof(char*));
    int input;//��J
    int length;
    int ch_ar10 = 10;//10�ӪŶ�
    int big = 0;//�P�_�O�_�j��10
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
                puts(array[i]);//�C�X�өҦ��W�r
            }
        }
        else if(input == 3){
        }
        else if(input == 4){
            for(i = 0;i < big; i++){
                free(array[i]);//����O����Ŷ�
            }
            free(array);//����O����Ŷ�
            break;
        }
    }
    return 0 ;
}
