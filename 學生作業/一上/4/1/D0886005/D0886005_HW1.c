 #include<stdio.h>
 #include<stdlib.h>
 int main(){
    //角色1
	char char1_type = 'W';
	int char1_hp = 45;
	int char1_atk = 18;
	int char1_def = 6;
	float char1=(char1_hp* 1.0 + char1_atk* 0.8 + char1_def* 0.5 - 50 ) * 6.5;
	//角色2
	char char2_type = 'G';
	int char2_hp = 43;
	int char2_atk = 17;
	int char2_def = 5;
	float char2=(char2_hp* 1.0 + char2_atk* 0.8 + char2_def* 0.5 - 50 ) * 6.5;
	//角色3
	char char3_type = 'A';
	int char3_hp = 48;
	int char3_atk = 15;
	int char3_def = 7;
    float char3=(char3_hp* 1.0 + char3_atk* 0.8 + char3_def* 0.5 - 50 ) * 6.5;
	//自訂角色
	char char4_type ;
	int char4_hp ;
	int char4_atk ;
	int char4_def ;

	 printf("角色1\n名稱:雷利\n屬性:W    攻擊:18\n血量:45   防禦:6\n角色強度預測:%.2f\n"
            "角色2\n名稱:阿呼\n屬性:G    攻擊:17\n血量:43   防禦:5\n角色強度預測:%.2f\n"
            "角色3\n名稱:布榖\n屬性:A    攻擊:15\n血量:48   防禦:7\n角色強度預測:%.2f\n",char1,char2,char3
			);

	printf("請玩家設定自訂角色\n");
	printf("請輸入屬性(F=火、W=水、G=土、A=風):");
	scanf("%c",&char4_type);
	printf("請輸入攻擊力:");
	scanf("%d",&char4_atk);
	printf("請輸入血量:");
	scanf("%d",&char4_hp);
	printf("請輸入防禦力:");
	scanf("%d",&char4_def);
	printf("自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n",char4_type,char4_atk,char4_hp,char4_def,(char4_hp* 1.0 + char4_atk* 0.8 + char4_def* 0.5 - 50 ) * 6.5);
	return 0;
 }
