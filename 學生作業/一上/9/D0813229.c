#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char PrintCharData(int char_name,int hp,int atk,int def) {
    printf("角色1\n"
           "名稱:老噴\n"
           "屬性:F     攻擊:15\n"
           "血量:40    防禦:5\n"
           "角色強度預測:29.25\n\n");
    printf("角色2\n"
           "名稱:老龜\n"
           "屬性:W    攻擊:16\n"
           "血量:41   防禦:6\n"
           "角色強度預測:44.20\n\n");
    printf("角色3\n"
           "名稱:老皮\n"
           "屬性G    攻擊:17\n"
           "血量:42   防禦:7\n"
           "角色強度預測:59.15\n\n");
    return;
}
char EditNewChar(int *is_create_char4,char type,int char4_hp,int char4_atk,int char4_def,char char4_name[21]) {
    printf("\n");
    int test=0,err_type=0;
    if(*is_create_char4==0) {           ///////當新增腳色的名字是空的就新增
        printf("新增角色\n");
    } else {
        printf("修改角色\n");
    }
    printf("名稱:");
    scanf("%s%*c",char4_name);
    printf("屬性:");
    scanf("%c%*c",&type);
    printf("血量:");
    scanf("%d",&char4_hp);
    printf("攻擊:");
    scanf("%d",&char4_atk);
    printf("防禦:");
    scanf("%d",&char4_def);
    switch(type) { //判斷角色屬性
    case'f':
            break;
    case 'g':
        break;
    case 'a':
        break;
    case 'w':
        break;
    case 'F':
        break;
    case 'G':
        break;
    case 'A':
        break;
    case 'W':
        break;
    default:
        test=1;
        err_type = 1; //標示錯誤種類
    }
    if (char4_hp<40||char4_hp>50||char4_atk<15||char4_atk>20||char4_def<5||char4_def>10) {
        test=1;
        err_type = 2;
    }//判斷能力值範圍
    switch(err_type) { //判斷顯示的東西
    case 0:
        break;
    case 1:
        printf("錯誤:無此屬性\n");
        break;
    case 2:
        printf("錯誤:無此屬性\n錯誤:能力數值在範圍之外\n");
        break;
    }
    if(test==0) {
        *is_create_char4=1;
        float a = (char4_hp*1.0+char4_atk*0.8+char4_def*0.5);
        float b = (a-50)*6.5;
        printf("\n");
        printf("角色4\n");
        printf("名稱:%s\n",char4_name);
        switch(type) {
        case'f':
                printf("屬性:F  ");
            break;
        case'g':
            printf("屬性:G  ");
            break;
        case'a':
                printf("屬性:A  ");
            break;
        case'w':
            printf("屬性:W  ");
            break;
        default:
            printf("屬性:%c   ",type);
            break;
        }
        printf("攻擊:%d\n",char4_atk);
        printf("血量:%d   ",char4_hp);
        printf("防禦:%d\n",char4_def);
        printf("角色強度預測:%.2lf",b);
        printf("\n");
        printf(" ");
        printf("\n");
    } else {
        EditNewChar(is_create_char4,type,char4_hp,char4_atk,char4_def,char4_name);
    }
}

