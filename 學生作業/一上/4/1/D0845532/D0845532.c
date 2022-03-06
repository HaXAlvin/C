#include<stdio.h>//標頭檔
int main()
{                  //主函式
    char char1type='G',char2type='A',char3type='F',char4type;//type
    int  char1atk=20,char2atk=15,char3atk=16,char4atk;//atk
    int  char1hp=40,char2hp=35,char3hp=44,char4hp;//hp
    int  char1def=10,char2def=10,char3def=5,char4def;//def
    printf("角色1\n"//印出文字
           "名稱:毛毛\n");
    printf("屬性:G    攻擊:20\n",char1type,char1atk);
    printf("血量:40   防禦:10\n", char2type,char2atk);
    printf("角色預測強度:%.2f\n\n",(char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50);

    printf("角色2\n"
           "名稱:皮皮\n");
    printf("屬性:A    攻擊:15\n",char2type,char2atk);
    printf("血量:35   防禦:10\n",char2hp,char2def);
    printf("角色預測強度:%.2f\n\n",(char2hp*1)+(char2atk*0.8)+(char2def*0.5)-50);

    printf("角色3\n"
           "名稱:瑞斯\n");
    printf("屬性:F    攻擊:16\n",char3type,char3atk);
    printf("血量:44   防禦:5\n",char3hp,char3def);
    printf("角色預測強度:%.2f\n\n",(char1hp*1)+(char1atk*0.8)+(char1def*0.5)-50);

    printf("新增角色\n");//新增角色
    printf("屬性:");
    scanf("%c",&char4type);
    printf("攻擊:");
    scanf("%d",&char4atk);
    printf("血量:");
    scanf("%d",&char4hp);
    printf("防禦:");
    scanf("%d",&char4def);
    printf("\n");

    printf("角色4\n");
    printf("名稱:自訂角色\n");
    printf("屬性:%c 攻擊%d\n",char4type,char4atk);
    printf("血量:%d 防禦%d\n",char4hp,char4def);
    printf("角色預測強度:%.2f\n",(char4hp*1)+(char4atk*0.8)+(char4def*0.5)-50);
    printf("\n");
    return 0;//結束

}
