#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    //����1
    char char1_type='F';//����1�ݩ�
    int char1_hp=43;//����1��q
    int char1_atk=18;//����1����
    int char1_def=7;//����1���m
    float char1_pow=( char1_hp * 1.0 +  char1_atk  * 0.8 + char1_def * 0.5 - 50 ) * 6.5;//����1�w���j��
    printf("����1\n�W��:���\n");
    printf("�ݩ�:%-6c",char1_type);
    printf("��q:%d\n",char1_hp);
    printf("����:%-6d",char1_atk);
    printf("���m:%d\n",char1_def);
    printf("����w���j��:%.2f\n\n",char1_pow);

    //����2
    char char2_type='W';//����2�ݩ�
    int char2_hp=43;//����2��q
    int char2_atk=16;//����2����
    int char2_def=9;//����2���m
    float char2_pow=( char2_hp * 1.0 +  char2_atk  * 0.8 + char2_def * 0.5 - 50 ) * 6.5;//����2�w���j��
    printf("����2\n�W��:�w�w\n");
    printf("�ݩ�:%-6c",char2_type);
    printf("��q:%d\n",char2_hp);
    printf("����:%-6d",char2_atk);
    printf("���m:%d\n",char2_def);
    printf("����w���j��:%.2f\n\n",char2_pow);

    //����3
    char char3_type='A';//����3�ݩ�
    int char3_hp=45;//����3��q
    int char3_atk=19;//����3����
    int char3_def=5;//����3���m
    float char3_pow=( char3_hp * 1.0 +  char3_atk  * 0.8 + char3_def * 0.5 - 50 ) * 6.5;//����3�w���j��
    printf("����3\n�W��:���\n");
    printf("�ݩ�:%-6c",char3_type);
    printf("��q:%d\n",char3_hp);
    printf("����:%-6d",char3_atk);
    printf("���m:%d\n",char3_def);
    printf("����w���j��:%.2f\n\n",char3_pow);

    printf("�O�_�s�W����?(1.Yes/2.No)");
    int y_or_n;
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    int char4_all=char4_hp+char4_atk+char4_def;

    float char4_pow;
    scanf("%d",&y_or_n);
    //1.Yes
    if(y_or_n==1){
        printf("\n�s�W����\n�ݩ�:");
        scanf("%s",&char4_type);
        printf("��q:");
        scanf("%d",&char4_hp);
        printf("����:");
        scanf("%d",&char4_atk);
        printf("���m:");
        scanf("%d",&char4_def);
    }
    //2.No
    else if(y_or_n==2)
        printf("\n");
    //�D1�D2
    else{
        printf("��J���~\n");
        return 0;
    }
    char4_all=char4_hp+char4_atk+char4_def;
    //�ݩʥ��T �ƭȥ��T
    if(((char4_type=='F')||(char4_type=='W')||(char4_type=='G')||(char4_type=='A')||(char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a'))&&((40<=char4_hp<=50)&&(15<=char4_atk<=20)&&(5<=char4_def<=10)&&(65<=char4_all<=70))){
        printf("\n");
        printf("����4\n�W��:�ױб�\n");
        if(islower(char4_type))//�p�G���p�g
            printf("�ݩ�:%-6c",toupper(char4_type));//�ର�j�g
        else if(isupper(char4_type))//�p�G���j�g
            printf("�ݩ�:%-6c",char4_type);//����
        printf("��q:%d\n",char4_hp);
        printf("����:%-6d",char4_atk);
        printf("���m:%d\n",char4_def);
        printf("����w���j��:%.2f\n",( char4_hp * 1.0 +  char4_atk  * 0.8 + char4_def * 0.5 - 50 ) * 6.5);
        printf("\n");
    }
    //�ݩʿ��~ �ƭȥ��T
    else if(((char4_type!='F')||(char4_type!='W')||(char4_type!='G')||(char4_type!='A')||(char4_type!='f')||(char4_type!='w')||(char4_type!='g')||(char4_type!='a'))&&(char4_hp>=40 && char4_hp<=50 && char4_atk>=15 && char4_atk<=20 && char4_def<=10 && char4_def>=5 && char4_all<=70 && char4_all>=65)){
        printf("���~:�L���ݩ�\n");
        return 0;
    }
    //�ݩʥ��T �ƭȿ��~
    else if((char4_type=='F')||(char4_type=='W')||(char4_type=='G')||(char4_type=='A')||(char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a')){
        printf("���~:��O�ƭȦb���w�d��~\n");
        return 0;
    }
    //�ݩʿ��~ �ƭȿ��~
    else if((char4_type!='F')||(char4_type!='W')||(char4_type!='G')||(char4_type!='A')||(char4_type!='f')||(char4_type!='w')||(char4_type!='g')||(char4_type!='a')){
        printf("���~:�L���ݩ�\n���~:��O�ƭȦb���w�d��~\n");
        return 0;
    }
    printf("��ܥ��𨤦�:");
    int fir_atk;//����
    scanf("%d",&fir_atk);
    //�p�G��1 2 3 4
    if((fir_atk==1)||(fir_atk==2)||(fir_atk==3)||(fir_atk==4))
        printf("��ܫ�𨤦�:");
    //�D1 2 3 4
    else{
        printf("���~:�L������\n");
        return 0;
    }
    int sec_atk;//���
    scanf("%d",&sec_atk);
    //�p�G������𭫽�
    if(fir_atk==sec_atk){
        printf("���~:���i���ƿ��\n");
        return 0;
    //�p�G��𤣬�1 2 3 4
    }else if((sec_atk>4)||(sec_atk<=0)){
        printf("���~:�L������\n");
        return 0;
    //�p�G���L�H�W���D
    }else
        printf("\n���𨤦⬰%d�B��𨤦⬰%d",fir_atk,sec_atk);

    return 0;
}
