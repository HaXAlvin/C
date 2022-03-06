#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int a,sem1,sem2,sem3,sem4,sem5,sem6,sem7,sem8;

    a = 0b11111111;
    a = a&0b0000001;
    a = a << 1;
    a = ~a;
    a = a << 2;
    a = ~a;
    a = a << 1;
    a = ~a;
    a = a << 1;
    a = ~a;
    a = a << 1;
    a = ~a;
    a = a << 1;
    a = ~a;

    sem1 = a >> 7;
    sem2 = a >> 6;
    sem2 = sem2&0b00000001;
    sem3 = a >> 5;
    sem3 = sem3&0b00000001;
    sem4 = a >> 4;
    sem4 = sem4&0b00000001;
    sem5 = a >> 3;
    sem5 = sem5&0b00000001;
    sem6 = a >> 2;
    sem6 = sem6&0b00000001;
    sem7 = a >> 1;
    sem7 = sem7&0b00000001;
    sem8 = a&0b00000001;

    printf("1st Semester = %d\n",sem1);
    printf("2nd Semester = %d\n",sem2);
    printf("3rd Semester = %d\n",sem3);
    printf("4th Semester = %d\n",sem4);
    printf("5th Semester = %d\n",sem5);
    printf("6th Semester = %d\n",sem6);
    printf("7th Semester = %d\n",sem7);
    printf("8th Semester = %d",sem8);

    return 0;
}
 end;
