#include<stdio.h>
#include<stdlib.h>

typedef union _content
{
    int i;
    float f;
    char s[16];
} content;

typedef struct _data
{
    content stuff;
    int sort;
    struct _data* nextptr;
    struct _data* lastptr;
} data;
//��J�ΰƵ{��
void input1(data *a)
{
    scanf("%d",&a->stuff);
}

void input2(data *a)
{
    scanf("%f",&a->stuff);
}

void input3(data *a)
{
    scanf("%s",&a->stuff);
}
//��X�ΰƵ{��
void output1(data *a)
{
    printf("%d\n",a->stuff.i);
}

void output2(data *a)
{
    printf("%f\n",a->stuff.f);
}

void output3(data *a)
{
    printf("%s\n",a->stuff.s);
}
//���~
void wrong(void)
{
    printf("��J���~!\n");
}
//�D�{��
int main()
{
    int system=0;
    int insort=0;
    void (*input[])(data *)={input1,input2,input3};
    void (*output[])(data *)={output1,output2,output3};
    data *headptr=NULL;
    data *currentptr=NULL;
    data scanptr;
    data *printptr;
    while(1)//�t�ΰj��
    {
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&system);
        if(system==0)//����
        {
            while(currentptr->lastptr!=NULL)
            {
                free(currentptr->nextptr);
                currentptr=currentptr->lastptr;
            }
            free(headptr);
            return 0;
        }
        else if(system==1)//��J
        {
            while(1)//���b�j��
            {
                printf("�������:(1.int/2.float/3.char[16]):");
                scanf("%d",&insort);
                if(insort==1||insort==2||insort==3)//��J���T
                {
                    break;
                }
                else//��J���~
                {
                    wrong;
                }
            }
            printf("��J���:");
            scanf("\n");
            input[insort-1](&scanptr);
            if(headptr==NULL)
            {
                headptr=malloc(sizeof(data));
                currentptr=headptr;
                headptr->lastptr=NULL;
            }
            else
            {
                currentptr->nextptr=malloc(sizeof(data));
                currentptr->nextptr->lastptr=currentptr;
                currentptr=currentptr->nextptr;
            }
            currentptr->stuff=scanptr.stuff;
            currentptr->sort=insort;
            currentptr->nextptr=NULL;
        }
        else if(system==2)//�L�X
        {
            printptr=headptr;
            while(printptr!=NULL)
            {
                output[(printptr->sort)-1](printptr);
                printptr=printptr->nextptr;
            }
        }
        else//��J���~
        {
            wrong();
        }
    }
}
