#include <stdio.h>
#include<string.h>

int main(){
//�ŧi�ܼ�
    char Char1_name[21]="�ǥ��t",Char2_name[21]="�p���s",Char3_name[21]="�p����",Char4_name[21];
    char type[4]={'W','A','G'};
    int atk[4]={15,20,15,-1};
    int hp[4]={50,40,45,-1};
    int def[4]={5,8,10,-1};

//�ˬd�ܼ�
    int Add,Char_num=3,Char_frist,Char_last;
    int case_num=5,is_Char4_exist=0;
    int is_nf1=0,is_nf2=0,is_ntf=0,is_nf3=0,is_nf4=0,is_nf5=0;
    while(1){
        printf("1.�s�W�έק﨤��\n");
        printf("2.��ܩҦ�������\n");
        printf("3.�԰�\n");
        printf("0.�����C��\n");
        printf("�п��:");
        scanf("%d",&case_num);
        printf("\n");
        switch(case_num){
            case 1:
                while(is_nf2==0){
                    is_nf2=1;
                    if(is_Char4_exist==0){
                        printf("�s�W����\n");
                    }
                    else
                        printf("�ק�s�W����\n");
                    printf("�W��:");
                    scanf("%s",&Char4_name);
                    getchar();
                    printf("�ݩ�:");
                    scanf("%c",&type[3]);
                    getchar();
                    printf("��q:");
                    scanf("%d",&hp[3]);
                    getchar();
                    printf("����:");
                    scanf("%d",&atk[3]);
                    getchar();
                    printf("���m:");
                    scanf("%d",&def[3]);
                    getchar();
                    if(type[3]!='F'&&type[3]!='f'&&type[3]!='W'&&type[3]!='w'&&
                        type[3]!='G'&&type[3]!='g'&&type[3]!='A'&&type[3]!='a'){
                        printf("���~:�L���ݩ�\n");
                        is_nf2=0;//���ưj��(2)
                        is_ntf=1;//�ݩʦ���
                        }
                    //�p�g���j�g
                    else if(type[3]=='f'){
                        type[3]='F';
                    }
                    else if(type[3]=='w'){
                        type[3]='W';
                    }
                    else if(type[3]=='g'){
                        type[3]='G';
                    }
                    else if(type[3]=='a'){
                        type[3]='A';
                    }
                    //�ˬd�ƭ�
                    int Char4_all = hp[3]+atk[3]+def[3];
                    if((hp[3]<40||hp[3]>50)||(atk[3]<15||atk[3]>20)||
                    (def[3]<5||def[3]>10)||(Char4_all<65||Char4_all>70)){
                        printf("���~:��O�ƭȦb����d�򤧥~\n\n");
                        is_nf2=0;//���ưj��(2)
                        is_ntf=0;//�s�����,����Ĳ�o�����J�u���ݩ�flag
                    }
                    //�����J�u���ݩ�,��\n���L-flag
                    if(is_ntf==1){
                        printf ("\n");
                    }
                }
                is_nf2=0;
                printf ("\n");
                printf("����4 \n");
                printf("�W��:%s \n",Char4_name);
                printf("�ݩ�:%c    ����:%d  \n",type[3],atk[3]);
                printf("��q:%d   ���m:%d  \n",hp[3],def[3]);
                printf("�j�׹w��:%.2f\n",( hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                is_Char4_exist=1;
                Char_num=4;
                break;
            case 2:
                printf("����1 \n");
                printf("�W��:%s \n",Char1_name);
                printf("�ݩ�:%c    ����:%d  \n",type[0],atk[0]);
                printf("��q:%d   ���m:%d  \n",hp[0],def[0]);
                printf("�j�׹w��:%.2f\n",( hp[0] * 1.0 + atk[0] * 0.8 + def[0] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                printf("����2 \n");
                printf("�W��:%s \n",Char2_name);
                printf("�ݩ�:%c    ����:%d  \n",type[1],atk[1]);
                printf("��q:%d   ���m:%d  \n",hp[1],def[1]);
                printf("�j�׹w��:%.2f\n",( hp[1] * 1.0 + atk[1] * 0.8 + def[1] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                printf("����3 \n");
                printf("�W��:%s \n",Char3_name);
                printf("�ݩ�:%c    ����:%d  \n",type[2],atk[2]);
                printf("��q:%d   ���m:%d  \n",hp[2],def[2]);
                printf("�j�׹w��:%.2f\n",( hp[2] * 1.0 + atk[2] * 0.8 + def[2] * 0.5 - 50 ) * 6.5);
                printf ("\n");
                if(is_Char4_exist==1){
                    printf ("\n");
                    printf("����4 \n");
                    printf("�W��:%s \n",Char4_name);
                    printf("�ݩ�:%c    ����:%d  \n",type[3],atk[3]);
                    printf("��q:%d   ���m:%d  \n",hp[3],def[3]);
                    printf("�j�׹w��:%.2f\n",( hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50 ) * 6.5);
                    printf ("\n");
                }
                break;
            case 3:
                while(is_nf5==0){
                    is_nf5=1;//�����ưj��(5)
                    //���������~���Ӫ��j��(3)
                    while(is_nf3==0){
                        is_nf3=1;//�����ưj��(3)
                        printf("��ܥ��𨤦�: ");
                        scanf("%d",&Char_frist);
                        if(Char_frist<=0||Char_frist>Char_num){
                            printf("���~:�L������\n");
                            is_nf3=0;//���ưj��(3)
                        }
                    }
                    //��������~���Ӫ��j��(4)
                    while(is_nf4==0){
                        is_nf4=1;//�����ưj��(4)
                        printf("��ܫ�𨤦�: ");
                        scanf("%d",&Char_last);
                        if(Char_last<=0||Char_last>Char_num){
                            printf("���~:�L������\n");
                            is_nf4=0;//���ưj��(4)
                        }
                    }
                    if(Char_last==Char_frist){
                        printf("���~:���i���ƿ��\n\n");
                        is_nf5=0;//���ưj��(5)
                        is_nf3=0;//���s�j��(3)
                        is_nf4=0;//���s�j��(4)
                    }
                }
                printf("\n���𬰨���%d�B��𬰨���%d\n",Char_frist,Char_last);
                //
                int FA_atk,FA_hp,FA_def;//�ŧi����ƭ�
                int LA_atk,LA_hp,LA_def;//�ŧi���ƭ�
                FA_atk=atk[Char_frist-1];
                FA_hp=hp[Char_frist-1];
                FA_def=def[Char_frist-1];
                LA_atk=atk[Char_last-1];
                LA_hp=hp[Char_last-1];
                LA_def=def[Char_last-1];
                //�ݩʭ��v
                double FA_attX=1,LA_attX=1,FAblood=1,LAblood=1;
                if(type[Char_frist-1]=='W'||type[Char_last-1]=='F'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='F'||type[Char_last-1]=='A'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='A'||type[Char_last-1]=='G'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                if(type[Char_frist-1]=='G'||type[Char_last-1]=='W'){
                    FA_attX=1.2;
                    LA_attX=0.8;
                }
                //
                if(type[Char_frist-1]=='F'&&type[Char_last-1]=='W'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='A'&&type[Char_last-1]=='F'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='G'&&type[Char_last-1]=='A'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                if(type[Char_frist-1]=='W'&&type[Char_last-1]=='G'){
                    FA_attX=0.8;
                    LA_attX=1.2;
                }
                int FAfull=hp[Char_frist-1];
                int LAfull=hp[Char_last-1];
                //
                double demage;
                int is_whowin,winner,loser,demage1;//�ŧi�ˮ`,�ֳ�flag,�ӧQ��,���Ѫ�
                printf("�԰��}�l\n\n");
                while(1){
                    if(FA_hp<FAfull/2){
                        FAblood=1.2;
                    }
                    demage = FA_atk*FA_attX*FAblood - LA_def;
                    demage1=demage;
                    LA_hp -= demage;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",Char_frist,Char_last,demage1);
                    printf("����%d HP: %d\t����%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
                    if(LA_hp<=0){
                        is_whowin=1;//�����
                        break;//���X�j��(6)
                    }
                    if(LA_hp<LAfull/2){
                        LAblood=1.2;
                    }
                    demage = LA_atk*LA_attX*LAblood - FA_def;
                    demage1=demage;
                    FA_hp -= demage;
                    printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",Char_last,Char_frist,demage1);
                    printf("����%d HP: %d\t����%d HP:%d\n\n",Char_frist,FA_hp,Char_last,LA_hp);
                    if(FA_hp<=0){
                        is_whowin=0;//����
                        break;//���X�j��(6)
                    }
                }
                if(is_whowin==1){
                    winner=Char_frist;
                    loser=Char_last;
                }
                else{
                    winner=Char_last;
                    loser=Char_frist;
                }
                //��ܳӱ�
                printf("����%d ���h�԰���O\n",loser);
                printf("�԰�����\n\n");
                printf("����%d ���\n\n",winner);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("��J���~\n\n");
                break;
        }
    }
}

