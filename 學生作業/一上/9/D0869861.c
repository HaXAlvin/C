#include<stdio.h>
#include<stdlib.h>

int EditNewChar (char newchar4_type, int newchar4_hp,int newchar4_atk,int newchar4_def) {
    //char newchar4_type;
    int indi;
    int char4_hp;
    int char4_atk;
    int char4_def;
    float newpower4;
//        int counter = 1; //to determine whether character 4 exist or not
    printf("New Character \n");
    indi=1;
    while (indi==1) {
        printf("Type=");
        scanf(" %c",&newchar4_type); // type input
        if (newchar4_type == 0b01100110) { // change small case character to upper case character
            newchar4_type = 0b01000110;
            indi=0;
        } else if (newchar4_type == 0b01110111) {
            newchar4_type = 0b01010111;
            indi=0;
        } else if (newchar4_type == 0b01100111) {
            newchar4_type = 0b01000111;
            indi=0;
        } else if (newchar4_type == 0b01100001) { // 'f'
            newchar4_type = 0b01000001; // 'F'
            indi=0;
        } else if (newchar4_type == 0b01000110 || newchar4_type == 0b01010111 || newchar4_type == 0b01000111 || newchar4_type == 0b01000001) {
            indi=0;
        } else {
            printf("This type is not available\n");
            indi=1;
        }
    }

    indi=1;
    while (indi==1) {
        printf("HP="); // HP input
        scanf("%d",&newchar4_hp);
        char4_hp=newchar4_hp;
        if (char4_hp < 40 | char4_hp > 51) { // check HP status
            printf("HP must be 40~50\n");
            indi=1;
        } else {
            indi=0;
        }
    }

    indi=1;
    while (indi==1) {
        printf("ATK=") ; // ATK input
        scanf("%d",&newchar4_atk);
        char4_atk=newchar4_atk;
        if (char4_atk < 15 | char4_atk > 21) { // check ATK status
            printf("ATK must be 15~20\n");
            indi=1;
        } else {
            indi=0;
        }
    }

    indi=1;
    while (indi==1) {
        printf("DEF=") ; // DEF input
        scanf("%d",&newchar4_def);
        char4_def=newchar4_def;
        if (char4_def < 5 | char4_def > 11) { // check DEF status
            printf("DEF must be 5~10\n");
            indi=1;
        } else {
            indi=0;
        }
    }


    newpower4 = ( newchar4_hp * 1.0 + newchar4_atk * 0.8 + newchar4_def * 0.5 - 50 ) * 6.5; // power calculation

    printf("\nCharacter4 \n"
           "Kevin \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",newchar4_type,newchar4_hp,newchar4_atk,newchar4_def,newpower4); // output

    return EditNewChar;
}

