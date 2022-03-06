#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

int main() {
    //角色1
    char char1_type='F';//屬性
    int char1_hp=45;//血量
    int char1_atk=17;//攻擊
    int char1_def=8;//防禦
    float char1_pre=(char1_hp*1.0+char1_atk*0.8+char1_def*0.5-50)*6.5;//強度預測
    //角色2
    char char2_type='G';
    int char2_hp=45;
    int char2_atk=15;
    int char2_def=10;
    float char2_pre=(char2_hp*1.0+char2_atk*0.8+char2_def*0.5-50)*6.5;
    //角色3
    char char3_type='A';
    int char3_hp=50;
    int char3_atk=15;
    int char3_def=5;
    float char3_pre=(char3_hp*1.0+char3_atk*0.8+char3_def*0.5-50)*6.5;
    //角色4
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float char4_pre;

    printf("角色1\n");
    printf("名稱:阿柴\n");
    printf("屬性:%c\t",char1_type);
    printf("攻擊:%d\n",char1_atk);
    printf("血量:%d\t",char1_hp);
    printf("防禦:%d\n",char1_def);
    printf("角色強度預測:%.2f\n",char1_pre);
    printf("\n");

    printf("角色2\n");
    printf("名稱:豆桑\n");
    printf("屬性:%c\t",char2_type);
    printf("攻擊:%d\n",char2_atk);
    printf("血量:%d\t",char2_hp);
    printf("防禦:%d\n",char2_def);
    printf("角色強度預測:%.2f\n",char2_pre);
    printf("\n");

    printf("角色3\n");
    printf("名稱:蘿絲 \n");
    printf("屬性:%c\t",char3_type);
    printf("攻擊:%d\n",char3_atk);
    printf("血量:%d\t",char3_hp);
    printf("防禦:%d\n",char3_def);
    printf("角色強度預測:%.2f\n",char3_pre);
    printf("\n");

    int chos;//訂定是否新增角色變數chos
    int frs_atk;//訂定先攻角色變數
    int sec_atk;//訂定後攻角色變數
    char a;
    printf("是否新增角色(1.Yes/2.No)? ");
    scanf("%d",&chos);
    if (chos==1) { //選擇新增角色
        printf("\n");
        printf("新增角色\n");
        printf("屬性:");
        scanf(" %c",&a);//因為會讀到前第3行的\n，%c前要空一格
        char4_type = a;
        printf("血量:");
        scanf("%d",&char4_hp);
        printf("攻擊:");
        scanf("%d",&char4_atk);
        printf("防禦:");
        scanf("%d",&char4_def);
        char4_pre=(char4_hp*1.0+char4_atk*0.8+char4_def*0.5-50)*6.5;

        if(char4_type != 'F') {
            printf("錯誤:無此屬性\n");//屬性輸入錯誤
        }
        if((char4_hp <40 || char4_hp >50) || (char4_atk <15 || char4_atk >20) || (char4_def <5 || char4_def >10) || (char4_hp+char4_atk+char4_def <65 || char4_hp+char4_atk+char4_def >70)) {
            //如果三者總和或個別數值超出範圍，則印出下列文字
            printf("錯誤:能力數值在限制範圍之外\n");//設定數據數值規範
        }
        if((char4_type=='F'||char4_type=='W'||char4_type=='G'||char4_type=='A'||char4_type=='f'||char4_type=='w'||char4_type=='g'||char4_type=='a')&&((40<=char4_hp && char4_hp<=50)&&(15<=char4_atk && char4_atk<=20)&&(5<=char4_def && char4_def<=10))) {
            //屬性、數值輸入正確
            printf("\n");
            printf("角色4\n");
            printf("名稱:自訂角色\n");
            if(islower(char4_type)!=0) { //如果輸入為小寫，印出時改為大寫
                printf("屬性:%c\t",toupper(char4_type));
            } else {
                a = char4_type;
                printf("屬性:%c\t",a);
            }//若原本為大寫，則直接印出
            printf("攻擊:%d\n",char4_atk);
            printf("血量:%d\t",char4_hp);
            printf("防禦:%d\n",char4_def);
            printf("角色強度預測:%.2f\n",char4_pre);
            printf("\n");
            printf("選擇先攻角色:");
            scanf("%d",&frs_atk);
            switch(frs_atk) {
            case 1 ... 4:
                printf("選擇後攻角色:");
                scanf("%d",&sec_atk);
                if((sec_atk==1 || sec_atk==2 || sec_atk==3 || sec_atk==4) && sec_atk!=frs_atk)//當後攻輸入正確
                    printf("\n先攻角色為%d、後攻角色為%d\n",frs_atk,sec_atk);
                else if(sec_atk==frs_atk)//當先攻與後攻角色重複，印出錯誤警告
                    printf("錯誤:不可重複選取\n");
                else
                    printf("錯誤:無此角色\n");//當後攻角色輸入為1~4以外數字，印出錯誤警告
                break;
            default :
                printf("錯誤:無此角色\n");//當先攻角色輸入為1~4以外數字，印出錯誤警告
            }


        }
        return 0;
    }


    if(chos==2) {
        //選擇不新增角色
        printf("\n");
        printf("選擇先攻角色:");
        scanf("%d",&frs_atk);
        if(frs_atk== 1||frs_atk==2||frs_atk==3) {
            printf("選擇後攻角色:");
            scanf("%d",&sec_atk);
            if((sec_atk==1 || sec_atk==2 || sec_atk==3) && sec_atk != frs_atk)
                printf("\n先攻角色為%d、後攻角色為%d\n",frs_atk,sec_atk);
            else if(sec_atk==frs_atk)
                printf("錯誤:不可重複選取\n");
            else
                printf("錯誤:無此角色\n");
            return 0;
        } else //輸入(1.Yes/2.No)之外的數字，印出錯誤警告
            printf("輸入錯誤\n");
        return 0;
    }
}




