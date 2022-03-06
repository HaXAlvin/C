#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("1.新增.\n");
    printf("2.印出.\n");
    printf("3.排序.\n");
    printf("4.離開.\n");
    int choose,i,len=0;//len是同學號碼
    char **student;//第一維是數量;第二維是名字
    char student_name[100];
    char *temp,*name_temp;//排序法需要
    student=calloc(10,sizeof(char*));
    char student_list[]={20};
    while(1){
        scanf("%d",&choose);
        getchar();
        if(choose==1){
            int student_num,student_name_num;//student_num是學生數 後者是學生名字數
            fgets(student_name,sizeof(student_name),stdin);
            printf("read:%s",student_name);
            if(len+1>=10&&(len+1)%5==0){
                printf("kkkkk\n");
                student=realloc(student,(len+5)*sizeof(char*));
            }
            student_name_num = strlen(student_name);//學生名字長度
            student[len] = calloc(student_name_num, sizeof(char));//名字長度丟入一維
            printf("ok?\n");
            strcpy(student[len],student_name);//各個名字丟入對應號碼
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
                    if(strcmp(student[m],student[m+1])>0){//j較小 往前移
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
