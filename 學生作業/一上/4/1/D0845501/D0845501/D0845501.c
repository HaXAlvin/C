#include<stdio.h>
int main(){
    //角色1
    char char_type1 = 'A';
    int char_atk1 = 19;
    int char_hp1 = 47;
    int char_def1 = 4;
    float char_power1 = (char_hp1*1.0+char_atk1*0.8+char_def1*0.5-50)*6.5;
    //角色2
    char char_type2 = 'F';
    int char_atk2 = 17;
    int char_hp2 = 45;
    int char_def2 = 5;
    float char_power2 = (char_hp2*1.0+char_atk2*0.8+char_def2*0.5-50)*6.5;
    //角色3
    char char_type3 = 'W';
    int char_atk3 = 20;
    int char_hp3 = 43;
    int char_def3 = 7;
    float char_power3 = (char_hp3*1.0+char_atk3*0.8+char_def3*0.5-50)*6.5;
    //角色4
    char char_type4;
    int char_atk4;
    int char_hp4;
    int char_def4;
    float char_power4;
    //角色1
    printf("角色1\n"
           "名稱:漩渦鳴人\n");
    printf("屬性:%c    攻擊:%d\n",char_type1,char_atk1);
    printf("血量:%d   防禦:%d\n",char_hp1,char_def1);
    printf("強度預測:%.2f\n\n",char_power1);
    //角色2
    printf("角色2\n"
           "名稱:納茲多拉格尼魯\n");
    printf("屬性:%c    攻擊:%d\n",char_type2,char_atk2);
    printf("血量:%d   防禦:%d\n",char_hp2,char_def2);
    printf("強度預測:%.2f\n\n",char_power2);
    //角色3
    printf("角色3\n"
           "名稱:蒙奇D魯夫\n");
    printf("屬性:%c    攻擊:%d\n",char_type3,char_atk3);
    printf("血量:%d   防禦:%d\n",char_hp3,char_def3);
    printf("強度預測:%.2f\n\n",char_power3);
    //角色4
    printf("新增角色\n");
    printf("屬性:");
    scanf("%c",&char_type4);
    printf("攻擊:");
    scanf("%d",&char_atk4);
    printf("血量:");
    scanf("%d",&char_hp4);
    printf("防禦:");
    scanf("%d",&char_def4);
    printf("\n");
    printf("角色4\n");
    printf("名稱:工藤新一\n");
    printf("屬性:%c    攻擊:%d\n",char_type4,char_atk4);
    printf("血量:%d   防禦:%d\n",char_hp4,char_def4);
    printf("強度預測:%.2f\n\n",(char_hp4*1.0+char_atk4*0.8+char_def4*0.5-50)*6.5);

    return 0;
}
