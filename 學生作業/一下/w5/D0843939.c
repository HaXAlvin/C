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
    char alpha;
}array;

//��J��ƨ禡
void in1(array *a, int b)
{
    scanf("%d", &a[b].base.i);
}

//��J�B�I�ƨ禡
void in2(array *a, int b)
{
    scanf("%f", &a[b].base.f);
}

//��J�r��禡
void in3(array *a, int b)
{
    scanf("%s", &a[b].base.s);
}

//��X��ƨ禡
void out1(array *a, int b)
{
   printf("%d\n", a[b].base.i);
}

//��X�B�I�Ƽƨ禡
void out2(array *a, int b)
{
   printf("%f\n", a[b].base.f);
}

//��X�r��禡
void out3(array *a, int b)
{
   printf("%s\n", a[b].base.s);
}

int main()
{
    //�]�w�ܼ�
    int n;
    char a;
    int time = 0;
    data base;
    //�إ߰ʺA�O����Ŷ�
    array *mall = malloc(sizeof(array));
    while(1)
    {
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d", &n);
        //��ܷs�W
        if(n == 1)
        {
            while(1)
            {
                printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
                getchar();
                scanf("%c", &a);
                //���s���t�ʺA�O����Ŷ�
                mall = realloc(mall,sizeof(array));
                //��J���
                if(a == 'i')
                {
                    printf("��J��ơG");
                    in1(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //��J�B�I��
                else if(a == 'f')
                {
                    printf("��J��ơG");
                    in2(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //��J�r��
                else if(a == 's')
                {
                    printf("��J��ơG");
                    in3(mall, time);
                    mall[time].alpha = a;
                    time++;
                    break;
                }
                //���b
                else
                {
                    printf("��J���~!\n");
                }
            }
        }
        //��ܦL�X
        if(n == 2)
        {
            //�P�_�ʺA�}�C���C���Φ�
            for(int i = 0; i < time; i++)
            {
                if(mall[i].alpha == 'i')
                {
                    out1(mall, i);
                }
                if(mall[i].alpha == 'f')
                {
                    out2(mall, i);
                }
                if(mall[i].alpha == 's')
                {
                    out3(mall, i);
                }
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
            printf("�����{��");
            free(mall);
            return 0;
        }
    }
}
