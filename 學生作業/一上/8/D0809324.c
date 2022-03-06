#include <stdio.h>
#include <stdlib.h>


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
    int player_1,player_2;


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

            player == 4;
            break;

        case 2:// Print All Character information
            for(i=0; i<player; i++) {
                stat[i] = ((HP[i]*1.0+ATK[i]*0.8+DEF[i]*0.5- 50)*6.5);
                printf("\nName:%s\nElement:%c\nHP:%d\nATK:%d\nDEF:%d\nPower Level:%.2f\n\n",name[i],element[i],HP[i],ATK[i],DEF[i],stat[i]);
            }
            break;


        }
    }



}






