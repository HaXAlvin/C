#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("1.�s�W.\n");
    printf("2.�L�X.\n");
    printf("3.�Ƨ�.\n");
    printf("4.���}.\n");
    int choose,i,len=0;//len�O�P�Ǹ��X
    char **student;//�Ĥ@���O�ƶq;�ĤG���O�W�r
    char student_name[100];
    char *temp,*name_temp;//�ƧǪk�ݭn
    student=calloc(10,sizeof(char*));
    char student_list[]={20};
    while(1){
        scanf("%d",&choose);
        getchar();
        if(choose==1){
            int student_num,student_name_num;//student_num�O�ǥͼ� ��̬O�ǥͦW�r��
            fgets(student_name,sizeof(student_name),stdin);
            printf("read:%s",student_name);
            if(len+1>=10&&(len+1)%5==0){
                printf("kkkkk\n");
                student=realloc(student,(len+5)*sizeof(char*));
            }
            student_name_num = strlen(student_name);//�ǥͦW�r����
            student[len] = calloc(student_name_num, sizeof(char));//�W�r���ץ�J�@��
            printf("ok?\n");
            strcpy(student[len],student_name);//�U�ӦW�r��J�������X
            printf("ok!\n");
            len++;
            choose=0;
        }
        else if(choose==2){
            for(int i = 0 ; i<len ; i++){
                printf("%d.%s",i+1,student[i]);
            }
        }
        else if(choose==3){
            for(int j = 0 ; j<len-1 ; j++){
                for(int m = 0 ; m<len-j-1  ; m++){
                    if(strcmp(student[m],student[m+1])>0){//j���p ���e��
                        name_temp=student[m];
                        student[m]=student[m+1];
                        student[m+1]=name_temp;
                    }
                }
            }
            for(int q =0 ; q<len ; q++ ){
                printf("%d.%s",q+1,student[q]);
            }
        }
        else if(choose==4){
            for(int i = 0; i <len-1 ; i++){
                free(student[i]);
            }
            free (student);
            break;
        }
    }
}
