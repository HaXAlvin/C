#include<stdio.h>
int main() {
    //����1
    char char_type1 = 'A';
    int char_atk1 = 19;
    int char_hp1 = 47;
    int char_def1 = 4;
    float char_power1 = (char_hp1*1.0+char_atk1*0.8+char_def1*0.5-50)*6.5;
    //����2
    char char_type2 = 'F';
    int char_atk2 = 17;
    int char_hp2 = 45;
    int char_def2 = 5;
    float char_power2 = (char_hp2*1.0+char_atk2*0.8+char_def2*0.5-50)*6.5;
    //����3
    char char_type3 = 'W';
    int char_atk3 = 20;
    int char_hp3 = 43;
    int char_def3 = 7;
    float char_power3 = (char_hp3*1.0+char_atk3*0.8+char_def3*0.5-50)*6.5;
    //����4
    char char_type4;
    int char_atk4;
    int char_hp4;
    int char_def4;
    float char_power4;
    //����1
    printf("����1\n"
           "�W��:�x����H\n");
    printf("�ݩ�:%c    ����:%d\n",char_type1,char_atk1);
    printf("��q:%d   ���m:%d\n",char_hp1,char_def1);
    printf("�j�׹w��:%.2f\n\n",char_power1);
    //����2
    printf("����2\n"
           "�W��:�ǯ��h�Ԯ楧�|\n");
    printf("�ݩ�:%c    ����:%d\n",char_type2,char_atk2);
    printf("��q:%d   ���m:%d\n",char_hp2,char_def2);
    printf("�j�׹w��:%.2f\n\n",char_power2);
    //����3
    printf("����3\n"
           "�W��:�X�_D�|��\n");
    printf("�ݩ�:%c    ����:%d\n",char_type3,char_atk3);
    printf("��q:%d   ���m:%d\n",char_hp3,char_def3);
    printf("�j�׹w��:%.2f\n\n",char_power3);

    int num;
    printf("�O�_�s�W����(1.Yes/2.No)?");
    scanf("%d",&num);

    if(num==1) {
        //����4
        printf("�s�W����\n");
        printf("�ݩ�:");
        getchar();
        scanf("%c",&char_type4);
        printf("����:");
        scanf("%d",&char_atk4);
        printf("��q:");
        scanf("%d",&char_hp4);
        printf("���m:");
        scanf("%d",&char_def4);
        printf("\n");

        if((char_type4 == 'F'||char_type4 =='W'||char_type4 =='G'||char_type4 =='A'||char_type4 =='f'||char_type4 =='w'||char_type4 =='g'||char_type4 =='a') && (char_hp4>=40 && char_hp4<=50 && char_atk4>=15 && char_atk4<=20 && char_def4>=5 && char_def4<=10) && (char_atk4+char_hp4+char_def4<=70 && 65<=char_atk4+char_hp4+char_def4)) {
            printf("����4\n");
            printf("�W��:�u�÷s�@\n");
            if(char_type4<96) {
                printf("�ݩ�:%c    ����:%d\n",char_type4,char_atk4);
            } else if(char_type4>96) {
                printf("�ݩ�:%c    ����:%d\n",char_type4-32,char_atk4);
            }
            printf("��q:%d   ���m:%d\n",char_hp4,char_def4);
            printf("�j�׹w��:%.2f\n\n",(char_hp4*1.0+char_atk4*0.8+char_def4*0.5-50)*6.5);
            printf("\n");
            int first,second;
            printf("��ܥ��𨤦�:");
            scanf("%d",&first);
            if(first == 1 || first == 2 || first == 3 || first == 4) {
                printf("��ܫ�𨤦�:");
                scanf("%d",&second);
            }
            if(second == 1 || second == 2 || second == 3 || second == 4 && first != second)
                printf("���𬰨���%d\n��𬰨���%d",first,second);
            else if(first == second)
                printf("���~:���o���ƿ��");
            else if(second != 1 || second != 2 || second != 3 || second != 4 )
                printf("���~:�L������");

            else if(first != 1 || first != 2 || first != 3 || first != 4)
                printf("���~:�L������");

        } else if((char_type4 != 'F'||char_type4 !='W'||char_type4 !='G'||char_type4 !='A'||char_type4 !='f'||char_type4 !='w'||char_type4 !='g'||char_type4 !='a') && (char_hp4>=40 && char_hp4<=50 && char_atk4>=15 && char_atk4<=20 && char_def4>=5 && char_def4<=10) && (char_atk4+char_hp4+char_def4<=70 && 65<=char_atk4+char_hp4+char_def4)) {
            printf("���~:�L���ݩ�\n");
        } else if((char_type4 == 'F'||char_type4 =='W'||char_type4 =='G'||char_type4 =='A'||char_type4 =='f'||char_type4 =='w'||char_type4 =='g'||char_type4 =='a') && (char_hp4<=40 || char_hp4>=50 || char_atk4<=15 || char_atk4>=20 || char_def4<=5 || char_def4>=10 || char_atk4+char_hp4+char_def4<=65 || char_atk4+char_hp4+char_def4>=70)) {
            printf("���~:��O�ƭȦb����d�򤧥~\n");
        } else if((char_type4 != 'F'||char_type4 !='W'||char_type4 !='G'||char_type4 !='A'||char_type4 !='f'||char_type4 !='w'||char_type4 !='g'||char_type4 !='a') && (char_hp4<=40 || char_hp4>=50 || char_atk4<=15 || char_atk4>=20 || char_def4<=5 || char_def4>=10 || char_atk4+char_hp4+char_def4<=65 || char_atk4+char_hp4+char_def4>=70)) {
            printf("���~:�L���ݩ�\n"
                   "���~:��O�ƭȦb����d�򤧥~\n");
        }
    } else if(num==2) {
        int first,second;
        printf("��ܥ��𨤦�:");
        scanf("%d",&first);
        if(first == 1 || first == 2 || first==3) {
            printf("��ܫ�𨤦�:");
            scanf("%d",&second);
        }
        if(second == 1 || second == 2 || second == 3 && first != second)
            printf("���𬰨���%d\n��𬰨���%d",first,second);
        else if(first == second)
            printf("���~:���o���ƿ��");
        else if(second != 1 || second != 2 || second != 3)
            printf("���~:�L������");

        else if(first != 1 || first != 2 || first != 3) {
            printf("���~:�L������");
        }
    } else if(num!=1 && num!=2) {
        printf("��J���~");
    }
    return 0;
}
