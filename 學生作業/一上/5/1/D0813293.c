#include<stdio.h>
#include<stdlib.h>

int main()
{   //char1=�p������
    char char1_type ='W';
    int char1_atk = 15;
    int char1_hp = 50;
    int char1_def= 5;
    //����j�׹w��
    float char1_predict= (char1_hp * 1 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5;
    //char2=������
    char char2_type = 'F';
    int char2_atk = 18;
    int char2_hp = 47;
    int char2_def = 5;
    //����j�׹w��
    float char2_predict= (char2_hp * 1 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;
    //char3=������
    char char3_type = 'A';
    int char3_atk = 15;
    int char3_hp = 45;
    int char3_def = 7;
    //����j�׹w��
    float char3_predict= (char3_hp * 1 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5;
    //�s�W����1=newchar1
    char newchar1_type;
    int newchar1_atk;
    int newchar1_hp;
    int newchar1_def;
    //�s�W����j�׹w��
    float newcahr1_predict;

    //��ܨ����T
    printf("����1\n�W��:�p������\n");
    printf("�ݩ�:%c\t����:%d\n",char1_type,char1_atk);
    printf("��q:%d\t���m:%d\n",char1_hp,char1_def);
    printf("����j�׹w��:%.2f\n\n",char1_predict);
    printf("����2\n�W��:������\n");
    printf("�ݩ�:%c\t����:%d\n",char2_type,char2_atk);
    printf("��q:%d\t���m:%d\n",char2_hp,char2_def);
    printf("����j�׹w��:%.2f\n\n",char2_predict);
    printf("����3\n�W��:������\n");
    printf("�ݩ�:%c\t����:%d\n",char3_type,char3_atk);
    printf("��q:%d\t���m:%d\n",char3_hp,char3_def);
    printf("����j�׹w��:%.2f\n\n",char3_predict);

    printf("\n�O�_�s�W����(1.YES/2.NO)?");
    char chose;//��ܬO�_�s�W����
    scanf(" %d",&chose);
    int first;//����
    int last;//���

    if(chose == 1){//�Y��ܷs�W����A�h��ܷs�W��J��T
        printf("\n�s�W����\n�ݩ�:");
        scanf(" %c", &newchar1_type);
        printf("����:");
        scanf("%d",&newchar1_atk);
        printf("��q:");
        scanf("%d", &newchar1_hp);
        printf("���m:");
        scanf("%d",&newchar1_def);
        //�ഫ�j�p�g
        if (newchar1_type== 'f' ){
            newchar1_type= 'F';
        }else if(newchar1_type== 'w' ){
            newchar1_type= 'W';
        }else if(newchar1_type== 'g' ){
            newchar1_type= 'G';
        }else if(newchar1_type== 'a' ){
            newchar1_type= 'A';
        }else if(newchar1_type== 'F' ){
            newchar1_type= 'F';
        }else if(newchar1_type== 'W' ){
            newchar1_type= 'W';
        }else if(newchar1_type== 'G' ){
            newchar1_type= 'G';
        }else if(newchar1_type== 'A' ){
            newchar1_type= 'A';
        }else {
            printf("���~: �L���ݩ�\n");
        }
        //�P�_����ƭ�
        if((newchar1_atk < 15)|(newchar1_atk > 20)){
            printf("���~ : ��O�ƭȦb�d�򤧥~\n");
            return 0;
        }
        if((newchar1_hp < 40)|(newchar1_hp > 50)){
            printf("���~ : ��O�ƭȦb�d�򤧥~\n");
            return 0;
        }
        if((newchar1_def < 5)|(newchar1_def > 10)){
            printf("���~ : ��O�ƭȦb�d�򤧥~\n");
            return 0;
        }
        if(((newchar1_hp + newchar1_atk + newchar1_def)< 65 )|((newchar1_hp + newchar1_atk + newchar1_def)> 70 )){
            printf("���~ : ��O�ƭȦb�d�򤧥~\n");
            return 0;
        }

        //�s�W����w���j��
        float newchar1_predict=(newchar1_hp * 1 + newchar1_atk * 0.8 + newchar1_def * 0.5 - 50) * 6.5;
        //�s�W�����T
        printf("\n����4\n�W��:�ۭq����\n�ݩ�:%c\t����:%d\n��q:%d\t���m:%d\n����j�׹w��:%.2f\n:"
               ,newchar1_type,newchar1_atk,newchar1_hp,newchar1_def,newchar1_predict);
        //��ܧ�������
        printf("��ܥ��𨤦�: ");
        scanf("%d",&first);
        if((first>4)|(first<1)){
            printf("���~: �L������\n");
        }else {
            printf("��ܫ�𨤦�: ");
            scanf("%d",&last);
            if((last>4)|(last<1)){
                printf("���~: �L������\n");
            }else if((last<=4)&(last>=1)){
                if(last == first){
                    printf("���~: ���i���ƿ��\n");
                }else {
                    printf("\n���𬰨���%d�B��𬰨���%d\n",first,last);
                }
            }
        }
    }else if(chose == 2){
        //��ܨ����������
        printf("��ܥ��𨤦�: ");
        scanf("%d",&first);
        if((first>3)|(first<1)){
            printf("���~: �L������\n");
        }else{
            printf("��ܫ�𨤦�: ");
            scanf("%d",&last);
            if((last>3)|(last<1)){
                printf("���~: �L������\n");
            }else if((last<=3)&(last>=1)){
                if(last == first){
                    printf("���~: ���i���ƿ��\n");
                }else{
                    printf("\n���𬰨���%d�B��𬰨���%d\n",first,last);
                }
            }
        }
    }
    else{
        printf("��J���~\n");
    }
    return 0;
}
