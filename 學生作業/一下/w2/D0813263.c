#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubblesort(char** name,int num){
    int i,j;
    char* tmp;//�]��name[j]�O�@���}�C
    for(i = 0; i < num-1; i++){//��w�ƧǪk
        for (j = 0;j < num-1;j++){
            if (strcmp(name[j],name[j+1]) > 0){//name[j] >> �j
                tmp = name[j];
                name[j] = name[j+1];
                name[j+1] = tmp;
            }
        }
    }
    return;
}

int main(){
    int opt,n=0,space=10,num=0,i=0;
    char** name;
    char str[100];
    name = malloc(space * sizeof(char));//�@��
    name = realloc(name,space*sizeof(char*));//�G��

    while(opt != 4) {
        do{
            n = 0;
            printf("1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
            scanf("%d",&opt);
            if (opt != 1 && opt != 2 && opt != 3 && opt != 4){
                printf("��J���~\n");
                n = 0;
            }
        }while (n == 1);
        if (opt == 4){//��������O����A�����{��
            for (i = 0;i < space;i++){//����G��
                free(name[i]);
            }
            free(name);//����@��
            return 0;
        }
        else if (opt == 1){
            getchar();
            gets(str);
            name[num] = malloc((strlen(str)+1) * sizeof(char));
            strcpy(name[num],str);//�Nstr�����r��s��name�}�C��
            printf("�m�W:%s\n",name[num]);
            num++;//num��l��0
            if (num+1 > space) space += 5;//�W�L10�ӥ[5�Ŷ�
        }
        else if (opt == 2){
            for(i = 0;i < num;i++){
                printf("%s\n",name[i]);
            }
        }
        else if (opt == 3){
            bubblesort(name,num);
            for(i = 0;i < num;i++){
                printf("%s\n",name[i]);
            }
        }
    }
}

