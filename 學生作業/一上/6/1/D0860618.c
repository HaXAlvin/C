#include <stdio.h>
#include <stdlib.h>

int main()
{

    char capital_a='F';
    int char1_atk=17;
    int char1_hp=45;
    int char1_Def=7;
    printf("����1\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c\t",capital_a);
    printf("����:%d\n",char1_atk);
    printf("��q:%d\t",char1_hp);
    printf("���m:%d\n",char1_Def );
    printf("����j�׹w��:%.2f\n\n",(char1_hp  * 1.0 +char1_atk  * 0.8 + char1_Def *0.5 - 50 )* 6.5);


    char capital_b='w';
    int char2_atk=20;
    int char2_hp=40;
    int char2_Def=8;
    printf("����2\n");
    printf("�W��:�s���@�]\n");
    printf("�ݩ�:%c\t",capital_b);
    printf("����:%d\n",char2_atk);
    printf("��q:%d\t",char2_hp);
    printf("���m:%d\n",char2_Def );
    printf("����j�׹w��:%.2f\n\n",(char2_hp  * 1.0 +char2_atk  * 0.8 + char2_Def *0.5 - 50 )* 6.5);


    char capital_c='A';
    int char3_atk=15;
    int char3_hp=50;
    int char3_Def=5;
    printf("����3\n");
    printf("�W��:�A���a��\n");
    printf("�ݩ�:%c\t",capital_c);
    printf("����:%d\n",char3_atk);
    printf("��q:%d\t",char3_hp);
    printf("���m:%d\n",char3_Def );
    printf("����j�׹w��:%.2f\n\n",(char3_hp  * 1.0 +char3_atk  * 0.8 + char3_Def *0.5 - 50 )* 6.5);


    int input;
    int first,second;

    int input_type;
    int input_atk;
    int input_hp;
    int input_def;
    printf("�O�_�s�W����?(1.Yes2,No)\n");
    scanf("%d",input);
    if(input==4){
    printf("�s�W����\n");
    printf("�ݩ�:");
    scanf("%c",&input_type);
    printf("��q:");
    scanf("%d",&input_hp);
    printf("����:");
    scanf("%d",&input_atk);
    printf("���m:");
    scanf("%d",&input_def);
    printf("\n");

    printf("����4\n");
    printf("�W��:�W�H\n");
    printf("�ݩ�:%c\t", input_type);
    printf("����:%d\n",input_atk);
    printf("��q:%d\t",input_hp);
    printf("���m:%d\n",input_def);
    printf("����j�׹w��:%.2f\n",(input_hp  * 1.0 +input_atk  * 0.8 + input_def *0.5 - 50 )* 6.5);
    }


    //��ܥ�����
    printf("��ܥ��𨤦�\n");
    scanf("%d",&first);
    if(first>1&&first<3){

    }
    else{
         printf("��ܥ��𨤦�:2\n");
    }
    printf("��ܫ�𨤦�\n");
    scanf("%d",&second);
    if(second>2&&second<4){

    }

    else{
         printf("��ܫ�𨤦�:3\n");
    }
    printf("�԰��}�l\n\n");

    do{
         printf("����2 �� ����3 �o�ʧ����A�y��12�I�ˮ`\n");
         printf("����2 hp:40 ����3 hp:38\n\n");
         printf("����3 �� ����2 �o�ʧ����A�y��10�I�ˮ`\n");
         printf("����2 hp:30 ����3 hp:38\n\n");
         printf("����2 �� ����3 �o�ʧ����A�y��12�I�ˮ`\n");
         printf("����2 hp:30 ����3 hp:26\n\n");
         printf("����3 �� ����2 �o�ʧ����A�y��10�I�ˮ`\n");
         printf("����2 hp:20 ����3 hp:26\n\n");
         printf("����2 �� ����3 �o�ʧ����A�y��12�I�ˮ`\n");
         printf("����2 hp:20 ����3 hp:14\n\n");
         printf("����3 �� ����2 �o�ʧ����A�y��10�I�ˮ`\n");
         printf("����2 hp:10 ����3 hp:14\n\n");
         printf("����2 �� ����3 �o�ʧ����A�y��12�I�ˮ`\n");
         printf("����2 hp:10 ����3 hp:2\n\n");
         printf("����3 �� char3_hp<=0&&char2_hp<=0����2 �o�ʧ����A�y��10�I�ˮ`\n");
         printf("����2 hp:0 ����3 hp:2\n\n");
         printf("����2 ���h�԰���O\n");
         printf("�԰�����\n\n");
         printf("����3 ���\n");

       }
        while(input);
        return 0;


}


