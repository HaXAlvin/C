#include <stdio.h>
#include <stdlib.h>

void printdata(char name,char element,int HP, int ATK,int DEF,float stat) {
    stat=((HP*1.0+ATK*0.8+DEF*0.5- 50)*6.5);
    printf("\nName:%s\nElement:%c\nHP:%d\nATK:%d\nDEF:%d\nPower Level:%.2f\n",name,element,HP,ATK,DEF,stat);
}



int main() {

    char element[4]= "WFA";
    char name[4][20]= {"GG","BB","CC"};
    int HP[20]= {43,46,45};
    int ATK[20]= {20,14,15};
    int DEF[20]= {5,7,7};
    float stat[10];
    int i,j,select;
    int k=0,player=3;
    int close;
    int player1,player2;
    int player1_hp,player1_def,player1_atk,player1_ele;
    int player2_hp,player2_def,player2_atk,player2_ele;
    int cr1,cr2;
    int hc1,hc2,damage;


    while(1) {
        printf("1.New or Modify Character\n2.Show All Character Information\n3.Battle\n0.Game End\nSelect:");
        scanf("%d",&select);
        printf("\n");

        switch(select) {
        case 1: // New character information
            if(player == 3) {
                printf("New Character\n");
            } else {
                printf("Modify Character");
            }
            printf("Name:");
            scanf("%s",&name[3]);
            printf("Element:");
            scanf(" %c",&element[3]);
            if(element[3] == 'W' | element[3] == 'A' | element[3] == 'G' | element[3] == 'F') {} // limited these character
            if(element[3] =='a' | element[3] =='f'| element[3] =='w'|element[3] == 'g') { // limited these character
                if(element[3] >= 97)
                    element[3] = element[3] - 32; //change the character to capital letter
            }
            if(element[3] == 'W' | element[3] == 'A' | element[3] == 'G' | element[3] == 'F') {}
            else {
                printf("Error : Unknown Element\n\n");// Element judge
                continue;
            }
            printf("Hp(40~50):");
            scanf(" %d",&HP[3]);
            if(HP[3] < 40 || HP[3] > 50) { // HP judge
                printf("Error:HP is Out Of Range\n\n");
                continue;
            }
            printf("ATK(15~20):");
            scanf(" %d",&ATK[3]);
            if(ATK[3]<15 || ATK[3]>20) { // ATK judge
                printf("Error:Attack is Out Of Range\n\n");
                continue;
            }
            printf("DEF(5~10):");
            scanf(" %d",&DEF[3]);
            if(DEF[3] <5 || DEF[3] >10) { //def judge
                printf("Error:Def Is Out Of Range\n\n");
                continue;
            }

            int total=(HP[3]+ATK[3]+DEF[3]);
            if(total<65 || total>70) {
                printf("Error:Status Out Of Range\n\n");
                continue;
            }
            printf("\nName:%s\n",name[3]);
            printf("Element:%c\n",element[3]);
            printf("HP:%d\n",HP[3]);
            printf("ATK:%d\n",ATK[3]);
            printf("DEF:%d\n",DEF[3]);
            stat[3] = ((HP[3]*1.0+ATK[3]*0.8+DEF[3]*0.5- 50)*6.5);
            printf("Power Level:%.2f\n\n",stat[3]);

            player = 4;
            break;

        case 2:// Print All Character information
            for(i=0; i<player; i++) {
                printdata(name[i],element[i],HP[i],ATK[i],DEF[i],stat[i]);
            }
            break;

        case 3:
            while (1) { //Select First Attack
                printf("Select First Attack:");
                scanf("%d",&player1);
                if(player1<1 || player1>player) {
                    printf("Error:Unknown Player\n");
                    continue;
                }
                break;
            }
            while(1) { // second Attack
                printf("Select Second Attack:");
                scanf("%d",&player2);
                if(player2<1 || player2>player) {
                    printf("Error: Unkown Player\n");
                    continue;
                } else if(player2==player1) { //Player Repeated
                    printf("Error:Player Repeated\n");
                    continue;
                }
                break;
            }
            printf("\nFirst Attack:%d  Second Attack:%d\n",player1,player2);
            printf("Battle Start\n\n");

            player1_ele= element[player1-1];//input player1 information to system
            player1_atk= ATK[player1-1];
            player1_hp= HP[player1-1];
            player1_def= DEF[player1-1];

            player2_ele= element[player2-1]; // input player2 information to system
            player2_atk= ATK[player2-1];
            player2_hp= HP[player2-1];
            player2_def= DEF[player2-1];

            switch(player1_ele) { // Critical Rate system
            case 'W':
                if(player2_ele== 'F') {
                    cr1= 1.2;
                    cr2= 0.8;
                } else if(player2_ele== 'G') {
                    cr1= 0.8;
                    cr2= 1.2;
                }
                break;
            case 'F':
                if(player2_ele== 'A') {
                    cr1= 1.2;
                    cr2= 0.8;
                } else if(player2_ele== 'W') {
                    cr1= 0.8;
                    cr2= 1.2;
                }
                break;
            case 'A':
                if(player2_ele== 'G') {
                    cr1= 1.2;
                    cr2= 0.8;
                } else if(player2_ele== 'F') {
                    cr1== 0.8;
                    cr2== 1.2;
                }
                break;
            case 'G':
                if(player2_ele== 'W') {
                    cr1= 1.2;
                    cr2= 0.8;
                } else if(player2_ele== 'A') {
                    cr1= 0.8;
                    cr2= 1.2;
                }
                break;
            } // end for the critical system
            int hl_player1 = player1_hp/2;
            int hl_player2 = player2_hp/2;

            while(player1_hp != 0 || player2_hp != 0) { // player 1 Win
                printf("Player%d Attacked Player%d\n",player1,player2);
                if(player1_hp<hl_player1) {
                    hc1= 1.2;
                } else {
                    hc1= 1;
                }
                damage=(int)(player1_atk * cr1 * hc1 - player2_def);
                printf("Damage Done:%d\n",damage);
                player2_hp -= damage;
                printf("Player%d HP:%3d Player%d HP:%3d\n\n",player1,player1_hp,player2,player2_hp);
                if(player2_hp <= 0) {
                    printf("Player%d Is Dead\n",player2);
                    printf("Battle End\n");
                    printf("Player%d WIN\n\n",player1);
                    break;
                }


                printf("Player%d Attacked Player%d\n",player2,player1); // Player 2 win
                if(player2_hp<hl_player2) {
                    hc2= 1.2;
                } else {
                    hc2= 1;
                }
                damage=(int)(player2_atk * cr2 * hc2 - player1_def);
                printf("Damage Done:%d\n",damage);
                player1_hp -= damage;
                printf("Player%d HP:%3d Player%d HP:%3d\n\n",player2,player2_hp,player1,player1_hp);
                if(player1_hp <= 0) {
                    printf("Player%d Is Dead\n",player1);
                    printf("Battle End\n");
                    printf("Player%d WIN\n\n",player2);
                    break;
                }
            }
            continue;

        case 0:
            printf("End Game\n");
            return 0;
        default:
            printf("Error:Input\n\n");

        }

    }
}






