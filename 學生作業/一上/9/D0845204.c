#include<stdio.h>
#include<ctype.h>
#include<string.h>
    char char_id[4][20]={"所羅門",
                         "瑪娜",
                         "摩西",
                         ""};
    char char_type[4]="FWG";
    int char_hp[4]={42,47,46};
    int char_atk[4]={18,15,19};
    int char_def[4]={9,6,5};
    int Fa,La;
    int suit;


int EditNewChar(int have)
{
        int is_correct=1;
        if(have==0){//還沒建立角色4時 case1需做的事:新增角色
                    printf("\n新增角色\n");
                    printf("名稱:");
                    scanf("%s",char_id[3]);
                    printf("屬性：");
                    scanf("%*c%c", &char_type[3]);
                    printf("血量：");
                    scanf("%d", &char_hp[3]);
                    printf("攻擊：");
                    scanf("%d", &char_atk[3]);
                    printf("防禦：");
                    scanf("%d", &char_def[3]);
                    //檢察屬性
                    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
                        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a'){
                        printf("錯誤：無此屬性\n");
                        is_correct = 0;
                    }
                    else if(char_type[3] >= 'a')
                        char_type[3] -= 32;
                    // 檢查能力數值
                    int char_sum = char_hp[3] + char_atk[3] + char_def[3];
                    if(char_hp[3] < 40 || char_hp[3] > 50 || char_atk[3] < 15 || char_atk[3] > 20 ||
                        char_def[3] < 5 || char_def[3] > 10 || char_sum < 65 || char_sum > 70){
                        printf("錯誤：能力數值在限制範圍之外\n");
                        return 0;
                    }
                    if(!is_correct)
                    return 0;

                    printf("\n角色4\n名稱：%s\n",char_id[3]);
                    printf("屬性：%c     攻擊：%d\n", char_type[3], char_atk[3]);
                    printf("血量：%d    防禦：%d\n", char_hp[3], char_def[3]);
                    printf("角色強度預測：%.2f\n\n", (char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
                    have=1;

        }
        else if(have==1){//已經新增角色4之後case1需要做的事:修改新增角色
                    printf("\n修改新增角色\n");
                    printf("名稱:");
                    scanf("%s",char_id[3]);
                    printf("屬性：");
                    scanf("%*c%c", &char_type[3]);
                    printf("血量：");
                    scanf("%d", &char_hp[3]);
                    printf("攻擊：");
                    scanf("%d", &char_atk[3]);
                    printf("防禦：");
                    scanf("%d", &char_def[3]);
                    //檢察屬性
                    if(char_type[3] != 'F' && char_type[3] != 'W' && char_type[3] != 'G' && char_type[3] != 'A' &&
                        char_type[3] != 'f' && char_type[3] != 'w' && char_type[3] != 'g' && char_type[3] != 'a'){
                        printf("錯誤：無此屬性\n");
                        is_correct = 0;
                    }
                    else if(char_type[3] >= 'a')
                    char_type[3] -= 32;
                    //檢查能力數值
                    int char_sum = char_hp[3] + char_atk[3] + char_def[3];
                    if(char_hp[3] < 40 || char_hp[3] > 50 || char_atk[3] < 15 || char_atk[3] > 20 ||
                        char_def[3] < 5 || char_def[3] > 10 || char_sum < 65 || char_sum > 70){
                        printf("錯誤：能力數值在限制範圍之外\n");
                    return 0;
                    }
                    if(!is_correct)
                    return 0;

                    printf("\n角色4\n名稱：%s\n",char_id[3]);
                    printf("屬性：%c     攻擊：%d\n", char_type[3], char_atk[3]);
                    printf("血量：%d    防禦：%d\n", char_hp[3], char_def[3]);
                    printf("角色強度預測：%.2f\n\n", (char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
                    have=1;
                    return;
        }
}
int PrintCharData(int have)
{

        if(have==0){//還沒新增角色4時印出已經有的3個角色素質
                     printf("角色1\n"
                            "名稱:所羅門\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[0],char_hp[0],char_atk[0],char_def[0],(char_hp[0] * 1.0 + char_atk[0] * 0.8 + char_def[0] * 0.5 - 50.0) * 6.5 );
                     printf("角色2\n"
                            "名稱:瑪娜\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[1],char_hp[1],char_atk[1],char_def[1],(char_hp[1] * 1.0 + char_atk[1] * 0.8 + char_def[1] * 0.5 - 50.0) * 6.5 );
                     printf("角色3\n"
                            "名稱:摩西\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[2],char_hp[2],char_atk[2],char_def[2],(char_hp[2] * 1.0 + char_atk[2] * 0.8 + char_def[2] * 0.5 - 50.0) * 6.5 );
        }
        else if(have==1){//有角色4時 印出4個角色
                     printf("角色1\n"
                            "名稱:所羅門\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[0],char_hp[0],char_atk[0],char_def[0],(char_hp[0] * 1.0 + char_atk[0] * 0.8 + char_def[0] * 0.5 - 50.0) * 6.5 );
                     printf("角色2\n"
                            "名稱:瑪娜\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[1],char_hp[1],char_atk[1],char_def[1],(char_hp[1] * 1.0 + char_atk[1] * 0.8 + char_def[1] * 0.5 - 50.0) * 6.5 );
                     printf("角色3\n"
                            "名稱:摩西\n"
                            "屬性:%-6c    血量:%-6d\n"
                            "攻擊:%-6d    防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_type[2],char_hp[2],char_atk[2],char_def[2],(char_hp[2] * 1.0 + char_atk[2] * 0.8 + char_def[2] * 0.5 - 50.0) * 6.5 );

                     printf("\n角色4\n名稱:%-6s\n"
                            "屬性:%-6c   血量:%-6d\n"
                            "攻擊:%-6d   防禦:%-6d\n"
                            "角色強度預測:%.2f\n\n",char_id[3],char_type[3],char_hp[3],char_atk[3],char_def[3],(char_hp[3] * 1.0 + char_atk[3] * 0.8 + char_def[3] * 0.5 - 50.0) * 6.5 );
        }
        return;
}
int SelectAndBattle(int have)
{
        if(have==1){//戰鬥判斷須將角色4加入判斷
                    printf("\n選擇先攻角色:");
                    while(scanf("%d",&Fa) && (Fa>4 || Fa<1)){//錯就一直選到對為止
                        printf("錯誤:無此角色");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&Fa);
                    break;
                    }
                    printf("選擇後攻角色:");
                    while(scanf("%d",&La) && (La>4||La<1)){
                        printf("錯誤:無此角色\n");
                        printf("選擇後攻角色:");
                        scanf(" %d",&La);
                    break;
                    }
                    while(Fa==La){ //不能自己跟自己打 因此錯誤
                        printf("錯誤:不可重複選取");
                        scanf("%d",&Fa);
                        scanf("%d",&La);

                    }
                    printf("\n先攻為角色%d、後攻為角色%d\n\n",Fa,La);
                    battle(Fa,La);
        }


        else if(have==0){//同上have=1要做的事情 只是沒有角色4
                    printf("\n選擇先攻角色:");
                    while(scanf("%d",&Fa) && (Fa>3 || Fa<1)){//錯就一直選到對為止
                        printf("錯誤:無此角色");
                        printf("\n選擇先攻角色:");
                        scanf("%d",&Fa);
                    break;
                    }
                    printf("選擇後攻角色:");
                    while(scanf("%d",&La) && (La>3||La<1)){
                        printf("錯誤:無此角色\n");
                        printf("選擇後攻角色:");
                        scanf(" %d",&La);
                    break;
                    }
                    while(Fa==La){ //不能自己跟自己打 因此錯誤
                        printf("錯誤:不可重複選取");
                        scanf("%d",&Fa);
                        scanf("%d",&La);

                    }
                    printf("\n先攻為角色%d、後攻為角色%d\n\n",Fa,La);
                    battle(Fa,La);
        }
}
int battle(int Fa,int La)
{
    int faatk,fadef,fahp,laatk,ladef,lahp;
    printf("戰鬥開始\n\n");
                    if(Fa==1){//判斷是誰要打架並且給予角色能力(先攻)
                        faatk=18;
                        fadef=9;
                        fahp=42;
                    }
                    if(Fa==2){
                        faatk=15;
                        fadef=6;
                        fahp=47;
                    }
                    if(Fa==3){
                        faatk=19;
                        fadef=5;
                        fahp=46;
                    }
                    if(Fa==4){
                        faatk=char_atk[3];
                        fadef=char_def[3];
                        fahp=char_hp[3];
                    }
                    if(La==1){//判斷是誰要打架並且給予角色能力(後攻)
                        laatk=18;
                        ladef=9;
                        lahp=42;
                    }
                    if(La==2){
                        laatk=15;
                        ladef=6;
                        lahp=47;
                    }
                    if(La==3){
                        laatk=19;
                        ladef=5;
                        lahp=46;
                    }
                    if(La==4){
                        laatk=char_atk[3];
                        ladef=char_def[3];
                        lahp=char_hp[3];
                    }
                    int fahp2,lahp2,fadmg,ladmg;
                    fahp2=fahp/2; //fahp2為先攻血量的一半
                    lahp2=lahp/2; //lahp2為後攻血量的一半
                    while(fahp>=0 && lahp>=0){//開始打架
                    if(Fa=='W'&&La=='F'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='F'&&La=='A'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='A'&&La=='G'){
                        fadmg=faatk*1.2;
                    }
                    else if(Fa=='G'&&La=='W'){
                        fadmg=faatk*1.2;
                    }
                    if(Fa=='F'&&La=='W'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='A'&&La=='F'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='G'&&La=='A'){
                        fadmg=faatk*0.8;
                    }
                    else if(Fa=='W'&&La=='G'){
                        fadmg=faatk*0.8;
                    }
                    else{
                        fadmg=faatk;
                    }
                     if(La=='W'&&Fa=='F'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='F'&&Fa=='A'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='A'&&Fa=='G'){
                        ladmg=laatk*1.2;
                    }
                    else if(La=='G'&&Fa=='W'){
                        ladmg=laatk*1.2;
                    }
                    if(La=='F'&&Fa=='W'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='A'&&Fa=='F'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='G'&&Fa=='A'){
                        ladmg=laatk*0.8;
                    }
                    else if(La=='W'&&Fa=='G'){
                        ladmg=laatk*0.8;
                    }
                    else{
                        ladmg=faatk;
                    }
                    if(fahp<fahp2){
                        fadmg=fadmg*1.2;
                    }
                    else{
                        fadmg=fadmg;
                    }
                    if(lahp<lahp2){
                        ladmg=ladmg*1.2;
                    }
                    else{
                        ladmg=ladmg;
                    }
                    fadmg=fadmg-ladef;
                    ladmg=ladmg-fadef;


                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",Fa,La,fadmg,Fa,fahp,La,lahp-fadmg);
                    lahp=lahp-fadmg; //剩餘血量=原來血量-攻擊力
                    if(fahp<=0||lahp<=0){//打架形成的條件 如果一方血量小於0就結束戰鬥
                        break;
                    }
                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",La,Fa,ladmg,Fa,fahp-ladmg,La,lahp);
                    fahp=fahp-ladmg;
                }
                if(fahp>lahp){//獲勝的條件,判斷是誰獲得勝利
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",La,Fa);
                }
                if(lahp>fahp){
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",Fa,La);
                }
                return;
}


int main()
{

    int have=0;
    int Fa,La;
    int faid,faatk,fadef,fahp,laid,laatk,ladef,lahp;

    while(1){  //while大迴圈，並在每次迴圈開始時讓使用者選取選項
        printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n"
               "請選擇:");
        scanf("%d",&suit);
        while(suit!=1 && suit!=2 && suit!=3 &&suit!=0){ //suut不能等於1234以外的數否則輸入錯誤
            printf("輸入錯誤!\n");
            printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n"
               "請選擇:");
            scanf("%d",&suit);
        }
        switch(suit){
            case 0://suit=0要做的事
                printf("結束遊戲\n");
                return 0;
            case 1://suit=1要做的事
                EditNewChar(have);
                have=1;
                break;
            case 2://suit=2要做的事
                PrintCharData(have);
                break;
            case 3://suit=3時要做的事
                SelectAndBattle(have);
            }
    }
}


