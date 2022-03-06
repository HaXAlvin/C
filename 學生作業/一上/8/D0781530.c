#include <stdio.h>
#include <stdlib.h>

int main()
{
    //角色1
    char char1_type='F';//屬性
    int char1_hp=45;//血量
    int char1_atk=17;//攻擊
    int char1_def=8;//防禦
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;//強度預測
    //角色2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //角色3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //角色4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    char char4_name[20];
    float char4_pre;

    int first_atk;//訂定先攻角色變數
    int first_atk_origin_hp;
    int first_atk_hp;
    int first_atk_atk;
    int first_atk_def;

    int second_atk;//訂定後攻角色變數
    int second_atk_origin_hp;
    int second_atk_hp;
    int second_atk_atk;
    int second_atk_def;

    int char4_is_create=0;
    int char4_is_delete=0;
    int is_correct, turn;
    int chs;

    do{
        printf("1. 新增或修改新增角色\n");
        printf("2. 顯示所有角色資料\n");
        printf("3. 戰鬥\n");
        printf("0. 結束遊戲\n");
        printf("請選擇：");
        scanf("%d",&chs);


        if(chs<0 || chs>3){
            printf("\n輸入錯誤!\n\n");

        }

        if(chs==2){
            printf("\n");
            printf("角色1\n");
            printf("名稱:阿柴\n");
            printf("屬性:%c     ",char1_type);
            printf("攻擊:%d\n",char1_atk);
            printf("血量:%d    ",char1_hp);
            printf("防禦:%d\n",char1_def);
            printf("角色強度預測:%.2f\n",char1_pre);
            printf("\n");

            printf("角色2\n");
            printf("名稱:豆桑\n");
            printf("屬性:%c     ",char2_type);
            printf("攻擊:%d\n",char2_atk);
            printf("血量:%d    ",char2_hp);
            printf("防禦:%d\n",char2_def);
            printf("角色強度預測:%.2f\n",char2_pre);
            printf("\n");

            printf("角色3\n");
            printf("名稱:蘿絲 \n");
            printf("屬性:%c     ",char3_type);
            printf("攻擊:%d\n",char3_atk);
            printf("血量:%d    ",char3_hp);
            printf("防禦:%d\n",char3_def);
            printf("角色強度預測:%.2f\n",char3_pre);
            printf("\n");

            if(char4_is_create = 1){
                printf("角色4\n名稱：%s\n",char4_name);
                printf("屬性：%c     攻擊：%d\n", char4_type, char4_atk);
                printf("血量：%d    防禦：%d\n", char4_hp, char4_def);
                printf("角色強度預測：%.2f\n", (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50.0) * 6.5 );
                printf("\n");
            }
        }

        if(chs==1){
            do{
                is_correct = 1; //初始化flag
                printf("\n");
                if(char4_is_delete == 1)//如果已經有填過新增角色的資料，印出修改新增角色
                    printf("修改新增角色\n");
                else
                    printf("新增角色\n");
                char4_is_create = 1;
                printf("名稱：");
                scanf("%*c%s",&char4_name);
                printf("屬性：");
                scanf("%*c%c", &char4_type);
                printf("血量：");
                scanf("%d", &char4_hp);
                printf("攻擊：");
                scanf("%d", &char4_atk);
                printf("防禦：");
                scanf("%d", &char4_def);
                //檢察屬性
                if(char4_type != 'F' && char4_type != 'W' && char4_type != 'G' && char4_type != 'A' &&
                   char4_type != 'f' && char4_type != 'w' && char4_type != 'g' && char4_type != 'a'){
                     printf("錯誤：無此屬性\n");
                     is_correct = 0;
                }
                else if(char4_type >= 'a')
                    char4_type -= 32;
                //檢查能力數值
                int char4_sum = char4_hp + char4_atk + char4_def;
                if(char4_hp < 40 || char4_hp > 50 || char4_atk < 15 || char4_atk > 20 ||
                   char4_def < 5 || char4_def > 10 || char4_sum < 65 || char4_sum > 70){
                     printf("錯誤：能力數值在限制範圍之外\n");
                     is_correct = 0;
                }
            }while(!is_correct);

            printf("\n角色4\n名稱：%s\n",char4_name);
            printf("屬性：%c     攻擊：%d\n", char4_type, char4_atk);
            printf("血量：%d    防禦：%d\n", char4_hp, char4_def);
            printf("角色強度預測：%.2f\n", (char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50.0) * 6.5 );
            printf("\n");
        }

        if(chs==3){
            printf("\n");
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

            printf("\n先攻為角色%d、後攻為角色%d\n", first_atk, second_atk);
            //將先攻的能力資料取出
            first_atk_hp = (first_atk == 1) ? char1_hp : (first_atk == 2) ? char2_hp : (first_atk == 3) ? char3_hp : char4_hp;
            first_atk_atk = (first_atk == 1) ? char1_atk : (first_atk == 2) ? char2_atk : (first_atk == 3) ? char3_atk : char4_atk;
            first_atk_def = (first_atk == 1) ? char1_def : (first_atk == 2) ? char2_def : (first_atk == 3) ? char3_def : char4_def;
            //將後攻的能力資料取出
            second_atk_hp = (second_atk == 1) ? char1_hp : (second_atk == 2) ? char2_hp : (second_atk == 3) ? char3_hp : char4_hp;
            second_atk_atk = (second_atk == 1) ? char1_atk : (second_atk == 2) ? char2_atk : (second_atk == 3) ? char3_atk : char4_atk;
            second_atk_def = (second_atk == 1) ? char1_def : (second_atk == 2) ? char2_def : (second_atk == 3) ? char3_def : char4_def;

            turn = 1; //初始化攻擊方
            first_atk_origin_hp = first_atk_hp;
            second_atk_origin_hp = second_atk_hp;

            printf("戰鬥開始\n\n");
            while(first_atk_hp > 0 && second_atk_hp > 0){
                int atk;
                if(turn == 1){
                    atk = first_atk_atk - second_atk_def;
                    second_atk_hp -= atk;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", first_atk, second_atk, atk);
                    turn = 2; //交換攻擊方
                }
                else{
                    atk = second_atk_atk - first_atk_def;
                    first_atk_hp -= atk;
                    printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", second_atk, first_atk, atk);
                    turn = 1; //交換攻擊方
                }
                printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
            }
            printf("角色%d 失去戰鬥能力\n", (first_atk_hp > 0) ? second_atk : first_atk);
            printf("戰鬥結束\n\n");
            printf("角色%d 獲勝\n", (first_atk_hp > 0) ? first_atk : second_atk);
            printf("\n");
            char4_is_create =0;
            char4_is_delete =1;//如果角色4有被填過資料，就加 1
        }

        if(chs==0){
            printf("\n");
            printf("結束遊戲\n");
            break;
        }
    }while(1);

    return 0;
}
