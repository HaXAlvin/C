#include <stdio.h>
#include <stdlib.h>

int main()
{
    int diagonal;  //�﨤�u����
    int columns;   //���
    int rows;      //�C��
    int check = 1; //�j�鱱��

    while (check == 1)  //��J�﨤�u���ת��j��
    {
        check = 0;

        printf("��J�٧ι﨤�u����(3�B5�B7�B9)�G");
        scanf("%d", &diagonal);

        if (!(diagonal == 3 || diagonal == 5 || diagonal == 7 || diagonal == 9))    //�Y��J�Ȥ��b�d��A�h�^��j��_�I
        {
            printf("��J���~!\n");
            check = 1;
        }
    }

    while (check == 0)  //��J��ƪ��j��
    {
        check = 1;

        printf("��J���(2~10)�G");
        scanf("%d", &columns);


        if (columns < 2 || columns > 10)    //�Y��J�Ȥ��b�d��A�h�^��j��_�I
        {
            printf("��J���~!\n");
            check = 0;
        }

    }

    while (check == 1)  //��J�C�ƪ��j��
    {
        check = 0;

        printf("��J�C��(2~10)�G");
        scanf("%d", &rows);

        if (rows < 2 || rows > 10)    //�Y��J�Ȥ��b�d��A�h�^��j��_�I
        {
            printf("��J���~!\n");
            check = 1;
        }
    }

    int mid = (diagonal + 1) / 2;                //mid = �٧Υ��������C
    int i, j, k, m, n;

    for (i = 0; i < rows; i++)                   //�L�Xrows(2~10)�C����٧Ϊ��j��
    {

        for (j = 1; j <= mid; j++)               //�L�X�C�@�ӵ٧Φ��h�֦檺�j�� (�u�L�W�b���Aj�`�@�|��mid��)
        {
            for (k = 0; k < columns; k++)        //�L�Xcolumns(2~10)�槹��٧Ϊ��j��
            {
                for (m = 0; m < mid - j; m++)    //mid�C�S���Ů�A�ӨC����mid�@�C�A�Ů���1�Aj�]�W�[1
                {
                    printf(" ");
                }
                for (n = 0; n < 2 * j - 1; n++)  //�C�C�W�[2���P�P�A2���HJ
                {
                    printf("*");
                }
                for (m = 0; m < mid - j; m++)    //�L�X�P�e���ۦP�ƶq���ťաA�H�K�v�T��ĤG�檺�٧�
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }

        for (j = mid - 1; j > 0; j--)           //�L�X�C�@�ӵ٧Φ��h�֦檺�j�� (�u�L�U�b���Aj�|��mid-1��C�ťթM�P�P���ƶq�P�W�b���ۤϡA�]��j�ĥλ���)
        {
            for (k = 0; k < columns; k++)       //��L�P�W���ۦP
            {
                for (m = 0; m < mid - j; m++)   
                {
                    printf(" ");
                }
                for (n = 0; n < 2 * j - 1; n++)
                {
                    printf("*");
                }
                for (m = 0;  m < mid - j; m++)
                {
                    printf(" ");
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
