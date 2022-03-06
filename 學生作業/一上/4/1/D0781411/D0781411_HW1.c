#include <stdio.h>
#include <stdlib.h>

int main()
{
    //角色1
	char char1_type = 'F';
	int char1_hp = 40;
	int char1_atk = 20;
	int char1_def = 10;
	float char_1 = (char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;
	printf("角色1\n名稱：豆豆\n");
	printf("屬性： %c  ",char1_type);
	printf("攻擊：%d\n",char1_atk);
	printf("血量：%d  ",char1_hp);
	printf("防禦：%d\n\n",char1_def);
	printf("角色強度：%.2f\n\n",char_1);
	//角色2
	char char2_type = 'W';
	int char2_hp = 50;
	int char2_atk = 15;
	int char2_def = 5;
	float char_2 = (char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
	printf("角色2\n名稱：薛薛\n");
	printf("屬性： %c  ",char2_type);
	printf("攻擊：%d\n",char2_atk);
	printf("血量：%d  ",char2_hp);
	printf("防禦：%d\n\n",char2_def);
	printf("角色強度：%.2f\n\n",char_2);
	//角色3
	char char3_type = 'G';
	int char3_hp = 45;
	int char3_atk = 15;
	int char3_def = 10;
	float char_3 = (char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
	printf("角色3\n名稱：貓咪\n");
	printf("屬性： %c  ",char3_type);
	printf("攻擊：%d\n",char3_atk);
	printf("血量：%d  ",char3_hp);
	printf("防禦：%d\n\n",char3_def);
	printf("角色強度：%.2f\n\n",char_3);
	//角色4
	int main();
	int char4_type;
	int char4_atk;
	int char4_hp;
	int char4_def;
	printf("新增角色\n屬性:");
	scanf ("%c",&char4_type);
	printf("血量:");
	scanf ("%d",&char4_hp);
	printf("攻擊:");
	scanf ("%d",&char4_atk);
	printf("防禦:");
	scanf ("%d",&char4_def);
	float char_4 = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
	printf("\n角色4\n名稱：破腦\n");
	printf("屬性： %c  ",char4_type);
	printf("攻擊：%d\n",char4_atk);
	printf("血量：%d  ",char4_hp);
	printf("防禦：%d\n",char4_def);
	printf("角色強度：%.2f\n\n",char_4);
	return 0;
}	
