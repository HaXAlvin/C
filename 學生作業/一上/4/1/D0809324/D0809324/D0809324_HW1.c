#include <stdio.h>
#include <stdlib.h>

 int main()
 {
   char char1_type = 'W'; //First Character information
   int char1_hp = 50;
   int char1_atk = 15;
   int char1_def = 5;
   float char1_pow =(char1_hp*1.0 +char1_atk*0.8 +char1_def*0.5-50)*6.5;

   char char2_type = 'F'; //Second Character information
   int char2_hp = 23;
   int char2_atk = 11;
   int char2_def = 45;
   float char2_pow =(char2_hp*1.0 +char2_atk*0.8 +char2_def*0.5-50)*6.5;

   char char3_type = 'E'; //Third Character information
   int char3_hp = 45;
   int char3_atk = 17;
   int char3_def = 7;
   float char3_pow =(char3_hp*1.0 +char3_atk*0.8 +char3_def*0.5-50)*6.5;

   char char_type; //custom Character information
   int char_hp;
   int char_atk;
   int char_def;


//Printed The First Character information
    printf("Character1\n"
           "Name:Tony\n"
           "Type:%c      HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,char1_pow);


//Printed The Second Character information
    printf("Character2\n"
           "Name:Steven\n"
           "Type:%c      HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,char2_pow);


//Printed The Third Character information
    printf("Character3\n"
           "Name:Arthur\n"
           "Type:%c      HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,char3_pow);

//Input information for new character
    printf("New Character\n");
    printf("Type="); scanf("%c",&char_type);
    printf("Hp=");   scanf("%d",&char_hp);
    printf("ATK=");  scanf("%d",&char_atk);
    printf("DEF=");  scanf("%d",&char_def);
    float char_pow = (char_hp*1.0 +char_atk*0.8 +char_def*0.5-50)*6.5; // Calculate the new Character Power Level


//Printed The custom Character information
    printf("\nCharacter4\n"
           "Name:custom\n"
           "Type:%c      HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f",char_type,char_hp,char_atk,char_def,char_pow);





     return 0;

 }
