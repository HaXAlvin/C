#include<stdio.h>
#include<ctype.h>

int main() {
    char name[][100] = {"馬力歐","路易吉","奇諾比奧",""};
    char type[10] = "WAF";
    int hp[4] = {50,40,45};
    int atk[4] = {15,20,17};
    int def[4] = {5,8,7};
    int n = 1;//flag
    int role = 3;//一開始的角色數目
    float T_ratio[2] = {0};//相剋倍率
    float B_ratio;//殘血倍率
    int num,i,first_atk,second_atk;
    float val[4] = {.0};//強度預測

    while (n == 1){
        do {
            n = 1;
            printf("1. 新增角色或修改角色\n2. 顯示所有角色資料\n3. 戰鬥\n0. 結束遊戲\n請選擇:");
            scanf("%d",&num);
            printf("\n");
            if ((num < 0) || (num > 3)){
                printf("輸入錯誤!\n\n");
                n = 0;
            }
        }while (n == 0);

        switch (num){
            case 1:
                do {
                    n = 0;
                    if (role < 4){
                        printf("\n新增角色\n");
                    }
                    else {
                        printf("\n修改新增角色\n");
                    }
                    printf("名稱:");
                    scanf("%s",name[3]);
                    printf("屬性:");
                    scanf(" %c",&type[3]);
                    printf("血量:");
                    scanf("%d",&hp[3]);
                    printf("攻擊力:");
                    scanf("%d",&atk[3]);
                    printf("防禦力:");
                    scanf("%d",&def[3]);

                    //屬性錯誤重新輸入
                    int sum = atk[3] + def[3] + hp[3];
                    val[3] = ((hp[3]*1.0)+(atk[3]*0.8)+(def[3]*0.5)-50)*6.5;
                    if (type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' && type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a'){
                        printf("錯誤:無此屬性\n");
                        n = 1;
                    }
                    //能力值錯誤重新輸入
                    if (atk[3] < 15 || atk[3] > 20 || def[3] < 5 || def[3] > 10 || hp[3] < 40 || hp[3] > 50 || sum < 65 || sum > 70){
                        printf("錯誤:能力數值在限制範圍之外\n");
                        n = 1;
                    }
                    //屬性大小寫轉換
                    if (islower(type[3])){
                       type[3] = toupper(type[3]);
                    }
                }while (n == 1);
                printf("\n角色4\n名稱:%s\n屬性:%c\t\t攻擊:%d\n血量:%d\t\t防禦:%d\n角色強度預測:%.2f\n\n",name[3],type[3],atk[3],hp[3],def[3],val[3]);
                n = 1;
                role = 4;
                break;
            case 2:
                for (i = 0 ; i < role ; i++ ){
                    val[i] = ((hp[i] * 1.0) + (atk[i] * 0.8) + (def[i] * 0.5) - 50) * 6.5;
                    printf("角色%d\n名稱:%s\n屬性:%c\t\t攻擊:%d\n血量:%d\t\t防禦:%d\n角色強度預測:%.2f\n\n",i+1,name[i],type[i],atk[i],hp[i],def[i],val[i]);
                }
                n = 1;
                break;
            case 3:
                do {
                    do{
                        n = 0;
                        printf("選擇先攻角色:");
                        scanf("%d",&first_atk);
                        if (first_atk > role || first_atk < 1){
                            printf("錯誤:無此角色\n");
                            n = 1;
                        }
                    }while(n == 1);
                    do{
                        n = 0;
                        printf("選擇後攻角色:");
                        scanf("%d",&second_atk);
                        if (second_atk > role || second_atk < 1){
                            printf("錯誤:無此角色\n");
                            n = 1;
                        }
                    }while(n == 1);
                    if (first_atk == second_atk){
                        printf("錯誤:不可重複選取\n\n");
                        n = 1;
                    }
                }while (n == 1);

                int atk1_hp,atk2_hp,atk1_atk,atk2_atk,atk1_def,atk2_def,atk1_type,atk2_type;

                printf("\n先攻為角色%d、後攻為角色%d",first_atk,second_atk);
                printf("\n戰鬥開始");

                switch (first_atk){
                    case 1:
                        atk1_hp = hp[0];
                        atk1_atk = atk[0];
                        atk1_def = def[0];
                        atk1_type = type[0];
                        break;
                    case 2:
                        atk1_hp = hp[1];
                        atk1_atk = atk[1];
                        atk1_def = def[1];
                        atk1_type = type[1];
                        break;
                    case 3:
                        atk1_hp = hp[2];
                        atk1_atk = atk[2];
                        atk1_def = def[2];
                        atk1_type = type[2];
                        break;
                    case 4:
                        atk1_hp = hp[3];
                        atk1_atk = atk[3];
                        atk1_def = def[3];
                        atk1_type = type[3];
                        break;
                }
                switch (second_atk){
                    case 1:
                        atk2_hp = hp[0];
                        atk2_atk = atk[0];
                        atk2_def = def[0];
                        atk2_type = type[0];
                        break;
                    case 2:
                        atk2_hp = hp[1];
                        atk2_atk = atk[1];
                        atk2_def = def[1];
                        atk2_type = type[1];
                        break;
                    case 3:
                        atk2_hp = hp[2];
                        atk2_atk = atk[2];
                        atk2_def = def[2];
                        atk2_type = type[2];
                        break;
                    case 4:
                        atk2_hp = hp[3];
                        atk2_atk = atk[3];
                        atk2_def = def[3];
                        atk2_type = type[3];
                        break;
                }
                //相剋倍率
                T_ratio[0] = 1.0;
                T_ratio[1] = 1.0;
                switch (atk1_type){
                    case 'W':
                        if (atk2_type == 'F'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'G'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'F':
                        if (atk2_type == 'A'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'W'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'A':
                        if (atk2_type == 'G'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'F'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                    case 'G':
                        if (atk2_type == 'W'){
                            T_ratio[0] = 1.2;
                            T_ratio[1] = 0.8;
                        }
                        if (atk2_type == 'A'){
                            T_ratio[0] = 0.8;
                            T_ratio[1] = 1.2;
                        }
                        break;
                }

                int atk1_hurt,atk2_hurt;
                int half_atk1 = atk1_hp / 2;//攻擊方血量小於原本的50%
                int half_atk2 = atk2_hp / 2;
                //先後攻回合對戰
                while (atk1_hp > 0 || atk2_hp > 0){
                    //殘血倍率
                    if (atk1_hp < half_atk1){
                        B_ratio = 1.2;
                    }
                    else {
                        B_ratio = 1.0;
                    }
                    //攻擊傷害
                    atk1_hurt = (int)(atk1_atk * T_ratio[0] * B_ratio - atk2_def);
                    atk2_hp -= atk1_hurt;//互相攻擊後之血量
                    printf("\n\n角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n",first_atk,second_atk,atk1_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
                    if (atk2_hp <= 0){
                        printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n",second_atk);
                        printf("角色%d 獲勝\n\n",first_atk);
                        break;
                    }
                    //殘血倍率
                    if (atk2_hp < half_atk2){
                        B_ratio = 1.2;
                    }
                    else {
                        B_ratio = 1.0;
                    }
                    //攻擊傷害
                    atk2_hurt = (int)(atk2_atk * T_ratio[1] * B_ratio - atk1_def);
                    atk1_hp -= atk2_hurt;//互相攻擊後之血量
                    printf("\n\n角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n",second_atk,first_atk,atk2_hurt,first_atk,atk1_hp,second_atk,atk2_hp);
                    if (atk1_hp <= 0){
                        printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n",first_atk);
                        printf("角色%d 獲勝\n\n",second_atk);
                        break;
                    }
                }
                n = 1;
                break;
            case 0:
                printf("結束遊戲\n");
                n = 0;
                break;
        }
    }
}
