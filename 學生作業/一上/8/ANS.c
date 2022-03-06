#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char char1_name[21] = "韓導";
	char char2_name[21] = "亞絲娜";
	char char3_name[21] = "雷姆";
	char char4_name[21];

	char type[4] = {'W', 'A', 'F'}; //屬性
	int hp[4] = {50, 40, 45};  //血量
	int atk[4] = {15, 20, 17};  //攻擊
	int def[4] = {5, 8, 7};  //防禦

    int first_atk;
    int first_atk_type;
    int first_atk_hp;
    int second_atk;
	int second_atk_type;
	int second_atk_hp;
	int type_rate;

    int char4_is_create = 0;
    int is_correct, turn, select;

    while (1) {
		printf("1. 新增或修改新增角色\n"
			   "2. 顯示所有角色資料\n"
			   "3. 戰鬥\n"
			   "0. 結束遊戲\n"
			   "請選擇：");
		scanf("%d", &select);
		printf("\n");
		switch ((0 > select || select > 3) ? -1 : select) {
			case -1:
				printf("輸入錯誤!\n");
				break;
			case 0:
				printf("結束遊戲\n");
				return 0;
			case 1:
				do {
					is_correct = 1; //初始化flag
                    printf("%s",char4_is_create?"修改新增角色\n":"新增角色\n");
					printf("名稱：");
					scanf("%s", char4_name);
		            printf("屬性：");
		            scanf("%*c%c", &type[3]);
		            printf("血量：");
		            scanf("%d", &hp[3]);
		            printf("攻擊：");
		            scanf("%d", &atk[3]);
		            printf("防禦：");
		            scanf("%d", &def[3]);
		            //檢察屬性
		            if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
		                type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a') {
		                printf("錯誤：無此屬性\n");
		                is_correct = 0;
		            }
		            else if (type[3] >= 'a')
		                type[3] -= 32;
		            //檢查能力數值
		            int char4_sum = hp[3] + atk[3] + def[3];
		            if (hp[3] < 40 || hp[3] > 50 || atk[3] < 15 || atk[3] > 20 ||
		                def[3] < 5 || def[3] > 10 || char4_sum < 65 || char4_sum > 70) {
		                printf("錯誤：能力數值在限制範圍之外\n");
		                is_correct = 0;
		            }
		            if (!is_correct)
		            	printf("\n");
				} while (!is_correct);
				char4_is_create = 1;
	            printf("\n角色4\n名稱：%s\n", char4_name);
		        printf("屬性：%c     攻擊：%d\n", type[3], atk[3]);
		        printf("血量：%d    防禦：%d\n", hp[3], def[3]);
		        printf("角色強度預測：%.2f\n", (hp[3] * 1.0 + atk[3] * 0.8 + def[3] * 0.5 - 50.0) * 6.5 );
		        break;
		    case 2:
		    	for (int i = 0; i < 3 + char4_is_create; i++) {
		    		if (i)
		    			printf("\n");
					printf("角色%d\n名稱：%s\n", i + 1, i == 0 ? char1_name : i == 1 ? char2_name : i == 2 ? char3_name : char4_name);
				    printf("屬性：%c     攻擊：%d\n", type[i], atk[i]);
				    printf("血量：%d    防禦：%d\n", hp[i], def[i]);
				    printf("角色強度預測：%.2f\n", (hp[i] * 1.0 + atk[i] * 0.8 + def[i] * 0.5 - 50.0) * 6.5 );
				}
				break;
			case 3:
				do{
			        is_correct = 1; //初始化flag
			        printf("選擇先攻角色：");
			        scanf("%d", &first_atk);
			        if(first_atk < 1 || first_atk > 3 + char4_is_create){
			            printf("錯誤：無此角色\n");
			            is_correct = 0;
			        }
			    }while(!is_correct);
			    do{
			        is_correct = 1; //初始化flag
			        printf("選擇後攻角色：");
			        scanf("%d", &second_atk);
			        if(second_atk < 1 || second_atk > 3 + char4_is_create){
			            printf("錯誤：無此角色\n");
			            is_correct = 0;
			        }
			        else if(second_atk == first_atk){
			            printf("錯誤：不可重複選取\n");
			            is_correct = 0;
			        }
			    }while(!is_correct);
			    printf("\n先攻為角色%d、後攻為角色%d\n", first_atk--, second_atk--);
			    turn = 1; //初始化攻擊方
			    first_atk_hp = hp[first_atk];
			    second_atk_hp = hp[second_atk];
			    //計算屬性相剋
			    first_atk_type = type[first_atk] == 'W' ? 0 : type[first_atk] == 'F' ? 1 : type[first_atk] == 'A' ? 2 : 3;
			    second_atk_type = type[second_atk] == 'W' ? 0 : type[second_atk] == 'F' ? 1 : type[second_atk] == 'A' ? 2 : 3;
				type_rate = second_atk_type - first_atk_type;//1 : first 剋 second
				type_rate = type_rate == 3 ? -1 : type_rate == -3 ? 1 : type_rate < -1 || type_rate > 1 ? 0 : type_rate;
			    printf("戰鬥開始\n\n");
			    while (first_atk_hp > 0 && second_atk_hp > 0) {
			        int atking;
			        if(turn == 1){
			            atking = atk[first_atk] * (1 + type_rate * 0.2) * (first_atk_hp < hp[first_atk] * 0.5 ? 1.2 : 1) - def[second_atk];
			            second_atk_hp -= atking;
			            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", first_atk + 1, second_atk + 1, atking);
			            turn = 2; //交換攻擊方
			        }
			        else{
			            atking = atk[second_atk] * (1 - type_rate * 0.2) * (second_atk_hp < hp[second_atk] * 0.5 ? 1.2 : 1) - def[first_atk];
			            first_atk_hp -= atking;
			            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", second_atk + 1, first_atk + 1, atking);
			            turn = 1; //交換攻擊方
			        }
			        printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk + 1, first_atk_hp, second_atk + 1, second_atk_hp);
			    }
			    printf("角色%d 失去戰鬥能力\n", (first_atk_hp > 0) ? second_atk + 1 : first_atk + 1);
			    printf("戰鬥結束\n\n");
			    printf("角色%d 獲勝\n", (first_atk_hp > 0) ? first_atk + 1 : second_atk + 1);
		}
		printf("\n");
	}
}
