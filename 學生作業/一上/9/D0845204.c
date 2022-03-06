#include<stdio.h>
#include<ctype.h>
#include<string.h>
    char char_id[4][20]={"��ù��",
                         "���R",
                         "����",
                         ""};
    char char_type[4]="FWG";
    int char_hp[4]={42,47,46};
    int char_atk[4]={18,15,19};
    int char_def[4]={9,6,5};
    int Fa,La;
    int suit;


int EditNewChar(int have)
{
        int is_correct=1;
        if(have==0){//�٨S�إߨ���4�� case1�ݰ�����:�s�W����
                    printf("\n�s�W����\n");
                    printf("�W��:");
                    scanf("%s",char_id[3]);
                    printf("�ݩʡG");
                    scanf("%*c%c", &char_type[3]);
                    printf("��q�G");
                    scanf("%d", &char_hp[3]);
                    printf("�����G");
                    scanf("%d", &char_atk[3]);
                    printf("���m�G");
                    scanf("%d", &char_def[3]);
                    //�˹��ݩ�
                    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
                        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a'){
                        printf("���~�G�L���ݩ�\n");
                        is_correct = 0;
                    }
                    else if(char_type[3] >= 'a')
                        char_type[3] -= 32;
                    // �ˬd��O�ƭ�
                    int char_sum = char_hp[3] + char_atk[3] + char_def[3];
                    if(char_hp[3] < 40 || char_hp[3] > 50 || char_atk[3] < 15 || char_atk[3] > 20 ||
                        char_def[3] < 5 || char_def[3] > 10 || char_sum < 65 || char_sum > 70){
                        printf("���~�G��O�ƭȦb����d�򤧥~\n");
                        return 0;
                    }
                    if(!is_correct)
                    return 0;

                    printf("\n����4\n�W�١G%s\n",char_id[3]);
                    printf("�ݩʡG%c     �����G%d\n", char_type[3], char_atk[3]);
                    printf("��q�G%d    ���m�G%d\n", char_hp[3], char_def[3]);
                    printf("����j�׹w���G%.2f\n\n", (char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
                    have=1;

        }
        else if(have==1){//�w�g�s�W����4����case1�ݭn������:�ק�s�W����
                    printf("\n�ק�s�W����\n");
                    printf("�W��:");
                    scanf("%s",char_id[3]);
                    printf("�ݩʡG");
                    scanf("%*c%c", &char_type[3]);
                    printf("��q�G");
                    scanf("%d", &char_hp[3]);
                    printf("�����G");
                    scanf("%d", &char_atk[3]);
                    printf("���m�G");
                    scanf("%d", &char_def[3]);
                    //�˹��ݩ�
                    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
                        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a'){
                        printf("���~�G�L���ݩ�\n");
                        is_correct = 0;
                    }
                    else if(char_type[3] >= 'a')
                    char_type[3] -= 32;
                    //�ˬd��O�ƭ�
                    int char_sum = char_hp[3] + char_atk[3] + char_def[3];
                    if(char_hp[3] < 40 || char_hp[3] > 50 || char_atk[3] < 15 || char_atk[3] > 20 ||
                        char_def[3] < 5 || char_def[3] > 10 || char_sum < 65 || char_sum > 70){
                        printf("���~�G��O�ƭȦb����d�򤧥~\n");
                    return 0;
                    }
                    if(!is_correct)
                    return 0;

                    printf("\n����4\n�W�١G%s\n",char_id[3]);
                    printf("�ݩʡG%c     �����G%d\n", char_type[3], char_atk[3]);
                    printf("��q�G%d    ���m�G%d\n", char_hp[3], char_def[3]);
                    printf("����j�׹w���G%.2f\n\n", (char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
                    have=1;
                    return;
        }
}
int PrintCharData(int have)
{

        if(have==0){//�٨S�s�W����4�ɦL�X�w�g����3�Ө������
                     printf("����1\n"
                            "�W��:��ù��\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[0],char_hp[0],char_atk[0],char_def[0],(char_hp[0] * 1.0 + char_atk[0] * 0.8 + char_def[0] * 0.5 - 50.0) * 6.5 );
                     printf("����2\n"
                            "�W��:���R\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[1],char_hp[1],char_atk[1],char_def[1],(char_hp[1] * 1.0 + char_atk[1] * 0.8 + char_def[1] * 0.5 - 50.0) * 6.5 );
                     printf("����3\n"
                            "�W��:����\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[2],char_hp[2],char_atk[2],char_def[2],(char_hp[2] * 1.0 + char_atk[2] * 0.8 + char_def[2] * 0.5 - 50.0) * 6.5 );
        }
        else if(have==1){//������4�� �L�X4�Ө���
                     printf("����1\n"
                            "�W��:��ù��\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[0],char_hp[0],char_atk[0],char_def[0],(char_hp[0] * 1.0 + char_atk[0] * 0.8 + char_def[0] * 0.5 - 50.0) * 6.5 );
                     printf("����2\n"
                            "�W��:���R\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[1],char_hp[1],char_atk[1],char_def[1],(char_hp[1] * 1.0 + char_atk[1] * 0.8 + char_def[1] * 0.5 - 50.0) * 6.5 );
                     printf("����3\n"
                            "�W��:����\n"
                            "�ݩ�:%-6c    ��q:%-6d\n"
                            "����:%-6d    ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_type[2],char_hp[2],char_atk[2],char_def[2],(char_hp[2] * 1.0 + char_atk[2] * 0.8 + char_def[2] * 0.5 - 50.0) * 6.5 );

                     printf("\n����4\n�W��:%-6s\n"
                            "�ݩ�:%-6c   ��q:%-6d\n"
                            "����:%-6d   ���m:%-6d\n"
                            "����j�׹w��:%.2f\n\n",char_id[3],char_type[3],char_hp[3],char_atk[3],char_def[3],(char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
        }
        return;
}
int SelectAndBattle(int have)
{
        if(have==1){//�԰��P�_���N����4�[�J�P�_
                    printf("\n��ܥ��𨤦�:");
                    while(scanf("%d",&Fa) && (Fa>4 || Fa<1)){//���N�@�����אּ��
                        printf("���~:�L������");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&Fa);
                    break;
                    }
                    printf("��ܫ�𨤦�:");
                    while(scanf("%d",&La) && (La>4||La<1)){
                        printf("���~:�L������\n");
                        printf("��ܫ�𨤦�:");
                        scanf(" %d",&La);
                    break;
                    }
                    while(Fa==La){ //����ۤv��ۤv�� �]�����~
                        printf("���~:���i���ƿ��");
                        scanf("%d",&Fa);
                        scanf("%d",&La);

                    }
                    printf("\n���𬰨���%d�B��𬰨���%d\n\n",Fa,La);
                    battle(Fa,La);
        }


        else if(have==0){//�P�Whave=1�n�����Ʊ� �u�O�S������4
                    printf("\n��ܥ��𨤦�:");
                    while(scanf("%d",&Fa) && (Fa>3 || Fa<1)){//���N�@�����אּ��
                        printf("���~:�L������");
                        printf("\n��ܥ��𨤦�:");
                        scanf("%d",&Fa);
                    break;
                    }
                    printf("��ܫ�𨤦�:");
                    while(scanf("%d",&La) && (La>3||La<1)){
                        printf("���~:�L������\n");
                        printf("��ܫ�𨤦�:");
                        scanf(" %d",&La);
                    break;
                    }
                    while(Fa==La){ //����ۤv��ۤv�� �]�����~
                        printf("���~:���i���ƿ��");
                        scanf("%d",&Fa);
                        scanf("%d",&La);

                    }
                    printf("\n���𬰨���%d�B��𬰨���%d\n\n",Fa,La);
                    battle(Fa,La);
        }
}
int battle(int Fa,int La)
{
    int faatk,fadef,fahp,laatk,ladef,lahp;
    printf("�԰��}�l\n\n");
                    if(Fa==1){//�P�_�O�֭n���[�åB���������O(����)
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
                        faatk=char_atk[3];
                        fadef=char_def[3];
                        fahp=char_hp[3];
                    }
                    if(La==1){//�P�_�O�֭n���[�åB���������O(���)
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
                        laatk=char_atk[3];
                        ladef=char_def[3];
                        lahp=char_hp[3];
                    }
                    int fahp2,lahp2,fadmg,ladmg;
                    fahp2=fahp/2; //fahp2�������q���@�b
                    lahp2=lahp/2; //lahp2������q���@�b
                    while(fahp>=0 && lahp>=0){//�}�l���[
                    if(Fa=='W'&&La=='F'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='F'&&La=='A'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='A'&&La=='G'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='G'&&La=='W'){
                        fadmg=faatk*1.2;
                    }
                    if(Fa=='F'&&La=='W'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='A'&&La=='F'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='G'&&La=='A'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='W'&&La=='G'){
                        fadmg=faatk*0.8;
                    }
                    else{
                        fadmg=faatk;
                    }
                     if(La=='W'&&Fa=='F'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='F'&&Fa=='A'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='A'&&Fa=='G'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='G'&&Fa=='W'){
                        ladmg=laatk*1.2;
                    }
                    if(La=='F'&&Fa=='W'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='A'&&Fa=='F'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='G'&&Fa=='A'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='W'&&Fa=='G'){
                        ladmg=laatk*0.8;
                    }
                    else{
                        ladmg=faatk;
                    }
                    if(fahp<fahp2){
                        fadmg=fadmg*1.2;
                    }
                    else{
                        fadmg=fadmg;
                    }
                    if(lahp<lahp2){
                        ladmg=ladmg*1.2;
                    }
                    else{
                        ladmg=ladmg;
                    }
                    fadmg=fadmg-ladef;
                    ladmg=ladmg-fadef;


                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",Fa,La,fadmg,Fa,fahp,La,lahp-fadmg);
                    lahp=lahp-fadmg; //�Ѿl��q=��Ӧ�q-�����O
                    if(fahp<=0||lahp<=0){//���[�Φ������� �p�G�@���q�p��0�N�����԰�
                        break;
                    }
                    printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n����%d HP:%d ����%d HP:%d\n\n",La,Fa,ladmg,Fa,fahp-ladmg,La,lahp);
                    fahp=fahp-ladmg;
                }
                if(fahp>lahp){//��Ӫ�����,�P�_�O����o�ӧQ
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",La,Fa);
                }
                if(lahp>fahp){
                    printf("����%d ���h�԰���O\n�԰�����\n\n����%d���\n",Fa,La);
                }
                return;
}


int main()
{

    int have=0;
    int Fa,La;
    int faid,faatk,fadef,fahp,laid,laatk,ladef,lahp;

    while(1){  //while�j�j��A�æb�C���j��}�l�����ϥΪ̿���ﶵ
        printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п��:");
        scanf("%d",&suit);
        while(suit!=1 && suit!=2 && suit!=3 &&suit!=0){ //suut���൥��1234�H�~���Ƨ_�h��J���~
            printf("��J���~!\n");
            printf("1. �s�W�έק�s�W����\n"
               "2. ��ܩҦ�������\n"
               "3. �԰�\n"
               "0. �����C��\n"
               "�п��:");
            scanf("%d",&suit);
        }
        switch(suit){
            case 0://suit=0�n������
                printf("�����C��\n");
                return 0;
            case 1://suit=1�n������
                EditNewChar(have);
                have=1;
                break;
            case 2://suit=2�n������
                PrintCharData(have);
                break;
            case 3://suit=3�ɭn������
                SelectAndBattle(have);
            }
    }
}


