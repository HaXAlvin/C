#include <stdio.h>
#include <stdlib.h>

int main()
{
    char type[4]="FWG";
    int hp[4]= {46,45,43,0};
    int attack[4]= {17,16,19,0};
    int defense[4]= {7,8,6,0};

    char name1[100]="阿泰";
    char name2[100]="阿禎";
    char name3[100]="阿澤";
    char name4[100];

    char ch4_type;
    int ch4_hp;
    int ch4_attack;
    int ch4_defense;

    int first_atk;
    int first_type;
    int first_atk_hp;
    int first_atk_atk;
    int first_atk_def;

    int second_atk;
    int second_type;
    int second_atk_hp;
    int second_atk_atk;
    int second_atk_def;

    int choose;
    int blood1=first_atk_hp/2;
    int blood2=second_atk_hp/2;
    while(1)
    {
        printf("1.新增或修改角色資料\n");
        printf("2.顯示所有角色資料\n");
        printf("3.戰鬥\n");
        printf("0.結束遊戲\n");
        printf("請選擇:");
        scanf("%d",&choose);
        if(choose==0)//結束遊戲選項
            return 0;

        if(choose==2)//顯示所有角色資料
        {
            printf("角色1\n名稱：%s\n",name1);
            printf("屬性：%c     攻擊：%d\n", type[0], attack[0]);
            printf("血量：%d    防禦：%d\n", hp[0], defense[0]);
            printf("角色強度預測：%.2f\n\n",
                   (hp[0] * 1.0 + attack[0] * 0.8 + defense[0] * 0.5 - 50.0) * 6.5 );
            printf("角色2\n名稱：%s\n",name2);
            printf("屬性：%c     攻擊：%d\n", type[1], attack[1]);
            printf("血量：%d    防禦：%d\n", hp[1], defense[1]);
            printf("角色強度預測：%.2f\n\n",
                   (hp[1] * 1.0 + attack[1] * 0.8 + defense[1] * 0.5 - 50.0) * 6.5 );
            printf("角色3\n名稱：%s\n",name3);
            printf("屬性：%c     攻擊：%d\n", type[2], attack[2]);
            printf("血量：%d    防禦：%d\n", hp[2], defense[2]);
            printf("角色強度預測：%.2f\n",
                   (hp[2] * 1.0 + attack[2] * 0.8 + defense[2] * 0.5 - 50.0) * 6.5 );
            if(hp[3]!=0)
            {
                printf("\n角色4\n名稱：%s",name4);
                printf("\n屬性：%c     攻擊：%d\n", type[3], attack[3]);
                printf("血量：%d    防禦：%d\n", hp[3], defense[3]);
                printf("角色強度預測：%.2f\n", (hp[3] * 1.0 + attack[3] * 0.8 + defense[3] * 0.5 - 50.0) * 6.5 );
                printf("\n");
            }
            continue ;
        }
        if(choose==1)//新增或修改新增角色資料
        {
            while(1)
            {
                if(hp[3]==0)
                    printf("\n新增角色\n");
                if(hp[3]!=0)
                    printf("修改新增角色\n");
                printf("名稱:");
                scanf("%s",name4);
                printf("屬性：");
                scanf("%*c%c", &type[3]);
                printf("血量：");
                scanf("%d", &hp[3]);
                printf("攻擊：");
                scanf("%d", &attack[3]);
                printf("防禦：");
                scanf("%d", &defense[3]);
                if(type[3] != 'F' && type[3] != 'W' && type[3] != 'G' && type[3] != 'A' &&
                        type[3] != 'f' && type[3] != 'w' && type[3] != 'g' && type[3] != 'a')
                {
                    printf("錯誤：無此屬性\n");
                    continue;
                }//屬性限制
                else if(type[3] >= 'a')
                    type[3] -= 32;

                int ch4_sum = hp[3] + attack[3] + defense[3];
                if(hp[3] < 40 || hp[3] > 50 || attack[3] < 15 || attack[3] > 20 ||
                        defense[3] < 5 || defense[3] > 10 || ch4_sum < 65 || ch4_sum > 70)
                {
                    printf("錯誤：能力數值在限制範圍之外\n");
                    continue;
                }//數值限制
                printf("\n角色4\n名稱：%s",name4);
                printf("\n屬性：%c     攻擊：%d\n", type[3], attack[3]);
                printf("血量：%d    防禦：%d\n", hp[3], defense[3]);
                printf("角色強度預測：%.2f\n", (hp[3] * 1.0 + attack[3] * 0.8 + defense[3] * 0.5 - 50.0) * 6.5 );
                printf("\n");
                break ;
            }
            continue;
        }
        if(choose==3)//戰鬥
        {
            while(1)//先攻選擇
            {
                printf("選擇先攻角色：");
                scanf("%d", &first_atk);
                if(first_atk!=1&&first_atk!=2&&first_atk!=3&&first_atk!=4 )
                {
                    printf("錯誤：無此角色\n");
                    continue;
                }
                break;
            }
            while(1)//後攻選擇
            {
                printf("選擇後攻角色：");
                scanf("%d", &second_atk);
                if(second_atk!=1&&second_atk!=2&&second_atk!=3&&second_atk!=4)
                {
                    printf("錯誤：無此角色\n");
                    continue;
                }
                else if(second_atk == first_atk)
                {
                    printf("錯誤：不可重複選取\n");
                    continue;
                }
                break;
            }
            printf("\n先攻為角色%d、後攻為角色%d\n", first_atk, second_atk);

            if (first_atk == 1)//先攻為角色1
            {
                first_type = type[0];
                first_atk_hp = hp[0] ;
                first_atk_atk = attack[0] ;
                first_atk_def = defense[0];
            }

            if (first_atk == 2)//先攻為角色2
            {
                first_type = type[1];
                first_atk_hp = hp[1] ;
                first_atk_atk = attack[1] ;
                first_atk_def = defense[1];
            }

            if (first_atk == 3)//先攻為角色3
            {
                first_type = type[2];
                first_atk_hp = hp[2] ;
                first_atk_atk = attack[2] ;
                first_atk_def = defense[2];
            }

            if (first_atk == 4)//先攻為角色4
            {
                first_type = type[3];
                first_atk_hp = hp[3] ;
                first_atk_atk = attack[3] ;
                first_atk_def = defense[3];
            }

            if (second_atk == 1)//後攻為角色1
            {
                second_type = type[0];
                second_atk_hp = hp[0] ;
                second_atk_atk = attack[0] ;
                second_atk_def = defense[0];
            }

            if (second_atk == 2)//後攻為角色2
            {
                second_type = type[1];
                second_atk_hp = hp[1] ;
                second_atk_atk = attack[1] ;
                second_atk_def = defense[1];
            }

            if (second_atk == 3)//後攻為角色3
            {
                second_type = type[2];
                second_atk_hp = hp[2] ;
                second_atk_atk = attack[2] ;
                second_atk_def = defense[2];
            }

            if (second_atk == 4)//後攻為角色4
            {
                second_type = type[3];
                second_atk_hp = hp[3] ;
                second_atk_atk = attack[3] ;
                second_atk_def = defense[3];
            }
            //屬性克制
            if(first_type=='W'&&second_type=='F')
            {
                first_atk_atk*1.2;
                second_atk_atk*0.8;
            }
            if(first_type=='F'&&second_type=='A')
            {
                first_atk_atk*1.2;
                second_atk_atk*0.8;
            }
            if(first_type=='A'&&second_type=='G')
            {
                first_atk_atk*1.2;
                second_atk_atk*0.8;
            }
            if(first_type=='G'&&second_type=='W')
            {
                first_atk_atk*1.2;
                second_atk_atk*0.8;
            }
            if(first_type=='F'&&second_type=='W')
            {
                first_atk_atk*0.8;
                second_atk_atk*1.2;
            }
            if(first_type=='A'&&second_type=='F')
            {
                first_atk_atk*0.8;
                second_atk_atk*1.2;
            }
            if(first_type=='G'&&second_type=='A')
            {
                first_atk_atk*0.8;
                second_atk_atk*1.2;
            }
            if(first_type=='W'&&second_type=='G')
            {
                first_atk_atk*0.8;
                second_atk_atk*1.2;
            }
            printf("戰鬥開始\n\n");
            while(1)
            {
                if(second_atk_hp<blood2)
                    first_atk_atk*1.2;
                if(first_atk_hp<blood1)
                    second_atk_atk*1.2;
                //殘血倍率
                printf("角色%d 對 角色%d 發動攻擊，造成 %d 傷害\n", first_atk, second_atk, first_atk_atk - second_atk_def);
                second_atk_hp = second_atk_hp - (first_atk_atk - second_atk_def);
                printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
                if(second_atk_hp<=0)
                {
                    printf("角色%d 失去戰鬥能力", second_atk);
                    printf("戰鬥結束\n\n");
                    printf("角色%d 獲勝\n", first_atk);
                    break;
                }
                printf("角色%d 對 角色%d 發動攻擊，造成 %d 傷害\n", second_atk, first_atk, second_atk_atk - first_atk_def);
                first_atk_hp = first_atk_hp - (second_atk_atk - first_atk_def);
                printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
                if(first_atk_hp<=0)
                {
                    printf("角色%d 失去戰鬥能力", first_atk);
                    printf("戰鬥結束\n\n");
                    printf("角色%d 獲勝\n", second_atk);
                    break;
                }
            }
            continue;
        }
    }
}
