 #include<stdio.h>
 int main()
 {
    char char1_type = 'F';
    int  char1_hp= 45;
    int  char1_atk= 16;
    int  char1_def= 5;
    float  char1_power=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5 -50)*6.5;
    char char2_type = 'A';
    int  char2_hp= 40;
    int  char2_atk= 20;
    int  char2_def= 8;
    float  char2_power=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5 -50)*6.5;
    char char3_type = 'G';
    int  char3_hp = 50;
    int  char3_atk = 16;
    int  char3_def = 5;
    float  char3_power=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5 -50)*6.5;
    char char4_type;
    int  char4_hp;
    int  char4_atk;
    int  char4_def;

    printf("����1\n"
            "�W�١G���ʧ�\n"
            "�ݩʡG%-6c    �����G%-6d\n"
            "��q�G%-6d    ���m�G%-6d\n"
            "����j�׹w��:%.2f\n",char1_type,char1_atk,char1_hp,char1_def,char1_power);
    printf("����2\n"
            "�W��:���ʤ�\n"
            "�ݩʡG%-6c    �����G%-6d\n"
            "��q�G%-6d    ���m�G%-6d\n"
            "����j�׹w��:%.2f\n",char2_type,char2_atk,char2_hp,char2_def,char2_power);
    printf("����3\n"
            "�W�١G�Ѯv�藍�_�ڤ��Ӫ��A���W�l\n"
            "�ݩʡG%-6c    �����G%-6d\n"
            "��q�G%-6d    ���m�G%-6d\n"
            "����j�׹w��:%.2f\n",char3_type,char3_atk,char3_hp,char3_def,char3_power);

    int choose,fir,sec;
        printf("\n�O�_�s�W����(1.Yes/2.No)? ");
        scanf("%d",&choose);
    switch(choose){
        case(1):
            printf("\n�s�W����\n");
            printf("�ݩ�:");
            scanf(" %c",&char4_type);
            printf("��q:");
            scanf("%d",&char4_hp);
            printf("����:");
            scanf("%d",&char4_atk);
            printf("���m:");
            scanf("%d",&char4_def);
            if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){//����4�ݩʤ��ŦX����
                printf("���~:�L���ݩ�\n");
                if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70){//����4�ƭȤ��ŦX����
                    printf("���~:��O�d��b����d�򤧥~\n");}
                    break;}
            if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70){//����4�ƭȤ��ŦX����
                printf("���~:��O�d��b����d�򤧥~\n");
                break;}
            float  char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5 -50)*6.5;
            if(isupper(char4_type)==0){//�O�_���j�g�r��
                char4_type=toupper(char4_type);//�ഫ���j�g�r��
            }
            printf("\n����4\n�W��:�ۭq����\n"
            "�ݩ�:%-6c    ����:%-6d\n"
            "��q:%-6d    ���m:%-6d\n\n"
            "����j�׹w��:%.2f\n",char4_type,char4_atk,char4_hp,char4_def,char4_power);

            printf("\n��ܥ��𨤦�:");
            scanf("%d",&fir);
            if(fir>4){//���𨤦�n�p��4
                printf("���~:�L������\n");
                break;}
            printf("��ܫ�𨤦�:\n");
            scanf("%d",&sec);
            if(sec>4){//��𨤦�n�p��4
                printf("���~:�L������\n");
                break;}
            if(fir==sec){//���𨤦⤣�����𨤦�
                printf("���~:���i���ƿ��\n");
                break;}
            printf("���𬰨���%d�B��𬰨���%d\n",fir,sec);
                break;
        case(2):
            printf("\n��ܥ��𨤦�:");
            scanf("%d",&fir);
            if(fir>3){//���𨤦�n�p��3
                printf("���~:�L������\n");
                break;}
            printf("��ܫ�𨤦�:");
            scanf("%d",&sec);
            if(sec>3){//��𨤦�n�p��3
                printf("���~:�L������\n");
                break;}
            if(fir==sec){//���𨤦⤣�����𨤦�
                printf("���~:���i���ƿ��\n");
                break;}
            printf("\n���𬰨���%d�B��𬰨���%d\n",fir,sec);
            break;
        default:
            printf("��J���~\n");
            break;
    }


     return 0;
 }
