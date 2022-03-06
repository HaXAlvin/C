#include<stdio.h>
int main() {
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

    int num;
    printf("是否新增角色(1.Yes/2.No)?");
    scanf("%d",&num);

    if(num==1) {
        //角色4
        printf("新增角色\n");
        printf("屬性:");
        getchar();
        scanf("%c",&char_type4);
        printf("攻擊:");
        scanf("%d",&char_atk4);
        printf("血量:");
        scanf("%d",&char_hp4);
        printf("防禦:");
        scanf("%d",&char_def4);
        printf("\n");

        if((char_type4 == 'F'||char_type4 =='W'||char_type4 =='G'||char_type4 =='A'||char_type4 =='f'||char_type4 =='w'||char_type4 =='g'||char_type4 =='a') && (char_hp4>=40 && char_hp4<=50 && char_atk4>=15 && char_atk4<=20 && char_def4>=5 && char_def4<=10) && (char_atk4+char_hp4+char_def4<=70 && 65<=char_atk4+char_hp4+char_def4)) {
            printf("角色4\n");
            printf("名稱:工藤新一\n");
            if(char_type4<96) {
                printf("屬性:%c    攻擊:%d\n",char_type4,char_atk4);
            } else if(char_type4>96) {
                printf("屬性:%c    攻擊:%d\n",char_type4-32,char_atk4);
            }
            printf("血量:%d   防禦:%d\n",char_hp4,char_def4);
            printf("強度預測:%.2f\n\n",(char_hp4*1.0+char_atk4*0.8+char_def4*0.5-50)*6.5);
            printf("\n");
            int first,second;
            printf("選擇先攻角色:");
            scanf("%d",&first);
            if(first == 1 || first == 2 || first == 3 || first == 4) {
                printf("選擇後攻角色:");
                scanf("%d",&second);
            }
            if(second == 1 || second == 2 || second == 3 || second == 4 && first != second)
                printf("先攻為角色%d\n後攻為角色%d",first,second);
            else if(first == second)
                printf("錯誤:不得重複選擇");
            else if(second != 1 || second != 2 || second != 3 || second != 4 )
                printf("錯誤:無此角色");

            else if(first != 1 || first != 2 || first != 3 || first != 4)
                printf("錯誤:無此角色");

        } else if((char_type4 != 'F'||char_type4 !='W'||char_type4 !='G'||char_type4 !='A'||char_type4 !='f'||char_type4 !='w'||char_type4 !='g'||char_type4 !='a') && (char_hp4>=40 && char_hp4<=50 && char_atk4>=15 && char_atk4<=20 && char_def4>=5 && char_def4<=10) && (char_atk4+char_hp4+char_def4<=70 && 65<=char_atk4+char_hp4+char_def4)) {
            printf("錯誤:無此屬性\n");
        } else if((char_type4 == 'F'||char_type4 =='W'||char_type4 =='G'||char_type4 =='A'||char_type4 =='f'||char_type4 =='w'||char_type4 =='g'||char_type4 =='a') && (char_hp4<=40 || char_hp4>=50 || char_atk4<=15 || char_atk4>=20 || char_def4<=5 || char_def4>=10 || char_atk4+char_hp4+char_def4<=65 || char_atk4+char_hp4+char_def4>=70)) {
            printf("錯誤:能力數值在限制範圍之外\n");
        } else if((char_type4 != 'F'||char_type4 !='W'||char_type4 !='G'||char_type4 !='A'||char_type4 !='f'||char_type4 !='w'||char_type4 !='g'||char_type4 !='a') && (char_hp4<=40 || char_hp4>=50 || char_atk4<=15 || char_atk4>=20 || char_def4<=5 || char_def4>=10 || char_atk4+char_hp4+char_def4<=65 || char_atk4+char_hp4+char_def4>=70)) {
            printf("錯誤:無此屬性\n"
                   "錯誤:能力數值在限制範圍之外\n");
        }
    } else if(num==2) {
        int first,second;
        printf("選擇先攻角色:");
        scanf("%d",&first);
        if(first == 1 || first == 2 || first==3) {
            printf("選擇後攻角色:");
            scanf("%d",&second);
        }
        if(second == 1 || second == 2 || second == 3 && first != second)
            printf("先攻為角色%d\n後攻為角色%d",first,second);
        else if(first == second)
            printf("錯誤:不得重複選擇");
        else if(second != 1 || second != 2 || second != 3)
            printf("錯誤:無此角色");

        else if(first != 1 || first != 2 || first != 3) {
            printf("錯誤:無此角色");
        }
    } else if(num!=1 && num!=2) {
        printf("輸入錯誤");
    }
    return 0;
}
