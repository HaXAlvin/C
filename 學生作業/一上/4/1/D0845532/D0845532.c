#include<stdio.h>//���Y��
int main()
{                  //�D�禡
    char char1type='G',char2type='A',char3type='F',char4type;//type
    int  char1atk=20,char2atk=15,char3atk=16,char4atk;//atk
    int  char1hp=40,char2hp=35,char3hp=44,char4hp;//hp
    int  char1def=10,char2def=10,char3def=5,char4def;//def
    printf("����1\n"//�L�X��r
           "�W��:���\n");
    printf("�ݩ�:G    ����:20\n",char1type,char1atk);
    printf("��q:40   ���m:10\n", char2type,char2atk);
    printf("����w���j��:%.2f\n\n",(char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50);

    printf("����2\n"
           "�W��:�֥�\n");
    printf("�ݩ�:A    ����:15\n",char2type,char2atk);
    printf("��q:35   ���m:10\n",char2hp,char2def);
    printf("����w���j��:%.2f\n\n",(char2hp*1)+(char2atk*0.8)+(char2def*0.5)-50);

    printf("����3\n"
           "�W��:�紵\n");
    printf("�ݩ�:F    ����:16\n",char3type,char3atk);
    printf("��q:44   ���m:5\n",char3hp,char3def);
    printf("����w���j��:%.2f\n\n",(char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50);

    printf("�s�W����\n");//�s�W����
    printf("�ݩ�:");
    scanf("%c",&char4type);
    printf("����:");
    scanf("%d",&char4atk);
    printf("��q:");
    scanf("%d",&char4hp);
    printf("���m:");
    scanf("%d",&char4def);
    printf("\n");

    printf("����4\n");
    printf("�W��:�ۭq����\n");
    printf("�ݩ�:%c ����%d\n",char4type,char4atk);
    printf("��q:%d ���m%d\n",char4hp,char4def);
    printf("����w���j��:%.2f\n",(char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50);
    printf("\n");
    return 0;//����

}
