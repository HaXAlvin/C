#include<stdio.h>

int main()
{
    int length,rows,columns; //�ŧi ���� �� �C
    printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
    scanf("%d",&length); //��J�﨤�u����
        while(1){
            if(length !=3 && length !=5 && length !=7 && length !=9){//��J�﨤�u���~���Ӫ��j��
                printf("��J���~!\n");
                printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
                scanf("%d",&length);
            }
            else break; //��J���T���X�j��
        }
    printf("��J���(2~10):");
        scanf("%d",&rows); //��J���
        while(1){
            if(rows<2 || rows>10){//��J��ƿ��~���Ӫ��j��
                printf("��J���~!\n");
                printf("��J���(2~10):");
                scanf("%d",&rows);
            }
            else break;//��J���T���X�j��
        }
    printf("��J�C��(2~10):");
        scanf("%d",&columns); //��J�C��
        while(1){
            if(columns<2 || columns>10){//��J�C�ƿ��~���Ӫ��j��
                printf("��J���~!\n");
                printf("��J�C��(2~10):");
                scanf("%d",&columns);
            }
            else break;//��J���T���X�j��
        }
        printf("\n");
        int i,j,k,m,n,p; //�ŧi�U�h���p�ƾ��j��
        //�Ĥ@�C�٧Ϊ��W�b��
        for(m=1;m<=columns;m++){//�C�ƪ��j��
            for(i=1;i<=length;i+=2){ // �W�b�����٧�(�]�A����)
                for(j=length;j>i;j-=2){ //�٧Υ��W�����ť�
                    printf(" ");
                }
                    for(k=1;k<=i;k++){ //�ɤW�P��
                        printf("*");
                    }
                    printf(" "); //�Ĥ@��٧ζ����ť�
                        //�ɤW2~9�檺�W�b��
                        for(n=1;n<=rows-1;n++){
                            for(j=length;j>i;j-=2){ //�٧Υk�W�����ť�
                                printf(" ");
                            }
                                for(j=length;j>i;j-=2){ //�s���٧Ϊ����W���ť�
                                    printf(" ");
                                }
                                    for(k=1;k<=i;k++){ //�ɤW�P��
                                        printf("*");
                                    }
                        printf(" ");//�A�ɤW�U�@�涡�j�٧Ϊ��ť�
                        }
            printf("\n");//�W�b����������
            }
                //�U�b���٧�(���]�A����)
                for(i=1;i<length;i+=2){
                    for(j=1;j<=i;j+=2){//���U���٧Ϊ��ť�
                        printf(" ");
                    }
                        for(k=length-2;k>=i;k--){//�ɤW�P��
                            printf("*");
                        }
                        printf(" ");//�Ĥ@�檺�U�b���٧ζ��j
                            //�ɤW2~9�檺�U�b��
                            for(p=1;p<=rows-1;p++){
                                for(j=1;j<=i;j+=2){//�k�U�����ť�
                                    printf(" ");
                                }
                                    for(j=1;j<=i;j+=2){//�s���٧Υ��U���ť�
                                        printf(" ");
                                    }
                                        for(k=length-2;k>=i;k--){//�ɤW�P��
                                            printf("*");
                                        }
                            printf(" ");//�C�ӵ٧ζ������j
                            }
                printf("\n");//�U�b����������
                }
        printf("\n");//�C�ӵ٧Ϊ��W�U���j
        }
    return 0;
}






