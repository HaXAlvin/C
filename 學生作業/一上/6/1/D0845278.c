#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
int main(){

	char char1_type = 'W'; char char2_type = 'F'; char char3_type = 'A';
	int char1_hp  = 40; int char2_hp  = 45; int char3_hp  = 42;
	int char1_atk = 20; int char2_atk = 15; int char3_atk = 17;
	int char1_def = 5 ; int char2_def = 10; int char3_def = 7 ;
	float char1_strongpre ;float char2_strongpre ;float char3_strongpre ;
	char1_strongpre = (char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5-50) * 6.5;
	char2_strongpre = (char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5-50) * 6.5;
	char3_strongpre = (char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5-50) * 6.5;
    //強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    printf("角色1\n名稱:劍指蒼穹\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char1_type,char1_atk,char1_hp,char1_def,char1_strongpre);
    printf("角色2\n名稱:敲血為凝\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char2_type,char2_atk,char2_hp,char2_def,char2_strongpre);
    printf("角色3\n名稱:超鬼特工\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",char3_type,char3_atk,char3_hp,char3_def,char3_strongpre);
    int addchar;
    int first_atk_char;
    int last_atk_char;
    do{
        printf("是否新增角色(1.Yes/2.No)?");
        scanf("%d",&addchar);
        if(addchar!=1&&addchar!=2){
            printf("輸入錯誤\n");
        }
    }while(addchar!=1&&addchar!=2);
    //規定使用著輸入範圍,並判斷是否合乎規定
    char char4_type ; int char4_hp; int char4_atk; int char4_def;float char4_strongpre;//新增角色4
    if(addchar==1){	//使用者選擇"是"
        printf("\n新增角色\n");
    	do{
    		char4_type = getchar();
    		printf("類型(F=火、W=水、G=土、A=風):");
            scanf("%c", &char4_type);
		    if(char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a'){ //一旦使用著輸入非屬性的字母，顯示錯誤
                printf("錯誤:無此屬性");
                return 0;
		    }
    	}while(char4_type!='F'&&char4_type!='W'&&char4_type!='G'&&char4_type!='A'&&char4_type!='f'&&char4_type!='w'&&char4_type!='g'&&char4_type!='a');
        do{
            do{
                printf("血量(40~50):");
                scanf("%d",&char4_hp);
                if (char4_hp<40||char4_hp>50){
            	    printf("\n錯誤:能力數值在限制範圍之外\n");
                }
            }while(char4_hp<40||char4_hp>50);

            do{
                printf("攻擊(15~20):");
                scanf("%d",&char4_atk);
                if (char4_atk<15||char4_atk>20){
            	    printf("\n錯誤:能力數值在限制範圍之外\n");
                }
            }while(char4_atk<15||char4_atk>20);

            do{
                printf("防禦(5~10):");
                scanf("%d", &char4_def);
                if (char4_def<5||char4_def>10){
            	    printf("\n錯誤:能力數值在限制範圍之外\n");
                }
            }while(char4_def<5||char4_def>10);
            if(char4_def + char4_hp + char4_atk<65||char4_def + char4_hp + char4_atk>70){
                printf("\n錯誤:能力數值在限制範圍之外\n");
            }
        }while(char4_def + char4_hp + char4_atk<65||char4_def + char4_hp + char4_atk>70);
        //計算新增角色的強度，並印出角色4的最終資訊
        char4_strongpre = (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5-50) * 6.5;
        printf("\n角色4\n名稱:自訂角色\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n強度預測:%.2f\n\n",toupper(char4_type),char4_atk,char4_hp,char4_def,char4_strongpre);
        do{
            do{
                printf("選擇先攻角色:");
                first_atk_char = getchar();
                scanf("%d",&first_atk_char);
                if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4){	//一旦輸入並非已定義角色，輸出錯誤
                    printf("無此角色\n");
                }
            }while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4);
            do{
                printf("選擇後攻角色:");
                last_atk_char = getchar();
                scanf("%d",&last_atk_char);
                if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4){	//一旦輸入並非已定義角色，輸出錯誤
                    printf("錯誤:無此角色\n");
                }
            }while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4);
                if(first_atk_char==last_atk_char){	//一旦先攻角色等於後攻角色，輸出錯誤
                    printf("錯誤:不可重複選取\n");
                }
            }while(first_atk_char==last_atk_char);
        printf("先攻角色為%d ，後攻角色為%d\n",first_atk_char,last_atk_char);	//印出最終輸入
    }
    else if(addchar==2){//使用者選擇"否"
        do{
            do{
                printf("選擇先攻角色:");
                first_atk_char = getchar();
                scanf("%d",&first_atk_char);
                if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3){	//一旦輸入並非已定義角色，輸出錯誤
                    printf("錯誤:無此角色\n");
                }
            }while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3);
            do{
                printf("選擇後攻角色:");
                last_atk_char = getchar();
                scanf("%d",&last_atk_char);
                if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3){	//一旦輸入並非已定義角色，輸出錯誤
                    printf("錯誤:無此角色\n");
                    }
            }while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3);
            if(first_atk_char==last_atk_char){	//一旦先攻角色等於後攻角色，輸出錯誤
                printf("錯誤:不可重複選取\n");
            }
        }while(first_atk_char==last_atk_char);
        printf("先攻角色為%d，後攻角色為%d\n",first_atk_char,last_atk_char);	//印出最終輸入
    }
    printf("開始戰鬥\n\n");
    int first_atk_hp;		//新增儲存資訊的變數
    int first_atk_atk;
    int first_atk_def;
    int last_atk_hp;
    int last_atk_atk;
    int last_atk_def;
    int round = 0;		//設定最初回合為0
		//判斷輸入的角色，把資料輸入暫存裡
    if(first_atk_char == 1){
      first_atk_hp = char1_hp;
      first_atk_atk = char1_atk;
      first_atk_def = char1_def;
    }
    else if (first_atk_char == 2){
      first_atk_hp = char2_hp;
      first_atk_atk = char2_atk;
      first_atk_def = char2_def;
    }
    else if (first_atk_char ==3){
      first_atk_hp = char3_hp;
      first_atk_atk = char3_atk;
      first_atk_def = char3_def;
    }
    else if (first_atk_char ==4){
      first_atk_hp = char4_hp;
      first_atk_atk = char4_atk;
      first_atk_def = char4_def;
    }
    if(last_atk_char == 1){
      last_atk_hp = char1_hp;
      last_atk_atk = char1_atk;
      last_atk_def = char1_def;
    }
    else if (last_atk_char == 2){
      last_atk_hp = char2_hp;
      last_atk_atk = char2_atk;
      last_atk_def = char2_def;
    }
    else if (last_atk_char == 3){
      last_atk_hp = char3_hp;
      last_atk_atk = char3_atk;
      last_atk_def = char3_def;
    }
    else if (last_atk_char == 4){
      last_atk_hp = char4_hp;
      last_atk_atk = char4_atk;
      last_atk_def = char4_def;
    }
    while(first_atk_char> 0||last_atk_char> 0){
        //判斷第幾回合以讓先後攻順序交換
        if(round%2==0){
            //攻擊傷害 = 攻擊方攻擊力 - 被攻擊方防禦力
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",first_atk_char,last_atk_char,first_atk_atk-last_atk_def);
            last_atk_hp = last_atk_hp - (first_atk_atk-last_atk_def);
            printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
        }
      else if(round%2==1){
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",last_atk_char,first_atk_char,last_atk_atk-first_atk_def);
        first_atk_hp = first_atk_hp - (last_atk_atk-first_atk_def);
        printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
      }
      round++;		//執行一次迴圈多一回合
      if(first_atk_hp<=0){
        printf("角色%d 失去戰鬥能力\n",first_atk_char);
        printf("戰鬥結束\n");
        printf("\n角色%d 獲勝\n",last_atk_char);
        break;//一旦角色沒血顯示訊息後結束迴圈
      }
      else if(last_atk_hp<=0){
        printf("角色%d 失去戰鬥能力\n",last_atk_char);
        printf("戰鬥結束\n");
        printf("\n角色%d 獲勝\n",first_atk_char);
        break;//一旦角色沒血顯示訊息後結束迴圈
      }
    }
    return 0;
}
