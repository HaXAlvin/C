#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char **dynaArr1;
    char dynaArr2[100];
    int select;
    int space=0,namecalculate=10,compare,length=0;
    int i=0,m=0,n=0;
    dynaArr1 = malloc(10*sizeof(char*));

    while(1)
    {
        printf("���:(1.�s�W2.�L�X3.�Ƨ�4.���})\n");
        scanf("%d",&select);
        //���1 ���ϥΪ̷s�W�W�r
        if(select==1)
        {
            //�Ŷ������h�C���W�[5��char �j�p���Ŷ�
            if(namecalculate==0)
            {
                dynaArr1 = realloc(dynaArr1,namecalculate+5*sizeof(char));
                namecalculate = namecalculate+5;
                namecalculate = 5;
            }
            getchar();
            gets(dynaArr2);
            //�����r�����
            //length = strlen(dynaArr1);
            for(int j=0;j<100;j++)
            {
                if(dynaArr2[j]!='\0')
                    m++;
            }
            //�t�m���Ŷ�����n����J���r���ƥ[�W��\0���Ҧ����Ŷ��j�p
            dynaArr1[space] = malloc(m+1*sizeof(char));
            //��ĤG�ӽƻs��Ĥ@��
            strcpy(dynaArr1[space],dynaArr2);
            space++;
        }
        // ���2 �L�X�ϥΪ̿�J���W�r
        if(select==2)
        {
            for(n=0;n<space;n++)
            {
                puts(dynaArr1[n]);
                printf("\n");
            }
        }
        //���3 �ϥΪw�j�ƧǪk�Ƨ�
        if(select==3)
        {
            for(int i=space-1;i>0;i--)
            {
                for(int c=0;c<i;c++)
                {
                    compare=strcmp(dynaArr1[c],dynaArr1[c+1]);
                    if(compare>0)
                    {
                        char* tmp=dynaArr1[c];
                        dynaArr1[c]=dynaArr1[c+1];
                        dynaArr1[c+1]=tmp;
                    }
                }
            }
            printf("�Ƨǧ���!\n");
        }
        //���4 ����O���� �����{��
        if(select==4)
        {
            for(int l=0;l<space;l++)
            {
                free(dynaArr1[i]);
            }
            free(dynaArr1);
            return 0;
        }
    }
}
