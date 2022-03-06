#include<stdio.h>
#include<stdlib.h>

typedef struct _Form
{
    char Num;
    union
    {
        int Int;
        char Char[16];
        float Float;
    }Type;
}Form;
//��J���ƨ禡
void Input(Form *Function,int i)
{
    //����int���������
    if(Function[i].Num=='i')
    {
        int Number;
        printf("��J���:");
        scanf("%d",&Function[i].Type.Int);
    }
    //����float���������
    else if(Function[i].Num=='f')
    {
        int Number;
        printf("��J���:");
        scanf("%f",&Function[i].Type.Float);
    }
    //����char���������
    else if(Function[i].Num=='s')
    {
        int Number;
        printf("��J���:");
        scanf("%s",&Function[i].Type.Char);
    }
    //���b
    else
    {
        printf("��J���~!\n");
    }
}
//��X���ƨ禡
void Output(Form *Function,int a)
{
    //��Xint���������
    if(Function[a].Num=='i')
    {
        printf("%d",Function[a].Type.Int);
    }
    //��Xfloat���������
    else if(Function[a].Num=='f')
    {
        printf("%f",Function[a].Type.Float);
    }
    //��Xchar���������
    else if(Function[a].Num=='s')
    {
        printf("%s",Function[a].Type.Char);
    }
}

int main()
{
    int Choose1;
            int i=0;
    //�إ߰ʺA�}�C
    Form *dynArr=malloc(sizeof(Form));
    while(1)
    {
        printf("���:(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&Choose1);

        getchar();
        //���b
        if((Choose1<0)||(Choose1>2))
        {
            printf("��J���~!\n");
        }
        //����ʺA�}�C�A�����{��
        if(Choose1==0)
        {
            printf("�����{��\n");
            free(dynArr);
            break;
        }
        //���1�A�N��J
        if(Choose1==1)
        {
            printf("�������:(i:int/f:float/s:char[16]):");
            scanf("%c",&dynArr[i].Num);
            getchar();
            while(dynArr[i].Num != 'i' && dynArr[i].Num != 's' && dynArr[i].Num != 'f')
            {
                printf("��J���~!\n");
                printf("�������:(i:int/f:float/s:char[16]):");
                scanf("%c",&dynArr[i].Num);
                getchar();
            }
            //�s�W�ʺA�}�C�j�p
            dynArr=realloc(dynArr,(i+2)*sizeof(Form));
            //�I�s��J���ƨ禡
            Input(dynArr,i);
            //����
            i++;
        }
        //���2�A�N��X
        if(Choose1==2)
        {
            int j;
            for(j=0;j<=i;j++)
            {
                if(dynArr[j].Num == 'i')
                    printf("%d\n",dynArr[j].Type.Int);
                if(dynArr[j].Num == 'f')
                    printf("%f\n",dynArr[j].Type.Float);
                if(dynArr[j].Num == 's')
                    printf("%s\n",dynArr[j].Type.Char);
            }
        }
    }
    return 0;
}