char SelectAndBattle(int first1,int second1) {
    int first,second;
    printf(" ");
    printf("\n");
    printf("選擇先攻角色:");
    scanf("%d",&first);
    while(first>4) {                                      ////////若選擇先攻角色不存在(最多只有四個角色)
        printf("錯誤:無此角色\n");
        printf("選擇先攻角色:");
        scanf("%d",&first);
    }
    printf("選擇後攻角色:");
    scanf("%d",&second);
    while(second>4) {                                     ////////若選擇後攻角色不存在(最多只有四個角色)
        printf("錯誤:無此角色\n");
        printf("選擇後攻角色:");
        scanf("%d",&second);
    }
    if(first==second) {                                   ////////若選擇先攻後攻角色相同時
        printf("錯誤:不可重複選取\n");
        printf("選擇先攻角色:");
        scanf("%d",&first);
        while(first>4) {
            printf("錯誤:無此角色\n");
            printf("選擇先攻角色:");
            scanf("%d",&first);
        }
        printf("選擇後攻角色:");
        scanf("%d",&second);
        while(second>4) {
            printf("錯誤:無此角色\n");
            printf("選擇後攻角色:");
            scanf("%d",&second);
        }
    }
    printf("\n");
    printf("先攻角色為%d\n",first);
    printf("後攻角色為%d",second);
    printf("\n");
    printf("     ");
    printf("\n");
    printf("先攻角色為%d、",first);
    printf("後攻角色為%d",second);
    printf("\n");
}
int main() {
    char char4_name[21]= {0};
    int is_create_char4=0;
    char type;
    char type1;
    int  char_hp,char_atk,char_def;
    char char_name;
    int hp,atk,def;
    int hp1,atk1,def1;
    int hp2,atk2,def2;
    int num;
    int hp_1,hp_2;
    char type_1,type_2,type_3;
    int char4_hp,char4_atk,char4_def;
    int test=0;
    int err_type = 0;
    char first_type,second_type;
    int first,second;
    int first_hp,first_atk,first_def;
    int second_hp,second_atk,second_def;
    int first_dam,second_dam;
    int first1,second1;
    while(num!=EOF) {
        printf("1.新增或修改新角色\n2.顯示所有角色資料\n3.戰鬥\n0.結束遊戲\n");
        printf("請選擇:");
        scanf("%d",&num);
        if(num<0||num>3) {
            printf("\n");
            printf("輸入錯誤!\n",num);
            printf("\n");
            printf("1.新增或修改新角色\n2.顯示所有角色資料\n3.戰鬥\n0.結束遊戲\n");
            printf("請選擇:");
            scanf("%d",&num);
        }
        switch(num) {                               //////選擇模式
        case 0: {
            printf("結束遊戲");
            return 0;
        }
        case 1: {

            EditNewChar(&is_create_char4,type,char4_hp,char4_atk,char4_def,char4_name);
            break;
        }
        case 2: {
            PrintCharData(char_name,hp,atk,def);
            if(char4_name[0]!=0) {
                printf("角色4\n");
                printf("名稱:%s\n",char4_name);
                printf("屬性:%c   ",type);
                printf("攻擊:%d\n",char4_atk);
                printf("血量:%d   ",char4_hp);
                printf("防禦:%d\n",char4_def);
                printf("\n");
            }
            break;
        }
        case 3: {
            SelectAndBattle(first1,second1);
            printf("戰鬥開始");
            printf("\n");
            printf("     ");
            printf("\n");
            switch(first) {                            ////////////存入先攻角色的相關數據
            case 1:
                hp1=40;
                hp_1=40;
                atk1=15;
                def1=5;
                break;
            case 2:
                hp1=41;
                hp_1=41;
                atk1=16;
                def1=6;
                break;
            case 3:
                hp1=42;
                hp_1=42;
                atk1=17;
                def1=7;
                break;
            case 4:
                hp1=char4_hp;
                atk1=char4_atk;
                def1=char4_def;
                break;
            default:
                hp1=0;
                break;
            }
            switch(second) {                          ////////////存入後攻角色的相關數據
            case 1:
                hp2=40;
                hp_2=40;
                atk2=15;
                def2=5;
                break;
            case 2:
                hp2=41;
                hp_2=41;
                atk2=16;
                def2=6;
                break;
            case 3:
                hp2=42;
                hp_2=42;
                atk2=17;
                def2=7;
                break;
            case 4:
                hp2=char4_hp;
                atk2=char4_atk;
                def2=char4_def;
                break;
            default:
                hp2=0;
                break;
            }
            first_dam=atk1-def2;               //////////計算傷害的基本公式(不相剋且血量高於最大值血量的一半)
            second_dam=atk2-def1;
            switch(first) {                            ///////決定先攻角色屬性
            case 1:
                type_1='F';
                break;
            case 2:
                type_2='W';
                break;
            case 3:
                type_3='G';
                break;
            case 4:
                break;

            }
            switch(second) {                              ///////決定後攻角色屬性
            case 1:
                type_1='F';
                break;
            case 2:
                type_2='W';
                break;
            case 3:
                type_3='G';
                break;
            case 4:
                break;

            }

            while(hp1>0&&hp2>0) { ///////////當兩隻腳色都還活著
                if(first==1&&second==2) { ///////////判斷先後攻角色分別的屬性，並加入屬性相剋的傷害加成以及殘血倍率
                    first_dam=atk1*0.8-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*0.8*1.2-def2;
                    }
                    second_dam=atk2*1.2-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2*1.2-def1;
                    }
                } else if(first==2&&second==1) {
                    first_dam=atk1*1.2-def2;

                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2*1.2-def2;
                    }
                    second_dam=atk2*0.8-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*0.8*1.2-def1;

                    }
                } else if(first==2&&second==3) {
                    first_dam=atk1*0.8-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*0.8*1.2-def2;
                    }
                    second_dam=atk2*1.2-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2*1.2-def1;
                    }
                } else if(first==3&&second==2) {
                    first_dam=atk1*1.2-def2;
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2*1.2-def2;
                    }
                    second_dam=atk2*0.8-def1;
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*0.8*1.2-def1;
                    }
                } else if(first==1&&second==3) {
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2-def2;
                    }
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2-def1;
                    }
                } else if(first==3&&second==1) {
                    if(hp1<(hp_1)/2) {
                        first_dam=atk1*1.2-def2;
                    }
                    if(hp2<(hp_2)/2) {
                        second_dam=atk2*1.2-def1;
                    }
                }
                if(first==4&&second==1) {

                    if(type=='W'||type=='w') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }

                    else if(type=='A'||type=='a') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {

                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==1&&second==4) {
                    if(type=='W'||type=='w') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==4&&second==2) {
                    if(type=='G'||type=='g') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='W'||type=='w') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==2&&second==4) {
                    if(type=='G'||type=='g') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    }
                    if(type=='F'||type=='f') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='A'||type=='a') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='W'||type=='w') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==4&&second==3) {
                    if(type=='A'||type=='a') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }
                    if(type=='W'||type=='w') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }
                if(first==3&&second==4) {
                    if(type=='A'||type=='a') {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    }
                    if(type=='W'||type=='w') {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    } else if(type=='F'||type=='f') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    } else if(type=='G'||type=='g') {
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2-def2;
                        }
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2-def1;
                        }
                    }
                }

                hp2=hp2-first_dam; ///////計算總傷害
                printf("角色%d 對角色%d 發動攻擊，造成%d傷害\n角色%d HP %d  角色%d  HP %d\n",first,second,first_dam,first,hp1,second,hp2);
                printf("\n");
                if(hp2>0) {

                    if(first==1&&second==2) { ///////////判斷先後攻角色分別的屬性，並加入屬性相剋的傷害加成以及殘血倍率
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(first==2&&second==1) {
                        first_dam=atk1*1.2-def2;

                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;

                        }
                    } else if(first==2&&second==3) {
                        first_dam=atk1*0.8-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*0.8*1.2-def2;
                        }
                        second_dam=atk2*1.2-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*1.2*1.2-def1;
                        }
                    } else if(first==3&&second==2) {
                        first_dam=atk1*1.2-def2;
                        if(hp1<(hp_1)/2) {
                            first_dam=atk1*1.2*1.2-def2;
                        }
                        second_dam=atk2*0.8-def1;
                        if(hp2<(hp_2)/2) {
                            second_dam=atk2*0.8*1.2-def1;
                        }
                    }
                    if(first==4&&second==1) {
                        if(type=='W'||type=='w') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        }

                        else if(type=='A'||type=='a') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='f'||type=='F') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==1&&second==4) {
                        if(type=='W'||type=='w') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==4&&second==2) {
                        if(type=='G'||type=='g') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='W'||type=='w') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==2&&second==4) {
                        if(type=='G'||type=='g') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        }
                        if(type=='F'||type=='f') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='A'||type=='a') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='W'||type=='w') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==4&&second==3) {
                        if(type=='A'||type=='a') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        }
                        if(type=='W'||type=='w') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    if(first==3&&second==4) {
                        if(type=='A'||type=='a') {
                            first_dam=atk1*0.8-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*0.8*1.2-def2;
                            }
                            second_dam=atk2*1.2-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2*1.2-def1;
                            }
                        }
                        if(type=='W'||type=='w') {
                            first_dam=atk1*1.2-def2;
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2*1.2-def2;
                            }
                            second_dam=atk2*0.8-def1;
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*0.8*1.2-def1;
                            }
                        } else if(type=='F'||type=='f') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        } else if(type=='G'||type=='g') {
                            if(hp1<(hp_1)/2) {
                                first_dam=atk1*1.2-def2;
                            }
                            if(hp2<(hp_2)/2) {
                                second_dam=atk2*1.2-def1;
                            }
                        }
                    }
                    hp1=hp1-second_dam; ///////計算總傷害
                    printf("角色%d 對角色%d 發動攻擊，造成%d傷害\n角色%d HP %d  角色%d  HP %d\n",second,first,second_dam,first,hp1,second,hp2);
                    printf("\n");
                }

            }
            if(hp1<=0||hp2<=0) { ////////兩個對戰角色的血量歸零
                if(hp1<=0) {
                    printf("角色%d  失去戰鬥能力\n戰鬥結束\n",first);
                    printf("\n");
                    printf("角色%d 獲勝",second);
                } else {
                    printf("角色%d  失去戰鬥能力\n戰鬥結束\n",second);
                    printf("\n");
                    printf("角色%d 獲勝",first);
                }
                printf("\n");
                printf(" ");
                printf("\n");
            }
        }
        }
    }
    return 0;
}
