#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    //�D�禡
    int caser;//case

    char name1[10]="����";

    char name2[10]="���";
    char name3[10]="���d";
    char name4[10];
    //�W�l
    char type[5];
    type[1]='G';
    type[2]='A';
    type[3]='F';
    char char1type=type[1],char2type=type[2],char3type=type[3],char4type=type[4];
    //type
    int  atk[5];
    atk[1]=20;
    atk[2]=15;
    atk[3]=16;
    int  char1atk,char2atk,char3atk,char4atk;
    char1atk=atk[1],char2atk=atk[2],char3atk=atk[3],char4atk=atk[4];
    atk[4]=0;
    //atk
    int  hp[5];
    hp[1]=40;
    hp[2]=40;
    hp[3]=44;
    int  char1hp=hp[1],char2hp=hp[2],char3hp=hp[3],char4hp=hp[4];
    //hp
    int  def[5];
    def[1]=10;
    def[2]=10;
    def[3]=5;
    int  char1def=def[1],char2def=def[2],char3def=def[3],char4def=def[4];
    //def
    int  add;
    //yes or no
    int first,last;
    //���� ���
    int first_atk,first_def,last_atk,last_def,first_HP,last_HP,first_type,last_type,first2_HP,last2_HP;
    //�԰��j��


    while(caser)
    {
        //�}�l
        printf("case:(��J1~3)\n0:����\n1:�s�W/�ק﨤��4\n2:�C�X����\n3:�԰�\n");
        scanf("%d",&caser);
        if(caser==0)
            break;
        if(caser==2)
        {

            printf("����1\n"
                   //�L�X��r
                   "�W��:%s\n",name1);
            printf("�ݩ�:%c    ����:%d\n",type[1],atk[1]);
            printf("��q:%d   ���m:%d\n", hp[1],def[1]);
            printf("����w���j��:%.2f\n\n",((hp[1]*1)+(atk[1]*0.8)+(def[1]*0.5)-50)*6.5);

            printf("����2\n"
                   "�W��:%s\n",name2);
            printf("�ݩ�:%c    ����:%d\n",type[2],atk[2]);
            printf("��q:%d   ���m:%d\n",hp[2],def[2]);
            printf("����w���j��:%.2f\n\n",((hp[2]*1)+(atk[2]*0.8)+(def[2]*0.5)-50)*6.5);

            printf("����3\n"
                   "�W��:%s\n",name3);
            printf("�ݩ�:%c    ����:%d\n",type[3],atk[3]);
            printf("��q:%d   ���m:%d\n",hp[3],def[3]);
            printf("����w���j��:%.2f\n\n",((hp[3]*1)+(atk[3]*0.8)+(def[3]*0.5)-50)*6.5);
            if(atk[4]!=0)
            {
                printf("����4\n");
                printf("�W��:%s\n",name4);
                printf("�ݩ�:%c ����%d\n",type[4],atk[4]);
                printf("��q:%d ���m%d\n",hp[4],def[4]);
                printf("����w���j��:%.2f\n",((hp[4]*1)+(atk[4]*0.8)+(def[4]*0.5)-50)*6.5);
                printf("\n");
            }
            continue;
        }
//    for(add; add>2;)
//    {
//        printf("�O�_�s�W����(1.yes 2.no)?");
//        scanf("%d",&add);
//        getchar();

//        if (add==1)
//        {
//
//            for(; ;)
        if(caser==1)
        {
            for(;;)
            {
                int add;
                printf("�w�g�s�W����?1.yes 2.no\n");
                scanf("%d",&add);
                if(add==2)
                    printf("�s�W����\n");
                //�s�W����
                if(add==1)
                    printf("�ק﨤��");
                for(;;){
                    printf("����W:");
                    scanf("%s",&name4);
                    printf("�ݩ�:");
                    scanf("%s",&type[4]);
                    getchar();
                    printf("����:");
                    scanf("%d",&atk[4]);
                    getchar();
                    printf("��q:");
                    scanf("%d",&hp[4]);
                    getchar();
                    printf("���m:");
                    scanf("%d",&def[4]);

                    getchar();
                    if (type[4] =='F' || type[4] =='f' || type[4] =='W' || type[4] =='w' ||//�ݩʥH�~
                            type[4] =='G' || type[4] =='g' || type[4] =='A' || type[4] =='a')
                    {
                        if (hp[4]<40 || hp[4]>50||//�ƭȭ���
                                atk[4]<15||atk[4]>20||
                                def[4]<5||def[4]>10)
                        {
                            printf("���~:��O�ƭȦb����~\n");
                            continue;

                        }
                        if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                        {

                            printf("���~:��O�ƭȦb����~\n");
                            continue;
                        }
                    }
                    else                            //�ݩʥH�~
                    {

                        if (hp[4]<40 || hp[4]>50||//�ƭȭ���
                                atk[4]<15||atk[4]>20||
                                def[4]<5||def[4]>10)
                        {
                            if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                            {
                                printf("�L���ݩ�\n");
                                printf("���~:��O�ƭȦb����~\n");
                                continue;
                            }

                        }
                        printf("�L���ݩ�\n");//�ݩʿ��~
                        continue;
                    }
                    if (type[4]=='f')//�j�p�g�ഫ
                    {
                        type[4]='F';
                    }
                    else if (type[4]=='w')
                    {
                        type[4]='W';
                    }
                    else if (type[4]=='g')
                    {
                        char4type='G';

                    }
                    else if (char4type=='a')
                    {
                        char4type='A';
                    }
                    if (hp[4]<40 || hp[4]>50||//�ƭȭ���
                            atk[4]<15||atk[4]>20||
                            def[4]<5||def[4]>10)
                    {
                        printf("���~:��O�ƭȦb����~\n");
                        continue;
                    }
                    if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                    {

                        printf("���~:��O�ƭȦb����~\n");
                        continue;
                    }






                    printf("\n");
                    printf("����4\n");
                    printf("�W��:%s\n",name4);
                    printf("�ݩ�:%c ����%d\n",type[4],atk[4]);
                    printf("��q:%d ���m%d\n",hp[4],def[4]);
                    printf("����w���j��:%.2f\n",((hp[4]*1)+(atk[4]*0.8)+(def[4]*0.5)-50)*6.5);
                    printf("\n");
                    break;
                }
                break;
            }
        }
        if(caser==3)
        {
            if (atk[4]==0) //��J2�����u
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
            else if(atk[4]!=0)
            {
                for(;;)
                {
                    printf("��J���𨤦�:\n");
                    scanf("%d",&first);
                    if (first!=1&&first!=2&&first!=3&&first!=4)
                    {
                        printf("���~:���⤣�s�b\n");
                        continue;
                    }



                    for(; ;)
                    {

                        printf("��J��𨤦�:\n");
                        scanf("%d",&last);
                        if (last!=1&&last!=2&&last!=3&&last!=4)
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

                    break;
                }
            }







            else
            {
                printf("��J���~\n");
                continue;
            }




            printf("���𬰨���%d�B��𬰨���%d\n",first,last);
            printf("�԰��}�l\n");
            for(; ;)
            {
                if(first==1)
                {
                    first_atk=atk[1],first_def=def[1],first_HP=hp[1],first_type=type[1];
                }
                if(first==2)
                {
                    first_atk=atk[2],first_def=def[2],first_HP=hp[2],first_type=type[2];;
                }
                if(first==3)
                {
                    first_atk=atk[3],first_def=def[3],first_HP=hp[3],first_type=type[3];;
                }
                if(first==4)
                {
                    first_atk=atk[4],first_def=def[4],first_HP=hp[4],first_type=type[4];;
                }
                if(last==1)
                {
                    last_atk=atk[1],last_def=def[1],last_HP=hp[1],last_type=type[1];
                }
                if(last==2)
                {
                    last_atk=atk[2],last_def=def[2],last_HP=hp[2],last_type=type[2];
                }
                if(last==3)
                {
                    last_atk=atk[3],last_def=def[3],last_HP=hp[3],last_type=type[3];
                }
                if(last==4)
                {
                    last_atk=atk[4],last_def=def[4],last_HP=hp[4],last_type=type[4];
                }

                first2_HP=first_HP/2;
                last2_HP=last_HP/2;
                if(first_type=='W'&&last_type=='F')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                 if(first_type=='F'&&last_type=='A')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                     if(first_type=='A'&&last_type=='G')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                     if(first_type=='G'&&last_type=='W')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                if(first_type=='F'&&last_type=='W')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                if(first_type=='A'&&last_type=='F')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                    if(first_type=='G'&&last_type=='A')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                    if(first_type=='W'&&last_type=='G')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;


                while(first_HP>0&&last_HP>0)        //�԰��j��
                {


                    if(first_HP<first2_HP)
                        first_atk=first_atk*1.2;
                    if(last_HP<last2_HP)
                        last_atk=last_atk*1.2;
                    printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",first,last,first_atk-last_def);
                    last_HP-=first_atk-last_def;
                    printf("����%d HP:%d ����%d HP:%d\n",first,first_HP,last,last_HP);


                    printf("\n");
                    if(last_HP<=0)
                    {
                        printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",last,first);
                        return 0;
                         //��ӧY����
                    }
                    printf("����%d �� ����%d �o�ʧ����y��%d�ˮ`\n",last,first,last_atk-first_def);
                    first_HP-=last_atk-first_def;
                    printf("����%d HP:%d ����%d HP:%d\n",first,first_HP,last,last_HP);
                    printf("\n");
                     if(first_HP<=0)
                    {
                        printf("����%d���h�԰���O\n�԰�����\n\n����%d���\n",first,last);
                        return 0;
                           //��ӧY����
                    }



                }


            }


        }
        else
            continue;
        return 0;
    }//����

}
