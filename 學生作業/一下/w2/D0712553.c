#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
    printf("1.�s�W\n");
    printf("2.�L�X\n");
    printf("3.�Ƨ�\n");
    printf("4.���}\n");

    ///case 1�ܼ�
    char **list;
    list = calloc(10, sizeof(char*));
    int stu_count = 0;  //�ǥͥثe�ƶq
    int list_count = 0;  //�M��ƶq
    char name[100];  //�Ȧs�W�r
    int name_len;  //�p��W�r����
    ///case 2�ܼ�
    int i;
    ///case 3�ܼ�
    int j;

    int choose;
    while (1){
        scanf("%d", &choose);  //��ܭn���檺�ﶵ
        getchar();


        switch (choose){
            case 1:  //�s�W
                //scanf("%s", name);
                fgets(name, sizeof(name), stdin);
                for(int i=0;i<=strlen(name);i++){
                    printf("da:%d\n",name[i]);
                }

                //�p�G�M��Χ��A�C���s�W����
                if (stu_count>=10 && (stu_count+1)%5==0){
                    list = realloc(list, stu_count+5 * sizeof(char *));
                }

                //�}�@�Ӥj�p�ŦX�W�r���ת��ĤG���Ŷ��A�s�i�h
                name_len = strlen(name);
                list[stu_count] = calloc(name_len, sizeof(char));
                strcpy(list[stu_count], name);

                stu_count++;

                break;
            case 2:
                for (i=0; i<stu_count; i++){
                    printf("%s", list[i]);
                }
                break;
            case 3:  //�w�j�Ƨ�
                for (i=0; i<stu_count-1; i++){
                    for (j=0; j<stu_count-i-1; j++){
                        if (strcmp(list[j], list[j+1]) > 0){
                            char* temp;
                            temp = list[j];
                            list[j] = list[j+1];
                            list[j+1] = temp;
                        }
                    }
                }
                break;
            case 4:
                for (i=0; i<stu_count; i++){
                    free(list[i]);
                }
                free(list);
                return 0;
        }
    }
    return 0;
}
