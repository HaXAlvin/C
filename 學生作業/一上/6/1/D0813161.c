#include<stdio.h>//���Y��
#include<stdlib.h>//���Y��
int main()//�D�禡
{
    char charl_type ='F',char2_type ='W',char3_type ='G',char4_type;
    int char1_hp = 42, char1_atk = 19,char1_def = 5;
    int char2_hp = 48,char2_atk = 16,char2_def = 5;
    int char3_hp = 45,char3_atk = 16, char3_def = 7;
    int char4_atk, char4_hp, char4_def;
    int input,input2,input3;
    char F,G,W,A,f,g,w,a;
    printf("����1\n"//�L�X����1
           "�W��:���`���l\n"
           "�ݩ�:%c\t����:%d\n"
           "��q:%d\t���m:%d\n",charl_type,char1_atk,char1_hp,char1_def);
    printf("����j�׹w��:%.2f\n\n",(char1_atk*0.8+char1_hp*1.0+char1_def*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    printf("����2\n"//�L�X����2
           "�W��:�ڪ���\n"
           "�ݩ�:%c\t����:%d\n"
           "��q:%d\t���m:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);
    printf("����j�׹w��:%.2f\n\n",(char2_atk*0.8+char2_hp*1.0+char2_def*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
            "\n";
    printf("����3\n"//�L�X����3
           "�W��:����\n"
           "�ݩ�:%c\t����:%d\n"
           "��q:%d\t���m:%d\n"
           ,char3_type,char3_atk,char3_hp,char3_def);
    printf("����j�׹w��:%.2f\n\n",(char3_atk*0.8+char3_hp*1.0+char3_def*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    do {
        printf("�O�_�s�W����(1.Yes/2.No)");//�L�X�O�_�s�W����
        scanf("%d",&input);
        printf("\n");
        if(input>2)//if��J�Ȥj��2
        printf("��J���~");//�L�X
    }while(input==1);
    //if��J�ȵ���1
    printf("�s�W����\n");//�L�X�s�W����
    printf("�ݩ�:",char4_type);//�L�X�ݩ�
    scanf(" %c",&char4_type);
    printf("����:",char4_atk);//�L�X����
    scanf("%d",&char4_atk);
    printf("��q:",char4_hp);//�L�X��q
    scanf("%d",&char4_hp);
    printf("���m:",char4_def);//�L�X���m
    scanf("%d",&char4_def);
    printf("\n");
    if((char4_atk+char4_hp+char4_def<50)||(char4_atk+char4_hp+char4_def>70)||(char4_atk>20)||(char4_atk<15)||(char4_hp>50)||(char4_hp<40)||(char4_def<5)||(char4_def>10))
        printf("���~:��O�ƭȦb����d�򤧥~\n");//if
    if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='a'&&char4_type!='w'&&char4_type!='g'){
        printf("���~:�L���ݩ�");//if char4_type������
        return 0;}//�^�ǡA�����禡
    if(char4_type=='f')//if char4_type����f,�ର�j�g
       char4_type='F';
    if(char4_type=='a')//if char4_type����a,�ର�j�g
       char4_type='A';
    if(char4_type=='g')//if char4_type����g,�ର�j�g
       char4_type='G';
    if(char4_type=='w')//if char4_type����w,�ର�j�g
       char4_type='W';
    printf("����4\n"//�L�X����4
           "�W��:�ۭq����\n"
           "�ݩ�:%c\t����:%d\n"
           "��q:%d\t���m:%d\n\n",char4_type,char4_atk,char4_hp,char4_def);
    printf("����j�׹w��:%.2f\n\n",(char4_atk*0.8+char4_hp*1.0+char4_def*0.5-50)*6.5);//�j�׹w�� =( ��q * 1.0 + ���� * 0.8 + ���m * 0.5 - 50 ) * 6.5
    printf("��ܥ��𨤦�:");//�L�X��ܥ��𨤦�
    scanf(" %d",&input2);
    if((input2>4)||(input2<1)){//if input2������1��4����
        printf("���~:�L������\n");//�L�X���~
        return 0;}
        printf("��ܫ�𨤦�:");//�L�X��ܨ���
        scanf(" %d",&input3);
        printf("\n");
    if((input3>4)||(input3<1)){//if input3������1��4����
        printf("���~:�L������\n");//�L�X���~
        return 0;}//�^�ǡA�����禡
    if(input2==input3){//if input2 ����input3
        printf("���~:���i���ƿ��\n");//�L�X���~:���i���ƿ��
        return 0;}//�^�ǡA�����禡
    else printf("���𬰨���%d�B��𬰨���%d",input2,input3);//�L�X����𨤦�

         if(input==2){
            printf("��ܥ��𨤦�:");//�L�X��ܫ�𨤦�
            scanf(" %d",&input2);
        if((input2>3)||(input2<1)){//if input2������1��4����
            printf("���~:�L������\n");//�L�X���~
            return 0;}//�^�ǡA�����禡
            printf("��ܫ�𨤦�:");//�L�X��ܫ�𨤦�
            scanf(" %d",&input3);
            printf("\n");
        if((input3>3)||(input3<1)){//if input3������1��4����
            printf("���~:�L������\n");//�L�X���~
            return 0;}//�^�ǡA�����禡
        if(input2==input3){//if input2 ����input3
            printf("���~:���i���ƿ��\n");//�L�X���~:���i���ƿ��
            return 0;}//�^�ǡA�����禡
            printf("���𬰨���%d�B��𬰨���%d\n",input2,input3);}//�L�X����𨤦�
            printf("�԰��}�l\n");

        return 0;//�^�ǡA�����禡
}
