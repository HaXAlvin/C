#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,columns,rows;

    printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
    scanf("%d",&n);
    while(n!=3&&n!=5&&n!=7&&n!=9){
        printf("��J���~!\n��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&n);
    }

    printf("��J���(2~10):");
    scanf("%d",&columns);
    while(columns<2||columns>10){
        printf("��J���~!\n��J���(2~10):");
        scanf("%d",&columns);
    }

    printf("��J�C��(2~10):");
    scanf("%d",&rows);
    while(rows<2||rows>10){
        printf("��J���~!\n��J�C��(2~10):");
        scanf("%d",&rows);
    }

    for(int i=0;i<rows;i++){//�L�X�C�@�C�٧�
    printf("\n");//�W�U�۾F���٧ά۹j�@��
        for(int k=1;k<=(n+1)/2;k++){//�L�X�C�@�C�٧Τ����W�b��+�������C�@�C
            for(int j=0;j<columns;j++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��W�b��+����
                for(int m=0;m<(n+1)/2-k;m++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��W�b��+����������ť�
                    printf(" ");
                }
                for(int p=0;p<k*2-1;p++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��W�b��+�������P�P����
                    printf("*");
                }
                for(int m=0;m<(n+1)/2-k;m++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��W�b��+�������k��ť�
                    if(j<columns-1){//�C�@�C�̫�@�ӵ٧Ϊ��k��ťդ��ΦL
                    printf(" ");
                    }
                }
            if(j<columns-1){//�C�@�ӥ��k�۾F���٧ά۹j�@�Ӫť�(�̫�@�Ӥ���)
                printf(" ");
            }
            }
                printf("\n");//�L���@�C�٧Ϊ��@�C�ᴫ��
        }
        for(int k=1;k<=(n+1)/2-1;k++){//�L�X�C�@�C�٧Τ����U�b�����C�@�C
            for(int j=0;j<columns;j++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��U�b��
                for(int m=0;m<k;m++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��U�b��������ť�
                    printf(" ");
                }
                for(int p=0;p<n-k*2;p++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��U�b�����P�P
                    printf("*");
                }
                for(int m=0;m<k;m++){//�L�X�C�@�C�٧Τ����C�@�ӵ٧Ϊ��U�b�����k��ť�
                    if(j<columns-1){//�C�@�C���̫�@�ӵ٧Ϊ��k��ťդ��ΦL
                    printf(" ");
                    }
                }
            if(j<columns-1){//�C�@�ӥ��k�۾F���٧ά۹j�@�Ӫť�(�̫�@�Ӥ���)
                printf(" ");
            }
            }
        if(k!=(n+1)/2-1||i!=rows-1){//�L���@�C�٧Ϊ��@�C�ᴫ��(�L�̫�@�C�٧Ϊ��̩��U�@�C�ɤ�����)
        printf("\n");
        }
        }

    }

    return 0;
}




