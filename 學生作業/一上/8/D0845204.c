
#include<stdio.h>
#include <ctype.h>
int main() {
    int  suit,have=0;     //�ܼ�have�Ψөw�q�O�_�w�g�s�W����4
    char char4_id[10];    //�������ίx�}�x�s
    char char4_type[1];
    int  char4_hp[1];
    int  char4_atk[1];
    int  char4_def[1];

    char char1_type[1]="F";
    int  char1_hp[1]= {42};
    int  char1_atk[1]= {18};
    int  char1_def[1]= {9};

    char char2_type[1]="W";
    int  char2_hp[1]= {47};
    int  char2_atk[1]= {15};
    int  char2_def[1]= {6};

    char char3_type[1]="G";
    int  char3_hp[1]= {46};
    int  char3_atk[1]= {19};
    int  char3_def[1]= {5};

    int Fa[1],La[1];
    int faid[1],faatk[1],fadef[1],fahp[1],laid[1],laatk[1],ladef[1],lahp[1];

    while(1) {    //while�j�j��A�æb�C���j��}�l�����ϥΪ̿���ﶵ
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п��:");
        scanf("%d",&suit);
        while(suit!=1 && suit!=2 && suit!=3 &&suit!=0) { //suut���൥��1234�H�~���Ƨ_�h��J���~
            printf("��J���~!\n");
            printf("1. �s�W�έק�s�W����\n"
                   "2. ��ܩҦ�������\n"
                   "3. �԰�\n"
                   "0. �����C��\n"
                   "�п��:");
            scanf("%d",&suit);
        }
        switch(suit) {
        case 0://suit=0�n������
            printf("�����C��\n");
            return 0;
        case 1://suit=1�n������
            if(have==0) { //�٨S�إߨ���4�� case1�ݰ�����:�s�W����
                printf("\n�s�W����\n");
                getchar();//�Y����
                printf("�W��:");
                gets(char4_id);
                printf("�ݩ�:");
                gets(char4_type);
                printf("��q:");
                scanf ("%d",&char4_hp[0]);
                printf("����:");
                scanf ("%d",&char4_atk[0]);
                printf("���m:");
                scanf ("%d",&char4_def[0]);
                while(char4_type[0]!='F'&&char4_type[0]!='W'&&char4_type[0]!='G'&&char4_type[0]!='A') {
                    printf("���~:�L���ݩ�\n");//�P�_�ݩʦ��S�����~
                    if(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70)
                        printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʿ��ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�W��:");
                    scanf (" %s",char4_id[10]);
                    printf("�ݩ�:");
                    scanf (" %c",char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("��q:");
                    scanf ("%d",&char4_hp[0]);
                    printf("����:");
                    scanf ("%d",&char4_atk[0]);
                    printf("���m:");
                    scanf ("%d",&char4_def[0]);
                }
                while(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70) {
                    printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʹ�ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�W��:");
                    scanf (" %s",char4_id[10]);
                    printf("�ݩ�:");
                    scanf (" %c",&char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("��q:");
                    scanf ("%d",&char4_hp[0]);
                    printf("����:");
                    scanf ("%d",&char4_atk[0]);
                    printf("���m:");
                    scanf ("%d",&char4_def[0]);

                }
                printf("\n����4\n�W��:%-6s\n"
                       "�ݩ�:%-6c   ��q:%-6d\n"
                       "����:%-6d   ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            have=1;
            if(have==1) { //�w�g�s�W����4����case1�ݭn������:�ק�s�W����
                printf("\n�ק�s�W����\n");
                printf("�W��:");
                scanf("% s", char4_id[10]);
                printf("��q:");
                scanf ("%d",&char4_hp[0]);
                printf("����:");
                scanf ("%d",&char4_atk[0]);
                printf("���m:");
                scanf ("%d",&char4_def[0]);
                while(char4_type[0]!='F'&&char4_type[0]!='W'&&char4_type[0]!='G'&&char4_type[0]!='A') {
                    printf("���~:�L���ݩ�\n");
                    if(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70)
                        printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʿ��ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�W��:");
                    scanf (" %s",char4_id[10]);
                    printf("�ݩ�:");
                    scanf (" %c",char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("��q:");
                    scanf ("%d",&char4_hp[0]);
                    printf("����:");
                    scanf ("%d",&char4_atk[0]);
                    printf("���m:");
                    scanf ("%d",&char4_def[0]);


                }
                while(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70) {
                    printf("���~:��O�Ȧb����d�򤧥~\n");//�ݩʹ�ɧP�_�O�_��O�Ȧb�d�򤧥~
                    printf("\n�s�W����4\n");
                    printf("�W��:");
                    scanf (" %s",char4_id[10]);
                    printf("�ݩ�:");
                    scanf (" %c",&char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("��q:");
                    scanf ("%d",&char4_hp[0]);
                    printf("����:");
                    scanf ("%d",&char4_atk[0]);
                    printf("���m:");
                    scanf ("%d",&char4_def[0]);

                }
                printf("\n����4\n�W��:%-6s\n"
                       "�ݩ�:%-6c   ��q:%-6d\n"
                       "����:%-6d   ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            break;
        case 2://suit=2�n������
            if(have==0) { //�٨S�s�W����4�ɦL�X�w�g����3�Ө������
                printf("����1\n"
                       "�W��:��ù��\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char1_type[0],char1_hp[0],char1_atk[0],char1_def[0],(char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50.0) * 6.5 );
                printf("����2\n"
                       "�W��:���R\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char2_type[0],char2_hp[0],char2_atk[0],char2_def[0],(char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50.0) * 6.5 );
                printf("����3\n"
                       "�W��:����\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char1_type[0],char3_hp[0],char3_atk[0],char3_def[0],(char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50.0) * 6.5 );
            }
            if(have==1) { //������4�� �L�X4�Ө���
                printf("����1\n"
                       "�W��:��ù��\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char1_type[0],char1_hp[0],char1_atk[0],char1_def[0],(char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50.0) * 6.5 );
                printf("����2\n"
                       "�W��:���R\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char2_type[0],char2_hp[0],char2_atk[0],char2_def[0],(char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50.0) * 6.5 );
                printf("����3\n"
                       "�W��:����\n"
                       "�ݩ�:%-6c    ��q:%-6d\n"
                       "����:%-6d    ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char1_type[0],char3_hp[0],char3_atk[0],char3_def[0],(char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50.0) * 6.5 );
                printf("\n����4\n�W��:%-6s\n"
                       "�ݩ�:%-6c   ��q:%-6d\n"
                       "����:%-6d   ���m:%-6d\n"
                       "����j�׹w��:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            break;
        case 3://suit=3�ɭn������
            if(have==1) { //�԰��P�_���N����4�[�J�P�_
                printf("\n��ܥ��𨤦�:");
                while(scanf("%d",&Fa[0]) && (Fa[0]>4 || Fa[0]<1)) { //���N�@�����אּ��
                    printf("���~:�L������");
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&Fa[0]);
                    break;
                }
                printf("��ܫ�𨤦�:");
                while(scanf("%d",&La[0]) && (La[0]>4||La[0]<1)) {
                    printf("���~:�L������\n");
                    printf("��ܫ�𨤦�:");
                    scanf(" %d",&La[0]);
                    break;
                }
                while(Fa[0]==La[0]) { //����ۤv��ۤv�� �]�����~
                    printf("���~:���i���ƿ��");
                    scanf("%d",&Fa[0]);
                    scanf("%d",&La[0]);

                }
                printf("\n���𬰨���%d�B��𬰨���%d\n\n",Fa[0],La[0]);

                printf("�԰��}�l\n\n");
                if(Fa[0]==1) { //�P�_�O�֭n���[�åB���������O(����)
                    faatk[0]=18;
                    fadef[0]=9;
                    fahp[0]=42;
                }
                if(Fa[0]==2) {
                    faatk[0]=15;
                    fadef[0]=6;
                    fahp[0]=47;
                }
                if(Fa[0]==3) {
                    faatk[0]=19;
                    fadef[0]=5;
                    fahp[0]=46;
                }
                if(Fa[0]==4) {
                    faatk[0]=char4_atk[0];
                    fadef[0]=char4_def[0];
                    fahp[0]=char4_hp[0];
                }
                if(La[0]==1) { //�P�_�O�֭n���[�åB���������O(���)
                    laatk[0]=18;
                    ladef[0]=9;
                    lahp[0]=42;
                }
                if(La[0]==2) {
                    laatk[0]=15;
                    ladef[0]=6;
                    lahp[0]=47;
                }
                if(La[0]==3) {
                    laatk[0]=19;
                    ladef[0]=5;
                    lahp[0]=46;
                }
                if(La[0]==4) {
                    laatk[0]=char4_atk[0];
                    ladef[0]=char4_def[0];
                    lahp[0]=char4_hp[0];
                }
                int fahp2[1],lahp2[1],fadmg[1],ladmg[1];
                fahp2[0]=fahp[0]/2; //fahp2�������q���@�b
                lahp2[0]=lahp[0]/2; //lahp2������q���@�b

                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]<fahp2[0]) { //�]��W�J��F�MW�ݦ�ҥH W�������O*1.2*1.2
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]>=fahp2[0]) { //�]��W�J��F�ҥHW�������O*1.2
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]<lahp2[0]) { //�]��F�QW�J��MF�ݦ�ҥH F�������O*0.8*1.2
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]>=lahp2[0]) { //�]��F�QW�J��ҥHF�������O*0.8
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]<fahp2[0]) { //�H�U�����γ��M�W�����@��
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }



                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }


                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }


                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }


                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                while(fahp[0]>=0 && lahp[0]>=0) { //�}�l���[
                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",Fa[0],La[0],fadmg[0],Fa[0],fahp[0],La[0],lahp[0]-fadmg[0]);
                    lahp[0]=lahp[0]-fadmg[0]; //�Ѿl��q=��Ӧ�q-�����O
                    if(fahp[0]<=0||lahp[0]<=0) { //���[�Φ������� �p�G�@���q�p��0�N�����԰�
                        break;
                    }
                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",La[0],Fa[0],ladmg[0],Fa[0],fahp[0],La[0],fahp[0]-ladmg[0]);
                    fahp[0]=fahp[0]-ladmg[0];
                }
                if(fahp[0]>lahp[0]) { //��Ӫ�����,�P�_�O����o�ӧQ
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",La[0],Fa[0]);
                }
                if(lahp[0]>fahp[0]) {
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",Fa[0],La[0]);
                }
            }
            if(have==0) { //�P�Whave=1�n�����Ʊ� �u�O�S������4
                printf("\n��ܥ��𨤦�:");
                while(scanf("%d",&Fa[0]) && (Fa[0]>3 || Fa[0]<1)) { //���N�@�����אּ��
                    printf("���~:�L������");
                    printf("\n��ܥ��𨤦�:");
                    scanf("%d",&Fa[0]);
                    break;
                }
                while(scanf("%d",&La[0]) && (La[0]>3||La[0]<1)) {
                    printf("��ܫ�𨤦�:");
                    printf("���~:�L������\n");
                    printf("��ܫ�𨤦�:");
                    scanf(" %d",&La[0]);
                    break;
                }
                while(Fa[0]==La[0]) {
                    printf("���~:���i���ƿ��");
                    scanf("%d",&Fa[0]);
                    scanf("%d",&La[0]);

                }
                printf("\n���𬰨���%d�B��𬰨���%d\n\n",Fa[0],La[0]);

                printf("�԰��}�l\n\n");
                if(Fa[0]==1) { //�P�_�O�֭n���[�åB���������O(����)
                    faatk[0]=18;
                    fadef[0]=9;
                    fahp[0]=42;
                }
                if(Fa[0]==2) {
                    faatk[0]=15;
                    fadef[0]=6;
                    fahp[0]=47;
                }
                if(Fa[0]==3) {
                    faatk[0]=19;
                    fadef[0]=5;
                    fahp[0]=46;
                }
                if(La[0]==1) { //�P�_�O�֭n���[�åB���������O(���)
                    laatk[0]=18;
                    ladef[0]=9;
                    lahp[0]=42;
                }
                if(La[0]==2) {
                    laatk[0]=15;
                    ladef[0]=6;
                    lahp[0]=47;
                }
                if(La[0]==3) {
                    laatk[0]=19;
                    ladef[0]=5;
                    lahp[0]=46;
                }
                int fahp2[1],lahp2[1],fadmg[1],ladmg[1];
                fahp2[0]=fahp[0]/2;
                lahp2[0]=lahp[0]/2;

                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }



                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }


                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }


                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }


                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                while(fahp[0]>=0 && lahp[0]>=0) { //�}�l���[
                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",Fa[0],La[0],fadmg[0],Fa[0],fahp[0],La[0],lahp[0]-fadmg[0]);
                    lahp[0]=lahp[0]-fadmg[0];
                    if(fahp[0]<=0||lahp[0]<=0) { //���[�Φ�������
                        break;
                    }
                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",La[0],Fa[0],ladmg[0],Fa[0],fahp[0],La[0],fahp[0]-ladmg[0]);
                    fahp[0]=fahp[0]-ladmg[0];
                }
                if(fahp[0]>lahp[0]) { //��Ӫ�����
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",La[0],Fa[0]);
                }
                if(lahp[0]>fahp[0]) {
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",Fa[0],La[0]);
                }
            }
            break;

        }
    }
}




