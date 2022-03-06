//#include<stdio.h>
//#include<ctype.h>
//
int main(){
    int a;
    if(1){
        int a;
    }
    printf("%d",a);
//
//    char char1_type ='F';
//    int char1_hp = 42;
//    int char1_atk = 18;
//    int char1_def = 9;
//
//    char char2_type ='G';
//    int char2_hp = 45;
//    int char2_atk = 15;
//    int char2_def = 10;
//
//    char char3_type ='A';
//    int char3_hp = 50;
//    int char3_atk = 15;
//    int char3_def = 5;
//
//    char char4_type;
//    int char4_hp;
//    int char4_atk;
//    int char4_def;
//
//	float tal1=((char1_hp*1.0)+(char1_atk*0.8)+(char1_def*0.5)-50)*6.5;
//	float tal2=((char2_hp*1.0)+(char2_atk*0.8)+(char2_def*0.5)-50)*6.5;
//	float tal3=((char3_hp*1.0)+(char3_atk*0.8)+(char3_def*0.5)-50)*6.5;
//
//
//    printf("角色1\n角色名稱:鎧凌\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n強度預測=%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,tal1);
//    printf("角色2\n角色名稱:睿童\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n強度預測=%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,tal2);
//    printf("角色3\n角色名稱:宜銹\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n強度預測=%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,tal3);
//    //printf("角色1\n角色名稱:鎧凌\n屬性:F\t\t血量:42\n攻擊:18\t\t防禦:9\n\n");//總和69
//    //printf("角色2\n角色名稱:睿童\n屬性:G\t\t血量:45\n攻擊:15\t\t防禦:10\n\n");//總和70
//    //printf("角色3\n角色名稱:宜銹\n屬性:A\t\t血量:50\n攻擊:15\t\t防禦:5\n\n");//總和70
//    //強度預測 = ( 血量 * 1.0 + 攻擊 * 0.8 + 防禦 * 0.5 - 50 ) * 6.5
//
//    printf("是否新增角色(1.Yes/2.No)?");
//    int chose;
//
//    scanf("%d",&chose);
//
//    if (chose==1){ //新增角色
//
//        printf("\n新增角色\n");
//        printf("屬性:");
//        scanf(" %c",&char4_type); //%c之前要有個空格  若是打%c不用打getchar 或 \n
//        printf("血量:");
//        scanf("%d",&char4_hp);
//        getchar();
//        printf("攻擊:");
//        scanf("%d",&char4_atk);
//        getchar();
//        printf("防禦:");
//        scanf("%d",&char4_def);
//
//        int sum=char4_def+char4_hp+char4_atk;
//
//        if ((char4_type!='G'&&char4_type!='W'&&char4_type!='A'&&char4_type!='F'&&char4_type!='a'&&char4_type!='f'&&char4_type!='g'&&char4_type!='w')&&(char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||sum<65||sum>70)){
//            printf("\n錯誤：無此屬性\n錯誤：能力數值在限制範圍之外");
//            return 0;
//
//        }
//
//        else if (char4_type!='G'&&char4_type!='W'&&char4_type!='A'&&char4_type!='F'&&char4_type!='a'&&char4_type!='f'&&char4_type!='g'&&char4_type!='w'){
//            printf("錯誤：無此屬性");   //若輸入非F A G W之屬性 則輸出無此屬性
//            return 0;
//
//        }
//
//
//
//        else if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10||sum<65||sum>70){
//            printf("錯誤：能力數值在限制範圍之外");  //設定各屬性之範圍
//            return 0;
//        }
//
//
//
//
//
//
//        float tal4=((char4_hp*1.0)+(char4_atk*0.8)+(char4_def*0.5)-50)*6.5;
//        printf("\n角色4\n角色名稱:自訂角色\n屬性:%c\t\t血量:%d\n攻擊:%d\t\t防禦:%d\n\n",toupper(char4_type),char4_hp,char4_atk,char4_def);
//        printf("強度預測=%.2f\n\n",tal4); //列出新增角色之屬性
//
//
//        printf("\n選擇先攻角色： ");
//        int first_atk;
//        scanf("%d",&first_atk);
//        if (first_atk>=5){ //新增角色後，有4個角色 >=5
//            printf("錯誤：無此角色");
//            return 0;
//        }
//
//        printf("選擇後攻角色： ");
//        int second_atk;
//        scanf("%d",&second_atk);
//        if (second_atk>=5){ //新增角色後，有4個角色 >=5
//            printf("錯誤：無此角色");
//            return 0; //直接結束程式
//        }
//
//
//        if (first_atk==second_atk){ //重複選取
//            printf("錯誤：不可重複選取");
//            return 0;
//        }
//
//
//        else {
//            printf("先攻為角色%d、後攻為角色%d",first_atk,second_atk);
//        }
//
//}
//
//
//
//    else if (chose==2){
//
//        printf("\n選擇先攻角色： ");
//        int first_atk;
//        scanf("%d",&first_atk);
//        if (first_atk>=4){ //新增角色後，有4個角色 >=5
//            printf("錯誤：無此角色");
//            return 0;
//        }
//
//        printf("選擇後攻角色： ");
//        int second_atk;
//        scanf("%d",&second_atk);
//        if (second_atk>=4){ //新增角色後，有4個角色 >=5
//            printf("錯誤：無此角色");
//            return 0; //直接結束程式
//        }
//
//
//        if (first_atk==second_atk){ //重複選取
//            printf("錯誤：不可重複選取");
//            return 0;
//        }
//
//
//        else {
//            printf("先攻為角色%d、後攻為角色%d",first_atk,second_atk);
//        }
//    }
//    else
//        printf("輸入錯誤");
//
//
    return 0;
}
