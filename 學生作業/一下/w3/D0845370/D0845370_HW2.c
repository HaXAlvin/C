#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp1(char *s1, char *s2){ //ASCII�Ƨ�
    if(strcmp(s1,s2) == 1) //�e������j,�ݥ洫
        return 1;
    else if(strcmp(s1,s2) == -1 || strcmp(s1,s2) == 0)
        return 0;
}

int cmp2(char *s1, char *s2){ //�r��Ƨ�
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int range = 0;
    if(len1 >= len2) //for�j��ݭn�]������
        range = len1;
    else
        range = len2;
    for(int i=0;i<range;i++){
        if((s1[i]>64 && s1[i]<91) && (s2[i]>96 && s2[i]<123)){ //�e���j�g,�᭱�p�g
            if(s1[i]+32 > s2[i]) //�e�����j�ݥ洫
                return 1;
            else
                return 0;
        }
        else if((s1[i]>96 && s1[i]<123) && (s2[i]>64 && s2[i]<91)){ //�e���p�g,�᭱�j�g
            if(s1[i] >= s2[i]+32) //�e�����j�ݥ洫
                return 1;
            else
                return 0;
        }
        else if(((s1[i]>64 && s1[i]<91) &&(s2[i]>64 && s2[i]<91)) || ((s1[i]>96 && s1[i]<123) && (s2[i]>96 && s2[i]<123))){ //�e�᳣�j�g �� �e�᳣�p�g
            if(s1[i] > s2[i]) //�e�����j�ݥ洫
                return 1;
            else //�~�����U�@�Ӧr��
                continue;
        }
        return 0; //�Y�O�e�᧹���@�˫h�����洫
    }
}

void sort(char **sArr,int n,int (*cmp)(char *, char *)){ //�洫
    for(int i=(n-1);i>0;i--){
        for(int j=0;j<i;j++){
            if(cmp(sArr[j],sArr[j+1]) == 1){ //�Y�O������e��洫
                char *temp = sArr[j];
                sArr[j] = sArr[j+1];
                sArr[j+1] = temp;
            }
        }
    }
}

int main(){
    while(1){
        int strnum = 0,count_num = 0,choose = 0;
        printf("�п�J�r���(��J0����)�G");
        scanf("%d", &strnum); //�r���
        if(strnum == 0)
            return 0;
        char **sArr = malloc(strnum * sizeof(char *)); //�Ĥ@���j�p
        getchar();
        while(count_num < strnum){ //��J�Ҧ��r��
            char tmp[500] = {0};
            gets(tmp);
            int len = strlen(tmp);
            sArr[count_num] = malloc(len * sizeof(char)); //�ĤG���j�p
            strcpy(sArr[count_num],tmp);
            count_num += 1;
        }
        printf("�п�ܱƧǤ覡(1. �HASCII/2. �H�r���)�G");
        scanf("%d", &choose);
        if(choose == 1)
            sort(sArr,strnum,cmp1);
        else if(choose == 2)
            sort(sArr,strnum,cmp2);
        for(int i=0;i<strnum;i++) //�L�X�Ƨǫᵲ�G
            printf("%s\n",sArr[i]);
        for(int i=0;i<strnum;i++) //����Ҧ��Ŷ�
            free(sArr[i]);
        free(sArr);
    }
}
