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
    switch(Role){//�ǲߦp��ϥ�switch
        case 1:
            printf("�s�W����4\n");
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
            if(char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'){
                printf("���~:�L���ݩ�\n");
                if(char4_hp<40|char4_hp>50|char4_atk<15|char4_atk>20|char4_def<5|char4_def>10|(char4_hp+char4_atk+char4_def)<65|(char4_hp+char4_atk+char4_def)>70){
                    printf("���~:��O�Ȧb����d�򤧥~");//�P�_�O�_��O�Ȧb�d�򤧥~
                }
                break;//�����@�Өƥ�
            }
            if(char4_hp<40|char4_hp>50|char4_atk<15|char4_atk>20|char4_def<5|char4_def>10|(char4_hp+char4_atk+char4_def)<65|(char4_hp+char4_atk+char4_def)>70){
                printf("���~:��O�Ȧb����d�򤧥~");
                break;
            }
            printf("\n����4\n�W��:�ۭq����\n"
                "�ݩ�:%-6c   ��q:%-6d\n"
                "����:%-6d   ���m:%-6d\n"
                "����j�׹w��:%.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,char4_power);
            printf("\n��ܥ��𨤦�:");
            scanf ("%d",&Fa);
            if (Fa>4){
                printf("���~:�L������");
                break;
            }
            printf("��ܫ�𨤦�:");
            scanf ("%d",&La);
            if (La>4){
                printf("���~:�L������");
                break;
            }
            if (Fa==La){
                printf("���~:���i���ƿ��");
                break;
            }
            printf("\n���𬰨���%d�B��𬰨���%d\n",Fa,La);
            break;
        case 2:
            printf("\n��ܥ��𨤦�:");
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
            break;
        default:
            printf("��J���~");
    }
    return 0;//����
}
