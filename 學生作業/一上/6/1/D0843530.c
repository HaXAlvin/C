#include<stdio.h>
#include<ctype.h>

int main(){

    char char1_type ='F';
    int char1_hp = 42;
    int char1_atk = 18;
    int char1_def = 9;
    int a = printf("111");
    printf("%d",a);
    system("pause");
    char char2_type ='G';
    int char2_hp = 45;
    int char2_atk = 15;
    int char2_def = 10;

    char char3_type ='A';
    int char3_hp = 50;
    int char3_atk = 15;
    int char3_def = 5;

    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;

	float tal1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;
	float tal2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;
	float tal3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;


    printf("角色1\n角色名稱:鎧凌\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n角色強度預測：%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,tal1);
    printf("角色2\n角色名稱:睿童\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n角色強度預測：%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,tal2);
    printf("角色3\n角色名稱:宜銹\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n角色強度預測：%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,tal3);
    //printf("角色1\n角色名稱:鎧凌\n屬性:F\t\t血量:42\n攻擊:18\t\t防禦:9\n\n");//總和69
    //printf("角色2\n角色名稱:睿童\n屬性:G\t\t血量:45\n攻擊:15\t\t防禦:10\n\n");//總和70
    //printf("角色3\n角色名稱:宜銹\n屬性:A\t\t血量:50\n攻擊:15\t\t防禦:5\n\n");//總和70
    //強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    int chose;
    int failed=0;
    int first_atk,second_atk;

    do{ //是否新增角色 輸入錯誤時 重新詢問
        printf("是否新增角色(1.Yes/2.No)?");
        scanf("%d",&chose);
        failed = 0;
        if (chose>=3||chose<=0){
            printf("輸入錯誤\n");
            failed = 1;
        }

    }while(failed == 1);


    if (chose==1){ //新增角色

        do{  //新增角色 且判斷數值及屬性是否錯誤
            failed = 0;
            printf("\n新增角色\n");
            printf("屬性:");
            scanf(" %c",&char4_type); //%c之前要有個空格  若是打%c不用打getchar 或 \n
            printf("血量:");
            scanf("%d",&char4_hp);
            getchar();
            printf("攻擊:");
            scanf("%d",&char4_atk);
            getchar();
            printf("防禦:");
            scanf("%d",&char4_def);

            int sum=char4_def+char4_hp+char4_atk;

            if ((char4_type!='G'&&char4_type!='W'&&char4_type!='A'&&char4_type!='F'&&char4_type!='a'&&char4_type!='f'&&char4_type!='g'&&char4_type!='w')&&(char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||sum<65||sum>70)){
                printf("\n錯誤：無此屬性\n錯誤：能力數值在限制範圍之外\n");
                failed = 1;

            }

            else if (char4_type!='G'&&char4_type!='W'&&char4_type!='A'&&char4_type!='F'&&char4_type!='a'&&char4_type!='f'&&char4_type!='g'&&char4_type!='w'){
                printf("錯誤：無此屬性\n");   //若輸入非F A G W之屬性 則輸出無此屬性
                failed = 1;

            }

            else if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||sum<65||sum>70){
                printf("錯誤：能力數值在限制範圍之外\n");  //設定各屬性之範圍
                failed = 1;
            }
        }while(failed == 1);


        float tal4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;
        printf("\n角色4\n角色名稱:自訂角色\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n",toupper(char4_type),char4_hp,char4_atk,char4_def);
        printf("角色強度預測：%.2f\n",tal4); //列出新增角色之屬性


    }

    do{  //選擇先攻後攻

        do{  //當先攻輸入錯誤時 重複輸入
            failed = 0;
            printf("\n選擇先攻角色： ");
            scanf("%d",&first_atk);
            if (chose == 1){
                if (first_atk>=5){ //新增角色後，有4個角色 >=5
                    printf("錯誤：無此角色");
                    failed = 1;
                }
            }
            else if(chose == 2){
                if (first_atk>=4){
                    printf("錯誤：無此角色");//沒有新增角色，有3個角色 >=4
                    failed = 1;
                }
            }
        }while(failed == 1);






        do{  //當後攻輸入錯誤時 重複輸入
            failed = 0;
            printf("選擇後攻角色： ");
            scanf("%d",&second_atk);

            if (chose == 1){
                if (second_atk>=5){ //新增角色後，有4個角色 >=5
                    printf("錯誤：無此角色\n");
                    failed = 1;
                }
            }
            else if(chose == 2){
                if (second_atk>=4){
                    printf("錯誤：無此角色\n");//沒有新增角色，有3個角色 >=4
                    failed = 1;
                }
            }
        }while(failed == 1);



        if (first_atk==second_atk){ //重複選取
            printf("錯誤：不可重複選取\n");
            failed = 1;
        }


        else {  //輸入正確 輸出先攻及後攻
            printf("\n先攻為角色%d、後攻為角色%d\n",first_atk,second_atk);
        }
    }while(failed == 1);





    int atk1,def1,atk2,def2,hp1,hp2;

    switch (first_atk){ //取出先攻的防禦及攻擊力
        case 1:
            atk1 = char1_atk;
            def1 = char1_def;
            hp1 = char1_hp;
            break;
        case 2:
            atk1 = char2_atk;
            def1 = char2_def;
            hp1 = char2_hp;
            break;
        case 3:
            atk1 = char3_atk;
            def1 = char3_def;
            hp1 = char3_hp;
            break;
        case 4:
            atk1 = char4_atk;
            def1 = char4_def;
            hp1 = char4_hp;
            break;
    }

    switch (second_atk){ //取出後攻的防禦及攻擊力

        case 1:
            atk2 = char1_atk;
            def2 = char1_def;
            hp2 = char1_hp;
            break;
        case 2:
            atk2 = char2_atk;
            def2 = char2_def;
            hp2 = char2_hp;
            break;
        case 3:
            atk2 = char3_atk;
            def2 = char3_def;
            hp2 = char3_hp;
            break;
        case 4:
            atk2 = char4_atk;
            def2 = char4_def;
            hp2 = char4_hp;
            break;
    }



    printf("戰鬥開始\n\n");


    do{  //對戰
        failed = 0;

        int hurt1 = atk1 - def2;
        int hurt2 = atk2 - def1;

        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",first_atk,second_atk,hurt1);
        hp2 = hp2 - hurt1;
        printf("角色%d HP： %d 角色%d HP： %d\n\n",first_atk,hp1,second_atk,hp2);

        if (hp1<=0 || hp2<=0){
            failed = 1;
            break;
        }


        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",second_atk,first_atk,hurt2);
        hp1 = hp1 - hurt2;
        printf("角色%d HP： %d 角色%d HP： %d\n\n",first_atk,hp1,second_atk,hp2);

        if (hp1<=0 || hp2<=0)
            failed = 1;




    }while(failed == 0);

    int win,lose;
    if (hp1<=0){  //辨別贏家及輸家
        lose = first_atk;
        win = second_atk;
    }

    else if (hp2<=0){  //辨別贏家及輸家
        lose = second_atk;
        win = first_atk;
    }



    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n",lose,win);


    return 0;
}
