#include<stdio.h>
#include<stdlib.h>

int main(){
    int leng, col, row;//�ܼ�:���סB��ơB�C��
    int i, j, k, m;

    //��J�﨤�u����
    do{
        printf("��J�٧ι﨤�u����(3�B5�B7�B9)�G");
        scanf("%d",&leng);
        if(leng ==3 || leng ==5 || leng ==7 || leng ==9)
            break;//��J���T�h���X�j��
        else{
            printf("��J���~!\n");
            continue;//��J���~�h�A����J
        }
    }while(1);

    //��J���
    do{
        printf("��J���(2 ~ 10)�G");
        scanf("%d",&col);
        if(col >=2 && col <=10)
            break;//��J���T�h���X�j��
        else{
            printf("��J���~!\n");
            continue;//��J���~�h�A����J
        }
    }while(1);

    //��J�C��
    do{
        printf("��J�C��(2 ~ 10)�G");
        scanf("%d",&row);
        if(row >=2 && row <=10)
            break;//��J���T�h���X�j��
        else{
            printf("��J���~!\n");
            continue;//��J���~�h�A����J
        }
    }while(1);

    //�٧αq������_���W�b��
    for(i=1; i<=row; i++){//�C��
            for(k=1; k<=(leng/2+1); k++){//�W�b���]�t������
            	for(j=1; j<=col; j++){//���
                    for(m=1; m<=(leng-1-k) ;m++){//�W�b���P������Ů�
                        printf(" ");
                    }
                    for(m=1; m<=(2*k-1); m++){//�W�b���P��
                        printf("*");
                    }
                    for(m=1; m<=(leng-1-k) ;m++){//�W�b���P���k��Ů�
                        printf(" ");
                    }
                }
                printf("\n");//�C��L�X�ᴫ��
            }
            //�٧ΤU�b��

            for(k=(leng/2); k>=1; k--){//�U�b�����t������
            	for(j=col; j>=1; j--){//���
                    for(m=(leng-1-k); m>=1 ;m--){//�U�b���Ů�
                        printf(" ");
                    }
                    for(m=(2*k-1); m>=1; m--){//�U�b���P��
                        printf("*");
                    }
                    for(m=(leng-1-k); m>=1 ;m--){//�U�b���Ů�
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
    }
    return 0;
}
