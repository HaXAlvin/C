#include<stdio.h>
int main(){
    int num1,fall=0,tag=0,count=0,membernum=2;
    char type[4]={'W','G','A'}; //�ݩ�
    float hp[4]={50,43,48} ; //��q
    float atk[4]={15,17,15} ; //����
    float def[4]={5,5,7}; //���m
    int num[4]={1,2,3}; //����s��
    char char1_name[210]={'�p','�Q'}; //����1
    char char2_name[210]={'��','�I'}; //����2
    char char3_name[210]={'��','�B'}; //����3
    char char4_name[210];
    float char1=(hp[0]* 1.0 + atk[0]* 0.8 + def[0]* 0.5 - 50 ) * 6.5;
    float char2=(hp[1]* 1.0 + atk[1]* 0.8 + def[1]* 0.5 - 50 ) * 6.5;
    float char3=(hp[2]* 1.0 + atk[2]* 0.8 + def[2]* 0.5 - 50 ) * 6.5;
    int char5,char6; //���𨤦� ��𨤦�
    float temp,temp2; //�x�s��l��q


    while(tag==0){
        printf("case 1. �s�W�έק�s�W����\ncase 2. ��ܩҦ�������\ncase 3. �԰�\ncase 0. �����C��\n�п�� : ");
        scanf("%d",&num1);
        printf("\n");
        if(num1==0||num1==1||num1==2||num1==3){
            if(num1==0){
                printf("�����C��\n");
                printf("\n");
                return 0;
            }
            if(num1==1){
                do{ if(count==0){
                    printf("�s�W����\n");
                    membernum=2;
                    }
                    else if(count>0){
                        printf("�ק�s�W����\n");
                        membernum=2;
                    }
                    printf("�W��: "), scanf("%s",char4_name);
                    getchar();
                    printf("�ݩ�: "), scanf("%c",&type[3]);
                    printf("��q: "), scanf("%f",&hp[3]);
                    printf("����: "), scanf("%f",&atk[3]);
                    printf("���m: "), scanf("%f",&def[3]);
                    printf("\n");
                    int sum=hp[3]+atk[3]+def[3]; //����ƭ��`�M
                    if((type[3]=='F'||type[3]=='W'||type[3]=='G'||type[3]=='A')&&(atk[3]>=15&&atk[3]<=20)&&(hp[3]<=50&&hp[3]>=40)&&(def[3]>=5&&def[3]<=10)&&(sum<=70&&sum>=65)){ //�Y�ݩʬ��j�g �B��O�ƭȬҩM��O�d��ҥ��T
                        printf("����4\n�W��:%s\n�ݩ�:%c    ����:%.0f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n",char4_name,type[3],atk[3],hp[3],def[3],(hp[3]* 1.0 + atk[3]* 0.8 + def[3]* 0.5 - 50 ) * 6.5);
                        fall=1;
                        num[3]=4; //�s�W����s��
                        membernum=membernum+1;
                        break;
                    }
                    else if((type[3]==102||type[3]==119||type[3]==103||type[3]==97)&&(atk[3]>=15&&atk[3]<=20)&&(hp[3]<=50&&hp[3]>=40)&&(def[3]>=5&&def[3]<=10)&&(sum<=70&&sum>=65)){ //�Y�ݩʬ��p�g �B��O�ƭȬҩM��O�d��ҥ��T
                        type[3]=type[3]-32 ;
                        printf("����4\n�W��:%s\n�ݩ�:%c    ����:%0.f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n",char4_name,type[3],atk[3],hp[3],def[3],(hp[3]* 1.0 + atk[3]* 0.8 + def[3]* 0.5 - 50 ) * 6.5);
                        fall=1;
                        num[3]=4; //�s�W����s��
                        membernum=membernum+1;
                        break;
                    }
                    else if((type[3]=='f'||type[3]=='w'||type[3]=='g'||type[3]=='a'||type[3]=='F'||type[3]=='W'||type[3]=='G'||type[3]=='A')&&((atk[3]<15||atk[3]>20)||(hp[3]>50||hp[3]<40)||(def[3]<5||def[3]>10)||(sum>70||sum<65))){
                            printf("���~:��O�ƭȦb����d�򤧥~\n"); //�Y�ݩʿ�J���T ����O�ƭȩί�O�d�򦳿�
                             printf("\n");
                            fall=0;
                    }
                    else if((type[3]!='f'||type[3]!='w'||type[3]!='g'||type[3]!='a'||type[3]!='F'||type[3]!='W'||type[3]!='G'||type[3]!='A')&&((atk[3]<15||atk[3]>20)||(hp[3]>50||hp[3]<40)||(def[3]<5||def[3]>10)||(sum>70||sum<65))){
                            printf("���~:�L���ݩ�\n���~:��O�ƭȦb����d�򤧥~\n"); // //�Y�ݩʿ�J�����T �B��O�ƭȩί�O�d�򦳿�
                             printf("\n");
                            fall=0;
                    }
                    else if((type[3]!='f'&&type[3]!='w'&&type[3]!='g'&&type[3]!='a'&&type[3]!='F'&&type[3]!='W'&&type[3]!='G'&&type[3]!='A')&&((atk[3]>15||atk[3]<20)||(hp[3]<50||hp[3]>40)||(def[3]>5||def[3]<10)||(sum<=70||sum>=65))){
                            printf("���~:�L���ݩ�\n"); // //�Y�ݩʿ�J�����T ����O�ƭȩM��O�d�򥿽T
                            fall=0;
                    }
                    num[3]=4;
                }while(fall==0);
                printf("\n");
                count=count+1;
            }
            if(num1==2){
                printf("����1\n�W��:�p�Q\n�ݩ�:W    ����:15\n��q:50   ���m:5\n����j�׹w��:%.2f\n\n"
                       "����2\n�W��:���I\n�ݩ�:G    ����:17\n��q:43   ���m:5\n����j�׹w��:%.2f\n\n"
                       "����3\n�W��:���B\n�ݩ�:A    ����:15\n��q:48   ���m:7\n����j�׹w��:%.2f\n\n",char1,char2,char3
                );
                if(membernum==3){
                    printf("����4\n�W��:%s\n�ݩ�:%c    ����:%.0f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n",char4_name,type[3],atk[3],hp[3],def[3],(hp[3]* 1.0 + atk[3]* 0.8 + def[3]* 0.5 - 50 ) * 6.5);
                }
                printf("\n");
            }
            if(num1==3){
                do{
                    printf("��ܥ��𨤦�:") , scanf("%d",&char5);
                    char5=char5-1;
                    if (num[char5]>0&&num[char5]<5){ //�Y����Ʀr��J���T
                        do{
                            printf("��ܫ�𨤦�:");
                            scanf("%d",&char6);
                            char6=char6-1;

                            if(num[char5]==num[char6]){ //�Y����ۦP
                                printf("���i���ƿ��\n");
                                fall=0;
                            }
                            else if (num[char6]>0&&num[char6]<5){ // �Y����Ʀr��J���T �B���⤣�ۦP
                                char5=char5+1 ,char6=char6+1 ;
                                printf("���𬰨���%d�B��𨤦⬰%d\n",char5,char6);
                                printf("�԰��}�l\n\n");

                                char5=char5-1 , char6=char6-1; //�ର�}�C�̭����Ʀr
                                temp=hp[char5]; //�x�s��l��q
                                temp2=hp[char6];//�x�s��l��q
                                while(hp[char5]>0 &&hp[char6]>0){
                                    float kr1, kr2; //�۫g���v
                                    if((type[char5]=='W'&&type[char6]=='F')||(type[char5]=='F'&&type[char6]=='A')||(type[char5]=='A'&&type[char6]=='G')||(type[char5]=='G'&&type[char6]=='W')){
                                        kr1=atk[char5]*1.2 , kr2=atk[char6]*0.8 ;  //���𭿲v�j
                                    }
                                    else if((type[char6]=='W'&&type[char5]=='F')||(type[char6]=='F'&&type[char5]=='A')||(type[char6]=='A'&&type[char5]=='G')||(type[char6]=='G'&&type[char5]=='W')){
                                        kr1=atk[char5]*0.8  , kr2=atk[char6]*1.2;  //��𭿲v�j
                                    }
                                    else{
                                        kr1=atk[char5] ,kr2=atk[char6] ;
                                    }
                                    //�H�W����w�۫g���v
                                    int hurt1;
                                    float blood1=1; //�ˮ`���� �ݦ孿�v
                                    int hurt2;
                                    float blood2=1; //�ˮ`���� �ݦ孿�v



                                    if(hp[char5]>0){ //������q�j��0
                                        if(hp[char5]<temp*0.5){
                                            blood1=blood1*1.2; //�ŦX�ݦ孿�v

                                        }

                                        hurt1=kr1*blood1-def[char6]; //���𪺧����ˮ`�ƭ�
                                        hp[char6]=hp[char6]-hurt1;//���Q�����᪺��q

                                        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",num[char5],num[char6],hurt1);
                                        printf("���� %d HP:%.0f ���� %d HP:%.0f\n",num[char5],hp[char5],num[char6],hp[char6]);
                                        printf("\n");
                                    }
                                    else{
                                        printf("���� %d ���h�԰��O\n�԰�����\n\n���� %d ���\n",num[char5],num[char6]);
                                    }
                                    if(hp[char6]<temp2*0.5){ //�ŦX�ݦ孿�v
                                        blood2=blood2*1.2;

                                    }
                                    if(hp[char6]>0){ //�p�G����q�j��0
                                        hurt2=kr2*blood2-def[char5]; //��𪺧����ˮ`�ƭ�
                                        hp[char5]=hp[char5]-hurt2;//����Q�����᪺��q
                                        printf("����%d �� ����%d �o�ʧ����A�y�� %d �I�ˮ`\n",num[char6],num[char5],hurt2);
                                        printf("���� %d HP:%.0f ���� %d HP:%.0f\n",num[char6],hp[char6],num[char5],hp[char5]);
                                        printf("\n");
                                        if(hp[char5]<0){ //�Y���𦺤`
                                            printf("���� %d ���h�԰��O\n�԰�����\n\n���� %d ���\n",num[char5],num[char6]);
                                        }

                                    }
                                    else{
                                        printf("���� %d ���h�԰��O\n�԰�����\n\n���� %d ���\n",num[char6],num[char5]);
                                        fall=1;

                                    }

                                }
                                hp[char5]=temp; //�_���q
                                hp[char6] =temp2;//�_���q


                                fall=1;
                            }
                            else{
                                printf("���~:�L������\n");
                            }
                        }while(fall==0);


                    break;
                    }
                    else //��J�L�����Ÿ�
                        printf("���~:�L������\n");
                        fall=0;
                }while(fall==0);
                printf("\n");
            }
        }
        else{
            printf("��J���~!\n");
            printf("\n");
        }
    }
    return 0;
}
