#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int main() {
    //����1
    char char1_type='F';//�ݩ�
    int char1_hp=45;//��q
    int char1_atk=17;//����
    int char1_def=8;//���m
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;//�j�׹w��
    //����2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //����3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //����4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pre;

    printf("����1\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c\t",char1_type);
    printf("����:%d\n",char1_atk);
    printf("��q:%d\t",char1_hp);
    printf("���m:%d\n",char1_def);
    printf("����j�׹w��:%.2f\n",char1_pre);
    printf("\n");

    printf("����2\n");
    printf("�W��:����\n");
    printf("�ݩ�:%c\t",char2_type);
    printf("����:%d\n",char2_atk);
    printf("��q:%d\t",char2_hp);
    printf("���m:%d\n",char2_def);
    printf("����j�׹w��:%.2f\n",char2_pre);
    printf("\n");

    printf("����3\n");
    printf("�W��:�ڵ� \n");
    printf("�ݩ�:%c\t",char3_type);
    printf("����:%d\n",char3_atk);
    printf("��q:%d\t",char3_hp);
    printf("���m:%d\n",char3_def);
    printf("����j�׹w��:%.2f\n",char3_pre);
    printf("\n");

    int chos;//�q�w�O�_�s�W�����ܼ�chos
    int frs_atk;//�q�w���𨤦��ܼ�
    int sec_atk;//�q�w��𨤦��ܼ�
    char a;
    printf("�O�_�s�W����(1.Yes/2.No)? ");
    scanf("%d",&chos);
    if (chos==1) { //��ܷs�W����
        printf("\n");
        printf("�s�W����\n");
        printf("�ݩ�:");
        scanf(" %c",&a);//�]���|Ū��e��3�檺\n�A%c�e�n�Ť@��
        char4_type = a;
        printf("��q:");
        scanf("%d",&char4_hp);
        printf("����:");
        scanf("%d",&char4_atk);
        printf("���m:");
        scanf("%d",&char4_def);
        char4_pre=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;

        if(char4_type != 'F') {
            printf("���~:�L���ݩ�\n");//�ݩʿ�J���~
        }
        if((char4_hp <40 || char4_hp >50) || (char4_atk <15 || char4_atk >20) || (char4_def <5 || char4_def >10) || (char4_hp+char4_atk+char4_def <65 || char4_hp+char4_atk+char4_def >70)) {
            //�p�G�T���`�M�έӧO�ƭȶW�X�d��A�h�L�X�U�C��r
            printf("���~:��O�ƭȦb����d�򤧥~\n");//�]�w�ƾڼƭȳW�d
        }
        if((char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A'||char4_type=='f'||char4_type=='w'||char4_type=='g'||char4_type=='a')&&((40<=char4_hp && char4_hp<=50)&&(15<=char4_atk && char4_atk<=20)&&(5<=char4_def && char4_def<=10))) {
            //�ݩʡB�ƭȿ�J���T
            printf("\n");
            printf("����4\n");
            printf("�W��:�ۭq����\n");
            if(islower(char4_type)!=0) { //�p�G��J���p�g�A�L�X�ɧאּ�j�g
                printf("�ݩ�:%c\t",toupper(char4_type));
            } else {
                a = char4_type;
                printf("�ݩ�:%c\t",a);
            }//�Y�쥻���j�g�A�h�����L�X
            printf("����:%d\n",char4_atk);
            printf("��q:%d\t",char4_hp);
            printf("���m:%d\n",char4_def);
            printf("����j�׹w��:%.2f\n",char4_pre);
            printf("\n");
            printf("��ܥ��𨤦�:");
            scanf("%d",&frs_atk);
            switch(frs_atk) {
            case 1 ... 4:
                printf("��ܫ�𨤦�:");
                scanf("%d",&sec_atk);
                if((sec_atk==1 || sec_atk==2 || sec_atk==3 || sec_atk==4) && sec_atk!=frs_atk)//�����J���T
                    printf("\n���𨤦⬰%d�B��𨤦⬰%d\n",frs_atk,sec_atk);
                else if(sec_atk==frs_atk)//�����P��𨤦⭫�ơA�L�X���~ĵ�i
                    printf("���~:���i���ƿ��\n");
                else
                    printf("���~:�L������\n");//���𨤦��J��1~4�H�~�Ʀr�A�L�X���~ĵ�i
                break;
            default :
                printf("���~:�L������\n");//����𨤦��J��1~4�H�~�Ʀr�A�L�X���~ĵ�i
            }


        }
        return 0;
    }


    if(chos==2) {
        //��ܤ��s�W����
        printf("\n");
        printf("��ܥ��𨤦�:");
        scanf("%d",&frs_atk);
        if(frs_atk== 1||frs_atk==2||frs_atk==3) {
            printf("��ܫ�𨤦�:");
            scanf("%d",&sec_atk);
            if((sec_atk==1 || sec_atk==2 || sec_atk==3) && sec_atk != frs_atk)
                printf("\n���𨤦⬰%d�B��𨤦⬰%d\n",frs_atk,sec_atk);
            else if(sec_atk==frs_atk)
                printf("���~:���i���ƿ��\n");
            else
                printf("���~:�L������\n");
            return 0;
        } else //��J(1.Yes/2.No)���~���Ʀr�A�L�X���~ĵ�i
            printf("��J���~\n");
        return 0;
    }
}




