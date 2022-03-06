#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�]�w���c
typedef union _data
{
    int i;
    float f;
    char s[16];
}data;

typedef struct _array
{
    data base;
    int num;
    struct _array* nextptr;
    struct _array* lastptr;
}array;

//��J��ƨ禡
void in1(array *a)
{
    scanf("%d", &a -> base);
}

//��J�B�I�ƨ禡
void in2(array *a)
{
    scanf("%f", &a -> base);
}

//��J�r��禡
void in3(array *a)
{
    scanf("%s", &a -> base);
}

//��X��ƨ禡
void out1(array *a)
{
   printf("%d\n", a -> base.i);
}

//��X�B�I�Ƽƨ禡
void out2(array *a)
{
   printf("%f\n", a -> base.f);
}

//��X�r��禡
void out3(array *a)
{
   printf("%s\n", a -> base.s);
}

int main()
{
    //�]�w�ܼ�
    int n = 0;
    int a;
    int time = 0;
    array *headptr = NULL;
    array *currentptr = NULL;
    array scanptr;
    array *printptr;
    while(1)
    {
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d", &n);
        //��ܷs�W
        if(n == 1)
        {
            time++;
            while(1)
            {
                printf("�������:(1�Gint/2�Gfloat/3�Gchar[16])�G");
                scanf("%d", &a);
                //��Jint
                if(a == 1)
                {
                    printf("��J���:");
                    scanf("\n");
                    in1(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //��Jfloat
                if(a == 2)
                {
                    printf("��J���:");
                    scanf("\n");
                    in2(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //��J�r��
                if(a == 3)
                {
                    printf("��J���:");
                    scanf("\n");
                    in3(&scanptr);
                    if(headptr == NULL)
                    {
                        headptr = malloc(sizeof(array));
                        currentptr = headptr;
                        headptr -> lastptr = NULL;
                    }
                    else
                    {
                        currentptr -> nextptr = malloc(sizeof(array));
                        currentptr -> nextptr -> lastptr=currentptr;
                        currentptr = currentptr -> nextptr;
                    }
                    currentptr -> base = scanptr.base;
                    currentptr -> num = a;
                    currentptr -> nextptr = NULL;
                    break;
                }
                //���b
                if(a != 1 && a != 2 && a != 3)
                {
                    printf("��J���~!\n");
                }
            }

        }
        //��ܦL�X
        if(n == 2)
        {
            printptr = headptr;
            while(printptr != NULL)
            {
                //��Xint
                if(printptr -> num == 1)
                {
                    out1(printptr);
                }
                //��Xfloat
                if(printptr -> num == 2)
                {
                    out2(printptr);
                }
                //��X�r��
                if(printptr -> num == 3)
                {
                    out3(printptr);
                }
                printptr = printptr -> nextptr;
            }

        }
        //���b
        if(n != 0 && n != 1 && n != 2)
        {
            printf("��J���~!\n");
        }
        //�����{��
        if(n == 0)
        {
            printf("�����{��\n");
            while(currentptr -> lastptr != NULL)
            {
                free(currentptr -> nextptr);
                currentptr = currentptr -> lastptr;
            }
            free(headptr);
            return 0;
        }
    }
}
