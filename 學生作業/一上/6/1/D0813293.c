#include<stdio.h>
#include<stdlib.h>

int main()
{   //char1=小熊維尼
    char char1_type ='W';
    int char1_atk = 15;
    int char1_hp = 50;
    int char1_def= 5;
    //角色強度預測
    float char1_predict= (char1_hp * 1 + char1_atk * 0.8 + char1_def * 0.5 - 50) * 6.5;
    //char2=跳跳虎
    char char2_type = 'F';
    int char2_atk = 18;
    int char2_hp = 47;
    int char2_def = 5;
    //角色強度預測
    float char2_predict= (char2_hp * 1 + char2_atk * 0.8 + char2_def * 0.5 - 50) * 6.5;
    //char3=粉紅豬
    char char3_type = 'A';
    int char3_atk = 15;
    int char3_hp = 45;
    int char3_def = 7;
    //角色強度預測
    float char3_predict= (char3_hp * 1 + char3_atk * 0.8 + char3_def * 0.5 - 50) * 6.5;
    //新增角色1=newchar1
    char newchar1_type;
    int newchar1_atk;
    int newchar1_hp;
    int newchar1_def;
    //新增角色強度預測
    float newcahr1_predict;

    //顯示角色資訊
    printf("角色1\n名稱:小熊維尼\n");
    printf("屬性:%c\t攻擊:%d\n",char1_type,char1_atk);
    printf("血量:%d\t防禦:%d\n",char1_hp,char1_def);
    printf("角色強度預測:%.2f\n\n",char1_predict);
    printf("角色2\n名稱:跳跳虎\n");
    printf("屬性:%c\t攻擊:%d\n",char2_type,char2_atk);
    printf("血量:%d\t防禦:%d\n",char2_hp,char2_def);
    printf("角色強度預測:%.2f\n\n",char2_predict);
    printf("角色3\n名稱:粉紅豬\n");
    printf("屬性:%c\t攻擊:%d\n",char3_type,char3_atk);
    printf("血量:%d\t防禦:%d\n",char3_hp,char3_def);
    printf("角色強度預測:%.2f\n\n",char3_predict);

    char chose;//選擇是否新增角色
    int addchar1=0;//先攻
    int addchar2=0;//後攻
    //新增暫存角色儲存對戰資料
    int addchar1_atk=0;
    int addchar1_hp=0;
    int addchar1_def=0;
    int addchar2_atk=0;
    int addchar2_hp=0;
    int addchar2_def=0;


    while((chose!=1)&&(chose!=2)){//重新輸入迴圈
        printf("\n是否新增角色(1.YES/2.NO)?");
        scanf(" %d",&chose);
        if((chose!=1)&&(chose!=2)){
            printf("輸入錯誤");
        }
    }
    if(chose == 1){//若選擇新增角色，則顯示新增輸入資訊
            while(1){
    printf("\n新增角色\n屬性:");
    scanf(" %c", &newchar1_type);
    printf("攻擊:");
    scanf("%d",&newchar1_atk);
    printf("血量:");
    scanf("%d", &newchar1_hp);
    printf("防禦:");
    scanf("%d",&newchar1_def);
    //轉換大小寫
    if (newchar1_type== 'f' ){
            newchar1_type= 'F';
    }else if(newchar1_type== 'w' ){
        newchar1_type= 'W';
    }else if(newchar1_type== 'g' ){
        newchar1_type= 'G';
    }else if(newchar1_type== 'a' ){
        newchar1_type= 'A';
    }else if(newchar1_type== 'F' ){
        newchar1_type= 'F';
    }else if(newchar1_type== 'W' ){
        newchar1_type= 'W';
    }else if(newchar1_type== 'G' ){
        newchar1_type= 'G';
    }else if(newchar1_type== 'A' ){
        newchar1_type= 'A';
    }else {
        printf("錯誤: 無此屬性\n");
    }
    //判斷角色數值
    if((newchar1_atk < 15)|(newchar1_atk > 20)){
        printf("錯誤 : 能力數值在範圍之外\n");
    }
    else if((newchar1_hp < 40)|(newchar1_hp > 50)){
        printf("錯誤 : 能力數值在範圍之外\n");
    }
    else if((newchar1_def < 5)|(newchar1_def > 10)){
        printf("錯誤 : 能力數值在範圍之外\n");
    }
    else if(((newchar1_hp + newchar1_atk + newchar1_def)< 65 )|((newchar1_hp + newchar1_atk + newchar1_def)> 70 )){
        printf("錯誤 : 能力數值在範圍之外\n");
    }
    else{
            break;
        }
    }
    //新增角色預測強度
    float newchar1_predict=(newchar1_hp * 1 + newchar1_atk * 0.8 + newchar1_def * 0.5 - 50) * 6.5;
    //新增角色資訊
    printf("\n角色4\n名稱:自訂角色\n屬性:%c\t攻擊:%d\n血量:%d\t防禦:%d\n角色強度預測:%.2f\n"
           ,newchar1_type,newchar1_atk,newchar1_hp,newchar1_def,newchar1_predict);

    //選擇攻擊順序
    while(1){//重新輸入迴圈
    printf("\n選擇先攻角色: ");
    scanf("%d",&addchar1);
    if((addchar1>4)|(addchar1<1)){
        printf("錯誤: 無此角色\n");
    }
    else{
        break;
    }
}
    while(1){//重新輸入迴圈
        printf("選擇後攻角色: ");
        scanf("%d",&addchar2);
        if((addchar2>4)|(addchar2<1)){
        printf("錯誤: 無此角色\n");
        }else if((addchar2<=4)&(addchar2>=1)){
        if(addchar2 == addchar1){
            printf("錯誤: 不可重複選取\n");
        }
        else{
            printf("\n先攻為角色%d、後攻為角色%d\n",addchar1,addchar2);
            printf("戰鬥開始\n");
            break;
           }
       }
   }
}
    if(chose == 2){
        //選擇角色攻擊順序
        while(1){//重新輸入迴圈
        printf("選擇先攻角色: ");
        scanf("%d",&addchar1);
    if((addchar1>3)|(addchar1<1)){
        printf("錯誤: 無此角色\n");
    }else{
        break;
    }
}
     while(1){//重新輸入迴圈
        printf("選擇後攻角色: ");
        scanf("%d",&addchar2);
        if((addchar2>3)|(addchar2<1)){
        printf("錯誤: 無此角色\n");
        }else if((addchar2<=3)&(addchar2>=1)){
        if(addchar2 == addchar1){
            printf("錯誤: 不可重複選取\n");
        }else{
            printf("\n先攻為角色%d、後攻為角色%d\n",addchar1,addchar2);
            printf("戰鬥開始\n");
            break;
        }
    }

}
    }     //設定暫存角色的角色資料
    if(addchar1==1){
        addchar1_atk=char1_atk,addchar1_hp=char1_hp,addchar1_def=char1_def;
    }if(addchar1==2){
        addchar1_atk=char2_atk,addchar1_hp=char2_hp,addchar1_def=char2_def;
    }if(addchar1==3){
        addchar1_atk=char3_atk,addchar1_hp=char3_hp,addchar1_def=char3_def;
    }if(addchar1==4){
        addchar1_atk=newchar1_atk,addchar1_hp=newchar1_hp,addchar1_def=newchar1_def;
    }if(addchar2==1){
        addchar2_atk=char1_atk,addchar2_hp=char1_hp,addchar2_def=char1_def;
    }if(addchar2==2){
        addchar2_atk=char2_atk,addchar2_hp=char2_hp,addchar2_def=char2_def;
    }if(addchar2==3){
        addchar2_atk=char3_atk,addchar2_hp=char3_hp,addchar2_def=char3_def;
    }if(addchar2==4){
        addchar2_atk=newchar1_atk,addchar2_hp=newchar1_hp,addchar2_def=newchar1_def;
    }
            //戰鬥迴圈
            while(1){
            printf("\n角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",addchar1,addchar2,(addchar1_atk-addchar2_def));
            addchar2_hp=addchar2_hp-(addchar1_atk-addchar2_def);
            printf("角色%d HP: %d 角色%d HP: %d\n\n",addchar1,addchar1_hp,addchar2,addchar2_hp);
            if(addchar2_hp<=0){
                printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n",addchar2,addchar1);
                break;
            }
            printf("角色%d 對 角色%d 發動攻擊，造成%d點傷害\n",addchar2,addchar1,(addchar2_atk-addchar1_def));
            addchar1_hp=addchar1_hp-(addchar2_atk-addchar1_def);
            printf("角色%d HP: %d 角色%d HP: %d\n",addchar1,addchar1_hp,addchar2,addchar2_hp);
            if(addchar1_hp<=0){
                printf("\n角色%d 失去戰鬥能力\n戰鬥結束\n\n角色%d 獲勝\n",addchar1,addchar2);
                break;
            }
        }
    return 0;
}

