#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union Type{ //�w�q
    int data_i;//��ƫ�
    float data_f;//�p�ƫ�
    char data_s[16];//�r��
};

struct Data{//struct���w�q
    union Type type;//union�ܼƪ��ŧi
    int choose;//1.int/2.float/3.char[16]
    struct Data *nextPtr;//�ۧڰѦҫ��Ц���
};

void add(struct Data *data){//�]�@��call by reference�禡
    printf("��������G�]1.int / 2.float / 3.char[16]�^�G");
    scanf("%d",&data->choose);
    getchar();
    while((data->choose!=1)&&(data->choose!=2)&&(data->choose!=3)){
            printf("��J���~�A�Э��s��J\n");
            printf("��������G�]1.int / 2.float / 3.char[16]�^�G");
            scanf("%d",&data->choose);
    }
    if(data->choose==1){ //1.int
        printf("��J��ơ]int�^�G");
        scanf("%d",&data->type.data_i);
    }
    else if(data->choose==2){ //2.float
        printf("��J��ơ]float�^�G");
        scanf("%f",&data->type.data_f);
    }
    else if(data->choose==3){ //3.char[16]
        printf("��J��ơ]char[16]�^�G");
        gets(data->type.data_s);
    }
}

int main(){
    struct Data *data = malloc(sizeof(struct Data));//struct�ŧi
    struct Data *currentPtr = data;//�]�@�ӼȦs�s�Y
    int choice;//1.�s�W/2.�L�X/0.����
    while(1235){
        printf("��ܡG�]1.�s�W / 2.�L�X / 0.�����^�G");
        scanf("%d",&choice);
        while((choice!=1)&&(choice!=2)&&(choice!=0)){
            printf("��J���~�A�Э��s��J\n");
            printf("��ܡG�]1.�s�W / 2.�L�X / 0.�����^�G");
            scanf("%d",&choice);
        }
        if(choice==1){//�s�W
            struct Data *newPtr = malloc(sizeof(struct Data));//�s�W�@�ӵ��c
            add(newPtr);//�I�s�禡
            currentPtr->nextPtr=newPtr;//�s�����Ь��ثe���Ъ��U�@��
            currentPtr=currentPtr->nextPtr;//�ثe���Ы��V�U�@�ӫ���
            currentPtr->nextPtr= NULL;//�ثe���Ъ��O�Ŧr��
        }
        else if(choice==2){//�L�X
            struct Data* lemon = data;//�]�@�ӼȦslemon
            while(lemon!=NULL){
                if(lemon->choose==1){
                    printf("%d\n",lemon->type.data_i);
                }
                else if(lemon->choose==2){
                    printf("%f\n",lemon->type.data_f);
                }
                else if(lemon->choose==3){
                    printf("%s\n",lemon->type.data_s);
                }
                lemon = lemon->nextPtr;
            }
        }
        else if(choice==0){//�����{��
            printf("���}���{��");
            free(data);
            return 0;
        }
    }
}
