#include<stdio.h>
#include<string.h>
int main()
{
    char char_name[21];
    char char1_name[21]= {'漩','渦','鳴','人'};
    char char2_name[21]= {'納','茲','多','拉','格','尼','魯'};
    char char3_name[21]= {'蒙','奇','D','魯','夫'};
    char char4_name[21];
    char char_type[4]= {'A','F','W'};
    int char_atk[4]= {19,17,20};
    int char_hp[4]= {47,45,43};
    int char_def[4]= {4,5,7};
    float char_power[4]= {92.30,72.15,82.15};
    int opt,i,times,F_atk, F_hp, F_def, S_atk, S_hp, S_def;
    char F_type,S_type,A,W,F,G;
    times=0;


    printf("1: 新增或修改新增角色\n"
           "2: 顯示所有角色資料\n"
           "3: 戰鬥\n"
           "0: 結束遊戲\n"
           "請選擇:");

    while(scanf("%d",&opt)!=EOF)
    {
        printf("\n");
        if(opt!=0&&opt!=1&&opt!=2&&opt!=3)
        {
            printf("輸入錯誤!\n\n");
        }
        if(opt==1)
        {
            //角色4
            printf("新增或修改新增角色\n");
            printf("名稱:");
            scanf("%s",&char4_name[21]);
            printf("屬性:");
            getchar();
            scanf("%c",&char_type[3]);
            printf("攻擊:");
            scanf("%d",&char_atk[3]);
            printf("血量:");
            scanf("%d",&char_hp[3]);
            printf("防禦:");
            scanf("%d",&char_def[3]);
            printf("\n");
            for(;;)
            {

                if((char_type[3] != 'F'&&char_type[3] !='W'&&char_type[3] !='G'&&char_type[3] !='A'&&char_type[3] !='f'&&char_type[3] !='w'&&char_type[3] !='g'&&char_type[3] !='a') &&
                        ((char_hp[3]<40 && char_hp[3]>50 && char_atk[3]<15 && char_atk[3]>20 && char_def[3]<5 && char_def[3]>10) ||
                         (char_atk[3]+char_hp[3]+char_def[3]<65 || char_atk[3]+char_hp[3]+char_def[3]>70)))
                {
                    printf("錯誤:無此屬性\n"
                           "錯誤:能力數值在限制範圍之外\n");
                    printf("新增或修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",&char4_name);
                    printf("屬性:");
                    getchar();
                    scanf("%c",&char_type[3]);
                    printf("攻擊:");
                    scanf("%d",&char_atk[3]);
                    printf("血量:");
                    scanf("%d",&char_hp[3]);
                    printf("防禦:");
                    scanf("%d",&char_def[3]);
                    printf("\n");
                    continue;
                }

                if((char_type[3] != 'F'&&char_type[3] !='W'&&char_type[3] !='G'&&char_type[3] !='A'&&char_type[3] !='f'&&char_type[3] !='w'&&char_type[3] !='g'&&char_type[3] !='a')&&
                        (char_hp[3]>=40 && char_hp[3]<=50 &&char_atk[3]>=15 && char_atk[3]<=20 && char_def[3]>=5 && char_def[3]<=10) &&
                        (char_atk[3]+char_hp[3]+char_def[3]<=70 && 65<=char_atk[3]+char_hp[3]+char_def[3]))
                {
                    printf("錯誤:無此屬性\n");
                    printf("新增或修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",&char4_name[21]);
                    printf("屬性:");
                    getchar();
                    scanf("%c",&char_type[3]);
                    printf("攻擊:");
                    scanf("%d",&char_atk[3]);
                    printf("血量:");
                    scanf("%d",&char_hp[3]);
                    printf("防禦:");
                    scanf("%d",&char_def[3]);
                    printf("\n");
                    continue;
                }
                if((char_type[3] == 'F'||char_type[3] =='W'||char_type[3] =='G'||char_type[3] =='A'||char_type[3] =='f'||char_type[3] =='w'||char_type[3] =='g'||char_type[3] =='a') &&
                        ((char_hp[3]<40 && char_hp[3]>50 && char_atk[3]<15 && char_atk[3]>20 && char_def[3]<5 && char_def[3]>10) ||
                         (char_atk[3]+char_hp[3]+char_def[3]<65 || char_atk[3]+char_hp[3]+char_def[3]>70)))
                {
                    printf("錯誤:能力數值在限制範圍之外\n");
                    printf("新增或修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",&char4_name[21]);
                    printf("屬性:");
                    getchar();
                    scanf("%c",&char_type[3]);
                    printf("攻擊:");
                    scanf("%d",&char_atk[3]);
                    printf("血量:");
                    scanf("%d",&char_hp[3]);
                    printf("防禦:");
                    scanf("%d",&char_def[3]);
                    printf("\n");
                    continue;
                }

                if((char_type[3] == 'F'||char_type[3] =='W'||char_type[3] =='G'||char_type[3] =='A'||char_type[3] =='f'||char_type[3] =='w'||char_type[3] =='g'||char_type[3] =='a') &&
                        (char_hp[3]>=40 && char_hp[3]<=50 &&char_atk[3]>=15 && char_atk[3]<=20 && char_def[3]>=5 && char_def[3]<=10) &&
                        (char_atk[3]+char_hp[3]+char_def[3]<=70 && 65<=char_atk[3]+char_hp[3]+char_def[3]))
                {
                    printf("角色4\n");
                    printf("名稱:%s",char4_name);
                    printf("\n");
                    if(char_type[3]<96)//大小寫轉換
                        printf("屬性:%c    攻擊:%d\n",char_type[3],char_atk[3]);

                    else if(char_type[3]>96)
                        printf("屬性:%c    攻擊:%d\n",char_type[3]-32,char_atk[3]);

                    printf("血量:%d   防禦:%d\n",char_hp[3],char_def[3]);
                    printf("強度預測:%.2f\n\n",(char_hp[3]*1.0+char_atk[3]*0.8+char_def[3]*0.5-50)*6.5);
                    printf("\n");
                    char_power[3]=(char_hp[3]*1.0+char_atk[3]*0.8+char_def[3]*0.5-50)*6.5;
                    break;

                }
            }
            times++;
        }
        if(opt==2)
        {
            for(int i=0; i<3; i++)
            {
                printf("角色%d\n",i+1);
                if(i==0)
                    printf("名稱:漩渦鳴人\n");
                if(i==1)
                    printf("名稱:納茲多拉格尼魯\n");
                if(i==2)
                    printf("名稱:蒙奇D魯夫\n");

                printf("屬性:%c    攻擊:%d\n",char_type[i],char_atk[i]);
                printf("血量:%d   防禦:%d\n",char_hp[i],char_def[i]);
                printf("強度預測:%.2f\n\n",char_power[i]);
            }
            if(times!=0)
            {
                printf("角色4\n");
                printf("名稱:%s\n",char4_name);
                printf("屬性:%c    攻擊:%d\n",char_type[3],char_atk[3]);
                printf("血量:%d   防禦:%d\n",char_hp[3],char_def[3]);
                printf("強度預測:%.2f\n\n",char_power[3]);
            }

        }
        if(opt==3)
        {
            if(times==0)
            {
                int first,second;
                printf("選擇先攻角色:");
                scanf("%d",&first);
                for(;;)
                {
                    if((first!= 1) && (first!= 2) && (first!= 3))
                    {
                        printf("無此角色\n");
                        printf("選擇先攻角色:");
                        scanf("%d",&first);
                        continue;
                    }
                    if((first == 1) || (first == 2) || (first==3))
                    {
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        break;
                    }
                }
                for(;;)
                {
                    if(first == second)
                    {
                        printf("錯誤:不得重複選擇\n");
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        continue;
                    }
                    if(second != 1 && second != 2 && second != 3)
                    {
                        printf("錯誤:無此角色\n");
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        continue;
                    }
                    if((second == 1 || second == 2 || second == 3) && first != second)
                    {
                        printf("\n");
                        printf("先攻為角色%d、後攻為角色%d\n戰鬥開始\n\n",first,second);
                        break;
                    }
                }
                //載入資料
                if(first == 1)
                {
                    F_type = char_type[0];
                    F_atk = char_atk[0];
                    F_hp = char_hp[0];
                    F_def = char_def[0];
                }
                if(first == 2)
                {
                    F_type = char_type[1];
                    F_atk = char_atk[1];
                    F_hp = char_hp[1];
                    F_def = char_def[1];
                }
                if(first == 3)
                {
                    F_type = char_type[2];
                    F_atk = char_atk[2];
                    F_hp = char_hp[2];
                    F_def = char_def[2];
                }
                if(second == 1)
                {
                    S_type = char_type[0];
                    S_atk = char_atk[0];
                    S_hp = char_hp[0];
                    S_def = char_def[0];
                }
                if(second == 2)
                {
                    S_type = char_type[1];
                    S_atk = char_atk[1];
                    S_hp = char_hp[1];
                    S_def = char_def[1];
                }
                if(second == 3)
                {
                    S_type = char_type[2];
                    S_atk = char_atk[2];
                    S_hp = char_hp[2];
                    S_def = char_def[2];
                }
                A==W,F==G,W==A,G==F;
                W>F;
                F>A;
                A>G;
                G>W;
                if(F_type>S_type)
                {
                    F_atk=F_atk*1.2;
                    S_atk=S_atk*0.8;
                }
                if(S_type>F_type)
                {
                    F_atk=F_atk*0.8;
                    S_atk=S_atk*1.2;
                }
                if(F_type==S_type)
                {
                    F_atk=F_atk*1.0;
                    S_atk=S_atk*1.0;
                }
                //開始戰鬥
                for(;;)
                {
                    printf("角色%d 對 角色%d 發動攻擊，造成%d 點傷害\n",first,second,(F_atk-S_def));
                    S_hp = S_hp-(F_atk-S_def);
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first,F_hp,second,S_hp);
                    if(S_hp<=0)
                    {
                        printf("角色%d 失去戰鬥能力\n"
                               "戰鬥結束\n\n"
                               "角色%d 獲勝\n"
                               ,second,first);
                        break;
                    }
                    if(S_hp<=S_hp*0.5)
                        S_atk=S_atk*1.2;
                    printf("角色%d 對 角色%d 發動攻擊，造成%d 點傷害\n",second,first,S_atk-F_def);
                    F_hp = F_hp-(S_atk-F_def);
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first,F_hp,second,S_hp);
                    if(F_hp<=S_hp*0.5)
                        F_atk=F_atk*1.2;
                    if(F_hp<=0)
                    {
                        printf("角色%d 失去戰鬥能力\n"
                               "戰鬥結束\n\n"
                               "角色%d 獲勝\n"
                               ,first,second);
                        break;
                    }
                }
                second=0;
            }
            else if(times!=0)
            {
                int first,second;
                printf("選擇先攻角色:");
                scanf("%d",&first);
                for(;;)
                {
                    if((first != 1) && (first != 2) && (first != 3) && (first != 4))
                    {
                        printf("無此角色\n");
                        printf("選擇先攻角色:");
                        scanf("%d",&first);
                        continue;
                    }
                    if((first == 1) || (first == 2) || (first==3) || (first == 4))
                    {
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        break;
                    }
                }
                for(;;)
                {
                    if(first == second)
                    {
                        printf("錯誤:不得重複選擇\n");
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        continue;
                    }
                    if(second != 1 && second != 2 && second != 3 && second != 4)
                    {
                        printf("錯誤:無此角色\n");
                        printf("選擇後攻角色:");
                        scanf("%d",&second);
                        continue;
                    }
                    if((second == 1 || second == 2 || second == 3 | second == 4) && first != second)
                    {
                        printf("\n");
                        printf("先攻為角色%d、後攻為角色%d\n戰鬥開始\n\n",first,second);
                        break;
                    }
                }
                //戰鬥開始
                if(first == 1)
                {
                    F_type = char_type[0];
                    F_atk = char_atk[0];
                    F_hp = char_hp[0];
                    F_def = char_def[0];
                }
                if(first == 2)
                {
                    F_type = char_type[1];
                    F_atk = char_atk[1];
                    F_hp = char_hp[1];
                    F_def = char_def[1];
                }
                if(first == 3)
                {
                    F_type = char_type[2];
                    F_atk = char_atk[2];
                    F_hp = char_hp[2];
                    F_def = char_def[2];
                }
                if(first == 4)
                {
                    F_type = char_type[3];
                    F_atk = char_atk[3];
                    F_hp = char_hp[3];
                    F_def = char_def[3];
                }
                if(second == 1)
                {
                    S_type = char_type[0];
                    S_atk = char_atk[0];
                    S_hp = char_hp[0];
                    S_def = char_def[0];
                }
                if(second == 2)
                {
                    S_type = char_type[1];
                    S_atk = char_atk[1];
                    S_hp = char_hp[1];
                    S_def = char_def[1];
                }
                if(second == 3)
                {
                    S_type = char_type[2];
                    S_atk = char_atk[2];
                    S_hp = char_hp[2];
                    S_def = char_def[2];
                }
                if(second == 4)
                {
                    S_type = char_type[3];
                    S_atk = char_atk[3];
                    S_hp = char_hp[3];
                    S_def = char_def[3];
                }
//                A==W,F==G,W==A,G==F;
//                W>F;
//                F>A;
//                A>G;
//                G>W;
                if(F_type>S_type)
                {
                    F_atk=F_atk*1.2;
                    S_atk=S_atk*0.8;
                }
                if(S_type>F_type)
                {
                    F_atk=F_atk*0.8;
                    S_atk=S_atk*1.2;
                }
                if(F_type==S_type)
                {
                    F_atk=F_atk*1.0;
                    S_atk=S_atk*1.0;
                }
                for(;;)
                {
                    printf("角色%d 對 角色%d 發動攻擊，造成%d 點傷害\n",first,second,(F_atk-S_def));
                    S_hp = S_hp-(F_atk-S_def);
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first,F_hp,second,S_hp);
                    if(S_hp<=0)
                    {
                        printf("角色%d 失去戰鬥能力\n"
                               "戰鬥結束\n\n"
                               "角色%d 獲勝\n"
                               ,second,first);
                        break;
                    }
                    if(S_hp<=S_hp*0.5)
                        S_atk=S_atk*1.2;
                    printf("角色%d 對 角色%d 發動攻擊，造成%d 點傷害\n",second,first,S_atk-F_def);
                    F_hp = F_hp-(S_atk-F_def);
                    printf("角色%d HP: %d 角色%d HP: %d\n\n",first,F_hp,second,S_hp);
                    if(F_hp<=S_hp*0.5)
                        F_atk=F_atk*1.2;
                    if(F_hp<=0)
                    {
                        printf("角色%d 失去戰鬥能力\n"
                               "戰鬥結束\n\n"
                               "角色%d 獲勝\n"
                               ,first,second);
                        break;
                    }
                }
                second=0;
            }
        }
        if(opt==0)
        {
            printf("遊戲結束\n");
            return 0;
        }

        printf("1: 新增或修改新增角色\n"
               "2: 顯示所有角色資料\n"
               "3: 戰鬥\n"
               "0: 結束遊戲\n"
               "請選擇:");
    }


    return 0;

}
