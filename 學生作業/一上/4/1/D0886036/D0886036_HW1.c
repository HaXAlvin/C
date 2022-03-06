#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch1_type= 'F';
    int ch1_hp=46;
    int ch1_attack=17;
    int ch1_defense=7;

    printf("角色一\n");
    printf("角色名稱:阿泰\n");
    printf("屬性:%c    ",ch1_type);
    printf("攻擊:%d\n",ch1_attack);
    printf("血量:%d   ",ch1_hp);
    printf("防禦:%d\n",ch1_defense);
    printf("角色預測強度:%.2f\n\n",((ch1_hp*1)+(ch1_attack*0.8)+(ch1_defense*0.5)-50)*6.5);
    printf("\n");

    char ch2_type= 'W';
    int ch2_hp=45;
    int ch2_attack=16;
    int ch2_defense=8;

    printf("角色二\n");
    printf("角色名稱:阿禎\n");
    printf("屬性:%c    ",ch2_type);
    printf("攻擊:%d\n",ch2_attack);
    printf("血量:%d   ",ch2_hp);
    printf("防禦:%d\n",ch2_defense);
    printf("角色預測強度:%.2f\n\n",((ch2_hp*1)+(ch2_attack*0.8)+(ch2_defense*0.5)-50)*6.5);
    printf("\n");

    char ch3_type= 'G';
    int ch3_hp=43;
    int ch3_attack=19;
    int ch3_defense=6;

    printf("角色三\n");
    printf("角色名稱:阿澤\n");
    printf("屬性:%c    ",ch3_type);
    printf("攻擊:%d\n",ch3_attack);
    printf("血量:%d   ",ch3_hp);
    printf("防禦:%d\n",ch3_defense);
    printf("角色預測強度:%.2f\n\n",((ch3_hp*1)+(ch3_attack*0.8)+(ch3_defense*0.5)-50)*6.5);
    printf("\n");

    char ch4_type;
    printf("新增角色\n");
    printf("屬性:");
    scanf("%c", &ch4_type);
    int ch4_hp, ch4_attack, ch4_defense;
    printf("攻擊:");
    scanf("%d", &ch4_attack);
    printf("血量:");
    scanf("%d", &ch4_hp);
    printf("防禦:");
    scanf("%d", &ch4_defense);
    printf("\n");
    printf("角色四\n");
    printf("名稱:阿芹\n");
    printf("屬性:%c    ",ch4_type);
    printf("攻擊:%d\n", ch4_attack);
    printf("血量:%d    ", ch4_hp);
    printf("防禦:%d\n", ch4_defense);
    printf("角色預測強度:%.2f\n\n",((ch4_hp*1)+(ch4_attack*0.8)+(ch4_defense*0.5)-50)*6.5);


    return 0;
}
