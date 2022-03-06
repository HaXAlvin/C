#include<stdio.h>//標頭檔
#include<stdlib.h>
//標頭檔


char type[4]= {'F','W','G'}; //屬性
int hp[4]= {42,48,45,0}; //血量
int atk[4]= {19,16,16,0}; //攻擊
int def[4]= {5,5,7,0}; //防禦
char char_n[][21]= {"死亡之翼","我阿嬤","阿公"};
int inputchar=0;

int is_correct,turn;

float bloodatk=1.2;
float first_restraintatk;
float second_restraintatk;

int first_atk, second_atk;

int first_atk_origin_hp;
int first_atk_type;
int first_atk_hp;
int first_atk_atk;
int first_atk_def;

int second_atk_origin_hp;
int second_atk_type;
int second_atk_hp;
int second_atk_atk;
int second_atk_def;
int choice=6;
char F,G,W,A,f,g,w,a;

int printf_player(int num) {
    printf("\n名稱:%s\n",char_n[num]);
    printf( "屬性:%c  攻擊:%d\n",type[num],atk[num]);
    printf("血量:%d   防禦:%d\n",hp[num],def[num]);
    printf("角色強度預測:%.2f\n\n",(atk[num]*0.8+hp[num]*1.0+def[num]*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
}
int editnewchar(int num) {
    do {
        if( inputchar==1) {
            printf("修改新增角色\n");//印出新增角色
        } else {
            printf("新增角色\n");//印出新增角色
        }
        printf("名稱:");
        scanf("%s",&char_n[3]);
        getchar();
        printf("屬性:");//印出屬性
        scanf(" %c",&type[3]);
        printf("血量:");//印出血量
        scanf("%d",&hp[3]);
        printf("攻擊:");//印出攻擊
        scanf("%d",&atk[3]);
        printf("防禦:");//印出防禦
        scanf("%d",&def[3]);
        printf("\n");
        if(type[3]!='F'&&type[3]!='G'&&type[3]!='A'&&type[3]!='W'&&type[3]!='f'&&type[3]!='a'&&type[3]!='w'&&type[3]!='g')
            printf("錯誤:無此屬性\n");//檢察屬性
        if((atk[3]+hp[3]+def[3]<50)||(atk[3]+hp[3]+def[3]>70)||(atk[3]>20)||(atk[3]<15)||(hp[3]>50)||(hp[3]<40)||(def[3]<5)||(def[3]>10))
            printf("錯誤:能力數值在限制範圍之外\n");//檢查能力數值
        if(type[3]=='f')//if char4_type等於f,轉為大寫
            type[3]='F';
        if(type[3]=='a')//if char4_type等於a,轉為大寫
            type[3]='A';
        if(type[3]=='g')//if char4_type等於g,轉為大寫
            type[3]='G';
        if(type[3]=='w')//if char4_type等於w,轉為大寫
            type[3]='W';
    } while((atk[3]+hp[3]+def[3]<50)||(atk[3]+hp[3]+def[3]>70)||(atk[3]>20)||(atk[3]<15)||(hp[3]>50)||(hp[3]<40)||(def[3]<5)||(def[3]>10)
            ||type[3]!='F'&&type[3]!='G'&&type[3]!='A'&&type[3]!='W'&&type[3]!='f'&&type[3]!='a'&&type[3]!='w'&&type[3]!='g');


    printf("角色4\n"//印出角色4
           "名稱:%s\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n\n",char_n[3],type[3],atk[3],hp[3],def[3]);
    printf("角色強度預測:%.2f\n\n",(atk[3]*0.8+hp[3]*1.0+def[3]*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    inputchar=1;
}

int SelectAndBattle(int first_atk,int second_atk) {
    do {
        is_correct = 1; //初始化flag
        printf("選擇先攻角色：");
        scanf("%d", &first_atk);
        if(first_atk < 1 || first_atk > 3 + inputchar) {
            printf("錯誤：無此角色\n");
            is_correct = 0;
        }
    } while(!is_correct);
    do {
        is_correct = 1; //初始化flag
        printf("選擇後攻角色：");
        scanf("%d", &second_atk);
        if(second_atk < 1 || second_atk > 3 + inputchar) {
            printf("錯誤：無此角色\n");
            is_correct = 0;
        } else if(second_atk == first_atk) {
            printf("錯誤：不可重複選取\n");
            is_correct = 0;
        }
    } while(!is_correct);
    printf("\n先攻為角色%d、後攻為角色%d\n", first_atk, second_atk);

    //將先攻的能力資料取出
    first_atk_hp = (first_atk == 1) ? hp[0] : (first_atk == 2) ? hp[1] : (first_atk == 3) ? hp[2] : hp[3];
    first_atk_atk = (first_atk == 1) ? atk[0] : (first_atk == 2) ? atk[1] : (first_atk == 3) ?atk[2] : atk[3];
    first_atk_def = (first_atk == 1) ? def[0] : (first_atk == 2) ? def[1] : (first_atk == 3) ? def[2] : def[3];
    first_atk_type = (first_atk == 1) ? type[0] : (first_atk == 2) ? type[1] : (first_atk == 3) ? type[2] : type[3];
    //將後攻的能力資料取出
    second_atk_hp = (second_atk == 1) ? hp[0] : (second_atk == 2) ? hp[1] : (second_atk == 3) ? hp[2] : hp[3];
    second_atk_atk = (second_atk == 1) ? atk[0] : (second_atk == 2) ? atk[1] : (second_atk == 3) ? atk[2] : atk[3];
    second_atk_def = (second_atk == 1) ? def[0] : (second_atk == 2) ? def[1] : (second_atk == 3) ? def[2] : def[3];
    second_atk_type = (second_atk == 1) ? type[0] : (second_atk == 2) ? type[1] : (second_atk == 3) ? type[2] : type[3];

    Battling( first_atk, second_atk);

}
int Battling(int first_atk,int second_atk) {
    turn = 1; //初始化攻擊方
    first_atk_origin_hp = first_atk_hp;
    second_atk_origin_hp = second_atk_hp;

    printf("戰鬥開始\n\n");

    if((first_atk_type=='W')&&(second_atk_type=='F')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;

    }
    if((first_atk_type=='W')&&(second_atk_type=='A')) {
        first_restraintatk=1;
        second_restraintatk=1;

    }
    if((first_atk_type=='W')&&(second_atk_type=='G')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='F')&&(second_atk_type=='A')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='F')&&(second_atk_type=='G')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='F')&&(second_atk_type=='W')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='A')&&(second_atk_type=='G')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='A')&&(second_atk_type=='W')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='A')&&(second_atk_type=='F')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='G')&&(second_atk_type=='W')) {
        first_restraintatk=1.2;
        second_restraintatk=0.8;
    }
    if((first_atk_type=='G')&&(second_atk_type=='F')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='G')&&(second_atk_type=='A')) {
        first_restraintatk=0.8;
        second_restraintatk=1.2;
    }
    if((first_atk_type=='W')&&(second_atk_type=='W')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='A')&&(second_atk_type=='A')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='G')&&(second_atk_type=='G')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    if((first_atk_type=='F')&&(second_atk_type=='F')) {
        first_restraintatk=1;
        second_restraintatk=1;
    }
    while(first_atk_hp >=0 && second_atk_hp >= 0) {
        int atk;
        if(turn == 1) {
            atk = first_atk_atk*first_restraintatk - second_atk_def;
            if(first_atk_hp <  first_atk_origin_hp/2) {
                atk= (first_atk_atk*bloodatk*first_restraintatk) - second_atk_def;
            }
            second_atk_hp -=atk;
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", first_atk, second_atk, atk);
            turn = 2; //交換攻擊方
        }

        else {
            atk = second_atk_atk*second_restraintatk - first_atk_def;
            if(second_atk_hp <  second_atk_origin_hp/2) {
                atk= (second_atk_atk*bloodatk*second_restraintatk) - first_atk_def;
            }
            first_atk_hp -=atk;
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n", second_atk, first_atk, atk);
            turn = 1; //交換攻擊方
        }
        printf("角色%d HP: %d  角色%d HP: %d\n\n", first_atk, first_atk_hp, second_atk, second_atk_hp);
    }
    printf("角色%d 失去戰鬥能力\n", (first_atk_hp > 0) ? second_atk : first_atk);
    printf("戰鬥結束\n\n");
    printf("角色%d 獲勝\n", (first_atk_hp > 0) ? first_atk : second_atk);
}

int main() { //主函式
    while(choice!=0) {
        printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n"
               "請選擇:");
        scanf("%d",&choice);
        printf("\n");
        if(choice<0||choice>3) {
            printf("輸入錯誤!\n\n");
        }
        if(choice==1) {
            editnewchar(3);
        }
        if(choice==2) {
            int i;
            for(i=0; i<3+inputchar; i++) {
                printf("角色%d\n",i+1);
                printf_player(i);
            }
        }
        if(choice==3) {
            SelectAndBattle(first_atk,second_atk);
        }
    }
    printf("\n");
    printf("結束遊戲\n");
    return 0;
}
