/*  109�~��  ��T�G�B
        �Ĥ��g�@�~    */
#include<stdio.h>//���Y��
#include<stdlib.h>
struct array//�w�q�}�C���c
{
    union arr//�w�q�p�X���c
    {
        int num;//���
        float Num;//���ׯB�I��
        char word[16];//�r���}�C
    } Arr;
    char t;//�Ψ��x�s��ƫ��A
};
void store(struct array *a)//�x�s��Ƥ��Ƶ{��
{
    char ty;//�ŧi�ܼ�
    while(1)
    {
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        scanf("%c",&ty);//��ܫ��A
        getchar();
        if(ty=='i')//���int
        {
            printf("��J��ơG");
            scanf("%d",&(a->Arr).num);//��J���
            a->t=ty;//�x�s���A
            break;//���X�j��
        }
        if(ty=='f')//���float
        {
            printf("��J��ơG");
            scanf("%f",&(a->Arr).Num);//��J���
            a->t=ty;//�x�s���A
            break;//���X�j��
        }

        if(ty=='s')//���char
        {
            printf("��J��ơG");
            gets((a->Arr).word);//��J���
            a->t=ty;//�x�s���A
            break;//���X�j��
        }
        if(!(ty=='i'||ty=='s'||ty=='f'))//��Ji�Bf�Bs�H�~
            printf("��J���~�I\n");
    }
}
int main()//�D�{��
{
    int n=0,sum=0;//��i�ܼ�
    struct array *mov=malloc(sum*sizeof(struct array));//�ŧimov�}�C��struct array���c���ʺA�}�C
    while(1)
    {
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d",&n);
        if(n==1)//��ܷs�W
        {
            getchar();
            sum++;//�}�C+1
            mov = realloc(mov,sum*sizeof(struct array));
            store(&mov[sum-1]);//call�Ƶ{��

        }
        if(n==2)//��ܦL�X
        {
            for(int i=0; i<sum; i++) //�j��L�X
            {
                if(mov[i].t=='i')//�p�G���A��int
                    printf("%d\n",mov[i].Arr.num);
                else if(mov[i].t=='f')//�p�G���A��floar
                    printf("%f\n",mov[i].Arr.Num);
                else if(mov[i].t=='s')//�p�G���A��char
                    puts(mov[i].Arr.word);
            }
        }
        if(n<0||n>2)//��J0�B1�B2�H�~
            printf("��J���~�I\n");
        if(n==0)//��ܵ���
        {
            printf("�����{��");
            return 0;//�^�ǡA�õ����{��
        }

    }

}
