#include<stdio.h>
#include<stdlib.h>

int main() {
    char char1_type ;
    int char1_hp;
    int char1_atk;
    int char1_def;
    int ans;
    int ans1;
    int ans2;
    int test=0;
    int err_type = 0;
    int ans3;
    int ans4;

    printf("����1\n"
           "�W��:�ѼQ\n"
           "�ݩ�:F     ����:15\n"
           "��q:40    ���m:5\n"
           "����j�׹w��:29.25\n\n");
    printf("����2\n"
           "�W��:���t\n"
           "�ݩ�:W    ����:16\n"
           "��q:41   ���m:6\n"
           "����j�׹w��:44.20\n\n");
    printf("����3\n"
           "�W��:�ѥ�\n"
           "�ݩ�G    ����:17\n"
           "��q:42   ���m:7\n"
           "����j�׹w��:59.15\n\n");


    printf("�O�_�s�W����(1.Yes/2.No)?");

    scanf("%d",&ans);
    //��J�Ʀr
    if (ans ==1)
        //��%d=1��
    {
        printf("�s�W����\n");
        printf("�ݩ�:");
        scanf("%*c%c",&char1_type);
        printf("��q:");
        scanf("%d",&char1_hp);
        printf("����:");
        scanf("%d",&char1_atk);
        printf("���m:");
        scanf("%d",&char1_def);
        switch(char1_type)
            //�P�_�����ݩ�
        {
        case'f':
                break;
        case'g':
            break;
        case'a':
                break;
        case'w':
            break;
        case'F':
                break;
        case'G':
            break;
        case'A':
                break;
        case'W':
            break;
        default:
            test = test +1; //�p����~����
            err_type = 1; //�Хܿ��~����

        }
        if (char1_hp<40||char1_hp>50||char1_atk<15||char1_atk>20||char1_def<5||char1_def>10) {
            test = test +1;
            err_type = 2;

        }//�P�_��O�Ƚd��
        switch(test) { //�P�_��ܪ��F��
        case 0:
            break;

        case 1:
            if(err_type == 1) {
                printf("�L���ݩ�");
                return 0;
            } else if(err_type == 2) {
                printf("���~:��O�ƭȦb�d�򤧥~");
                return 0;
            } else {
                break;
            }

        case 2:
            printf("�L���ݩ�\n���~:��O�ƭȦb�d�򤧥~");
            return 0;
        }
        float a = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5);
        float b = (a-50)*6.5;
        printf("\n");
        printf("����4\n");
        printf("�W��:�ۭq����\n");
        printf("�ݩ�:%c   ",char1_type);
        printf("����:%d\n",char1_atk);
        printf("��q:%d   ",char1_hp);
        printf("���m:%d\n",char1_def);
        printf("����j�׹w��:%.2lf",b);

        printf("\n");
        printf("��ܥ��𨤦�:");
        scanf("%d",&ans3);
        if (ans3>4) {
            printf("���~:�L������");
            return 0;
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&ans4);
        if (ans4>4) {
            printf("���~:�L������");
            return 0;
        }
        printf("���𨤦⬰:%d",ans3);
        printf("��𨤦⬰:%d",ans4);
        return 0;
    }



    else if(ans==2)
        //��%d=2��
    {
        printf("��ܥ��𨤦�:");
        scanf("%d",&ans1);
        if (ans1==ans2) {
            printf("���~:���i���ƿ��");
            return 0;
        }

        else if (ans1>3) {
            printf("���~:�L������");
            return 0;
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&ans2);

        if (ans1==ans2) {
            printf("���~:���i���ƿ��");
            return 0;
        }

        else if (ans2>3) {
            printf("���~:�L������");
            return 0;
        }
        printf("���𨤦⬰:%d",ans1);
        printf("��𨤦⬰:%d",ans2);
    }
    if (ans>2)
        printf("��J���~");

    return 0;

}
