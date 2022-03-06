#include <stdio.h>

int main(){
    char Char1_type='W',Char2_type='F',Char3_type='G',Char4_type;//屬性
    int Char1_atk=15,Char2_atk=20,Char3_atk=15,Char4_atk;//攻擊
    int Char1_hp=50,Char2_hp=40,Char3_hp=45,Char4_hp;//血量
    int Char1_def=5,Char2_def=5,Char3_def=10,Char4_def;//防禦
    printf("角色1 \n");
    printf("名稱:傑尼龜 \n");
    printf("屬性:%c    攻擊:%d  \n",Char1_type,Char1_atk);
    printf("血量:%d   防禦:%d  \n",Char1_hp,Char1_def);
    printf("強度預測:%.2f\n",( Char1_hp * 1.0 + Char1_atk * 0.8 + Char1_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("角色2 \n");
    printf("名稱:小火龍 \n");
    printf("屬性:%c    攻擊:%d  \n",Char2_type,Char2_atk);
    printf("血量:%d   防禦:%d  \n",Char2_hp,Char2_def);
    printf("強度預測:%.2f\n",( Char2_hp * 1.0 + Char2_atk * 0.8 + Char2_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("角色3 \n");
    printf("名稱:小拳石 \n");
    printf("屬性:%c    攻擊:%d  \n",Char2_type,Char2_atk);
    printf("血量:%d   防禦:%d  \n",Char2_hp,Char2_def);
    printf("強度預測:%.2f\n",( Char3_hp * 1.0 + Char3_atk * 0.8 + Char3_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    printf("新增角色 \n");
    printf("屬性:");
    scanf("%c",&Char4_type);
    printf("血量:");
    scanf("%d",&Char4_hp);
    printf("攻擊:");
    scanf("%d",&Char4_atk);
    printf("防禦:");
    scanf("%d",&Char4_def);
    printf ("\n");
    printf("角色4 \n");
    printf("名稱:自訂角色 \n");
    printf("屬性:%c    攻擊:%d  \n",Char4_type,Char4_atk);
    printf("血量:%d   防禦:%d  \n",Char4_hp,Char4_def);
    printf("強度預測:%.2f\n",( Char4_hp * 1.0 + Char4_atk * 0.8 + Char4_def * 0.5 - 50 ) * 6.5);
    printf ("\n");
    return 0;
}
