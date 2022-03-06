#include <stdio.h>
#include <stdlib.h>

typedef union{ //�x�s��ƪ����A
    int i_data; //���
    float f_data; //�B�I��
    char s_data[16]; //�r��
}Type;

typedef struct{ //�s���ƪ����c
    Type type; //���
    char choosetype; //��ƫ��A
}Data;

void inputnewdata(int num, Data *arr){ //�s�W���
    while(1){ //��ܪ���ƫ��A�W�X����
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        getchar();
        scanf("%c", &arr[num].choosetype);
        if(arr[num].choosetype == 'i' || arr[num].choosetype == 'f' || arr[num].choosetype == 's')
            break;
        printf("��J���~!\n");
    }
    printf("��J��ơG");
    if(arr[num].choosetype == 'i') //��ƫ��A���
        scanf("%d", &arr[num].type.i_data);
    else if(arr[num].choosetype == 'f') //�B�I�ƫ��A���
        scanf("%f", &arr[num].type.f_data);
    else if(arr[num].choosetype == 's'){ //�r�ꫬ�A���
        getchar();
        gets(arr[num].type.s_data);
    }
}

void printdata(int num, Data *ans){ //�L�X�s�W���Ҧ����
    int i;
    for(i=0;i<num;i++){
        if(ans[i].choosetype == 'i') //�L�X���
            printf("%d\n", ans[i].type.i_data);
        else if(ans[i].choosetype == 'f') //�L�X�B�I��
            printf("%f\n", ans[i].type.f_data);
        else if(ans[i].choosetype == 's') //�L�X�r��
            printf("%s\n", ans[i].type.s_data);
    }
}

int main(){
    int choose = 0,datanum = 0;
    Data *data;
    while(1){
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�F");
        scanf("%d", &choose);
        if(choose == 0){
            printf("�����{��");
            free(data); //����O����
            return 0;
        }
        else if(choose == 1){
            if(datanum == 0) //��}�C���׬�0
                data = malloc(1 * sizeof(Data)); //�W�[1��struct�j�p���O����Ŷ�
            else
                data = realloc(data, (datanum+1) * sizeof(Data)); //�W�[1��struct�j�p���O����Ŷ�
            inputnewdata(datanum, data); //�s�W���
            datanum += 1; //��Ƽ�+1
        }
        else if(choose == 2){ //�L�X�Ҧ��s�W���
            printdata(datanum, data);
        }
        else if(choose < 0 || choose > 2) //��J�W�X����
            printf("��J���~!\n");
    }
}
