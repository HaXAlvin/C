#include<stdio.h>
int fall=0;
void EditNewChar(char name[],char type,float atk,float hp,float def,int sum){
    sum=hp+atk+def;
    int num[4];

    if((type=='F'||type=='W'||type=='G'||type=='A')&&(atk>=15&&atk<=20)&&(hp<=50&&hp>=40)&&(def>=5&&def<=10)&&(sum<=70&&sum>=65)){ //�Y�ݩʬ��j�g �B��O�ƭȬҩM��O�d��ҥ��T
        printf("����4\n�W��:%s\n�ݩ�:%c    ����:%.0f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
        fall=1;
        return ;

    }
    else if((type==102||type==119||type==103||type==97)&&(atk>=15&&atk<=20)&&(hp<=50&&hp>=40)&&(def>=5&&def<=10)&&(sum<=70&&sum>=65)){ //�Y�ݩʬ��p�g �B��O�ƭȬҩM��O�d��ҥ��T
        type=type-32 ;
        printf("����4\n�W��:%s\n�ݩ�:%c    ����:%0.f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
        fall=1;
        return ;
        //break;
        }
    else if((type=='f'||type=='w'||type=='g'||type=='a'||type=='F'||type=='W'||type=='G'||type=='A')&&((atk<15||atk>20)||(hp>50||hp<40)||(def<5||def>10)||(sum>70||sum<65))){
        printf("���~:��O�ƭȦb����d�򤧥~\n"); //�Y�ݩʿ�J���T ����O�ƭȩί�O�d�򦳿�
        printf("\n");
        fall=0;
    }
    else if((type!='f'||type!='w'||type!='g'||type!='a'||type!='F'||type!='W'||type!='G'||type!='A')&&((atk<15||atk>20)||(hp>50||hp<40)||(def<5||def>10)||(sum>70||sum<65))){
        printf("���~:�L���ݩ�\n���~:��O�ƭȦb����d�򤧥~\n"); // //�Y�ݩʿ�J�����T �B��O�ƭȩί�O�d�򦳿�
        printf("\n");
        fall=0;
    }
    else if((type!='f'&&type!='w'&&type!='g'&&type!='a'&&type!='F'&&type!='W'&&type!='G'&&type!='A')&&((atk>15||atk<20)||(hp<50||hp>40)||(def>5||def<10)||(sum<=70||sum>=65))){
        printf("���~:�L���ݩ�\n"); // //�Y�ݩʿ�J�����T ����O�ƭȩM��O�d�򥿽T
        fall=0;
    }
    return ;
}


void PrintCharData(char name[],char type,float atk,float hp ,float def){
    printf("�W��:%s\n�ݩ�:%c    ����:%.0f\n��q:%.0f   ���m:%.0f\n����j�׹w��:%.2f\n\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
    return ;
}
void Battling(int char5,int char6,float hp[],char type[],float atk[],int num[],float def[]){
    float temp,temp2;//�x�s��l��q
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


void SelectAndBattle(int char5,int char6,int num[],float hp[],char type[],float atk[],float def[]){
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
                    printf("\n");
                    printf("���𬰨���%d�B��𨤦⬰%d\n",char5,char6);
                    printf("�԰��}�l\n\n");
                    Battling(char5,char6,hp,type,atk,num,def);
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
}



int main(){
    int num1,tag=0,count=0,membernum=2;
    char type[4]={'W','G','A'}; //�ݩ�
    float hp[4]={50,43,48} ; //��q
    float atk[4]={15,17,15} ; //����
    float def[4]={5,5,7}; //���m
    int num[4]={1,2,3}; //����s��
    char char1_name[2100]={"�w�w"}; //����1
    char char2_name[2100]={"���I"}; //����2
    char char3_name[2100]={"���B"}; //����3
    char char4_name[2100];
    int char5,char6; //���𨤦� ��𨤦�



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
                do{
                    if(count==0){
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
                    EditNewChar(char4_name,type[3],  atk[3],hp[3],def[3],sum) ;
                    if(type[3]==102||type[3]==119||type[3]==103||type[3]==97) {//�Y�ݩʬ��p�g
                        type[3]=type[3]-32 ; //�ର�j�g
                    }
                    membernum=membernum+1;
                    num[3]=4;
                }while(fall==0);
                printf("\n");
                count=count+1;
            }
            if(num1==2){
                printf("����1\n"),PrintCharData(char1_name,type[0],atk[0],hp[0] ,def[0]);
                printf("����2\n"),PrintCharData(char2_name,type[1],atk[1],hp[1] ,def[1]);
                printf("����3\n"),PrintCharData(char3_name,type[2],atk[2],hp[2] ,def[2]);

                if(membernum==3){
                    printf("����4\n"),PrintCharData(char4_name,type[3],atk[3],hp[3] ,def[3]);
                }
                printf("\n");
            }
            if(num1==3){
                SelectAndBattle(char5,char6,num,hp,type,atk,def);
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
