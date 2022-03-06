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

    //¨¤¦â4
    /*printf("New Character \n"
           "type=\n"
           "HP=\n"
           "ATK=\n"
           "DEF=\n\n");
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    scanf("%c",&char4_type);
    scanf("%d",&char4_hp);
    scanf("%d",&char4_atk);
    scanf("%d",&char4_def);
    printf("character4 \n"
           "Kevin \n"
           "type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n\n",char4_type,char4_hp,char4_atk,char4_def);*/

    //Answer 答案
    char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    printf("New Character \n");
    printf("Type=");   scanf("%c",&char4_type);
    printf("HP=");     scanf("%d",&char4_hp);
    printf("ATK=") ;   scanf("%d",&char4_atk);
    printf("DEF=") ; scanf("%d",&char4_def);
    float power4 = ( char4_hp * 1.0 + char4_atk * 0.8 + char4_def * 0.5 - 50 ) * 6.5;

    printf("\nCharacter4 \n"
           "Kevin \n"
           "Type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n"
           "Power Level= %.2f\n\n",char4_type,char4_hp,char4_atk,char4_def,power4);

    /*char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    printf("New Character \n");
    printf("type=\n", scanf("%c",&char4_type));
    printf("HP=\n",scanf("%d",&char4_hp));
    printf("ATK=\n", scanf("%d",&char4_atk)) ;
    printf("DEF=\n\n",scanf("%d",&char4_def)) ;

    printf("\ncharacter4 \n"
           "Kevin \n"
           "type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n\n",char4_type,char4_hp,char4_atk,char4_def);*/

    /*char char4_type;
    int char4_hp;
    int char4_atk;
    int char4_def;
    printf("New Character \n");
    printf("type=\n");
    printf("HP=\n");
    printf("ATK=\n") ;
    printf("DEF=\n\n" ) ;
    scanf("%c",&char4_type);
    scanf("%d",&char4_hp);
    scanf("%d",&char4_atk);
    scanf("%d",&char4_def);
    printf("\ncharacter4 \n"
           "Kevin \n"
           "type=%c     HP=%d \n"
           "ATK=%d     DEF=%d\n\n",char4_type,char4_hp,char4_atk,char4_def);*/


    return 0;
 }
