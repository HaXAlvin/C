#include<stdio.h>
#include<stdlib.h>
 int main ()
 {
    //Character 1
    char char1_type = 'W';
    int char1_hp = 47;
    int char1_atk = 17;
    int char1_def = 6;
    float power1 = ( char1_hp * 1.0 + char1_atk * 0.8 + char1_def * 0.5 - 50 ) * 6.5;
    printf("Character1 \n"
           "Joko \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,power1);

    //Character 2
    char char2_type = 'F';
    int char2_hp = 43;
    int char2_atk = 19;
    int char2_def = 5;
    float power2 = ( char2_hp * 1.0 + char2_atk * 0.8 + char2_def * 0.5 - 50 ) * 6.5;
    printf("Character2 \n"
           "Bodo \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,power2);

    //Character 3
    char char3_type = 'G';
    int char3_hp = 45;
    int char3_atk = 16;
    int char3_def = 8;
    float power3 = ( char3_hp * 1.0 + char3_atk * 0.8 + char3_def * 0.5 - 50 ) * 6.5;
    printf("Character3 \n"
           "Amat \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,power3);

     //Answer 答案
    char char4_type;
    char c1[25] ="Character 1";
    char c2[25] ="Character 2";
    char c3[25] ="Character 3";
    char c4[25] ="Character 4";
    char first_atk[25];
    char second_atk[25];
    int char4_hp;
    int char4_atk;
    int char4_def;
    int counter = 0;
    int ask;
    int first, second;
    int hit1, hit2, def1, def2, hp1, hp2, dmg1, dmg2;


    sequence:
    printf("Do you want to make a new character? 1 Yes / 2 NO\n");// asking do they want a new character
    scanf("%d",&ask);
    if (ask == 1)
    {
        counter = counter+1; //to determine whether character 4 exist or not
        printf("New Character \n");
        printf("Type=");
        scanf(" %c",&char4_type); // type input
        if (char4_type == 0b01100110) // change small case character to upper case character
            char4_type = 0b01000110;
        else if (char4_type == 0b01110111)
            char4_type = 0b01010111;
        else if (char4_type == 0b01100111)
            char4_type = 0b01000111;
        else if (char4_type == 0b01100001) // 'f'
            char4_type = 0b01000001; // 'F'
        else if (char4_type == 0b01000110 || 0b01010111 ||  0b01000111 ||  0b01000001)
        {
            goto skip;
        }
        else
        {
            printf("This type is not available\n");
            return 0;
        }


        skip:
        printf("HP="); // HP input
        scanf("%d",&char4_hp);
        if (char4_hp < 40 | char4_hp > 51) // check HP status
           {
                printf("HP must be 40~50\n");
                return 0;
           }

        printf("ATK=") ; // ATK input
        scanf("%d",&char4_atk);
        if (char4_atk < 15 | char4_atk > 21) // check ATK status
            {
                printf("ATK must be 15~20\n");
                return 0;
            }

        printf("DEF=") ; // DEF input
        scanf("%d",&char4_def);
        if (char4_def < 5 | char4_def > 11) // check DEF status
            {
               printf("DEF must be 5~10\n");
                return 0;
            }


        float power4 = ( char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5; // power calculation

        printf("\nCharacter4 \n"
            "Kevin \n"
            "Type=%c     HP=%d \n"
            "ATK=%d     DEF=%d\n"
            "Power Level= %.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,power4); // output

         goto atk_seq;

    }
    else if (ask == 2)
    {
        atk_seq:
            printf("First attack = ");
            scanf("%d",&first);

                    switch(first) //to assign the string to var first_atk
                        {
                            case 1:
                                strcpy(first_atk,c1);
                                dmg1 = char1_atk;
                                def1 = char1_def;
                                hp1 = char1_hp;
                                break;
                            case 2:
                                strcpy(first_atk,c2);
                                dmg1 = char2_atk;
                                def1 = char2_def;
                                hp1 = char2_hp;
                                break;
                            case 3:
                                strcpy(first_atk,c3);
                                dmg1 = char3_atk;
                                def1 = char3_def;
                                hp1 = char3_hp;
                                break;
                            case 4:
                                if (counter==1)
                                {
                                    strcpy(first_atk,c4);
                                    dmg1 = char4_atk;
                                    def1 = char4_def;
                                    hp1 = char4_hp;
                                    break;
                                }
                                else
                                {
                                    printf("Character doesn't exist");
                                    return 0;
                                    break;
                                }
                            default:
                                printf("Character doesn't exist");
                                return 0;
                                break;
                        }
            printf("Second attack = ");
            scanf("%d",&second);
                    switch(second) //to assign the string to var second_atk
                        {
                            case 1:
                                strcpy(second_atk,c1);
                                dmg2 = char1_atk;
                                def2 = char1_def;
                                hp2 = char1_hp;
                                break;
                            case 2:
                                strcpy(second_atk,c2);
                                dmg2 = char2_atk;
                                def2 = char2_def;
                                hp2 = char2_hp;
                                break;
                            case 3:
                                strcpy(second_atk,c3);
                                dmg2 = char3_atk;
                                def2 = char3_def;
                                hp2 = char3_hp;
                                break;
                            case 4:
                                 if (counter==1)
                                {
                                    strcpy(second_atk,c4);
                                    dmg2 = char4_atk;
                                    def2 = char4_def;
                                    hp2 = char4_hp;
                                    break;
                                }
                                else
                                {
                                    printf("Character doesn't exist");
                                    return 0;
                                    break;
                                }
                            default:
                                printf("Character doesn't exist");
                                return 0;
                                break;
                        }

        if (first == second)
        {
            printf("Cannot be the same");
        }
        else
        {
            printf("First to attack %s, Second to attack %s\n",first_atk ,second_atk );
        }

        hit1= dmg1-def2;
        hit2= dmg2-def1;
        while (hp1>0 && hp2>0)
        {
            hp1 = hp1-hit2;
            printf("%s attack %s, %d damage!\n",first_atk,second_atk,hit1);
            printf("%s HP = %d, %s HP= %d\n\n",first_atk,hp1,second_atk,hp2);

            if (hp1>0 && hp2>0)
            {
                 hp2 = hp2-hit1;
                printf("%s attack %s, %d damage!\n",second_atk,first_atk,hit2);
                printf("%s HP = %d, %s HP= %d\n\n",first_atk,hp1,second_atk,hp2);
            }

        }

        if (hp1<=0)
        {
            printf("%s have been defeated",first_atk);
        }
        else if (hp2<=0)
        {
            printf("%s have been defeated",second_atk);
        }


    }
    else if (ask > 2)
    {
        printf("This option is not available\n");
        goto sequence;
    }
    return 0;
 }
