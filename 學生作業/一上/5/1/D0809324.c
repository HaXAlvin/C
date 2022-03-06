#include <stdio.h>
#include <stdlib.h>


int main() {
    char char1_type = 'W'; //First Character information
    int char1_hp = 42;
    int char1_atk = 19;
    int char1_def = 7;
    float char1_pow =(char1_hp*1.0 +char1_atk*0.8 +char1_def*0.5-50)*6.5;

    char char2_type = 'A'; //Second Character information
    int char2_hp = 40;
    int char2_atk = 18;
    int char2_def = 8;
    float char2_pow =(char2_hp*1.0 +char2_atk*0.8 +char2_def*0.5-50)*6.5;

    char char3_type = 'F'; //Third Character information
    int char3_hp = 37;
    int char3_atk = 24;
    int char3_def = 7;
    float char3_pow =(char3_hp*1.0 +char3_atk*0.8 +char3_def*0.5-50)*6.5;

    char char_type; //custom Character information
    int char_hp;
    int char_pow;
    int char_atk;
    int char_def;
    int ask,first,second;


//Printed The First Character information
    printf("Character1\n"
           "Name:Tony\n"
           "Type:%c     HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char1_type,char1_hp,char1_atk,char1_def,char1_pow);


//Printed The Second Character information
    printf("Character2\n"
           "Name:Steven\n"
           "Type:%c     HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char2_type,char2_hp,char2_atk,char2_def,char2_pow);


//Printed The Third Character information
    printf("Character3\n"
           "Name:Arthur\n"
           "Type:%c     HP:%d\n"
           "ATK:%d      DEF:%d\n"
           "Power Level:%.2f\n\n",char3_type,char3_hp,char3_atk,char3_def,char3_pow);
//Asking For the Create New Character

    printf("Add A New Character? 1.Yes/2.No?");
    scanf("%d",&ask);
//Input information for new character
    if(ask==1) {
        printf("New Character\n");
        printf("Type=");
        scanf(" %c",&char_type);
        if(char_type == 'W' | char_type == 'A' | char_type == 'G' | char_type == 'F') {} // limited these character
        if(char_type =='a' | char_type =='f'| char_type =='w'|char_type == 'g') { // limited these character
            if(char_type >= 97)
                char_type = char_type - 32; //change the character to capital letter
        }
        if(char_type == 'W' | char_type == 'A' | char_type == 'G' | char_type == 'F') {}
        else {

            printf("Error : Unknown Element\n");// element judge
            return 0;
        }
        printf("Hp=");
        scanf(" %d",&char_hp);
        if(char_hp < 40 | char_hp > 50) { // hp judge
            printf("Error:HP is Out Of Range");
            return 0;
        }
        printf("ATK=");
        scanf(" %d",&char_atk);
        if(char_atk < 15 | char_atk>20) { // hp judge
            printf("Error:Attack is Out Of Range");
            return 0;
        }
        printf("DEF=");
        scanf(" %d",&char_def);
        if(char_def <5 | char_def >10) { //def judge
            printf("Error:Def Is Out Of Range");
            return 0;
        }
        int char_total = (char_hp+char_atk+char_def);
        if(char_total < 65 | char_total > 70) { // calculate the atk+def+hp = total
            printf("Error:Character Out Of Range");
            return 0;
        }
        printf("\nCharacter4\n" //Printed The custom Character information
               "Name:custom\n"
               "Type:%c     HP:%d\n"
               "ATK:%d      DEF:%d\n"
               "Power Level:%.2f",char_type,char_hp,char_atk,char_def,char_pow);// Calculate the new Character Power Level
        float char_pow = (char_hp*1.0 +char_atk*0.8 +char_def*0.5-50)*6.5;

    }

    else if(ask==2) {
        printf("Choose First Atk Character: ");
        scanf("%d",&first);  //First Attack Character
        if(first < 1 || first > 3) {
            printf("Error:Unknown First Attack Character");//input wrong first Attacker
            return 0;
        }
        printf("Choose Second Attack Character: ");
        scanf("%d",&second);//input second character
        if(second <1 || second  >3) {
            printf("Error:Unknown Second Attack Character\n");//input wrong second Attacker
            return 0;
        } else if(first == second) {
            printf("Error: Character Repeat\n");//input character repeat
            return 0;
        }
        printf("First Atk: Character:%d , Second Atk: Character:%d\n",first,second);

    } else {
        printf("Error:Input Wrong");
        return 0;
    }

    return 0;
}






