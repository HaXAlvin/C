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
    int choose;//�Ĥ@�ӿﶵ
    int count=0;//�Ʀ��X�Ӽƾ�
    all*list=malloc(sizeof(all));

    while(1){
        char temp[50]={0};//�ĤG�ӿﶵ
        char choose_c;
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&choose);
        getchar();
        if(choose==1){
            if(count!=0){
                list=realloc(list,(count+1)*sizeof(all));
            }
            while(temp[0]!='i'&&temp[0]!='f'&&temp[0]!='s'){
                printf("��ܫ��A:(i:int/f:float/s:char[16]):");
                scanf("%s",temp);
                getchar();
                choose_c=temp[0];
                if(choose_c!='i'&&choose_c!='f'&&choose_c!='s'){
                    printf("��J���~\n");
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
            printf("��J���:");
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
            printf("�����{��\n");
            free(list);
            break;
        }
    }
    return 0;
}
