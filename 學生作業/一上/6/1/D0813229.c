#include<stdio.h>
#include<stdlib.h>

int main() {

    int char1_hp=40;
    int char1_atk=15;
    int char1_def=5;
    int char2_hp=41;
    int char2_atk=16;
    int char2_def=6;
    int char3_hp=42;
    int char3_atk=17;
    int char3_def=7;
    char char4_type ;
    int char4_hp;
    int char4_atk;
    int char4_def;
    int ans;
    int ans1;
    int ans2;
    int test=0;
    int err_type = 0;
    int hp1;
    int hp2;
    int atk1;
    int atk2;
    int def1;
    int def2;
    char dam1;
    char dam2;

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
    while(ans>2) {
        printf("��J���~\n");
        printf("�O�_�s�W����(1.Yes/2.No)?");
        scanf("%d",&ans);
    }
    printf("\n");
    if (ans ==1)
        //��%d=1��
    {
        printf("�s�W����\n");
        printf("�ݩ�:");
        scanf("%*c%c",&char4_type);
        printf("��q:");
        scanf("%d",&char4_hp);
        printf("����:");
        scanf("%d",&char4_atk);
        printf("���m:");
        scanf("%d",&char4_def);
        switch(char4_type)
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
        if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10) {
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

        switch(char4_type) {
        case'f':
            printf("�ݩ�:F  ");
            break;
        case'g':
            printf("�ݩ�:G  ");
            break;
        case'a':
            printf("�ݩ�:A  ");
            break;
        case'w':
            printf("�ݩ�:W  ");
            break;
        default:
            printf("�ݩ�:%c   ",char4_type);
            break;
        }
        printf("����:%d\n",char4_atk);
        printf("��q:%d   ",char4_hp);
        printf("���m:%d\n",char4_def);
        printf("����j�׹w��:%.2lf",b);
        printf("\n");
        printf("      ");
        printf("\n");
        printf("��ܥ��𨤦�:");
        scanf("%d",&ans1);
        while(ans1>4) {
            printf("���~:�L������\n");
            printf("��ܥ��𨤦�:");
            scanf("%d",&ans1);
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&ans2);
        while(ans2>4) {
            printf("���~:�L������\n");
            printf("��ܫ�𨤦�:");
            scanf("%d",&ans2);
        }
        printf("���𨤦⬰%d",ans1);
        printf("��𨤦⬰%d",ans2);
    } else if(ans==2)
        //��%d=2��
    {
        printf("��ܥ��𨤦�:");
        scanf("%d",&ans1);
        if(ans1==ans2) {
            printf("���~:���i���ƿ��\n");
            return 0;
        } else if(ans1>3) {
            printf("���~:�L������");
            return 0;
        }
        printf("��ܫ�𨤦�:");
        scanf("%d",&ans2);
        if (ans1==ans2) {
            printf("���~:���i���ƿ��");
            return 0;
        } else if (ans2>3) {
            printf("���~:�L������");
            return 0;
        }
        printf("\n");
        printf("���𨤦⬰%d�B",ans1);
        printf("��𨤦⬰%d",ans2);
    }
    printf("\n");
    printf("�԰��}�l");
    printf("\n");
    printf("     ");
    printf("\n");
    switch(ans1) {
    case 1:
        hp1=40;
        atk1=15;
        def1=5;
        break;
    case 2:
        hp1=41;
        atk1=16;
        def1=6;
        break;
    case 3:
        hp1=42;
        atk1=17;
        def1=7;
        break;
    case 4:
        hp1=char4_hp;
        atk1=char4_atk;
        def1=char4_def;
        break;
    default:
        hp1=0;
        break;
    }
    switch(ans2) {
    case 1:
        hp2=40;
        atk2=15;
        def2=5;
        break;
    case 2:
        hp2=41;
        atk2=16;
        def2=6;
        break;
    case 3:
        hp2=42;
        atk2=17;
        def2=7;
        break;
    case 4:
        hp2=char4_hp;
        atk2=char4_atk;
        def2=char4_def;
        break;
    default:
        hp2=0;
        break;
    }
    dam1=atk1-def2;
    dam2=atk2-def1;

    while(hp1>0&hp2>0) {

        hp2=hp2-dam1;
        printf("����%d �﨤��%d �o�ʧ����A�y��%d�ˮ`\n����%d HP %d  ����%d  HP %d\n",ans1,ans2,dam1,ans1,hp1,ans2,hp2);
        printf("\n");
        if(hp2>0) {
            hp1=hp1-dam2;
            printf("����%d �﨤��%d �o�ʧ����A�y��%d�ˮ`\n����%d HP %d  ����%d  HP %d\n",ans2,ans1,dam2,ans1,hp1,ans2,hp2);
            printf("\n");
        }

    }
    if(hp1<=0|hp2<=0) {
        if(hp1<=0) {
            printf("����%d  ���h�԰���O\n�԰�����\n",ans1);
            printf("\n");
            printf("����%d ���",ans2);
        } else {
            printf("����%d  ���h�԰���O\n�԰�����\n",ans2);
            printf("\n");
            printf("����%d ���",ans1);
        }

    }
    return 0;
}
