#include <stdio.h>
#include <stdlib.h>

void EditNewChar(char char_name[][21],char type[],int hp[],int atk[],int def[]){
    int repeat_value;//迴圈判斷
    while(1){
        repeat_value=0;
        printf("\n新增角色(屬性總和=65~70)\n名稱:");
        scanf("%s%*c",&char_name[3]);
        printf("屬性(F/W/G/A):");
        scanf("%c",&type[3]);
        //如果是小寫，則轉換成大寫
        if((type[3]=='f')||(type[3]=='w')||(type[3]=='g')||(type[3]=='a'))
            type[3]=type[3]-32;
        printf("輸入血量(40~50):");
        scanf("%d",&hp[3]);
        printf("輸入攻擊(15~20):");
        scanf("%d",&atk[3]);
        printf("輸入防禦(5~10):");
        scanf("%d",&def[3]);
        //如果屬性不等於FWGA，則repeat_value=1，繼續重複輸入角色資料
        if((type[3]!='F')&&(type[3]!='W')&&(type[3]!='G')&&(type[3]!='A')){
            printf("錯誤:無此屬性\n");
            repeat_value=1;
        }
        //判斷能力數值是否在限制範圍內，如果為否，則repeat_value=1，繼續重複輸入角色資料
        if(!(atk[3]>=15&&atk[3]<=20)||!(hp[3]>=40&&hp[3]<=50)||!(def[3]>=5&&def[3]<=10)||
           !(atk[3]+hp[3]+def[3]>=65&&atk[3]+hp[3]+def[3]<=70)){
            printf("錯誤:能力數值在限制範圍之外\n");
            repeat_value=1;
        }
        //如果前兩項if條件都為假，則印出自訂角色
        if(repeat_value==0){
            printf("\n角色4\n名稱:%s\n屬性\:%c     攻擊\:%d\n血量\:%d    防禦\:%d\n角色強度預測:%.2f\n\n"
                   ,char_name[3],type[3],atk[3],hp[3],def[3],(hp[3]*1.0+atk[3]*0.8+def[3]*0.5-50)*6.5);
            break;
        }
    }
}
void PrintCharData(char char_name[][21],char type[],int hp[],int atk[],int def[]){
    int temp;
    if(hp[3]!=0)//如果角色4存在，則temp=4，下面的for會印出4個角色
        temp=4;
    else
        temp=3;//如果角色4不存在，則temp=3，下面的for會印出3個角色
        for(int n1=0;n1<temp;n1++){
            printf("\n角色%d\n名稱:%s\n屬性\:%c     攻擊\:%d\n血量\:%d    防禦\:%d\n角色強度預測:%.2f\n\n"
                   ,n1+1,char_name[n1],type[n1],atk[n1],hp[n1],def[n1],(hp[n1]*1.0+atk[n1]*0.8+def[n1]*0.5-50)*6.5);
        }
}
void SelectAndBattle(char type[],int hp[],int atk[],int def[],int sel_char[]){
    int temp;
    int s1,s2;//戰鬥時，攻擊方=sel_char[s1]，防守方=sel_char[s2]
    char Phases[4][4]={"WFA","GWF","AGW","FAG"};//相剋表，第一列"WFA"代表:F被W剋，F剋A
    printf("\n");
    do{
        temp=0;//如果之後先攻角色輸入正確，則temp依然為0，然後跳出迴圈
        printf("選擇先攻角色:");
        scanf("%d",&sel_char[0]);
        if(sel_char[0]<1||(sel_char[0]>3&&hp[3]==0)||(sel_char[0]>4&&hp[3]!=0)){
            printf("錯誤:無此角色\n");
            temp=1;
        }
    }while(temp==1);
    while(1){
        printf("選擇後攻角色:");
        scanf("%d",&sel_char[1]);
        if(sel_char[1]<1||(sel_char[1]>3&&hp[3]==0)||(sel_char[1]>4&&hp[3]!=0))
            printf("錯誤:無此角色\n");
        //因為先攻角色必存在，所以"無此角色"不可能與"不可重複選取"同時發生，因此這兩個條件不用各別用if判斷
        else if(sel_char[1]==sel_char[0])
            printf("錯誤:不可重複選取\n");
        else{
            printf("\n先攻角色為%d、後攻角色為%d\n戰鬥開始\n\n",sel_char[0],sel_char[1]);
            break;//輸入正確，跳出迴圈
        }
    }
    /*sel_data[2][6]:先攻資料(第一列):hp、atk、def、相剋倍率、殘血倍率、下個回合傷害
                     後攻資料(第二列):hp、atk、def、相剋倍率、殘血倍率、下個回合傷害*/
    double sel_data[2][6]={{hp[sel_char[0]-1],atk[sel_char[0]-1],def[sel_char[0]-1],1,1,0},
                           {hp[sel_char[1]-1],atk[sel_char[1]-1],def[sel_char[1]-1],1,1,0}};

    //檢查有無相剋，先從Phases陣列(相剋表)的第二行找到先攻的屬性，找到後檢查這一列的第一項和第三項屬性是否為後攻的屬性
    for(int n1=0;n1<4;n1++){
        if(type[sel_char[0]-1]==Phases[n1][1]){//找先攻的屬性
            //如果這列的第三項屬性=後攻屬性，則代表先攻剋後攻，先攻相剋倍率=1.2，後攻相剋倍率=0.8
            if(Phases[n1][2]==type[sel_char[1]-1]){
                sel_data[0][3]=1.2;
                sel_data[1][3]=0.8;
                break;
            }
            //如果這列的第一項屬性=後攻屬性，則代表後攻剋先攻
            else if(Phases[n1][0]==type[sel_char[1]-1]){
                sel_data[0][3]=0.8;
                sel_data[1][3]=1.2;
                break;
            }
        }
    }
    Battling(sel_char,sel_data,hp);//呼叫戰鬥函式
}
void Battling(int sel_char[],double sel_data[2][6],int hp[]){
    int temp,s1,s2;
    //戰鬥時，攻擊方=sel_char[s1]，防守方=sel_char[s2]
    s1=0;
    s2=1;
    while(sel_data[0][0]>0&&sel_data[1][0]>0){//判斷雙方血量，來決定是否繼續迴圈
        //設定自己的攻擊=(int)(自己的攻擊力 * 相剋倍率 * 殘血倍率 - 被攻擊方防禦力)
        sel_data[0][5]=(int)(sel_data[0][1]*sel_data[0][3]*sel_data[0][4]-sel_data[1][2]);//設定先攻攻擊
        sel_data[1][5]=(int)(sel_data[1][1]*sel_data[1][3]*sel_data[1][4]-sel_data[0][2]);//設定後攻攻擊
        //攻擊方"sel_char[s1]"攻擊
        sel_data[s2][0]=sel_data[s2][0]-sel_data[s1][5];//防守方hp=防守方hp-攻擊方atk
        printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n角色%d HP: %d 角色%d HP: %d\n\n"
               ,sel_char[s1],sel_char[s2],(int)sel_data[s1][5],sel_char[0],(int)sel_data[0][0],sel_char[1],(int)sel_data[1][0]);
        //殘血倍率檢查
        if(hp[sel_char[0]-1]>2*sel_data[0][0])//先攻血量小於原本的50%時殘血倍率為1.2倍
            sel_data[0][4]=1.2;
        if(hp[sel_char[1]-1]>2*sel_data[1][0])//後攻血量小於原本的50%
            sel_data[1][4]=1.2;
        //攻守交換
        temp=s1;
        s1=s2;
        s2=temp;
    }
    //判斷輸贏家
    if(sel_data[0][0]<=0)//檢查先攻血量
        printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n",sel_char[0],sel_char[1]);
    else
        printf("角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n\n",sel_char[1],sel_char[0]);
}
int main(){
    int user_in,sel_char[2];//由左至右為:case選擇之輸入、先後攻角色
    char char_name[4][21]={"SKY","SUN","DUST"};//角色名稱
    char type[4]="WWA";//角色屬性
    int hp[4]={50,45,40};
    int atk[4]={15,20,20};
    int def[4]={5,5,10};

    while(1){
        printf("1. 新增或修改新增角色\n"
               "2. 顯示所有角色資料\n"
               "3. 戰鬥\n"
               "0. 結束遊戲\n"
               "請選擇:");
        scanf("%d",&user_in);
        if(user_in==0){//case0:結束
            printf("\n結束遊戲\n");
            break;
        }
        else if(user_in==1){//case1:新增角色
            EditNewChar(char_name,type,hp,atk,def);
        }
        else if(user_in==2){//case2:列出角色資料
            PrintCharData(char_name,type,hp,atk,def);
        }
        else if(user_in==3){//case3:戰鬥
            SelectAndBattle(type,hp,atk,def,sel_char);
        }
        else//case選擇輸入錯誤，重複輸入case選擇之輸入
            printf("\n輸入錯誤!\n\n");
    }
}




