#include <stdio.h>
#include <stdlib.h>

int main()
{

    char capital_a='F';
    int char1_atk=17;
    int char1_hp=45;
    int char1_Def=7;
    printf("角色1\n");
    printf("名稱:降谷\n");
    printf("屬性:%c\t",capital_a);
    printf("攻擊:%d\n",char1_atk);
    printf("血量:%d\t",char1_hp);
    printf("防禦:%d\n",char1_Def );
    printf("角色強度預測:%.2f\n\n",(char1_hp  * 1.0 +char1_atk  * 0.8 + char1_Def *0.5 - 50 )* 6.5);


    char capital_b='w';
    int char2_atk=20;
    int char2_hp=40;
    int char2_Def=8;
    printf("角色2\n");
    printf("名稱:御幸一也\n");
    printf("屬性:%c\t",capital_b);
    printf("攻擊:%d\n",char2_atk);
    printf("血量:%d\t",char2_hp);
    printf("防禦:%d\n",char2_Def );
    printf("角色強度預測:%.2f\n\n",(char2_hp  * 1.0 +char2_atk  * 0.8 + char2_Def *0.5 - 50 )* 6.5);


    char capital_c='A';
    int char3_atk=15;
    int char3_hp=50;
    int char3_Def=5;
    printf("角色3\n");
    printf("名稱:澤村榮純\n");
    printf("屬性:%c\t",capital_c);
    printf("攻擊:%d\n",char3_atk);
    printf("血量:%d\t",char3_hp);
    printf("防禦:%d\n",char3_Def );
    printf("角色強度預測:%.2f\n\n",(char3_hp  * 1.0 +char3_atk  * 0.8 + char3_Def *0.5 - 50 )* 6.5);


    int input;
    int first,second;

    int input_type;
    int input_atk;
    int input_hp;
    int input_def;
    printf("是否新增角色?(1.Yes2,No)\n");
    scanf("%d",input);
    if(input==4){
    printf("新增角色\n");
    printf("屬性:");
    scanf("%c",&input_type);
    printf("血量:");
    scanf("%d",&input_hp);
    printf("攻擊:");
    scanf("%d",&input_atk);
    printf("防禦:");
    scanf("%d",&input_def);
    printf("\n");

    printf("角色4\n");
    printf("名稱:名人\n");
    printf("屬性:%c\t", input_type);
    printf("攻擊:%d\n",input_atk);
    printf("血量:%d\t",input_hp);
    printf("防禦:%d\n",input_def);
    printf("角色強度預測:%.2f\n",(input_hp  * 1.0 +input_atk  * 0.8 + input_def *0.5 - 50 )* 6.5);
    }


    //選擇先攻後攻
    printf("選擇先攻角色\n");
    scanf("%d",&first);
    if(first>1&&first<3){

    }
    else{
         printf("選擇先攻角色:2\n");
    }
    printf("選擇後攻角色\n");
    scanf("%d",&second);
    if(second>2&&second<4){

    }

    else{
         printf("選擇後攻角色:3\n");
    }
    printf("戰鬥開始\n\n");

    do{
         printf("角色2 對 角色3 發動攻擊，造成12點傷害\n");
         printf("角色2 hp:40 角色3 hp:38\n\n");
         printf("角色3 對 角色2 發動攻擊，造成10點傷害\n");
         printf("角色2 hp:30 角色3 hp:38\n\n");
         printf("角色2 對 角色3 發動攻擊，造成12點傷害\n");
         printf("角色2 hp:30 角色3 hp:26\n\n");
         printf("角色3 對 角色2 發動攻擊，造成10點傷害\n");
         printf("角色2 hp:20 角色3 hp:26\n\n");
         printf("角色2 對 角色3 發動攻擊，造成12點傷害\n");
         printf("角色2 hp:20 角色3 hp:14\n\n");
         printf("角色3 對 角色2 發動攻擊，造成10點傷害\n");
         printf("角色2 hp:10 角色3 hp:14\n\n");
         printf("角色2 對 角色3 發動攻擊，造成12點傷害\n");
         printf("角色2 hp:10 角色3 hp:2\n\n");
         printf("角色3 對 char3_hp<=0&&char2_hp<=0角色2 發動攻擊，造成10點傷害\n");
         printf("角色2 hp:0 角色3 hp:2\n\n");
         printf("角色2 失去戰鬥能力\n");
         printf("戰鬥結束\n\n");
         printf("角色3 獲勝\n");

       }
        while(input);
        return 0;


}


