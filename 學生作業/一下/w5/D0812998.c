#include<stdio.h>
#include<stdlib.h>
union data
{
    int Int;
    float Float;
    char Char[16];
};//�]�m1��union���x�s���
struct array
{
    union data data2;
    char Char2;
};//�s�istruct�̦b�]�t�@��char��@������k
int main()
{
    int choose,count=0,n=1;
    struct array *array2;
    array2 = malloc (0*sizeof(struct array));//�]�m�@�Ӭ�0���ʺA�}�C
    while(1)
    {
        printf("(1.�s�W/2.�L�X/0.����):");
        scanf("%d",&choose);
        if(choose!=1&&choose!=2&&choose!=0)
        {
            printf("��J���~!\n");
            continue;
        }//���b
        else if(choose == 1)
        {
            while(1)
            {
                array2 = realloc(array2,n*sizeof(struct array));//�C���s�W�h���L�@��n�Ӥj�p���O����Ŷ�,n�C�@���s�W�h+1
                printf("�������:(i : int/f : float/s:char[16]):");
                getchar();
                scanf("%c",&array2[count].Char2);
                if(array2[count].Char2 == 'i')
                {
                    printf("��J���:");
                    scanf("%d",&array2[count].data2.Int);
                    break;
                }//��Ji�s�bunion��int��
                else if(array2[count].Char2 == 'f')
                {
                    printf("��J���:");
                    scanf("%f",&array2[count].data2.Float);
                    break;
                }//��Jf�s�bunion��flaot��
                else if(array2[count].Char2 == 's')
                {
                    printf("��J���:");
                    scanf("%s",&array2[count].data2.Char);
                    break;
                }//��Js�s�bunion��char��
                else
                {
                    printf("��J���~!\n");
                    continue;
                }//���b
            }
        }
        if(choose == 2)
        {
            for(int j=0;j<count;j++)
            {
                if(array2[j].Char2=='i')
                {
                    printf("%d\n",array2[j].data2.Int);
                }//�p�G�}�C��i�h��Xunion�̪�int
                else if(array2[j].Char2=='f')
                {
                    printf("%f\n",array2[j].data2.Float);
                }//�p�G�}�C��f�h��Xunion�̪�float
                else if(array2[j].Char2=='s')
                {
                    printf("%s\n",array2[j].data2.Char);
                }//�p�G�}�C��s�h��Xunion�̪�char
            }
        }
        if(choose == 0)
        {
            free(array2);
            return 0;
        }//����ʺA�t�m�O����
        n++;
        count++;
    }
}
