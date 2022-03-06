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
    int choose_data;//1.int/2.float/3.char[16]
};

void add(struct Data *data,int count){//�]�@��call by reference�禡
    printf("��������G�]1.int / 2.float / 3.char[16]�^�G");
    scanf("%d",&data[count].choose_data);
    while((data[count].choose_data!=1)&&(data[count].choose_data!=2)&&(data[count].choose_data!=3)){
        printf("��J���~�A�Э��s��J\n");
        printf("��ܡG�]1.�s�W / 2.�L�X / 0.�����^�G");
        scanf("%d",&data[count].choose_data);
    }
    if(data[count].choose_data==1){ //1.int
        printf("��J��ơ]int�^�G");
        scanf("%d",&data[count].type.data_i);
    }
    else if(data[count].choose_data==2){ //2.float
        printf("��J��ơ]float�^�G");
        scanf("%f",&data[count].type.data_f);
    }
    else if(data[count].choose_data==3){ //3.char[16]
        printf("��J��ơ]char[16]�^�G");
        getchar();
        gets(data[count].type.data_s);
    }
}

int main(){
    struct Data* data = malloc(1*sizeof(struct Data));//struct�ŧi
    int choice;//1.�s�W/2.�L�X/0.����
    int count=0;//�p��X�����
    while(1235){
        printf("��ܡG�]1.�s�W / 2.�L�X / 0.�����^�G");
        scanf("%d",&choice);
        while((choice!=1)&&(choice!=2)&&(choice!=0)){
            printf("��J���~�A�Э��s��J\n");
            printf("��ܡG�]1.�s�W / 2.�L�X / 0.�����^�G");
            scanf("%d",&choice);
        }
        if(choice==1){//�s�W
            if(count>0){//�Ĥ@����ƫ�A�C���W�[�@��struct�j�p���O����Ŷ�
                data = realloc(data,(count+1)*sizeof(struct Data));
            }
            add(data,count);//�I�s�禡
            count+=1;
        }
        else if(choice==2){//�L�X
            for(int i=0 ;i<count ;i++){
                if(data[i].choose_data==1){
                    printf("%d\n",data[i].type.data_i);
                }
                else if(data[i].choose_data==2){
                    printf("%f\n",data[i].type.data_f);
                }
                else if(data[i].choose_data==3){
                    printf("%s\n",data[i].type.data_s);
                }
            }
        }
        else if(choice==0){//�����{��
            printf("���}���{��");
            free(data);
            return 0;
        }
    }
}
