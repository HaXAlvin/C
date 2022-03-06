#include<stdio.h>
int fall=0;
void EditNewChar(char name[],char type,float atk,float hp,float def,int sum){
    sum=hp+atk+def;
    int num[4];

    if((type=='F'||type=='W'||type=='G'||type=='A')&&(atk>=15&&atk<=20)&&(hp<=50&&hp>=40)&&(def>=5&&def<=10)&&(sum<=70&&sum>=65)){ //若屬性為大寫 且能力數值皆和能力範圍皆正確
        printf("角色4\n名稱:%s\n屬性:%c    攻擊:%.0f\n血量:%.0f   防禦:%.0f\n角色強度預測:%.2f\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
        fall=1;
        return ;

    }
    else if((type==102||type==119||type==103||type==97)&&(atk>=15&&atk<=20)&&(hp<=50&&hp>=40)&&(def>=5&&def<=10)&&(sum<=70&&sum>=65)){ //若屬性為小寫 且能力數值皆和能力範圍皆正確
        type=type-32 ;
        printf("角色4\n名稱:%s\n屬性:%c    攻擊:%0.f\n血量:%.0f   防禦:%.0f\n角色強度預測:%.2f\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
        fall=1;
        return ;
        //break;
        }
    else if((type=='f'||type=='w'||type=='g'||type=='a'||type=='F'||type=='W'||type=='G'||type=='A')&&((atk<15||atk>20)||(hp>50||hp<40)||(def<5||def>10)||(sum>70||sum<65))){
        printf("錯誤:能力數值在限制範圍之外\n"); //若屬性輸入正確 但能力數值或能力範圍有錯
        printf("\n");
        fall=0;
    }
    else if((type!='f'||type!='w'||type!='g'||type!='a'||type!='F'||type!='W'||type!='G'||type!='A')&&((atk<15||atk>20)||(hp>50||hp<40)||(def<5||def>10)||(sum>70||sum<65))){
        printf("錯誤:無此屬性\n錯誤:能力數值在限制範圍之外\n"); // //若屬性輸入不正確 且能力數值或能力範圍有錯
        printf("\n");
        fall=0;
    }
    else if((type!='f'&&type!='w'&&type!='g'&&type!='a'&&type!='F'&&type!='W'&&type!='G'&&type!='A')&&((atk>15||atk<20)||(hp<50||hp>40)||(def>5||def<10)||(sum<=70||sum>=65))){
        printf("錯誤:無此屬性\n"); // //若屬性輸入不正確 但能力數值和能力範圍正確
        fall=0;
    }
    return ;
}


void PrintCharData(char name[],char type,float atk,float hp ,float def){
    printf("名稱:%s\n屬性:%c    攻擊:%.0f\n血量:%.0f   防禦:%.0f\n角色強度預測:%.2f\n\n",name,type,atk,hp,def,(hp* 1.0 + atk* 0.8 + def* 0.5 - 50 ) * 6.5);
    return ;
}
void Battling(int char5,int char6,float hp[],char type[],float atk[],int num[],float def[]){
    float temp,temp2;//儲存原始血量
    char5=char5-1 , char6=char6-1; //轉為陣列裡面的數字
    temp=hp[char5]; //儲存原始血量
    temp2=hp[char6];//儲存原始血量
    while(hp[char5]>0 &&hp[char6]>0){
        float kr1, kr2; //相剋倍率
        if((type[char5]=='W'&&type[char6]=='F')||(type[char5]=='F'&&type[char6]=='A')||(type[char5]=='A'&&type[char6]=='G')||(type[char5]=='G'&&type[char6]=='W')){
            kr1=atk[char5]*1.2 , kr2=atk[char6]*0.8 ;  //先攻倍率大
        }

        else if((type[char6]=='W'&&type[char5]=='F')||(type[char6]=='F'&&type[char5]=='A')||(type[char6]=='A'&&type[char5]=='G')||(type[char6]=='G'&&type[char5]=='W')){
            kr1=atk[char5]*0.8  , kr2=atk[char6]*1.2;  //後攻倍率大
        }
        else{
            kr1=atk[char5] ,kr2=atk[char6] ;
        }
    //以上為制定相剋倍率
        int hurt1;
        float blood1=1; //傷害攻擊 殘血倍率
        int hurt2;
        float blood2=1; //傷害攻擊 殘血倍率


        if(hp[char5]>0){ //當先攻血量大於0
            if(hp[char5]<temp*0.5){
                blood1=blood1*1.2; //符合殘血倍率
            }

            hurt1=kr1*blood1-def[char6]; //先攻的攻擊傷害數值
            hp[char6]=hp[char6]-hurt1;//後攻被攻擊後的血量

            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",num[char5],num[char6],hurt1);
            printf("角色 %d HP:%.0f 角色 %d HP:%.0f\n",num[char5],hp[char5],num[char6],hp[char6]);
            printf("\n");
        }
        else{
            printf("角色 %d 失去戰鬥力\n戰鬥結束\n\n角色 %d 獲勝\n",num[char5],num[char6]);
        }
        if(hp[char6]<temp2*0.5){ //符合殘血倍率
            blood2=blood2*1.2;
        }
        if(hp[char6]>0){ //如果後攻血量大於0
            hurt2=kr2*blood2-def[char5]; //後攻的攻擊傷害數值
            hp[char5]=hp[char5]-hurt2;//先攻被攻擊後的血量
            printf("角色%d 對 角色%d 發動攻擊，造成 %d 點傷害\n",num[char6],num[char5],hurt2);
            printf("角色 %d HP:%.0f 角色 %d HP:%.0f\n",num[char6],hp[char6],num[char5],hp[char5]);
            printf("\n");
            if(hp[char5]<0){ //若先攻死亡
                printf("角色 %d 失去戰鬥力\n戰鬥結束\n\n角色 %d 獲勝\n",num[char5],num[char6]);
            }

        }
        else{
            printf("角色 %d 失去戰鬥力\n戰鬥結束\n\n角色 %d 獲勝\n",num[char6],num[char5]);
            fall=1;
        }

    }
    hp[char5]=temp; //復原血量
    hp[char6] =temp2;//復原血量
    fall=1;
}


void SelectAndBattle(int char5,int char6,int num[],float hp[],char type[],float atk[],float def[]){
    do{
        printf("選擇先攻角色:") , scanf("%d",&char5);
        char5=char5-1;
        if (num[char5]>0&&num[char5]<5){ //若角色數字輸入正確
            do{
                printf("選擇後攻角色:");
                scanf("%d",&char6);
                char6=char6-1;

                if(num[char5]==num[char6]){ //若角色相同
                    printf("不可重複選取\n");
                    fall=0;
                }
                else if (num[char6]>0&&num[char6]<5){ // 若角色數字輸入正確 且角色不相同
                    char5=char5+1 ,char6=char6+1 ;
                    printf("\n");
                    printf("先攻為角色%d、後攻角色為%d\n",char5,char6);
                    printf("戰鬥開始\n\n");
                    Battling(char5,char6,hp,type,atk,num,def);
                }
                else{
                    printf("錯誤:無此角色\n");
                }
            }while(fall==0);
            break;
        }
        else //輸入無關的符號
            printf("錯誤:無此角色\n");
            fall=0;
    }while(fall==0);
}



int main(){
    int num1,tag=0,count=0,membernum=2;
    char type[4]={'W','G','A'}; //屬性
    float hp[4]={50,43,48} ; //血量
    float atk[4]={15,17,15} ; //攻擊
    float def[4]={5,5,7}; //防禦
    int num[4]={1,2,3}; //角色編號
    char char1_name[2100]={"安安"}; //角色1
    char char2_name[2100]={"阿呼"}; //角色2
    char char3_name[2100]={"布榖"}; //角色3
    char char4_name[2100];
    int char5,char6; //先攻角色 後攻角色



    while(tag==0){
        printf("case 1. 新增或修改新增角色\ncase 2. 顯示所有角色資料\ncase 3. 戰鬥\ncase 0. 結束遊戲\n請選擇 : ");
        scanf("%d",&num1);
        printf("\n");
        if(num1==0||num1==1||num1==2||num1==3){
            if(num1==0){
                printf("結束遊戲\n");
                printf("\n");
                return 0;
            }
            if(num1==1){
                do{
                    if(count==0){
                        printf("新增角色\n");
                        membernum=2;
                    }
                    else if(count>0){
                        printf("修改新增角色\n");
                        membernum=2;
                    }
                    printf("名稱: "), scanf("%s",char4_name);
                    getchar();
                    printf("屬性: "), scanf("%c",&type[3]);
                    printf("血量: "), scanf("%f",&hp[3]);
                    printf("攻擊: "), scanf("%f",&atk[3]);
                    printf("防禦: "), scanf("%f",&def[3]);
                    printf("\n");

                    int sum=hp[3]+atk[3]+def[3]; //角色數值總和
                    EditNewChar(char4_name,type[3],  atk[3],hp[3],def[3],sum) ;
                    if(type[3]==102||type[3]==119||type[3]==103||type[3]==97) {//若屬性為小寫
                        type[3]=type[3]-32 ; //轉為大寫
                    }
                    membernum=membernum+1;
                    num[3]=4;
                }while(fall==0);
                printf("\n");
                count=count+1;
            }
            if(num1==2){
                printf("角色1\n"),PrintCharData(char1_name,type[0],atk[0],hp[0] ,def[0]);
                printf("角色2\n"),PrintCharData(char2_name,type[1],atk[1],hp[1] ,def[1]);
                printf("角色3\n"),PrintCharData(char3_name,type[2],atk[2],hp[2] ,def[2]);

                if(membernum==3){
                    printf("角色4\n"),PrintCharData(char4_name,type[3],atk[3],hp[3] ,def[3]);
                }
                printf("\n");
            }
            if(num1==3){
                SelectAndBattle(char5,char6,num,hp,type,atk,def);
                printf("\n");
            }
        }
        else{
            printf("輸入錯誤!\n");
            printf("\n");
        }
    }
    return 0;
}