int PrintCharData (int newchar4_type, int newchar4_hp,int newchar4_atk,int newchar4_def, float newpower4,int counter) {
    int char1_hp = 47,char1_atk = 17,char1_def = 6;
    int char2_hp = 43,char2_atk = 19,char2_def = 5;
    int char3_hp = 45,char3_atk = 16,char3_def = 8;
    int *char4_hp,*char4_atk,*char4_def;
    char char1_type = 'W',char2_type = 'F',char3_type = 'G',*char4_type;
    float power1, power2, power3,*power4;

//        char4_type= &newchar4_type;
//        char4_hp= &newchar4_hp;
//        char4_atk= &newchar4_atk;
//        char4_def= &newchar4_def;
//        power4= &newpower4;

    power1 = ( char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    printf("Character1 \n"
           "Joko \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,power1);

    //Character 2
    power2 = ( char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    printf("Character2 \n"
           "Bodo \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,power2);

    //Character 3
    power3 = ( char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    printf("Character3 \n"
           "Amat \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,power3);

    if (counter>=1) {
        printf("\nCharacter4 \n"
               "Kevin \n"
               "Type=%c     HP=%d \n"
               "ATK=%d     DEF=%d\n"
               "Power Level= %.2f\n\n",newchar4_type,newchar4_hp,newchar4_atk,newchar4_def,newpower4); // output

    }
}

int Battling (int dmg1, int dmg2,int hp1, int hp2,int halfhp1, int halfhp2,int def1,int def2,char first_atk[25], char second_atk[25], char type1,char type2) {

    float mod1,mod2,hit1,hit2,bloodmod1=1,bloodmod2=1;

    if (type1=='W' && type2=='F' || type1=='F' && type2=='A' || type1=='A' && type2=='G' || type1=='G' && type2=='W'  ) {
        mod1=1.2;
        mod2=0.8;
    } else if (type2=='W' && type1=='F' || type2=='F' && type1=='A' || type2=='A' && type1=='G' || type2=='G' && type1=='W'  ) {
        mod2=1.2;
        mod1=0.8;
    } else if (type1==type2) {
        mod1=1;
        mod2=1;
    }

    hit1= dmg1*mod1;
    hit2= dmg2*mod2;
    while (hp1>0 && hp2>0) {
        if (hp2<halfhp2) {
            bloodmod2=1.2;
        } else if (hp1<halfhp1) {
            bloodmod1=1.2;
        }
        hp1 = hp1-(hit2*bloodmod2)+def1;
        printf("%s attack %s, %.1f damage!\n",first_atk,second_atk,hit1);
        printf("%s HP = %d, %s HP= %d\n\n",first_atk,hp1,second_atk,hp2);

        if (hp1>0 && hp2>0) {
            hp2 = hp2-(hit1*bloodmod1)+def2;
            printf("%s attack %s, %.1f damage!\n",second_atk,first_atk,hit2);
            printf("%s HP = %d, %s HP= %d\n\n",first_atk,hp1,second_atk,hp2);
        }
    }

    if (hp1<=0) {
        printf("%s have been defeated\n",first_atk);
    } else if (hp2<=0) {
        printf("%s have been defeated\n",second_atk);
    }

    return Battling;

}

int SelectAndBattle (char newchar4_type,int char4_hp, int char4_atk, int char4_def,int counter) {
    //int Battling();
    int indicator1=1,indicator2=1,first,second;
    char c1[25] ="Character 1";
    char c2[25] ="Character 2";
    char c3[25] ="Character 3";
    char c4[25] ="Character 4";
    char first_atk[25],second_atk[25];
    char type1,type2;
    int def1, def2, hp1, hp2, dmg1, dmg2, halfhp1, halfhp2;
    char char1_type = 'W',char2_type = 'F',char3_type = 'G';
    int char1_hp = 47,char1_atk = 17,char1_def = 6;
    int char2_hp = 43,char2_atk = 19,char2_def = 5;
    int char3_hp = 45,char3_atk = 16,char3_def = 8;

    while (indicator1==1) {
        printf("First attack = ");
        scanf("%d",&first);

        switch(first) { //to assign the string to var first_atk
        case 1:
            strcpy(first_atk,c1);
            type1 = 'W';
            dmg1 = char1_atk;
            def1 = char1_def;
            hp1 = char1_hp;
            indicator1=0;
            halfhp1=0.5*hp1;
            break;
        case 2:
            strcpy(first_atk,c2);
            type1 = 'F';
            dmg1 = char2_atk;
            def1 = char2_def;
            hp1 = char2_hp;
            halfhp1=0.5*hp1;
            indicator1=0;
            break;
        case 3:
            strcpy(first_atk,c3);
            dmg1 = char3_atk;
            type1 = 'G';
            def1 = char3_def;
            hp1 = char3_hp;
            halfhp1=0.5*hp1;
            indicator1=0;
            break;
        case 4:
            if (counter==1) {
                strcpy(first_atk,c4);
                type1 = newchar4_type;
                dmg1 = char4_atk;
                def1 = char4_def;
                hp1 = char4_hp;
                halfhp1=0.5*hp1;
                indicator1=0;
                break;
            } else {
                printf("Character doesn't exist\n");
                indicator1=1;
                break;
            }
        default:
            printf("Character doesn't exist\n");
            indicator1=1;
            break;
        }
    }

    while (indicator2==1) {
        printf("Second attack = ");
        scanf("%d",&second);
        while (first == second) {
            printf("Cannot be the same\n");
            printf("Second attack = ");
            scanf("%d",&second);
        }
        switch(second) { //to assign the string to var second_atk
        case 1:
            strcpy(second_atk,c1);
            type2 = 'W';
            dmg2 = char1_atk;
            def2 = char1_def;
            hp2 = char1_hp;
            halfhp2=0.5*hp2;
            indicator2=0;
            break;
        case 2:
            strcpy(second_atk,c2);
            type2 = 'F';
            dmg2 = char2_atk;
            def2 = char2_def;
            hp2 = char2_hp;
            halfhp2=0.5*hp2;
            indicator2=0;
            break;
        case 3:
            strcpy(second_atk,c3);
            type2 = 'G';
            dmg2 = char3_atk;
            def2 = char3_def;
            hp2 = char3_hp;
            halfhp2=0.5*hp2;
            indicator2=0;
            break;
        case 4:
            if (counter==1) {
                strcpy(second_atk,c4);
                type2 = newchar4_type;
                dmg2 = char4_atk;
                def2 = char4_def;
                hp2 = char4_hp;
                halfhp2=0.5*hp2;
                indicator2=0;
                break;
            } else {
                printf("Character doesn't exist\n");
                indicator2=1;
                break;
            }
        default:
            printf("Character doesn't exist\n");
            indicator2=1;
            break;
        }
    }
    printf("First to attack %s, Second to attack %s\n",first_atk,second_atk );

    indicator1=1;
    indicator2=1;
    Battling (dmg1,dmg2,hp1,hp2,halfhp1,halfhp2,def1,def2,first_atk,second_atk,type1,type2);

    return SelectAndBattle;

}



int main () {
    //Answer 答案
    char char4_type,newchar4_type;
    int char4_hp,newchar4_hp;
    int char4_atk,newchar4_atk;
    int char4_def,newchar4_def;
    int counter=0;
    int ask,option,indicator1=1,indicator2=1,indi;
    int first, second;
    float newpower4;

    printf("(1) Add or modify new role, (2) Display all role data, (3) Fight, (0)End Game\n");
    while (scanf("%d",&option)!=EOF) {


        switch (option) {
        case 1: //Add or modify new role
            EditNewChar(newchar4_type,newchar4_hp,newchar4_atk,newchar4_def);
            counter = 1; //to determine whether character 4 exist or not
            break;
        case 2: //Display all role data
            PrintCharData(newchar4_type,newchar4_hp,newchar4_atk,newchar4_def,newpower4,counter);
            break;

        case 3: //Fight
            SelectAndBattle (newchar4_type,char4_hp,char4_atk,char4_def,counter);
            break;

        case 0: //End Game
            return 0;
            break;

        default:
            printf("No such option!\n");
            break;
        }
        printf("(1) Add or modify new role, (2) Display all role data, (3) Fight, (0)End Game\n");
    }
}
