#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
void playerchoose() {
    printf("1.新增或修改新增角色\n");
    printf("2.顯示所有角色資料\n");
    printf("3.戰鬥\n");
    printf("0.結束遊戲\n");
    printf("請選擇：");
    return;
}
void print_char_data(int i,char char_name[],char type,int atk,int hp,int def) {//角色強度計算和印出角色資訊
    //角色強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    float strongpre = (hp*1.0 + atk * 0.8 + def * 0.5 -50 ) * 6.5;
    printf("角色%d\n名稱:%s\n屬性:%c    攻擊:%d\n血量:%d   防禦:%d\n角色強度預測:%.2f\n\n",i,char_name,type,atk,hp,def,strongpre);
}
int does_addchar_correct(char type,int atk,int hp,int def) {//判斷角色新增資訊是否正確
    int correctflag=1;
    if(type != 'F' && type != 'W' && type != 'G' && type != 'A'&& type != 'f' && type != 'w' && type != 'g' && type != 'a') {
        printf("錯誤：無此屬性\n");
        correctflag = 0;
    }
    int char4_total = hp + atk + def;
    if(hp < 40 || hp > 50 || atk < 15 || atk > 20 || def < 5 || def > 10 || char4_total < 65 || char4_total > 70) {
        printf("錯誤：能力數值在限制範圍之外\n");
        printf("\n");
        correctflag = 0;
    }
    if(correctflag==0)
        return 0;
    else if(correctflag==1)
        return 1;
}
void addchar(int addcharflag,char char_name[][21],char type[],int hp[],int atk[],int def[]) {//新增與修改角色
    if(addcharflag==0) {
        printf("新增角色\n");
        printf("名稱:");
        scanf("%s",&char_name[4]);
        printf("類型(F=火、W=水、G=土、A=風):");
        scanf(" %c", &type[4]);
        printf("血量(40~50):");
        scanf("%d", &hp[4]);
        printf("攻擊(15~20):");
        scanf("%d", &atk[4]);
        printf("防禦(5~10):");
        scanf("%d", &def[4]);
        printf("\n");
        return;
    } else if(addcharflag==1) {
        printf("修改新增角色\n");
        printf("名稱:");
        scanf("%s",&char_name[4]);
        printf("類型(F=火、W=水、G=土、A=風):");
        scanf(" %c", &type[4]);
        printf("血量(40~50):");
        scanf("%d", &hp[4]);
        printf("攻擊(15~20):");
        scanf("%d", &atk[4]);
        printf("防禦(5~10):");
        scanf("%d", &def[4]);
        printf("\n");
        return;
    }
}
float first_blood_rate(char first_atk_type,char last_atk_type) {//計算殘屑倍率
    if((first_atk_type=='W'&&last_atk_type=='F')||(first_atk_type=='F'&&last_atk_type=='A')||
            (first_atk_type=='A'&&last_atk_type=='G')||(first_atk_type=='G'&&last_atk_type=='W'))
        return 1.2;//firstatkhurt = first_atk_atk*1.2;
    else if((first_atk_type=='F'&&last_atk_type=='W')||(first_atk_type=='A'&&last_atk_type=='F')||
            (first_atk_type=='G'&&last_atk_type=='A')||(first_atk_type=='W'&&last_atk_type=='G'))
        return 0.8;//firstatkhurt = first_atk_atk*0.8;
    else
        return 1.0;
}
float last_blood_rate(char first_atk_type,char last_atk_type) {//計算殘屑倍率
    if((last_atk_type=='W'&&first_atk_type=='F')||(last_atk_type=='F'&&first_atk_type=='A')||
            (last_atk_type=='A'&&first_atk_type=='G')||(last_atk_type=='G'&&first_atk_type=='W'))
        return 1.2;//lastatkhurt = last_atk_atk*1.2;
    else if((last_atk_type=='F'&&first_atk_type=='W')||(last_atk_type=='A'&&first_atk_type=='F')||
            (last_atk_type=='G'&&first_atk_type=='A')||(last_atk_type=='W'&&first_atk_type=='G'))
        return 0.8;//lastatkhurt = last_atk_atk*0.8;
}
//攻擊傷害 = (int)(攻擊方攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
//屬性相剋倍率：屬性關係W>F>A>G>W
//若為相剋關係：優勢者1.2倍，劣勢者0.8倍,若雙方無相剋則攻擊力各為1.0倍
//殘血倍率：攻擊方血量小於原本的50%時殘血倍率為1.2倍
//battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
void battling(int first_atk_char,int last_atk_char,char first_atk_type,char last_atk_type,int first_atk_atk,int last_atk_atk,int first_atk_hp,int last_atk_hp,int first_atk_def,int last_atk_def) {
    int round = 0;
    float firstatkhurt=0;//先攻攻擊力addchar(addchar_flag,char_name[4],type[4],hp[4],atk[4],def[4]);
    float lastatkhurt=0;//後攻攻擊力
    int max_first_atk_hp = first_atk_hp;
    int max_last_atk_hp = last_atk_hp;
    while(first_atk_char> 0||last_atk_char> 0) {
        //攻擊傷害 = 攻擊方攻擊力*相剋倍率*殘血倍率 - 被攻擊方防禦力
        float firstbloodrate = first_blood_rate(first_atk_type,last_atk_type);
        float lastbloodrate = last_blood_rate(first_atk_type,last_atk_type);
        firstatkhurt = first_atk_atk * firstbloodrate;
        lastatkhurt = last_atk_atk * lastbloodrate;
        //判斷第幾回合以讓先後攻順序交換
        if(round%2==0) {
            if(first_atk_hp<(0.5 * max_first_atk_hp))//判斷殘寫倍率
                firstatkhurt = firstatkhurt*1.2;
            int finalfirstatkhurt = firstatkhurt-last_atk_def;//減掉防禦力
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",first_atk_char,last_atk_char,finalfirstatkhurt);
            last_atk_hp = last_atk_hp - finalfirstatkhurt;
            printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
        } else if(round%2==1) {
            if(last_atk_hp<(0.5 * max_last_atk_hp))
                lastatkhurt=lastatkhurt*1.2;
            int finallastatkhurt = lastatkhurt-first_atk_def;
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",last_atk_char,first_atk_char,finallastatkhurt);
            first_atk_hp = first_atk_hp - finallastatkhurt;
            printf("角色%d HP: %d 角色%d HP: %d\n\n",first_atk_char,first_atk_hp,last_atk_char,last_atk_hp);
        }
        round++;//執行一次迴圈多一回合
        if(first_atk_hp<=0) {
            printf("角色%d 失去戰鬥能力\n",first_atk_char);
            printf("戰鬥結束\n");
            printf("\n角色%d 獲勝\n\n",last_atk_char);
            break;//一旦角色沒血顯示訊息後結束迴圈
        } else if(last_atk_hp<=0) {
            printf("角色%d 失去戰鬥能力\n",last_atk_char);
            printf("戰鬥結束\n");
            printf("\n角色%d 獲勝\n\n",first_atk_char);
            break;//一旦角色沒血顯示訊息後結束迴圈
        }
    }
}
void SelectAndBattle(int first_atk_char,int last_atk_char,char type[],int hp[],int atk[],int def[]) {//輸入戰鬥角色資訊及判斷是否輸入錯誤
    int first_atk_hp, first_atk_atk,first_atk_def,last_atk_hp,last_atk_atk,last_atk_def,first_atk_type,last_atk_type;
    do {
        do {
            printf("選擇先攻角色:");
            scanf("%d",&first_atk_char);
            if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4)  //一旦輸入並非已定義角色，輸出錯誤
                printf("錯誤:無此角色\n");
        } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3&&first_atk_char!=4);
        do {
            printf("選擇後攻角色:");
            scanf("%d",&last_atk_char);
            if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4)  //一旦輸入並非已定義角色，輸出錯誤
                printf("錯誤:無此角色\n");
        } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3&&last_atk_char!=4);
        if(first_atk_char==last_atk_char)   //一旦先攻角色等於後攻角色，輸出錯誤
            printf("錯誤:不可重複選取\n");
    } while(first_atk_char==last_atk_char);
    printf("\n先攻角色為%d ，後攻角色為%d\n",first_atk_char,last_atk_char);  //印出最終輸入
    printf("開始戰鬥\n\n");
    if(first_atk_char == 1) {
        first_atk_hp = hp[1];
        first_atk_atk = atk[1];
        first_atk_def = def[1];
        first_atk_type = type[1];
    } else if (first_atk_char == 2) {
        first_atk_hp = hp[2];
        first_atk_atk = atk[2];
        first_atk_def = def[2];
        first_atk_type = type[2];
    } else if (first_atk_char ==3) {
        first_atk_hp = hp[3];
        first_atk_atk = atk[3];
        first_atk_def = def[3];
        first_atk_type = type[3];
    } else if (first_atk_char ==4) {
        first_atk_hp = hp[4];
        first_atk_atk = atk[4];
        first_atk_def = def[4];
        first_atk_type = type[4];
    }
    if(last_atk_char == 1) {
        last_atk_hp = hp[1];
        last_atk_atk = atk[1];
        last_atk_def = def[1];
        last_atk_type = type[1];
    } else if (last_atk_char == 2) {
        last_atk_hp = hp[2];
        last_atk_atk = atk[2];
        last_atk_def = def[2];
        last_atk_type = type[2];
    } else if (last_atk_char == 3) {
        last_atk_hp = hp[3];
        last_atk_atk = atk[3];
        last_atk_def = def[3];
        last_atk_type = type[3];
    } else if (last_atk_char == 4) {
        last_atk_hp = hp[4];
        last_atk_atk = atk[4];
        last_atk_def = def[4];
        last_atk_type = type[4];
    }//戰鬥
    battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
}
void SelectAndBattle123(int first_atk_char,int last_atk_char,char type[],int hp[],int atk[],int def[]) {//輸入戰鬥角色資訊及判斷是否輸入錯誤
    int first_atk_hp, first_atk_atk,first_atk_def,last_atk_hp,last_atk_atk,last_atk_def,first_atk_type,last_atk_type;
    do {
        do {
            printf("選擇先攻角色:");
            scanf("%d",&first_atk_char);
            if(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3)  //一旦輸入並非已定義角色，輸出錯誤
                printf("錯誤:無此角色\n");
        } while(first_atk_char!=1&&first_atk_char!=2&&first_atk_char!=3);
        do {
            printf("選擇後攻角色:");
            scanf("%d",&last_atk_char);
            if(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3)  //一旦輸入並非已定義角色，輸出錯誤
                printf("錯誤:無此角色\n");
        } while(last_atk_char!=1&&last_atk_char!=2&&last_atk_char!=3);
        if(first_atk_char==last_atk_char)   //一旦先攻角色等於後攻角色，輸出錯誤
            printf("錯誤:不可重複選取\n");
    } while(first_atk_char==last_atk_char);
    printf("\n先攻角色為%d ，後攻角色為%d\n",first_atk_char,last_atk_char);  //印出最終輸入
    printf("開始戰鬥\n\n");
    if(first_atk_char == 1) {
        first_atk_hp = hp[1];
        first_atk_atk = atk[1];
        first_atk_def = def[1];
        first_atk_type = type[1];
    } else if (first_atk_char == 2) {
        first_atk_hp = hp[2];
        first_atk_atk = atk[2];
        first_atk_def = def[2];
        first_atk_type = type[2];
    } else if (first_atk_char ==3) {
        first_atk_hp = hp[3];
        first_atk_atk = atk[3];
        first_atk_def = def[3];
        first_atk_type = type[3];
    }
    if(last_atk_char == 1) {
        last_atk_hp = hp[1];
        last_atk_atk = atk[1];
        last_atk_def = def[1];
        last_atk_type = type[1];
    } else if (last_atk_char == 2) {
        last_atk_hp = hp[2];
        last_atk_atk = atk[2];
        last_atk_def = def[2];
        last_atk_type = type[2];
    } else if (last_atk_char == 3) {
        last_atk_hp = hp[3];
        last_atk_atk = atk[3];
        last_atk_def = def[3];
        last_atk_type = type[3];
    }//戰鬥
    battling(first_atk_char,last_atk_char,first_atk_type,last_atk_type,first_atk_atk,last_atk_atk,first_atk_hp,last_atk_hp,first_atk_def,last_atk_def);
}
int main() {
    int playerchose;
    float strongpre[5];
    char type[5]= {'0','W','A','F','0'};
    char char_name [5][21]= {"","劍指蒼穹","敲血為凝","超鬼特工",""};
    int hp[5] = {0,50,40,45,0};
    int atk[5] = {0,15,20,17,0};
    int def[5] = {0,5,8,7,0};
    int i,j,k;
    int first_atk_char,last_atk_char,addchar_flag=0,correctflag = 1;
    while(5) { //一直循環問題直到結束
        playerchoose();
        scanf("%d",&playerchose);
        printf("\n");
        if(playerchose==1) {
            int exit = 0;
            if (addchar_flag==0) {
                while(!exit) {//計算新增角色的強度，並印出角色4的最終資訊
                    addchar(addchar_flag,char_name,type,hp,atk,def);
                    if(type[4] >= 'a')
                        type[4] -= 32;
                    exit = does_addchar_correct(type[4],atk[4],hp[4],def[4]);
                }
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
                addchar_flag=1;//紀錄是否有角色4
            } else if(addchar_flag==1) {//計算修改新增角色的強度，並印出角色4的最終資訊
                while(!exit) {
                    addchar(addchar_flag,char_name,type,hp,atk,def);
                    if(type[4] >= 'a')
                        type[4] -= 32;
                    exit = does_addchar_correct(type[4],atk[4],hp[4],def[4]);
                }
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
                addchar_flag=1;//紀錄是否有角色4
            }
        } else if(playerchose==2) {
            if(addchar_flag==0) { //沒有角色4
                print_char_data(1,char_name[1],type[1],atk[1],hp[1],def[1]);
                print_char_data(2,char_name[2],type[2],atk[2],hp[2],def[2]);
                print_char_data(3,char_name[3],type[3],atk[3],hp[3],def[3]);
            } else if (addchar_flag==1) { //有角色4
                print_char_data(1,char_name[1],type[1],atk[1],hp[1],def[1]);
                print_char_data(2,char_name[2],type[2],atk[2],hp[2],def[2]);
                print_char_data(3,char_name[3],type[3],atk[3],hp[3],def[3]);
                print_char_data(4,char_name[4],type[4],atk[4],hp[4],def[4]);
            }
        } else if(playerchose==3) {
            if(addchar_flag==0) {
                SelectAndBattle123(first_atk_char,last_atk_char,type,hp,atk,def);
            } else if(addchar_flag==1) {
                SelectAndBattle(first_atk_char,last_atk_char,type,hp,atk,def);
            }
        } else if(playerchose==0) {
            printf("結束遊戲\n");
            return 0;
        } else
            printf("輸入錯誤！\n\n");
    }
    return 0;
}


