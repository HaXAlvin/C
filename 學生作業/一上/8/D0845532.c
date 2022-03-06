#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    //主函式
    int caser;//case

    char name1[10]="毛毛貓";

    char name2[10]="毛毛";
    char name3[10]="臭臭泥";
    char name4[10];
    //名子
    char type[5];
    type[1]='G';
    type[2]='A';
    type[3]='F';
    char char1type=type[1],char2type=type[2],char3type=type[3],char4type=type[4];
    //type
    int  atk[5];
    atk[1]=20;
    atk[2]=15;
    atk[3]=16;
    int  char1atk,char2atk,char3atk,char4atk;
    char1atk=atk[1],char2atk=atk[2],char3atk=atk[3],char4atk=atk[4];
    atk[4]=0;
    //atk
    int  hp[5];
    hp[1]=40;
    hp[2]=40;
    hp[3]=44;
    int  char1hp=hp[1],char2hp=hp[2],char3hp=hp[3],char4hp=hp[4];
    //hp
    int  def[5];
    def[1]=10;
    def[2]=10;
    def[3]=5;
    int  char1def=def[1],char2def=def[2],char3def=def[3],char4def=def[4];
    //def
    int  add;
    //yes or no
    int first,last;
    //先攻 後攻
    int first_atk,first_def,last_atk,last_def,first_HP,last_HP,first_type,last_type,first2_HP,last2_HP;
    //戰鬥迴圈


    while(caser)
    {
        //開始
        printf("case:(輸入1~3)\n0:結束\n1:新增/修改角色4\n2:列出角色\n3:戰鬥\n");
        scanf("%d",&caser);
        if(caser==0)
            break;
        if(caser==2)
        {

            printf("角色1\n"
                   //印出文字
                   "名稱:%s\n",name1);
            printf("屬性:%c    攻擊:%d\n",type[1],atk[1]);
            printf("血量:%d   防禦:%d\n", hp[1],def[1]);
            printf("角色預測強度:%.2f\n\n",((hp[1]*1)+(atk[1]*0.8)+(def[1]*0.5)-50)*6.5);

            printf("角色2\n"
                   "名稱:%s\n",name2);
            printf("屬性:%c    攻擊:%d\n",type[2],atk[2]);
            printf("血量:%d   防禦:%d\n",hp[2],def[2]);
            printf("角色預測強度:%.2f\n\n",((hp[2]*1)+(atk[2]*0.8)+(def[2]*0.5)-50)*6.5);

            printf("角色3\n"
                   "名稱:%s\n",name3);
            printf("屬性:%c    攻擊:%d\n",type[3],atk[3]);
            printf("血量:%d   防禦:%d\n",hp[3],def[3]);
            printf("角色預測強度:%.2f\n\n",((hp[3]*1)+(atk[3]*0.8)+(def[3]*0.5)-50)*6.5);
            if(atk[4]!=0)
            {
                printf("角色4\n");
                printf("名稱:%s\n",name4);
                printf("屬性:%c 攻擊%d\n",type[4],atk[4]);
                printf("血量:%d 防禦%d\n",hp[4],def[4]);
                printf("角色預測強度:%.2f\n",((hp[4]*1)+(atk[4]*0.8)+(def[4]*0.5)-50)*6.5);
                printf("\n");
            }
            continue;
        }
//    for(add; add>2;)
//    {
//        printf("是否新增角色(1.yes 2.no)?");
//        scanf("%d",&add);
//        getchar();

//        if (add==1)
//        {
//
//            for(; ;)
        if(caser==1)
        {
            for(;;)
            {
                int add;
                printf("已經新增角色?1.yes 2.no\n");
                scanf("%d",&add);
                if(add==2)
                    printf("新增角色\n");
                //新增角色
                if(add==1)
                    printf("修改角色");
                for(;;){
                    printf("角色名:");
                    scanf("%s",&name4);
                    printf("屬性:");
                    scanf("%s",&type[4]);
                    getchar();
                    printf("攻擊:");
                    scanf("%d",&atk[4]);
                    getchar();
                    printf("血量:");
                    scanf("%d",&hp[4]);
                    getchar();
                    printf("防禦:");
                    scanf("%d",&def[4]);

                    getchar();
                    if (type[4] =='F' || type[4] =='f' || type[4] =='W' || type[4] =='w' ||//屬性以外
                            type[4] =='G' || type[4] =='g' || type[4] =='A' || type[4] =='a')
                    {
                        if (hp[4]<40 || hp[4]>50||//數值限制
                                atk[4]<15||atk[4]>20||
                                def[4]<5||def[4]>10)
                        {
                            printf("錯誤:能力數值在限制之外\n");
                            continue;

                        }
                        if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                        {

                            printf("錯誤:能力數值在限制之外\n");
                            continue;
                        }
                    }
                    else                            //屬性以外
                    {

                        if (hp[4]<40 || hp[4]>50||//數值限制
                                atk[4]<15||atk[4]>20||
                                def[4]<5||def[4]>10)
                        {
                            if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                            {
                                printf("無此屬性\n");
                                printf("錯誤:能力數值在限制之外\n");
                                continue;
                            }

                        }
                        printf("無此屬性\n");//屬性錯誤
                        continue;
                    }
                    if (type[4]=='f')//大小寫轉換
                    {
                        type[4]='F';
                    }
                    else if (type[4]=='w')
                    {
                        type[4]='W';
                    }
                    else if (type[4]=='g')
                    {
                        char4type='G';

                    }
                    else if (char4type=='a')
                    {
                        char4type='A';
                    }
                    if (hp[4]<40 || hp[4]>50||//數值限制
                            atk[4]<15||atk[4]>20||
                            def[4]<5||def[4]>10)
                    {
                        printf("錯誤:能力數值在限制之外\n");
                        continue;
                    }
                    if ((def[4]+atk[4]+hp[4])<65||(def[4]+atk[4]+hp[4])>70)
                    {

                        printf("錯誤:能力數值在限制之外\n");
                        continue;
                    }






                    printf("\n");
                    printf("角色4\n");
                    printf("名稱:%s\n",name4);
                    printf("屬性:%c 攻擊%d\n",type[4],atk[4]);
                    printf("血量:%d 防禦%d\n",hp[4],def[4]);
                    printf("角色預測強度:%.2f\n",((hp[4]*1)+(atk[4]*0.8)+(def[4]*0.5)-50)*6.5);
                    printf("\n");
                    break;
                }
                break;
            }
        }
        if(caser==3)
        {
            if (atk[4]==0) //輸入2的路線
            {
                for(;;)
                {
                    printf("輸入先攻角色:\n");
                    scanf("%d",&first);
                    if (first!=1&&first!=2&&first!=3)
                    {
                        printf("錯誤:角色不存在\n");
                        continue;
                    }


                    {
                        for(; ;)
                        {

                            printf("輸入後攻角色:\n");
                            scanf("%d",&last);
                            if (last!=1&&last!=2&&last!=3)
                            {
                                printf("錯誤:角色不存在\n");
                                continue;
                            }

                            if (first==last)
                            {
                                printf("錯誤:不可重複選取\n");
                                continue;
                            }
                            break;
                        }
                    }
                    break;
                }

            }
            else if(atk[4]!=0)
            {
                for(;;)
                {
                    printf("輸入先攻角色:\n");
                    scanf("%d",&first);
                    if (first!=1&&first!=2&&first!=3&&first!=4)
                    {
                        printf("錯誤:角色不存在\n");
                        continue;
                    }



                    for(; ;)
                    {

                        printf("輸入後攻角色:\n");
                        scanf("%d",&last);
                        if (last!=1&&last!=2&&last!=3&&last!=4)
                        {
                            printf("錯誤:角色不存在\n");
                            continue;
                        }

                        if (first==last)
                        {
                            printf("錯誤:不可重複選取\n");
                            continue;
                        }
                        break;
                    }

                    break;
                }
            }







            else
            {
                printf("輸入錯誤\n");
                continue;
            }




            printf("先攻為角色%d、後攻為角色%d\n",first,last);
            printf("戰鬥開始\n");
            for(; ;)
            {
                if(first==1)
                {
                    first_atk=atk[1],first_def=def[1],first_HP=hp[1],first_type=type[1];
                }
                if(first==2)
                {
                    first_atk=atk[2],first_def=def[2],first_HP=hp[2],first_type=type[2];;
                }
                if(first==3)
                {
                    first_atk=atk[3],first_def=def[3],first_HP=hp[3],first_type=type[3];;
                }
                if(first==4)
                {
                    first_atk=atk[4],first_def=def[4],first_HP=hp[4],first_type=type[4];;
                }
                if(last==1)
                {
                    last_atk=atk[1],last_def=def[1],last_HP=hp[1],last_type=type[1];
                }
                if(last==2)
                {
                    last_atk=atk[2],last_def=def[2],last_HP=hp[2],last_type=type[2];
                }
                if(last==3)
                {
                    last_atk=atk[3],last_def=def[3],last_HP=hp[3],last_type=type[3];
                }
                if(last==4)
                {
                    last_atk=atk[4],last_def=def[4],last_HP=hp[4],last_type=type[4];
                }

                first2_HP=first_HP/2;
                last2_HP=last_HP/2;
                if(first_type=='W'&&last_type=='F')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                 if(first_type=='F'&&last_type=='A')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                     if(first_type=='A'&&last_type=='G')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                     if(first_type=='G'&&last_type=='W')
                    first_atk=first_atk*1.2,last_atk=last_atk*0.8;
                if(first_type=='F'&&last_type=='W')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                if(first_type=='A'&&last_type=='F')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                    if(first_type=='G'&&last_type=='A')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;
                    if(first_type=='W'&&last_type=='G')
                    last_atk=last_atk*1.2,first_atk=first_atk*0.8;


                while(first_HP>0&&last_HP>0)        //戰鬥迴圈
                {


                    if(first_HP<first2_HP)
                        first_atk=first_atk*1.2;
                    if(last_HP<last2_HP)
                        last_atk=last_atk*1.2;
                    printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",first,last,first_atk-last_def);
                    last_HP-=first_atk-last_def;
                    printf("角色%d HP:%d 角色%d HP:%d\n",first,first_HP,last,last_HP);


                    printf("\n");
                    if(last_HP<=0)
                    {
                        printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",last,first);
                        return 0;
                         //獲勝即結束
                    }
                    printf("角色%d 對 角色%d 發動攻擊造成%d傷害\n",last,first,last_atk-first_def);
                    first_HP-=last_atk-first_def;
                    printf("角色%d HP:%d 角色%d HP:%d\n",first,first_HP,last,last_HP);
                    printf("\n");
                     if(first_HP<=0)
                    {
                        printf("角色%d失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",first,last);
                        return 0;
                           //獲勝即結束
                    }



                }


            }


        }
        else
            continue;
        return 0;
    }//結束

}
