#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //����1
    char char1_type = 'F';
    int char1_hp = 40;
    int char1_atk = 20;
    int char1_def = 10;
    float char_1 = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
    printf("����1\n�W�١G����\n");
    printf("�ݩʡG %c  ",char1_type);
    printf("�����G%d\n",char1_atk);
    printf("��q�G%d  ",char1_hp);
    printf("���m�G%d\n\n",char1_def);
    printf("����j�סG%.2f\n\n",char_1);
    //����2
    char char2_type = 'W';
    int char2_hp = 50;
    int char2_atk = 15;
    int char2_def = 5;
    float char_2 = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    printf("����2\n�W�١G����\n");
    printf("�ݩʡG %c  ",char2_type);
    printf("�����G%d\n",char2_atk);
    printf("��q�G%d  ",char2_hp);
    printf("���m�G%d\n\n",char2_def);
    printf("����j�סG%.2f\n\n",char_2);
    //����3
    char char3_type = 'G';
    int char3_hp = 45;
    int char3_atk = 15;
    int char3_def = 10;
    float char_3 = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    printf("����3\n�W�١G�߫}\n");
    printf("�ݩʡG %c  ",char3_type);
    printf("�����G%d\n",char3_atk);
    printf("��q�G%d  ",char3_hp);
    printf("���m�G%d\n\n",char3_def);
    printf("����j�סG%.2f\n\n",char_3);

    //����4���j�u
    int new_char; //�O�_�s�W����
    char char4_type; //�ݩʦr��
    int char4_atk;
    int char4_hp;
    int char4_def;
    int attack1; //����
    int attack2; //���
    printf("�O�_�s�W����(1.Yes 2.No)  ");
    scanf("%d%*c",&new_char);
    if (new_char==1)
    {
        printf("�����ݩ�:");
        scanf ("%c",&char4_type);
        char4_type=toupper(char4_type);//�p�g��j�g
        if (char4_type==65||char4_type==70||char4_type==71||char4_type==87) //F,W,G,A �� ASCII
        {
            printf("��q:");
            scanf ("%d",&char4_hp);
            printf("����:");
            scanf ("%d",&char4_atk);
            printf("���m:");
            scanf ("%d",&char4_def);
            if (char4_atk>20||char4_atk<15||char4_hp>50||char4_hp<40||char4_def<5||char4_def>10||(char4_def+char4_hp+char4_atk)>70||(char4_def+char4_hp+char4_atk)<65)//��O����~
            {
                printf("���~:��O�ƭȦb����d�򤧥~");
            }
            else//��O�ƭȤ�
            {
                float char_4 = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
                printf("\n����4\n�W�١G�}��\n");
                printf("�ݩʡG %c  ",char4_type);
                printf("�����G%d\n",char4_atk);
                printf("��q�G%d  ",char4_hp);
                printf("���m�G%d\n",char4_def);
                printf("����j�סG%.2f\n\n",char_4);

	            printf("������𨤦�");
	            scanf("%d",&attack1);
	            if (attack1>=5||attack1<1) //����u��1~4  attack�d��  1<= attack <=4
	            {
	                printf("���~:�L������");
	            }
	            else
	            {
	                printf("�����𨤦�");
	                scanf("%d",&attack2);
	                if(attack2>=5||attack2<1)//����u��1~5  attack�d��  1<= attack <=4
	                {
	                    printf("���~:�L������");
	                }
	                else if(attack1==attack2)//���⤣�୫��
	                {
	                    printf("���~:���i���ƿ��");
	                }
	                else
	                {
	                    printf("���𨤦⬰%d,��𨤦⬰%d\n",attack1,attack2);
	                }

	            }
	        }

        }
        else
        {
            printf("���~:�L���ݩ�");
        }
    }
    else if(new_char==2)//���s�W����
    {

        printf("������𨤦�");
        scanf("%d",&attack1);
        if (attack1>=4||attack1<1) //����u��1~3  attack�d��  1<= attack <=3
        {
            printf("���~:�L������");
        }
        else
        {
            printf("�����𨤦�");
            scanf("%d",&attack2);
            if(attack2>=4||attack2<1)//����u��1~3  attack�d��  1<= attack <=3
            {
                printf("���~:�L������");
            }
            else if(attack1==attack2)//���⤣�୫��
            {
                printf("���~:���i���ƿ��");
            }
            else
            {
                printf("���𨤦⬰%d,��𨤦⬰%d\n",attack1,attack2);
            }

        }

    }
    else//��L�����~�Ʀr (�﨤����)
    {
        printf("��J���~\n\n");
    }
    return 0;
}	// �������j�A��
