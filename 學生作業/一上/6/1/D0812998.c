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
    int  atk1_hp;
    int  atk1_atk;
    int  atk1_def;
    int  atk2_hp;
    int  atk2_atk;
    int  atk2_def;

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

            while((char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)){//��J���~���s��J
            	if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')//�����ݩʤ��ŦX����
					printf("���~:�L���ݩ�\n");
				if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)//�����O�d�򤣲ŦX����
				printf("���~:��O�d��b����d�򤧥~\n");
		   		printf("\n�s�W����\n");
            	printf("�ݩ�:");
            	scanf(" %c",&char4_type);
            	printf("��q:");
            	scanf("%d",&char4_hp);
            	printf("����:");
            	scanf("%d",&char4_atk);
            	printf("���m:");
            	scanf("%d",&char4_def);
			}

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
            while(fir>4){//���𨤦�n�p��4
                printf("���~:�L������\n");
                printf("\n��ܥ��𨤦�:");
                scanf("%d",&fir);
            }
            printf("��ܫ�𨤦�:");
            scanf("%d",&sec);
            while(sec>4){//��𨤦�n�p��4
                printf("���~:�L������\n");
                printf("\n��ܫ�𨤦�:");
                scanf("%d",&sec);
            }
            while(fir==sec){//���𨤦⤣�����𨤦�
                printf("���~:���i���ƿ��\n");
                printf("\n��ܥ��𨤦�:");
            	scanf("%d",&fir);
                while(fir>4){//���𨤦�n�p��4
                    printf("���~:�L������\n");
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&fir);
                }
                printf("��ܫ�𨤦�:");
                scanf("%d",&sec);
                while(sec>4){//��𨤦�n�p��4
                    printf("���~:�L������\n");
                    printf("\n��ܫ�𨤦�:");
                    scanf("%d",&sec);
                }
            }

            printf("���𬰨���%d�B��𬰨���%d\n",fir,sec);
            printf("�԰��}�l\n\n");
            if(fir==1){//�إ߼Ȧs
                atk1_hp = char1_hp;
                atk1_def = char1_def;
                atk1_atk = char1_atk;
            }else if(fir==2){
                atk1_hp = char2_hp;
                atk1_def = char2_def;
                atk1_atk = char2_atk;
            }else if(fir==3){
                atk1_hp = char3_hp;
                atk1_def = char3_def;
                atk1_atk = char3_atk;
            }else if(fir==4){
                atk1_hp = char4_hp;
                atk1_def = char4_def;
                atk1_atk = char4_atk;
            }
            if(sec==1){
                atk2_hp = char1_hp;
                atk2_def = char1_def;
                atk2_atk = char1_atk;
            }else if(sec==2){
                atk2_hp = char2_hp;
                atk2_def = char2_def;
                atk2_atk = char2_atk;
            }else if(sec==3){
                atk2_hp = char3_hp;
                atk2_def = char3_def;
                atk2_atk = char3_atk;
            }else if(sec==4){
                atk2_hp = char4_hp;
                atk2_def = char4_def;
                atk2_atk = char4_atk;
            }
            int hur1 = atk1_atk - atk2_def;
            int hur2 = atk2_atk - atk1_def;
            do{
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",fir,sec,hur1);
                printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                if(atk2_hp<=0){
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",sec,fir);
                    break;}
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",sec,fir,hur2);
                printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

            }while(0<atk1_hp&&0<atk2_hp);
            if(atk1_hp<=0){
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",fir,sec);
                break;
            }
            break;




        case(2):
            printf("\n��ܥ��𨤦�:");
            scanf("%d",&fir);
    		while(fir>4){//���𨤦�n�p��4
                printf("���~:�L������\n");
                printf("\n��ܥ��𨤦�:");
                scanf("%d",&fir);
            }
            printf("��ܫ�𨤦�:");
            scanf("%d",&sec);
            while(sec>4){//��𨤦�n�p��4
                printf("���~:�L������\n");
                printf("\n��ܫ�𨤦�:");
                scanf("%d",&sec);
            }
            while(fir==sec){//���𨤦⤣�����𨤦�
                    printf("���~:���i���ƿ��\n");
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&fir);
                while(fir>4){//���𨤦�n�p��4
                    printf("���~:�L������\n");
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&fir);
                }
                printf("��ܫ�𨤦�:");
                scanf("%d",&sec);
                while(sec>4){//��𨤦�n�p��4
                    printf("���~:�L������\n");
                    printf("\n��ܫ�𨤦�:");
                    scanf("%d",&sec);
                }
            }

            printf("���𬰨���%d�B��𬰨���%d\n",fir,sec);
            printf("�԰��}�l\n\n");
            if(fir==1){//�إ߼Ȧs
                atk1_hp = char1_hp;
                atk1_def = char1_def;
                atk1_atk = char1_atk;
            }else if(fir==2){
                atk1_hp = char2_hp;
                atk1_def = char2_def;
                atk1_atk = char2_atk;
            }else if(fir==3){
                atk1_hp = char3_hp;
                atk1_def = char3_def;
                atk1_atk = char3_atk;
            }else if(fir==4){
                atk1_hp = char4_hp;
                atk1_def = char4_def;
                atk1_atk = char4_atk;
            }
            if(sec==1){
                atk2_hp = char1_hp;
                atk2_def = char1_def;
                atk2_atk = char1_atk;
            }else if(sec==2){
                atk2_hp = char2_hp;
                atk2_def = char2_def;
                atk2_atk = char2_atk;
            }else if(sec==3){
                atk2_hp = char3_hp;
                atk2_def = char3_def;
                atk2_atk = char3_atk;
            }else if(sec==4){
                atk2_hp = char4_hp;
                atk2_def = char4_def;
                atk2_atk = char4_atk;
            }
            do{
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",fir,sec,hur1);
                printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                if(atk2_hp<=0){
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",sec,fir);
                    break;}
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",sec,fir,hur2);
                printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);
            }while(0<atk1_hp&&0<atk2_hp);
            if(atk1_hp<=0){
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",fir,sec);
                break;
            }
            break;

        default:
            while(choose>2){//��J���~���s��J
            	printf("��J���~\n");
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

                    while((char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')||(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)){
                        if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a')
                            printf("���~:�L���ݩ�\n");
                        if(15>char4_atk||char4_atk>20|40>char4_hp|char4_hp>50|5>char4_def|char4_def>10|65>(char4_hp+char4_atk+char4_def)|(char4_hp+char4_atk+char4_def)>70)
                        printf("���~:��O�d��b����d�򤧥~\n");
                        printf("\n�s�W����\n");
                        printf("�ݩ�:");
                        scanf(" %c",&char4_type);
                        printf("��q:");
                        scanf("%d",&char4_hp);
                        printf("����:");
                        scanf("%d",&char4_atk);
                        printf("���m:");
                        scanf("%d",&char4_def);
                    }

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
                    while(fir>4){//���𨤦�n�p��4
                        printf("���~:�L������\n");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&fir);
                    }
                    printf("��ܫ�𨤦�:");
                    scanf("%d",&sec);
                    while(sec>4){//��𨤦�n�p��4
                        printf("���~:�L������\n");
                        printf("\n��ܫ�𨤦�:");
                        scanf("%d",&sec);
                    }
                    while(fir==sec){//���𨤦⤣�����𨤦�
                        printf("���~:���i���ƿ��\n");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&fir);
                        while(fir>4){//���𨤦�n�p��4
                            printf("���~:�L������\n");
                            printf("\n��ܥ��𨤦�:");
                            scanf("%d",&fir);
                        }
                        printf("��ܫ�𨤦�:");
                        scanf("%d",&sec);
                        while(sec>4){//��𨤦�n�p��4
                            printf("���~:�L������\n");
                            printf("\n��ܫ�𨤦�:");
                            scanf("%d",&sec);
                        }
                    }
                    printf("���𬰨���%d�B��𬰨���%d\n",fir,sec);
                    printf("�԰��}�l\n\n");
                    if(fir==1){
                        atk1_hp = char1_hp;
                        atk1_def = char1_def;
                        atk1_atk = char1_atk;
                    }else if(fir==2){
                        atk1_hp = char2_hp;
                        atk1_def = char2_def;
                        atk1_atk = char2_atk;
                    }else if(fir==3){
                        atk1_hp = char3_hp;
                        atk1_def = char3_def;
                        atk1_atk = char3_atk;
                    }else if(fir==4){
                        atk1_hp = char4_hp;
                        atk1_def = char4_def;
                        atk1_atk = char4_atk;
                    }
                    if(sec==1){
                        atk2_hp = char1_hp;
                        atk2_def = char1_def;
                        atk2_atk = char1_atk;
                    }else if(sec==2){
                        atk2_hp = char2_hp;
                        atk2_def = char2_def;
                        atk2_atk = char2_atk;
                    }else if(sec==3){
                        atk2_hp = char3_hp;
                        atk2_def = char3_def;
                        atk2_atk = char3_atk;
                    }else if(sec==4){
                        atk2_hp = char4_hp;
                        atk2_def = char4_def;
                        atk2_atk = char4_atk;
                    }
                    int hur1 = atk1_atk - atk2_def;
                    int hur2 = atk2_atk - atk1_def;
                    do{
                        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",fir,sec,hur1);
                        printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                        if(atk2_hp<=0){
                            printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",sec,fir);
                            break;}
                        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",sec,fir,hur2);
                        printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

                    }while(0<atk1_hp&&0<atk2_hp);
                    if(atk1_hp<=0){
                        printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",fir,sec);
                        break;
                    }
                    break;




                case(2):
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&fir);
                    while(fir>4){//���𨤦�n�p��4
                        printf("���~:�L������\n");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&fir);
                    }
                    printf("��ܫ�𨤦�:");
                    scanf("%d",&sec);
                    while(sec>4){//��𨤦�n�p��4
                        printf("���~:�L������\n");
                        printf("\n��ܫ�𨤦�:");
                        scanf("%d",&sec);
                    }
                    while(fir==sec){//���𨤦⤣�����𨤦�
                        printf("���~:���i���ƿ��\n");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&fir);
                        while(fir>4){//���𨤦�n�p��4
                            printf("���~:�L������\n");
                            printf("\n��ܥ��𨤦�:");
                            scanf("%d",&fir);
                        }
                        printf("��ܫ�𨤦�:");
                        scanf("%d",&sec);
                        while(sec>4){//��𨤦�n�p��4
                            printf("���~:�L������\n");
                            printf("\n��ܫ�𨤦�:");
                            scanf("%d",&sec);
                        }
                    }

                    printf("���𬰨���%d�B��𬰨���%d\n",fir,sec);
                    printf("�԰��}�l\n\n");
                    if(fir==1){
                        atk1_hp = char1_hp;
                        atk1_def = char1_def;
                        atk1_atk = char1_atk;
                    }else if(fir==2){
                        atk1_hp = char2_hp;
                        atk1_def = char2_def;
                        atk1_atk = char2_atk;
                    }else if(fir==3){
                        atk1_hp = char3_hp;
                        atk1_def = char3_def;
                        atk1_atk = char3_atk;
                    }else if(fir==4){
                        atk1_hp = char4_hp;
                        atk1_def = char4_def;
                        atk1_atk = char4_atk;
                    }
                    if(sec==1){
                        atk2_hp = char1_hp;
                        atk2_def = char1_def;
                        atk2_atk = char1_atk;
                    }else if(sec==2){
                        atk2_hp = char2_hp;
                        atk2_def = char2_def;
                        atk2_atk = char2_atk;
                    }else if(sec==3){
                        atk2_hp = char3_hp;
                        atk2_def = char3_def;
                        atk2_atk = char3_atk;
                    }else if(sec==4){
                        atk2_hp = char4_hp;
                        atk2_def = char4_def;
                        atk2_atk = char4_atk;
                    }
                    do{
                        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",fir,sec,hur1);
                        printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp,sec,atk2_hp-=hur1);
                        if(atk2_hp<=0){
                            printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",sec,fir);
                            break;}
                        printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",sec,fir,hur2);
                        printf("����%d HP:%d ����%d HP:%d\n\n",fir,atk1_hp-=hur2,sec,atk2_hp);

                    }while(0<atk1_hp&&0<atk2_hp);
                    if(atk1_hp<=0){
                        printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",fir,sec);
                        break;
                    }
                    break;
                }

            }
    }


    return 0;
 }

