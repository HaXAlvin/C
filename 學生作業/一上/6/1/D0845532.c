#include<stdio.h>//���Y��
int main()
{
    //�D�禡
    char char1type='G',char2type='A',char3type='F',char4type;//type
    int  char1atk=20,char2atk=15,char3atk=16,char4atk;//atk
    int  char1hp=40,char2hp=40,char3hp=44,char4hp;//hp
    int  char1def=10,char2def=10,char3def=5,char4def;//def
    int  add;//yes or no
    int first,last;//���� ���
    int first_atk,first_def,last_atk,last_def,first_HP,last_HP;//�԰��j��

    printf("����1\n"//�L�X��r
           "�W��:���\n");
    printf("�ݩ�:G    ����:20\n",char1type,char1atk);
    printf("��q:40   ���m:10\n", char2type,char2atk);
    printf("����w���j��:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);

    printf("����2\n"
           "�W��:�֥�\n");
    printf("�ݩ�:A    ����:15\n",char2type,char2atk);
    printf("��q:40   ���m:10\n",char2hp,char2def);
    printf("����w���j��:%.2f\n\n",((char2hp*1)+(char2atk*0.8)+(char2def*0.5)-50)*6.5);

    printf("����3\n"
           "�W��:�紵\n");
    printf("�ݩ�:F    ����:16\n",char3type,char3atk);
    printf("��q:44   ���m:5\n",char3hp,char3def);
    printf("����w���j��:%.2f\n\n",((char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50)*6.5);
    for(add; ;)
    {
        printf("�O�_�s�W����(1.yes 2.no)?");
        scanf("%d",&add);
        getchar();

        if (add==1)
        {

            for(; ;)
            {
                printf("�s�W����\n");//�s�W����
                printf("�ݩ�:");
                scanf("%c",&char4type);
                getchar();
                printf("����:");
                scanf("%d",&char4atk);
                getchar();
                printf("��q:");
                scanf("%d",&char4hp);
                getchar();
                printf("���m:");
                scanf("%d",&char4def);
                getchar();
                if (char4type =='F' || char4type =='f' || char4type =='W' || char4type =='w' ||//�ݩʥH�~
                        char4type =='G' || char4type =='g' || char4type =='A' || char4type =='a')
                {
                    if (char4hp<40 || char4hp>50||//�ƭȭ���
                            char4atk<15||char4atk>20||
                            char4def<5||char4def>10)
                    {
                        printf("���~:��O�ƭȦb����~\n");
                        continue;

                    }
                    if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70)
                    {
                        printf("��q:%d ���m%d\n",char4hp,char4def);
                        printf("����w���j��:%.2f\n",((char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50)*6.5);
                        printf("���~:��O�ƭȦb����~\n");
                        continue;
                    }
                }
                else                            //�ݩʥH�~
                {

                    if (char4hp<40 || char4hp>50||//�ƭȭ���
                            char4atk<15||char4atk>20||
                            char4def<5||char4def>10)
                    {
                        if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70)
                        {
                            printf("�L���ݩ�\n");
                            printf("���~:��O�ƭȦb����~\n");
                            continue;
                        }

                    }
                    printf("�L���ݩ�\n");//�ݩʿ��~
                    continue;
                }
                if (char4type=='f')//�j�p�g�ഫ
                {
                    char4type='F';
                }
                else if (char4type=='w')
                {
                    char4type='W';
                }
                else if (char4type=='g')
                {
                    char4type='G';

                }
                else if (char4type=='a')
                {
                    char4type='A';
                }
                if (char4hp<40 || char4hp>50||//�ƭȭ���
                        char4atk<15||char4atk>20||
                        char4def<5||char4def>10)
                {
                    printf("���~:��O�ƭȦb����~\n");
                    continue;
                }
                if ((char4def+char4atk+char4hp)<65||(char4def+char4atk+char4hp)>70)
                {

                    printf("���~:��O�ƭȦb����~\n");
                    continue;
                }
                break;
            }
            printf("\n");

            printf("��q:%d ���m%d\n",char4hp,char4def);
            printf("����w���j��:%.2f\n",((char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50)*6.5);
            printf("\n");
            printf("����4\n");
            printf("�W��:�ۭq����\n");
            printf("�ݩ�:%c ����%d\n",char4type,char4atk);
            printf("��q:%d ���m%d\n",char4hp,char4def);
            printf("����w���j��:%.2f\n",((char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50)*6.5);
            printf("\n");
            for(;;)
            {
                printf("��J���𨤦�:\n");
                scanf("%d",&first);
                if (first!=1&&first!=2&&first!=3)
                {
                    printf("���~:���⤣�s�b\n");
                    continue;
                }


                {
                    for(; ;)
                    {

                        printf("��J��𨤦�:\n");
                        scanf("%d",&last);
                        if (last!=1&&last!=2&&last!=3)
                        {
                            printf("���~:���⤣�s�b\n");
                            continue;
                        }

                        if (first==last)
                        {
                            printf("���~:���i���ƿ��\n");
                            continue;
                        }
                        break;
                    }
                }
                break;
            }



        }

        else if (add==2) //��J2�����u
        {
            for(;;)
            {
                printf("��J���𨤦�:\n");
                scanf("%d",&first);
                if (first!=1&&first!=2&&first!=3)
                {
                    printf("���~:���⤣�s�b\n");
                    continue;
                }


                {
                    for(; ;)
                    {

                        printf("��J��𨤦�:\n");
                        scanf("%d",&last);
                        if (last!=1&&last!=2&&last!=3)
                        {
                            printf("���~:���⤣�s�b\n");
                            continue;
                        }

                        if (first==last)
                        {
                            printf("���~:���i���ƿ��\n");
                            continue;
                        }
                        break;
                    }
                }
                break;
            }

        }

        else
        {
            printf("��J���~\n");
            continue;
        }
        break;

    }
    printf("���𬰨���%d�B��𬰨���%d\n",first,last);
    printf("�԰��}�l\n");
    for(; ;)
    {
        if(first==1)
        {
            first_atk=char1atk,first_def=char1def,first_HP=char1hp;
        }
        if(first==2)
        {
            first_atk=char2atk,first_def=char2def,first_HP=char2hp;
        }
        if(first==3)
        {
            first_atk=char3atk,first_def=char3def,first_HP=char3hp;
        }
        if(first==4)
        {
            first_atk=char4atk,first_def=char4def,first_HP=char4hp;
        }
        if(last==1)
        {
            last_atk=char1atk,last_def=char1def,last_HP=char1hp;
        }
        if(last==2)
        {
            last_atk=char2atk,last_def=char2def,last_HP=char2hp;
        }
        if(last==3)
        {
            last_atk=char3atk,last_def=char3def,last_HP=char3hp;
        }
        if(last==4)
        {
            last_atk=char4atk,last_def=char4def,last_HP=char4hp;
        }

        while(first_HP>0&&last_HP>0)        //�԰��j��
        {
            printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",first,last,first_atk-last_def);
            last_HP-=first_atk-last_def;
            printf("����%d HP:%d ����%d HP:%d\n",first,first_HP,last,last_HP);

            printf("\n");
            if(last_HP<=0)
            {
                printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",last,first);
                return 0; //��ӧY����
            }
            printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",last,first,last_atk-first_def);
            first_HP-=last_atk-first_def;
            printf("����%d HP:%d ����%d HP:%d\n",first,first_HP,last,last_HP);
            printf("\n");
            if(first_HP<=0)
            {
                printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",first,last);
                return 0;   //��ӧY����
            }

        }

    };
    return 0;//����

}
