#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    //1.�s�W 2.�L�X 3.�Ƨ� 4.���}
    char **name_table;//�t�m10�ӪŶ�
    char names[100];
    int count_name=0;
    int choose=0;
    name_table=calloc(10,sizeof(char*));
    while(1235) {
        printf("1.�s�W\n2.�L�X\n3.�Ƨ�\n4.���}\n");
        printf("�п�J�G");
        scanf("%d",&choose);
        while((choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)){//��J���O1.2.3.4�h�L�X��J���~
            printf("�X��J���~�A�Э��s��J�X\n");
            printf("1.�s�W\n2.�L�X\n3.�Ƨ�\n4.���}\n");
            scanf("%d",&choose);
        }
        if(choose==1) {
            printf("\n�i�s�W�j\n");//�@���s�W5��char*�j�p���Ŷ�
            printf("�п�J�G");
            if((count_name>=10)&&(count_name%5==0)) { //10�ӳ����F��~�|�A���X5��
                name_table = realloc(name_table,(count_name+5)*sizeof(char*));//��10�ӪŶ������F�᭫�s�A���X5�ӪŶ�
            }
            getchar();
            gets(names);
            printf("\n");
            name_table[count_name]= malloc((strlen(names)+1)*sizeof(char));
            strcpy(name_table[count_name],names);//�s�J
            count_name++;//�p��X�Ӹ��
            printf("\n");
        } else if(choose==2) {
            printf("\n�i�L�X�j\n");
            for(int j=0 ; j<count_name ; j++) {
                printf("Case%d�G%s\n",j+1,name_table[j]);
            }
            printf("\n");
        } else if(choose==3) {
            printf("\n�i�Ƨǡj\n");
            for(int i=count_name-1 ; i>=0 ; i--) {
                for(int j=0 ; j<i ; j++) {
                    if(strcmp(name_table[j],name_table[j+1])==1){//�Q�Ϊw�j�ƧǪk�N���бƧ�
                        char *temp1=name_table[j];
                        char *temp2=name_table[j+1];
                        name_table[j+1]= temp1;
                        name_table[j]= temp2;
                    }
                }
            }
            printf("\n");
        } else if(choose==4) {
            printf("�i���}���t�ΡA�w��U���A�ӡj\n");
            free(name_table);
            return 0;
        }
    }

}
