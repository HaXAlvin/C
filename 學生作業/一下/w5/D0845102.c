#include <stdio.h>
#include <stdlib.h>
typedef enum//�L�X�ɪ��ﶵ
{
    I,F,S
} type;
typedef union//�]�@�ӥ]�t�n�D�榡��union
{
    int i_;
    char s_[16];
    float f_;
} input;
struct array//�]�@�ӰO����
{
    input transform;
    type what_type;
};
void call_in(struct array *in_type,int n)//����������禡
{
    for(char choose=0;;)
    {

        printf("�������:(i:int/f:float/s:char[16]:");

        scanf("%c",&choose);
        getchar();
        if(choose=='i')
        {printf("��J���:");
            scanf("%d",&in_type[n].transform.i_);
            in_type[n].what_type=I;
            break;
        }
        else if(choose=='f')
        {printf("��J���:");
            scanf("%f",&in_type[n].transform.f_);
            in_type[n].what_type=F;
            break;
        }
        else if(choose=='s')
        {printf("��J���:");
            scanf("%s",in_type[n].transform.s_);
            in_type[n].what_type=S;
            break;
        }
        else
        {
            printf("��J���~!\n");
            choose='\0';
        }
    }
}
int main()
{
    struct array *arr = malloc(0);//�]�@��struct�������ʺA�}�C
    int count=0;
    for(int option;;)
    {
        printf("���:(1.�s�W)/2.�L�X/0.����):");
        scanf("%d",&option);
        getchar();
        if(option==1)
        {
            arr = realloc(arr, (count+1) * sizeof(struct array));
            call_in(arr,count);//�I�s�禡
            count++;
            option=-1;//���m�ﶵ�Ѽ�
        }
        else if(option==2)
        {
            for(int j=0; j<count; j++)
            {

                if(arr[j].what_type==I)//���P�_����,�A��X
                {
                    printf("%d\n",arr[j].transform.i_);

                }
                else if(arr[j].what_type==F)
                {
                    printf("%f\n",arr[j].transform.f_);
                }
                else if(arr[j].what_type==S)
                {
                    printf("%s\n",arr[j].transform.s_);
                }
            }
            option=-1;//���m�ﶵ�Ѽ�

        }
        else if(option==0)
        {
            printf("�����{��\n");
            free(arr);
            return 0;
        }
        else if(option>2)//debug,�ﶵ�L�j�|�ɭPbug
        {
             printf("��J���~!\n");
            option=-1;//���m�ﶵ�Ѽ�
        }
        else
        {
            printf("��J���~!\n");
            option=-1;//���m�ﶵ�Ѽ�
        }
    }

}
