#include<stdio.h>//標頭檔
#include<stdlib.h>//標頭檔
int main()//主函式
{
    char charl_type ='F',char2_type ='W',char3_type ='G',char4_type;
    int char1_hp = 42, char1_atk = 19,char1_def = 5;
    int char2_hp = 48,char2_atk = 16,char2_def = 5;
    int char3_hp = 45,char3_atk = 16, char3_def = 7;
    int char4_atk, char4_hp, char4_def;
    int input,input2,input3;
    char F,G,W,A,f,g,w,a;
    printf("角色1\n"//印出角色1
           "名稱:死亡之翼\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n",charl_type,char1_atk,char1_hp,char1_def);
    printf("角色強度預測:%.2f\n\n",(char1_atk*0.8+char1_hp*1.0+char1_def*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    printf("角色2\n"//印出角色2
           "名稱:我阿嬤\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n"
           ,char2_type,char2_atk,char2_hp,char2_def);
    printf("角色強度預測:%.2f\n\n",(char2_atk*0.8+char2_hp*1.0+char2_def*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
            "\n";
    printf("角色3\n"//印出角色3
           "名稱:阿公\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n"
           ,char3_type,char3_atk,char3_hp,char3_def);
    printf("角色強度預測:%.2f\n\n",(char3_atk*0.8+char3_hp*1.0+char3_def*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    do {
        printf("是否新增角色(1.Yes/2.No)");//印出是否新增角色
        scanf("%d",&input);
        printf("\n");
        if(input>2)//if輸入值大於2
        printf("輸入錯誤");//印出
    }while(input==1);
    //if輸入值等於1
    printf("新增角色\n");//印出新增角色
    printf("屬性:",char4_type);//印出屬性
    scanf(" %c",&char4_type);
    printf("攻擊:",char4_atk);//印出攻擊
    scanf("%d",&char4_atk);
    printf("血量:",char4_hp);//印出血量
    scanf("%d",&char4_hp);
    printf("防禦:",char4_def);//印出防禦
    scanf("%d",&char4_def);
    printf("\n");
    if((char4_atk+char4_hp+char4_def<50)||(char4_atk+char4_hp+char4_def>70)||(char4_atk>20)||(char4_atk<15)||(char4_hp>50)||(char4_hp<40)||(char4_def<5)||(char4_def>10))
        printf("錯誤:能力數值在限制範圍之外\n");//if
    if(char4_type!='F'&&char4_type!='G'&&char4_type!='A'&&char4_type!='W'&&char4_type!='f'&&char4_type!='a'&&char4_type!='w'&&char4_type!='g'){
        printf("錯誤:無此屬性");//if char4_type不等於
        return 0;}//回傳，結束函式
    if(char4_type=='f')//if char4_type等於f,轉為大寫
       char4_type='F';
    if(char4_type=='a')//if char4_type等於a,轉為大寫
       char4_type='A';
    if(char4_type=='g')//if char4_type等於g,轉為大寫
       char4_type='G';
    if(char4_type=='w')//if char4_type等於w,轉為大寫
       char4_type='W';
    printf("角色4\n"//印出角色4
           "名稱:自訂角色\n"
           "屬性:%c\t攻擊:%d\n"
           "血量:%d\t防禦:%d\n\n",char4_type,char4_atk,char4_hp,char4_def);
    printf("角色強度預測:%.2f\n\n",(char4_atk*0.8+char4_hp*1.0+char4_def*0.5-50)*6.5);//強度預測 =( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
    printf("選擇先攻角色:");//印出選擇先攻角色
    scanf(" %d",&input2);
    if((input2>4)||(input2<1)){//if input2不介於1到4之間
        printf("錯誤:無此角色\n");//印出錯誤
        return 0;}
        printf("選擇後攻角色:");//印出選擇角色
        scanf(" %d",&input3);
        printf("\n");
    if((input3>4)||(input3<1)){//if input3不介於1到4之間
        printf("錯誤:無此角色\n");//印出錯誤
        return 0;}//回傳，結束函式
    if(input2==input3){//if input2 等於input3
        printf("錯誤:不可重複選取\n");//印出錯誤:不可重複選取
        return 0;}//回傳，結束函式
    else printf("先攻為角色%d、後攻為角色%d",input2,input3);//印出先後攻角色

         if(input==2){
            printf("選擇先攻角色:");//印出選擇後攻角色
            scanf(" %d",&input2);
        if((input2>3)||(input2<1)){//if input2不介於1到4之間
            printf("錯誤:無此角色\n");//印出錯誤
            return 0;}//回傳，結束函式
            printf("選擇後攻角色:");//印出選擇後攻角色
            scanf(" %d",&input3);
            printf("\n");
        if((input3>3)||(input3<1)){//if input3不介於1到4之間
            printf("錯誤:無此角色\n");//印出錯誤
            return 0;}//回傳，結束函式
        if(input2==input3){//if input2 等於input3
            printf("錯誤:不可重複選取\n");//印出錯誤:不可重複選取
            return 0;}//回傳，結束函式
            printf("先攻為角色%d、後攻為角色%d\n",input2,input3);}//印出先後攻角色
            printf("戰鬥開始\n");

        return 0;//回傳，結束函式
}
