#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    //���� ��O / �m�W 
    char name[200][200] ={"����","����","�߫}"};
    char char_type [5] = {'F','W','G'};
    char counter_type[4] ={'W','F','A','G'};//�@W>F>A>G>W 
    int char_hp [5] = {40,50,45};
    int weak_hp [5] = {20,25,22};
    int char_atk [5] = {20,15,15};
    int char_def [5] = {10,5,10};
    double  char_power [5]={0};
    int i=0;//�j��Ϊ� 
    for(i=0;i<4;i++)
    { 
    	char_power [i] = (char_hp[i]*1.0+char_atk[i]*0.8+char_def[i]*0.5-50)*6.5;
    } 
    //���� ��O / �m�W 
    int attack_first; //���𨤦� 
    int attack_second; //��𨤦� 
    int attack_first_hp;//���𨤦⪺�ͩR
    int attack_first_atk;//���𨤦⪺����
    int attack_first_def;//���𨤦⪺���m
    char attack_first_type;//�����ݩ� 
    int attack_second_hp;//��𨤦⪺�ͩR
    int attack_second_atk;//��𨤦⪺����
    int attack_second_def;//��𨤦⪺���m
	char attack_second_type;//����ݩ�	
    int j;//�j��Χ� 
    int type_control;//�۫g�P�w�� 
    int game_type=1;//�A�n�F�� 
    int max_char=3;//����̤j�� 
    int attack_first_weak_hp;//���𨤦⪺��z��q 
    int attack_second_weak_hp;//��𨤦⪺��z��q 
    int first_char_hurt;//���𨤦���쪺�ˮ` 
    int second_char_hurt;//��𨤦���쪺�ˮ` 
    double  attack_first_count=1;//���𨤦⥴�X�ˮ`��count���v
    double  attack_second_count=1;//��𨤦⥴�X�ˮ`��count���v
    double  attack_first_weak=1;//���𨤦⥴�X�ˮ`����z���v  
    double  attack_second_weak=1;//��𨤦⥴�X�ˮ`����z���v  
    double  first_complex_magnification;//���𨤦�Q���쪺��X���v 
    double  second_complex_magnification;//��𨤦�Q���쪺��X���v 
    int  damage_first;
    int  damage_second;
    //while�j�j��}�l
	//�i�J�C��   
    printf("1. �s�W�έק﨤��\n");
    printf("2. ��ܩҦ�������\n");
    printf("3. �԰�\n");
    printf("0. �����C��\n");
    printf("�п��:");
    while(scanf("%d%*c",&game_type)&&game_type!=0)  //�O0�N���� 
    {
		// �ﶵ1  �s�W���� 
	    if (game_type==1)
	    {
	    	if(max_char==3)   //�S���s�W������ 
	    	{
	    		printf("\n�s�W����\n");
			}
			if(max_char==4)	  //�ڲ{�b�n�ק﨤�� 
			{
				printf("�ק�s�W����\n");
			}
			printf("����W��:");   //�q�o�̶}�l�O�s���⪺ ��O��/ID  �٦��@�Ǿ԰��Ϊ��]�w 
	    	gets(name[3]);
	        printf("�����ݩ�:");
	        scanf ("%c%*c",&char_type[3]);
	        char_type[3]=toupper(char_type[3]);//�p�g��j�g
	        printf("��q:");
	        scanf ("%d",&char_hp[3]);
	        printf("����:");
	        scanf ("%d",&char_atk[3]);
	        printf("���m:");
	        scanf ("%d%*c",&char_def[3]);
	        while(char_type[3]!=65&&char_type[3]!=70&&char_type[3]!=71&&char_type[3]!=87||char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||(char_def[3]+char_hp[3]+char_atk[3])>70||(char_def[3]+char_hp[3]+char_atk[3])<65)
	        {
	            if(char_type[3]!=65&&char_type[3]!=70&&char_type[3]!=71&&char_type[3]!=87)
	            {
	                printf("���~:�L���ݩ�\n\n");
	            }
	            if(char_atk[3]>20||char_atk[3]<15||char_hp[3]>50||char_hp[3]<40||char_def[3]<5||char_def[3]>10||(char_def[3]+char_hp[3]+char_atk[3])>70||(char_def[3]+char_hp[3]+char_atk[3])<65)
	            {
	                printf("���~:��O�ƭȦb����d�򤧥~\n\n");
	            }
	            printf("����W��:");
		    	gets(name[3]);
		        printf("�����ݩ�:");
		        scanf ("%c%*c",&char_type[3]);
		        char_type[3]=toupper(char_type[3]);//�p�g��j�g
		        printf("��q:");
		        scanf ("%d",&char_hp[3]);
		        printf("����:");
		        scanf ("%d",&char_atk[3]);
		        printf("���m:");
		        scanf ("%d%*c",&char_def[3]);
	        }
	        printf("\n");
	        char_power [3] = (char_hp[3]*1.0+char_atk[3]*0.8+char_def[3]*0.5-50)*6.5;
	        for(i=3;i<=3;i++)
	        {
	        	printf("����%d\n",i+1);
			    printf("�W��:%s\n",name[i]);
		       	printf("�ݩ�:%c    ����:%d\n",char_type[i],char_atk[i]);
		    	printf("��q:%d   ���m:%d\n",char_hp[i],char_def[i]);
		        printf("����j��:%.2f\n\n",char_power[i]);
			}
	        weak_hp [3] = char_hp[3]/2;
		    max_char=4;
	    }
	    //�ﶵ2   ��X������ 
	    else if(game_type==2)
	    {
	    	printf("\n");
		    for(i=0;i<max_char;i++)   
		    {
			    printf("����%d\n",i+1);
			    printf("�W��:%s\n",name[i]);
		       	printf("�ݩ�:%c    ����:%d\n",char_type[i],char_atk[i]);
		    	printf("��q:%d   ���m:%d\n",char_hp[i],char_def[i]);
		        printf("����j��:%.2f\n\n",char_power[i]);
			}
	    }
	    //�ﶵ3  �԰� 
	    //�ק��I
	    else if(game_type==3)
        {
        	attack_first_count=1; //�J��v���m 
        	attack_second_weak=1; //��z���v���m 
			attack_first_weak=1;  //��z���v���m 
            printf("\n��J���𨤦�:");  //�o�̶}�l�﨤�� 
            scanf("%d",&attack_first);
            while (attack_first>max_char||attack_first<1) //����u��1~max_char ����d��  1<=����<=max_char
            {
                printf("���~:�L������\n");
                printf("������𨤦�");
                scanf("%d",&attack_first);
            }
            if(attack_first<=max_char||attack_first>=1)
            {
                printf("��J��𨤦�");
                scanf("%d",&attack_second);
                while(attack_first==attack_second||attack_second>max_char||attack_second<1)//����u��1~max_char ����d��  1<=����<=max_char
                {
                    if(attack_first==attack_second)
                    {
                        printf("���~:���i���ƿ��\n");
                    }
                    if(attack_second>max_char||attack_second<1)
                    {
                        printf("���~:�L������\n");
                    }
                    printf("��J��𨤦�");
                    scanf("%d", &attack_second);
                }
            }
            //�﨤���� 
            printf("\n���𨤦⬰%d,��𨤦⬰%d\n",attack_first,attack_second);
            printf("�԰��}�l\n\n");
            // ���𨤦��O�� 
            attack_first_atk=char_atk[attack_first-1];
            attack_first_hp=char_hp[attack_first-1];
            attack_first_def=char_def[attack_first-1];
            attack_first_type=char_type[attack_first-1];
            attack_first_weak_hp=attack_first_hp/2;
			//��𨤦��O�� 
            attack_second_atk=char_atk[attack_second-1];
            attack_second_hp=char_hp[attack_second-1];
            attack_second_def=char_def[attack_second-1];
            attack_second_type=char_type[attack_second-1];
			attack_second_weak_hp=attack_second_hp/2;
			// ��O��(�۫g) 
            if(attack_first_type=='W')
            {
            	type_control=0;
			}
			if(attack_first_type=='F')
            {
            	type_control=1;
			}
			if(attack_first_type=='A')
            {
            	type_control=2;
			}
			if(attack_first_type=='G')
            {
            	type_control=3;
			}
			if(counter_type[(type_control+1)%4]==attack_second_type) //����J����   �O�o���v���m 
			{
				attack_first_count=1.2;
			} 
			if(counter_type[(type_control+3)%4]==attack_second_type) //���J����� 
			{
				attack_first_count=0.8;
			}
			attack_second_count=2-attack_first_count; //���v�ۥ[��2 
			//printf("�ڬO���𪺱d�S���v: %f\n",attack_first_count);
			//printf("�ڬO��𪺱d�S���v: %f\n",attack_second_count);
			//�԰����`
			while(attack_first_hp>0&&attack_second_hp>0)
			{
				if(attack_first_hp<attack_first_weak_hp) //����𨤵�z�� 
				{
					attack_second_weak=1.2;  //��𨤪����v�W�� 
					//printf("���𨤦��z\n\n");
				}
				if(attack_second_hp<attack_second_weak_hp) //����𨤵�z�� 
				{
					attack_first_weak=1.2; //���𨤪����v�W�� 
					//printf("��𨤦��z\n\n");
				}
				first_char_hurt=attack_second_atk*(attack_second_count*attack_second_weak)-attack_first_def;//���𨤦� ���쪺�ˮ`   �o�̤����`  �ڤ��Odebug�Ϊ� 
				second_char_hurt=attack_first_atk*(attack_first_count*attack_first_weak)-attack_second_def;//��𨤦� ���쪺�ˮ`   �ڤ��Odebug�Ϊ�  
				//�԰��ɰʺA�ƭȳ]�w����
				if(attack_first_hp>0&&attack_second_hp>0)
				{
					attack_second_hp=attack_second_hp-second_char_hurt;
					printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",attack_first,attack_second,second_char_hurt);
					printf("����%d HP :%d\n",attack_first,attack_first_hp);
	       		 	printf("����%d HP :%d\n\n",attack_second,attack_second_hp);
	       		}
       		 	if(attack_second_hp<=0)
        		{
		            printf("����%d ���h�԰���O\n",attack_second);
		            printf("�԰�����\n\n");
		            printf("����%d ���\n\n",attack_first);
        		}
        		
        		if(attack_first_hp>0&&attack_second_hp>0)
				{
					attack_first_hp=attack_first_hp-first_char_hurt;
					printf("����%d �� ����%d �o�ʧ����A�y��%d�I�ˮ`\n",attack_second,attack_first,first_char_hurt);
					printf("����%d HP :%d\n",attack_first,attack_first_hp);
       		 		printf("����%d HP :%d\n\n",attack_second,attack_second_hp);
	       		}
  
       		 	if(attack_first_hp<=0&&attack_second_hp>0)
		        {
		            printf("����%d ���h�԰���O\n",attack_first);
		            printf("�԰�����\n\n");
		            printf("����%d ���\n\n",attack_second);
		        }
			} 
        }
	    //�ﶵ��L
		else
		{
			printf("\n��J���~!\n");
		}
    	printf("1. �s�W�έק﨤��\n");
		printf("2. ��ܩҦ�������\n");
		printf("3. �԰�\n");
		printf("0. �����C��\n");	
		printf("�п��:");
	}
}	// �������j�A��
