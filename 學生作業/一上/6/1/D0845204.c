#include<stdio.h>
int main()
{
    char char1_type='F';
    int  char1_hp=42;
    int  char1_atk=18;
    int  char1_def=9;
    float char1_power=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    char char2_type='W';
    int  char2_hp=47;
    int  char2_atk=15;
    int  char2_def=6;
    float char2_power=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    char char3_type='G';
    int  char3_hp=46;
    int  char3_atk=19;
    int  char3_def=5;
    float char3_power=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    char char4_type;
    int  char4_hp;
    int  char4_atk;
    int  char4_def;
    int faid,faatk,fadef,fahp,laid,laatk,ladef,lahp;
    printf("����1\n"
           "�W��:��ù��\n"
           "�ݩ�:%-6c    ��q:%-6d\n"
           "����:%-6d    ���m:%-6d\n"
           "����j�׹w��:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,char1_power);
    printf("����2\n"
           "�W��:���R\n"
           "�ݩ�:%-6c    ��q:%-6d\n"
           "����:%-6d    ���m:%-6d\n"
           "����j�׹w��:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,char2_power);
    printf("����3\n"
           "�W��:����\n"
           "�ݩ�:%-6c    ��q:%-6d\n"
           "����:%-6d    ���m:%-6d\n"
           "����j�׹w��:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,char3_power);

    int Role,Fa,La;//�ɩw�e���
    printf("�O�_�s�W����(1.Yes/2.No)? ");
    scanf("%d",&Role);
    while(Role!=1 && Role!=2){
        printf("��J���~\n�O�_�s�W����(1.Yes/2.No)?");
        scanf("%d",&Role);
    }
    switch(Role){//�ǲߦp��ϥ�switch
        case 1:
            printf("\n�s�W����4\n");
            printf("�ݩ�:");
            scanf (" %c",&char4_type);
            if(isupper(char4_type)==0);
                char4_type=toupper(char4_type);
            printf("��q:");
            scanf ("%d",&char4_hp);
            printf("����:");
            scanf ("%d",&char4_atk);
            printf("���m:");
            scanf ("%d",&char4_def);
            float char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
            while(char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'){
                printf("���~:�L���ݩ�\n");
                if(char4_hp<40|char4_hp>50|char4_atk<15|char4_atk>20|char4_def<5|char4_def>10|(char4_hp+char4_atk+char4_def)<65|(char4_hp+char4_atk+char4_def)>70)
                    printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʿ��ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�ݩ�:");
                    scanf (" %c",&char4_type);
                    if(isupper(char4_type)==0);
                        char4_type=toupper(char4_type);
                    printf("��q:");
                    scanf ("%d",&char4_hp);
                    printf("����:");
                    scanf ("%d",&char4_atk);
                    printf("���m:");
                    scanf ("%d",&char4_def);
                    float char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;

            }
            while(char4_hp<40|char4_hp>50|char4_atk<15|char4_atk>20|char4_def<5|char4_def>10|(char4_hp+char4_atk+char4_def)<65|(char4_hp+char4_atk+char4_def)>70){
                    printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʹ�ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�ݩ�:");
                    scanf (" %c",&char4_type);
                    if(isupper(char4_type)==0);
                        char4_type=toupper(char4_type);
                    printf("��q:");
                    scanf ("%d",&char4_hp);
                    printf("����:");
                    scanf ("%d",&char4_atk);
                    printf("���m:");
                    scanf ("%d",&char4_def);
                    float char4_power=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
            }
            printf("\n����4\n�W��:�ۭq����\n"
                "�ݩ�:%-6c   ��q:%-6d\n"
                "����:%-6d   ���m:%-6d\n"
                "����j�׹w��:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,char4_power);

            printf("\n��ܥ��𨤦�:");
            while(scanf("%d",&Fa) && (Fa>4 || Fa<1)){//���N�@�����אּ��
                printf("���~:�L������");
                printf("\n��ܥ��𨤦�:");
                scanf("%d",&Fa);

            }
            printf("��ܫ�𨤦�:");
            while(scanf("%d",&La) && (La>4||La<1)){
                printf("���~:�L������\n");
                printf("��ܫ�𨤦�:");
                scanf(" %d",&La);

            }
            while(Fa==La){
                printf("���~:���i���ƿ��");
                scanf("%d",&Fa);
                scanf("%d",&La);

            }
            printf("\n���𬰨���%d�B��𬰨���%d\n\n",Fa,La);

            printf("�԰��}�l\n\n");
            if(Fa==1){//�ݬݬO�n���[�åB���������O(����)
            faatk=18;
            fadef=9;
            fahp=42;
            }
            if(Fa==2){
            faatk=15;
            fadef=6;
            fahp=47;
            }
            if(Fa==3){
            faatk=19;
            fadef=5;
            fahp=46;
            }
            if(Fa==4){
            faatk=char4_atk;
            fadef=char4_def;
            fahp=char4_hp;
            }
            if(La==1){//�ݬݬO�n���[�åB���������O(���)
            laatk=18;
            ladef=9;
            lahp=42;
            }
            if(La==2){
            laatk=15;
            ladef=6;
            lahp=47;
            }
            if(La==3){
            laatk=19;
            ladef=5;
            lahp=46;
            }
            if(La==4){
            laatk=char4_atk;
            ladef=char4_def;
            lahp=char4_hp;
            }
            int fadmg=faatk-ladef,ladmg=laatk-fadef;
            while(fahp>=0 && lahp>=0){//�}�l���[
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",Fa,La,fadmg,Fa,fahp,La,lahp-fadmg);
                lahp=lahp-fadmg;
                if(fahp<=0||lahp<=0){//���[�Φ�������
                    break;
                }
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",La,Fa,ladmg,Fa,fahp,La,fahp-ladmg);
                fahp=fahp-ladmg;
            }
            if(fahp>>lahp){//��Ӫ�����
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",La,Fa);
            }
            if(lahp>>fahp){
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",Fa,La);
            }
            break;
        case 2:
            printf("\n��ܥ��𨤦�:");//�Pcase1�u�O�֤F�@�Ө���
            scanf ("%d",&Fa);
            if (Fa>3){
                printf("���~:�L������");
                break;
            }
            printf("��ܫ�𨤦�:");
            scanf ("%d",&La);
            if (La>3){
                printf("���~:�L������");
                break;
            }
            if (Fa==La){
                printf("���~:���i���ƿ��");
                break;
            }
            printf("\n���𬰨���%d�B��𬰨���%d\n",Fa,La);
            printf("�԰��}�l\n\n");
            if(Fa==1){
            faatk=18;
            fadef=9;
            fahp=42;
            }
            if(Fa==2){
            faatk=15;
            fadef=6;
            fahp=47;
            }
            if(Fa==3){
            faatk=19;
            fadef=5;
            fahp=46;
            }

            if(La==1){
            laatk=18;
            ladef=9;
            lahp=42;
            }
            if(La==2){
            laatk=15;
            ladef=6;
            lahp=47;
            }
            if(La==3){
                laatk=19;
                ladef=5;
                lahp=46;
            }

            while(fahp>=0 && lahp>=0){
                int fadmg=faatk-ladef,ladmg=laatk-fadef;
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",Fa,La,fadmg,Fa,fahp,La,lahp-fadmg);
                lahp=lahp-fadmg;
                if(fahp<=0||lahp<=0){
                    break;
                }
                printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",La,Fa,ladmg,Fa,fahp,La,fahp-ladmg);
                fahp=fahp-ladmg;
            }
            if(fahp>>lahp){
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",La,Fa);
            }
            if(lahp>>fahp){
                printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",Fa,La);
            }
            break;
        default:
            break;
    }
    return 0;//����
}

