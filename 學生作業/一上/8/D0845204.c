
#include<stdio.h>
#include <ctype.h>
int main() {
    int  suit,have=0;     //變數have用來定義是否已經新增角色4
    char char4_id[10];    //角色素質用矩陣儲存
    char char4_type[1];
    int  char4_hp[1];
    int  char4_atk[1];
    int  char4_def[1];

    char char1_type[1]="F";
    int  char1_hp[1]= {42};
    int  char1_atk[1]= {18};
    int  char1_def[1]= {9};

    char char2_type[1]="W";
    int  char2_hp[1]= {47};
    int  char2_atk[1]= {15};
    int  char2_def[1]= {6};

    char char3_type[1]="G";
    int  char3_hp[1]= {46};
    int  char3_atk[1]= {19};
    int  char3_def[1]= {5};

    int Fa[1],La[1];
    int faid[1],faatk[1],fadef[1],fahp[1],laid[1],laatk[1],ladef[1],lahp[1];

    while(1) {    //while大迴圈，並在每次迴圈開始時讓使用者選取選項
        printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n"
               "請選擇:");
        scanf("%d",&suit);
        while(suit!=1 && suit!=2 && suit!=3 &&suit!=0) { //suut不能等於1234以外的數否則輸入錯誤
            printf("輸入錯誤!\n");
            printf("1. 新增或修改新增角色\n"
                   "2. 顯示所有角色資料\n"
                   "3. 戰鬥\n"
                   "0. 結束遊戲\n"
                   "請選擇:");
            scanf("%d",&suit);
        }
        switch(suit) {
        case 0://suit=0要做的事
            printf("結束遊戲\n");
            return 0;
        case 1://suit=1要做的事
            if(have==0) { //還沒建立角色4時 case1需做的事:新增角色
                printf("\n新增角色\n");
                getchar();//吃換行
                printf("名稱:");
                gets(char4_id);
                printf("屬性:");
                gets(char4_type);
                printf("血量:");
                scanf ("%d",&char4_hp[0]);
                printf("攻擊:");
                scanf ("%d",&char4_atk[0]);
                printf("防禦:");
                scanf ("%d",&char4_def[0]);
                while(char4_type[0]!='F'&&char4_type[0]!='W'&&char4_type[0]!='G'&&char4_type[0]!='A') {
                    printf("錯誤:無此屬性\n");//判斷屬性有沒有錯誤
                    if(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70)
                        printf("錯誤:能力值在限制範圍之外\n");//屬性錯時判斷是否能力值在範圍之外
                    printf("\n新增角色4\n");
                    printf("名稱:");
                    scanf (" %s",char4_id[10]);
                    printf("屬性:");
                    scanf (" %c",char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("血量:");
                    scanf ("%d",&char4_hp[0]);
                    printf("攻擊:");
                    scanf ("%d",&char4_atk[0]);
                    printf("防禦:");
                    scanf ("%d",&char4_def[0]);
                }
                while(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70) {
                    printf("錯誤:能力值在限制範圍之外\n");//屬性對時判斷是否能力值在範圍之外
                    printf("\n新增角色4\n");
                    printf("名稱:");
                    scanf (" %s",char4_id[10]);
                    printf("屬性:");
                    scanf (" %c",&char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("血量:");
                    scanf ("%d",&char4_hp[0]);
                    printf("攻擊:");
                    scanf ("%d",&char4_atk[0]);
                    printf("防禦:");
                    scanf ("%d",&char4_def[0]);

                }
                printf("\n角色4\n名稱:%-6s\n"
                       "屬性:%-6c   血量:%-6d\n"
                       "攻擊:%-6d   防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            have=1;
            if(have==1) { //已經新增角色4之後case1需要做的事:修改新增角色
                printf("\n修改新增角色\n");
                printf("名稱:");
                scanf("% s", char4_id[10]);
                printf("血量:");
                scanf ("%d",&char4_hp[0]);
                printf("攻擊:");
                scanf ("%d",&char4_atk[0]);
                printf("防禦:");
                scanf ("%d",&char4_def[0]);
                while(char4_type[0]!='F'&&char4_type[0]!='W'&&char4_type[0]!='G'&&char4_type[0]!='A') {
                    printf("錯誤:無此屬性\n");
                    if(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70)
                        printf("錯誤:能力值在限制範圍之外\n");//屬性錯時判斷是否能力值在範圍之外
                    printf("\n新增角色4\n");
                    printf("名稱:");
                    scanf (" %s",char4_id[10]);
                    printf("屬性:");
                    scanf (" %c",char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("血量:");
                    scanf ("%d",&char4_hp[0]);
                    printf("攻擊:");
                    scanf ("%d",&char4_atk[0]);
                    printf("防禦:");
                    scanf ("%d",&char4_def[0]);


                }
                while(char4_hp[0]<40|char4_hp[0]>50|char4_atk[0]<15|char4_atk[0]>20|char4_def[0]<5|char4_def[0]>10|(char4_hp[0]+char4_atk[0]+char4_def[0])<65|(char4_hp[0]+char4_atk[0]+char4_def[0])>70) {
                    printf("錯誤:能力值在限制範圍之外\n");//屬性對時判斷是否能力值在範圍之外
                    printf("\n新增角色4\n");
                    printf("名稱:");
                    scanf (" %s",char4_id[10]);
                    printf("屬性:");
                    scanf (" %c",&char4_type[0]);
                    if(isupper(char4_type[0])==0);
                    char4_type[0]=toupper(char4_type[0]);
                    printf("血量:");
                    scanf ("%d",&char4_hp[0]);
                    printf("攻擊:");
                    scanf ("%d",&char4_atk[0]);
                    printf("防禦:");
                    scanf ("%d",&char4_def[0]);

                }
                printf("\n角色4\n名稱:%-6s\n"
                       "屬性:%-6c   血量:%-6d\n"
                       "攻擊:%-6d   防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            break;
        case 2://suit=2要做的事
            if(have==0) { //還沒新增角色4時印出已經有的3個角色素質
                printf("角色1\n"
                       "名稱:所羅門\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char1_type[0],char1_hp[0],char1_atk[0],char1_def[0],(char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50.0) * 6.5 );
                printf("角色2\n"
                       "名稱:瑪娜\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char2_type[0],char2_hp[0],char2_atk[0],char2_def[0],(char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50.0) * 6.5 );
                printf("角色3\n"
                       "名稱:摩西\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char1_type[0],char3_hp[0],char3_atk[0],char3_def[0],(char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50.0) * 6.5 );
            }
            if(have==1) { //有角色4時 印出4個角色
                printf("角色1\n"
                       "名稱:所羅門\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char1_type[0],char1_hp[0],char1_atk[0],char1_def[0],(char1_hp[0] * 1.0 + char1_atk[0] * 0.8 + char1_def[0] * 0.5 - 50.0) * 6.5 );
                printf("角色2\n"
                       "名稱:瑪娜\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char2_type[0],char2_hp[0],char2_atk[0],char2_def[0],(char2_hp[0] * 1.0 + char2_atk[0] * 0.8 + char2_def[0] * 0.5 - 50.0) * 6.5 );
                printf("角色3\n"
                       "名稱:摩西\n"
                       "屬性:%-6c    血量:%-6d\n"
                       "攻擊:%-6d    防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char1_type[0],char3_hp[0],char3_atk[0],char3_def[0],(char3_hp[0] * 1.0 + char3_atk[0] * 0.8 + char3_def[0] * 0.5 - 50.0) * 6.5 );
                printf("\n角色4\n名稱:%-6s\n"
                       "屬性:%-6c   血量:%-6d\n"
                       "攻擊:%-6d   防禦:%-6d\n"
                       "角色強度預測:%.2f\n\n",char4_id[10],char4_type[0],char4_hp[0],char4_atk[0],char4_def[0],(char4_hp[0] * 1.0 + char4_atk[0] * 0.8 + char4_def[0] * 0.5 - 50.0) * 6.5 );
            }
            break;
        case 3://suit=3時要做的事
            if(have==1) { //戰鬥判斷須將角色4加入判斷
                printf("\n選擇先攻角色:");
                while(scanf("%d",&Fa[0]) && (Fa[0]>4 || Fa[0]<1)) { //錯就一直選到對為止
                    printf("錯誤:無此角色");
                    printf("\n選擇先攻角色:");
                    scanf("%d",&Fa[0]);
                    break;
                }
                printf("選擇後攻角色:");
                while(scanf("%d",&La[0]) && (La[0]>4||La[0]<1)) {
                    printf("錯誤:無此角色\n");
                    printf("選擇後攻角色:");
                    scanf(" %d",&La[0]);
                    break;
                }
                while(Fa[0]==La[0]) { //不能自己跟自己打 因此錯誤
                    printf("錯誤:不可重複選取");
                    scanf("%d",&Fa[0]);
                    scanf("%d",&La[0]);

                }
                printf("\n先攻為角色%d、後攻為角色%d\n\n",Fa[0],La[0]);

                printf("戰鬥開始\n\n");
                if(Fa[0]==1) { //判斷是誰要打架並且給予角色能力(先攻)
                    faatk[0]=18;
                    fadef[0]=9;
                    fahp[0]=42;
                }
                if(Fa[0]==2) {
                    faatk[0]=15;
                    fadef[0]=6;
                    fahp[0]=47;
                }
                if(Fa[0]==3) {
                    faatk[0]=19;
                    fadef[0]=5;
                    fahp[0]=46;
                }
                if(Fa[0]==4) {
                    faatk[0]=char4_atk[0];
                    fadef[0]=char4_def[0];
                    fahp[0]=char4_hp[0];
                }
                if(La[0]==1) { //判斷是誰要打架並且給予角色能力(後攻)
                    laatk[0]=18;
                    ladef[0]=9;
                    lahp[0]=42;
                }
                if(La[0]==2) {
                    laatk[0]=15;
                    ladef[0]=6;
                    lahp[0]=47;
                }
                if(La[0]==3) {
                    laatk[0]=19;
                    ladef[0]=5;
                    lahp[0]=46;
                }
                if(La[0]==4) {
                    laatk[0]=char4_atk[0];
                    ladef[0]=char4_def[0];
                    lahp[0]=char4_hp[0];
                }
                int fahp2[1],lahp2[1],fadmg[1],ladmg[1];
                fahp2[0]=fahp[0]/2; //fahp2為先攻血量的一半
                lahp2[0]=lahp[0]/2; //lahp2為後攻血量的一半

                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]<fahp2[0]) { //因為W克制F和W殘血所以 W的攻擊力*1.2*1.2
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]>=fahp2[0]) { //因為W克制F所以W的攻擊力*1.2
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]<lahp2[0]) { //因為F被W克制和F殘血所以 F的攻擊力*0.8*1.2
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]>=lahp2[0]) { //因為F被W克制所以F的攻擊力*0.8
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]<fahp2[0]) { //以下的情形都和上面的一樣
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }



                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }


                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }


                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }


                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                while(fahp[0]>=0 && lahp[0]>=0) { //開始打架
                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",Fa[0],La[0],fadmg[0],Fa[0],fahp[0],La[0],lahp[0]-fadmg[0]);
                    lahp[0]=lahp[0]-fadmg[0]; //剩餘血量=原來血量-攻擊力
                    if(fahp[0]<=0||lahp[0]<=0) { //打架形成的條件 如果一方血量小於0就結束戰鬥
                        break;
                    }
                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",La[0],Fa[0],ladmg[0],Fa[0],fahp[0],La[0],fahp[0]-ladmg[0]);
                    fahp[0]=fahp[0]-ladmg[0];
                }
                if(fahp[0]>lahp[0]) { //獲勝的條件,判斷是誰獲得勝利
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",La[0],Fa[0]);
                }
                if(lahp[0]>fahp[0]) {
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",Fa[0],La[0]);
                }
            }
            if(have==0) { //同上have=1要做的事情 只是沒有角色4
                printf("\n選擇先攻角色:");
                while(scanf("%d",&Fa[0]) && (Fa[0]>3 || Fa[0]<1)) { //錯就一直選到對為止
                    printf("錯誤:無此角色");
                    printf("\n選擇先攻角色:");
                    scanf("%d",&Fa[0]);
                    break;
                }
                while(scanf("%d",&La[0]) && (La[0]>3||La[0]<1)) {
                    printf("選擇後攻角色:");
                    printf("錯誤:無此角色\n");
                    printf("選擇後攻角色:");
                    scanf(" %d",&La[0]);
                    break;
                }
                while(Fa[0]==La[0]) {
                    printf("錯誤:不可重複選取");
                    scanf("%d",&Fa[0]);
                    scanf("%d",&La[0]);

                }
                printf("\n先攻為角色%d、後攻為角色%d\n\n",Fa[0],La[0]);

                printf("戰鬥開始\n\n");
                if(Fa[0]==1) { //判斷是誰要打架並且給予角色能力(先攻)
                    faatk[0]=18;
                    fadef[0]=9;
                    fahp[0]=42;
                }
                if(Fa[0]==2) {
                    faatk[0]=15;
                    fadef[0]=6;
                    fahp[0]=47;
                }
                if(Fa[0]==3) {
                    faatk[0]=19;
                    fadef[0]=5;
                    fahp[0]=46;
                }
                if(La[0]==1) { //判斷是誰要打架並且給予角色能力(後攻)
                    laatk[0]=18;
                    ladef[0]=9;
                    lahp[0]=42;
                }
                if(La[0]==2) {
                    laatk[0]=15;
                    ladef[0]=6;
                    lahp[0]=47;
                }
                if(La[0]==3) {
                    laatk[0]=19;
                    ladef[0]=5;
                    lahp[0]=46;
                }
                int fahp2[1],lahp2[1],fadmg[1],ladmg[1];
                fahp2[0]=fahp[0]/2;
                lahp2[0]=lahp[0]/2;

                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }



                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='W'&&La[0]=='W'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }

                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }


                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='F'&&La[0]=='F'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }

                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*0.8-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]*0.8-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }


                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='A'&&La[0]=='A'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }


                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]<fahp2[0]) {
                    fadmg[0]=faatk[0]*1.2-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&fahp[0]>=fahp2[0]) {
                    fadmg[0]=faatk[0]-ladef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]<lahp2[0]) {
                    ladmg[0]=laatk[0]*1.2-fadef[0];
                }
                if(Fa[0]=='G'&&La[0]=='G'&&lahp[0]>=lahp2[0]) {
                    ladmg[0]=laatk[0]-fadef[0];
                }
                while(fahp[0]>=0 && lahp[0]>=0) { //開始打架
                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",Fa[0],La[0],fadmg[0],Fa[0],fahp[0],La[0],lahp[0]-fadmg[0]);
                    lahp[0]=lahp[0]-fadmg[0];
                    if(fahp[0]<=0||lahp[0]<=0) { //打架形成的條件
                        break;
                    }
                    printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n角色%d HP:%d 角色%d HP:%d\n\n",La[0],Fa[0],ladmg[0],Fa[0],fahp[0],La[0],fahp[0]-ladmg[0]);
                    fahp[0]=fahp[0]-ladmg[0];
                }
                if(fahp[0]>lahp[0]) { //獲勝的條件
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",La[0],Fa[0]);
                }
                if(lahp[0]>fahp[0]) {
                    printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d獲勝\n",Fa[0],La[0]);
                }
            }
            break;

        }
    }
}




