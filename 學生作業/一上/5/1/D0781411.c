#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

    //角色4分隔線
    int new_char; //是否新增角色
    char char4_type; //屬性字元
    int char4_atk;
    int char4_hp;
    int char4_def;
    int attack1; //先攻
    int attack2; //後攻
    printf("是否新增角色(1.Yes 2.No)  ");
    scanf("%d%*c",&new_char);
    if (new_char==1)
    {
        printf("角色屬性:");
        scanf ("%c",&char4_type);
        char4_type=toupper(char4_type);//小寫轉大寫
        if (char4_type==65||char4_type==70||char4_type==71||char4_type==87) //F,W,G,A 的 ASCII
        {
            printf("血量:");
            scanf ("%d",&char4_hp);
            printf("攻擊:");
            scanf ("%d",&char4_atk);
            printf("防禦:");
            scanf ("%d",&char4_def);
            if (char4_atk>20||char4_atk<15||char4_hp>50||char4_hp<40||char4_def<5||char4_def>10||(char4_def+char4_hp+char4_atk)>70||(char4_def+char4_hp+char4_atk)<65)//能力限制外
            {
                printf("錯誤:能力數值在限制範圍之外");
            }
            else//能力數值內
            {
                float char_4 = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;
                printf("\n角色4\n名稱：破腦\n");
                printf("屬性： %c  ",char4_type);
                printf("攻擊：%d\n",char4_atk);
                printf("血量：%d  ",char4_hp);
                printf("防禦：%d\n",char4_def);
                printf("角色強度：%.2f\n\n",char_4);

	            printf("選取先攻角色");
	            scanf("%d",&attack1);
	            if (attack1>=5||attack1<1) //角色只有1~4  attack範圍  1<= attack <=4
	            {
	                printf("錯誤:無此角色");
	            }
	            else
	            {
	                printf("選取後攻角色");
	                scanf("%d",&attack2);
	                if(attack2>=5||attack2<1)//角色只有1~5  attack範圍  1<= attack <=4
	                {
	                    printf("錯誤:無此角色");
	                }
	                else if(attack1==attack2)//角色不能重複
	                {
	                    printf("錯誤:不可重複選取");
	                }
	                else
	                {
	                    printf("先攻角色為%d,後攻角色為%d\n",attack1,attack2);
	                }

	            }
	        }

        }
        else
        {
            printf("錯誤:無此屬性");
        }
    }
    else if(new_char==2)//不新增角色
    {

        printf("選取先攻角色");
        scanf("%d",&attack1);
        if (attack1>=4||attack1<1) //角色只有1~3  attack範圍  1<= attack <=3
        {
            printf("錯誤:無此角色");
        }
        else
        {
            printf("選取後攻角色");
            scanf("%d",&attack2);
            if(attack2>=4||attack2<1)//角色只有1~3  attack範圍  1<= attack <=3
            {
                printf("錯誤:無此角色");
            }
            else if(attack1==attack2)//角色不能重複
            {
                printf("錯誤:不可重複選取");
            }
            else
            {
                printf("先攻角色為%d,後攻角色為%d\n",attack1,attack2);
            }

        }

    }
    else//其他的錯誤數字 (選角部分)
    {
        printf("輸入錯誤\n\n");
    }
    return 0;
}	// 結束的大括號
