#include<stdio.h>

int main(){
    int diagonal,columns,rows,temp_count;//�ŧi �﨤�u���� ��� �C�� �p��P�C���ƪ�flag
    //��J�﨤�u����
    while(1){//��J�﨤�u���׿��~���Ӫ��j��(1)
        printf("��J�﨤�u����(3�B5�B7�B9):");
        scanf("%d",&diagonal);
        if(diagonal==3||diagonal==5||diagonal==7||diagonal==9){
            break;//��J���T���X�j��(1)
        }
        else{
            printf("��J���~!\n");//��ܿ��~�~��]�j��(1)
        }
    }
    //��J���
    while(1){//��J��ƿ��~���Ӫ��j��(2)
        printf("��J���(2~10):");
        scanf("%d",&columns);
        if(columns>=2&&columns<=10){
            break;//��J���T���X�j��(2)
        }
        else{
            printf("��J���~!\n");//��ܿ��~�~��]�j��(2)
        }
    }
    //��J�C��
    while(1){//��J�C�ƿ��~���Ӫ��j��(3)
        printf("��J�C��(2~10):");
        scanf("%d",&rows);
        if(rows>=2&&rows<=10){
            break;//��J���T���X�j��(3)
        }
        else{
            printf("��J���~!\n");//��ܿ��~�~��]�j��(3)
        }
    }
    printf("\n");
    //�}�lprint�٫�
    for(int i=1;i<=rows;i++){//�̫�B�z�C�ƭ��ƪ��Ĥ@�hfor�j��[1]
        for(int j=1;j<=diagonal/2;j++){//�B�z�C��٫����ĤG�hfor�j��[1-1]
            //�٫��W�b���T����
            temp_count=columns;//���stemp_count
            do{//�B�z���ƴX�檺do�j��[1-1-1]
                for(int k=diagonal/2-j+1;k>=1;k--){//�٫����W���p�T���ťժ��ĥ|�hfor�j��[1-1-1-1]
                    printf(" ");
                }
                for(int k=1;k<=2*j-1;k++){//�٫����T��*���ĥ|�hfor�j��[1-1-1-2]
                    printf("*");
                }
                for(int k=diagonal/2-j+1;k>=1;k--){//�٫��k�W���p�T���ťժ��ĥ|�hfor�j��[1-1-1-3]
                    printf(" ");
                }
                printf(" ");//�C�ӵ٫������Ů�
                temp_count--;//���temp_count
            }while(temp_count>=1);//�z�Ltemp_count�ӧP�_���ƴX��
            printf("\n");//�C�洫��
        }
        //�٫�����������
        temp_count=columns;//���stemp_count
        do{//�B�z���ƴX����do�j��[1-2]
            for(int j=1;j<=diagonal;j++){//�٫�����������*���ĤT�hfor�j��[1-2-1]
                printf("*");
            }
            printf(" ");//�C�ӵ٧ζ����ť�
            temp_count--;//���temp_count
        }while(temp_count>=1);//�z�Ltemp_count�ӧP�_���ƴX��
        printf("\n");
        //�٫��U�b���T����
        for(int j=diagonal/2;j>=1;j--){//�B�z�C��٫����ĤG�hfor�j��[1-3]
            temp_count=columns;//���stemp_count
            do{//�B�z���ƴX�檺do�j��[1-3-1]
                for(int k=diagonal/2-j+1;k>=1;k--){//�٫����U���p�T���ťժ��ĥ|�hfor�j��[1-3-1-1]
                    printf(" ");
                }
                for(int k=1;k<=2*j-1;k++){//�٫����T��*���ĥ|�hfor�j��[1-3-1-2]
                    printf("*");
                }
                for(int k=diagonal/2-j+1;k>=1;k--){//�٫��k�U���p�T���ťժ��ĥ|�hfor�j��[1-3-1-3]
                    printf(" ");
                }
                printf(" ");//�C�ӵ٫������Ů�
                temp_count--;//���temp_count
            }while(temp_count>=1);//�z�Ltemp_count�ӧP�_���ƴX��
            printf("\n");//�C�洫��
        }
    printf("\n");//���C�j\n
    }
    //�{������
    return 0;
}

