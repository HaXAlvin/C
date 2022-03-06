#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    //角色1
    char char1_type='F';//角色1屬性
    int char1_hp=43;//角色1血量
    int char1_atk=18;//角色1攻擊
    int char1_def=7;//角色1防禦
    float char1_pow=( char1_hp * 1.0 +  char1_atk  * 0.8 + char1_def * 0.5 - 50 ) * 6.5;//角色1預測強度
    printf("角色1\n名稱:花花\n");
    printf("屬性:%-6c",char1_type);
    printf("血量:%d\n",char1_hp);
    printf("攻擊:%-6d",char1_atk);
    printf("防禦:%d\n",char1_def);
    printf("角色預測強度:%.2f\n\n",char1_pow);

    //角色2
    char char2_type='W';//角色2屬性
    int char2_hp=43;//角色2血量
    int char2_atk=16;//角色2攻擊
    int char2_def=9;//角色2防禦
    float char2_pow=( char2_hp * 1.0 +  char2_atk  * 0.8 + char2_def * 0.5 - 50 ) * 6.5;//角色2預測強度
    printf("角色2\n名稱:泡泡\n");
    printf("屬性:%-6c",char2_type);
    printf("血量:%d\n",char2_hp);
    printf("攻擊:%-6d",char2_atk);
    printf("防禦:%d\n",char2_def);
    printf("角色預測強度:%.2f\n\n",char2_pow);

    //角色3
    char char3_type='A';//角色3屬性
    int char3_hp=45;//角色3血量
    int char3_atk=19;//角色3攻擊
    int char3_def=5;//角色3防禦
    float char3_pow=( char3_hp * 1.0 +  char3_atk  * 0.8 + char3_def * 0.5 - 50 ) * 6.5;//角色3預測強度
    printf("角色3\n名稱:毛毛\n");
    printf("屬性:%-6c",char3_type);
    printf("血量:%d\n",char3_hp);
    printf("攻擊:%-6d",char3_atk);
    printf("防禦:%d\n",char3_def);
    printf("角色預測強度:%.2f\n\n",char3_pow);

    printf("是否新增角色?(1.Yes/2.No)");
    int y_or_n;
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    int char4_all=char4_hp+char4_atk+char4_def;

    float char4_pow;
    scanf("%d",&y_or_n);
    //1.Yes
    if(y_or_n==1){
        printf("\n新增角色\n屬性:");
        scanf("%s",&char4_type);
        printf("血量:");
        scanf("%d",&char4_hp);
        printf("攻擊:");
        scanf("%d",&char4_atk);
        printf("防禦:");
        scanf("%d",&char4_def);
    }
    //2.No
    else if(y_or_n==2)
        printf("\n");
    //非1非2
    else{
        printf("輸入錯誤\n");
        return 0;
    }
    char4_all=char4_hp+char4_atk+char4_def;
    //屬性正確 數值正確
    if(((char4_type=='F')||(char4_type=='W')||(char4_type=='G')||(char4_type=='A')||(char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a'))&&((40<=char4_hp<=50)&&(15<=char4_atk<=20)&&(5<=char4_def<=10)&&(65<=char4_all<=70))){
        printf("\n");
        printf("角色4\n名稱:尤教授\n");
        if(islower(char4_type))//如果為小寫
            printf("屬性:%-6c",toupper(char4_type));//轉為大寫
        else if(isupper(char4_type))//如果為大寫
            printf("屬性:%-6c",char4_type);//不變
        printf("血量:%d\n",char4_hp);
        printf("攻擊:%-6d",char4_atk);
        printf("防禦:%d\n",char4_def);
        printf("角色預測強度:%.2f\n",( char4_hp * 1.0 +  char4_atk  * 0.8 + char4_def * 0.5 - 50 ) * 6.5);
        printf("\n");
    }
    //屬性錯誤 數值正確
    else if(((char4_type!='F')||(char4_type!='W')||(char4_type!='G')||(char4_type!='A')||(char4_type!='f')||(char4_type!='w')||(char4_type!='g')||(char4_type!='a'))&&(char4_hp>=40 && char4_hp<=50 && char4_atk>=15 && char4_atk<=20 && char4_def<=10 && char4_def>=5 && char4_all<=70 && char4_all>=65)){
        printf("錯誤:無此屬性\n");
        return 0;
    }
    //屬性正確 數值錯誤
    else if((char4_type=='F')||(char4_type=='W')||(char4_type=='G')||(char4_type=='A')||(char4_type=='f')||(char4_type=='w')||(char4_type=='g')||(char4_type=='a')){
        printf("錯誤:能力數值在限定範圍外\n");
        return 0;
    }
    //屬性錯誤 數值錯誤
    else if((char4_type!='F')||(char4_type!='W')||(char4_type!='G')||(char4_type!='A')||(char4_type!='f')||(char4_type!='w')||(char4_type!='g')||(char4_type!='a')){
        printf("錯誤:無此屬性\n錯誤:能力數值在限定範圍外\n");
        return 0;
    }
    printf("選擇先攻角色:");
    int fir_atk;//先攻
    scanf("%d",&fir_atk);
    //如果為1 2 3 4
    if((fir_atk==1)||(fir_atk==2)||(fir_atk==3)||(fir_atk==4))
        printf("選擇後攻角色:");
    //非1 2 3 4
    else{
        printf("錯誤:無此角色\n");
        return 0;
    }
    int sec_atk;//後攻
    scanf("%d",&sec_atk);
    //如果先攻跟後攻重複
    if(fir_atk==sec_atk){
        printf("錯誤:不可重複選取\n");
        return 0;
    //如果後攻不為1 2 3 4
    }else if((sec_atk>4)||(sec_atk<=0)){
        printf("錯誤:無此角色\n");
        return 0;
    //如果均無以上問題
    }else
        printf("\n先攻角色為%d、後攻角色為%d",fir_atk,sec_atk);

    return 0;
}
