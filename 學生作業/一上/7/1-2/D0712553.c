#include<stdio.h>
int main(){
    int row; //�C -
    int col; //�� |
    int n; //�٧ι﨤�u����
    int p = 1; //flag:���O�̧Ƕi�J�T�Ӱj��
    while(p){ //�M�w�٧ι﨤�u����
        printf("��J�٧ι﨤�u����(3�B5�B7�B9): ");
        scanf("%d", &n);
        switch (n){ //�ŦX3�B5�B7�B9
            case 3:
            case 5:
            case 7:
            case 9:
                p = 0; //��J���T�A���}�﨤�u���װj��
                break;
            default: //��J���~
                printf("��J���~�I\n");
        }
    }
    p = 1; //�i�J��J��j��
    while(p){ //�M�w���
        printf("��J���(2~10): ");
        scanf("%d", &col);
        if(col>=2 && col<=10){ //��d��b2~10����
            p = 0; //��J���T�A���}��j��
        }
        else{ //��J���~
            printf("��J���~�I\n");
        }
    }
    p = 1; //�i�J��J�C�j��
    while(p){ //�M�w�C��
        printf("��J�C��(2~10): ");
        scanf("%d", &row);
        if(row>=2 && row <=10){ //�C�d��b2~10����
            p = 0; //��J���T�A���}�C�j��
        }
        else{ //��J���~
            printf("��J���~�I\n");
        }
    }
    int i; //�C�Ƶ٧�
    int j; //��Ƶ٧�
    int k; //��٧Τ��C
    int m; //��٧Τ���
    for(i=1; i<=row; i++){ //���ƦL�X�C�ƭӵ٧�
        for(j=1; j<=n*row+(row-1); j++){ //�C�ӵ٧ΤW�U�j�@�C
            printf(" ");
        }
        printf("\n");
        for(j=1; j<=n; j++){ //���ƦL�X��ƪ��٧�-�W�b��
            for(k=1; k<=col; k++){ //�L�X�C�ӵ٧ΤW�b��
                for(m=1; m<=(n-j); m++){ //�W�b�����Ů�ơA����
                        printf(" ");
                }
                for(m=1; m<=(2*j - 1); m++){ //�W�b���P���ơA���W
                    printf("*");
                }
                if(k!=col){ //�C�ӵ٧Υk���@��A�̥k���n�j
                    for(m=1; m<=(n-j)+1; m++){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        for(j=n-1; j>=1; j--){ //���ƦL�X��ƪ��٧�-�U�b��
            for(k=1; k<=col; k++){ //�L�X�C�ӵ٧ΤU�b��
                for(m=n-j; m>=1; m--){ //�U�b�����Ů�ơA���W
                    printf(" ");
                }
                for(m=1; m<=(2*j-1); m++){ //�U�b���P���ơA����
                    printf("*");
                }
                if(k!=col){ //�C�ӵ٧Υk���@��A�̥k���n�j
                    for(m=(n-j)+1; m>=1; m--){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
