#include<stdio.h>

int main()
{
    int dia, col, rows;//�﨤�u(diagonal), ���(columns), �C��(rows)
    int i, j, k, m;
    while (printf("��J�٧ι﨤�u����(3�B5�B7�B9):"), scanf("%d", &dia) && (dia != 3 && dia != 5 && dia != 7 && dia != 9))
    {
        printf("��J���~!\n");//�﨤�u��J���~
    }
    while (printf("��J���(2~10):"), scanf("%d", &col) && (col < 2 || col > 10))
    {
        printf("��J���~!\n");//��ƿ�J���~
    }
    while (printf("��J�C��(2~10):"), scanf("%d", &rows) && (rows < 2 || rows > 10))
    {
        printf("��J���~!\n");//�C�ƿ�J���~
    }
    printf("\n");
    for (i = 0; i < rows; i++)//�@��n�C
    {
        for (j = 0; j < dia / 2 + 1; j++)//�٧Ϊ��W�b���@��(�﨤�u / 2 + 1)�C
        {
            for (k = 0; k < col; k++)//�٧Ϊ��W�b���ݭn�h�֭�
            {
                for (m = dia / 2; m > j; m--)//�W�b�� �e���ťժ�����
                    printf(" ");
                for (m = 0; m < 1 + j * 2; m++)//�W�b���� *
                    printf("*");
                for (m = dia / 2; m > j; m--)//�W�b�� �᭱�ťժ�����
                    printf(" ");
                if (k < col)//�C�ӵ٧Τ����Ť@��
                    printf(" ");
            }
            printf("\n");
        }
        for (j = 0; j < dia / 2; j++)//�٧Ϊ��U�b���@��(�﨤�u / 2)�C
        {
            for (k = 0; k < col; k++)//�٧Ϊ��U�b���ݭn�h�֭�
            {
                for (m = 0; m <= j; m++)//�U�b�� �e���ťժ�����
                    printf(" ");
                for (m = dia; m > j * 2 + 2 ; m--)//�U�b����*
                    printf("*");
                for (m = 0; m <= j; m++)//�U�b�� �᭱�ťժ�����
                    printf(" ");
                if (k < col)
                    printf(" ");//�C�ӵ٧Τ����Ť@��
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
