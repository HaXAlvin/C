#include<stdio.h>
#include<string.h>
size_t my_strlen(const char*s){
    int count=0;
    while(count>=0){
        if( *(s+count) != '\0'){
            count++;
        }
        else {
            break;
        }
    }
    return count;
}
/* my_strlen副程式
   宣告count為0的變數
   使用 while迴圈 去比對s1中的字串
   如果s1中的字串不為'\0'，則count加1，
   如果s1中的字串有為'\0'，則停止while迴圈*/
int my_strcmp(const char*s1,const char*s2){
    int count1=0;
    int answer;
    while(count1>=0){
        if ( *(s1+count1) > *(s2+count1)){
            answer=1;
            break;
        }
        else if ( *(s1+count1) < *(s2+count1)){
            answer=-1;
            break;
        }
        else{
            count1++;
        }
        if ( (*(s1+count1)=='\0') && (*(s2+count1)=='\0')){
            answer=0;
            break;
        }
    }
    return answer;
}
/* my_strcmp副程式
   宣告count1為0的變數和answer的變數
   使用while迴圈 去比對s1和s2中字串大小
   如果s1中的字串比s2中的還小，則另answer為-1且停止while迴圈
   如果s1中的字串比s2中的還大，則另answer為1且停止while迴圈
   如果相同的話，則count1加1，繼續while迴圈，
   當s1和s2中字串都'\0'，則停止while迴圈*/
char *my_strcpy(char *s1, const char *s2){
    int count2=0;
    while(count2>=0){
        *(s1+count2)=*(s2+count2);
        if ( *(s2+count2)=='\0'){
            break;
        }
        count2++;
    }
    return s1;
}
/* my_strcp副程式
   宣告count2為0的變數
   使用while迴圈，使s1中的字串變成s2中的字串，且使count2加1
   如果s2中字串跑到的是'\0'，則停止while迴圈*/
char *my_strcat(char *s1, const char *s2){
    int count3=0;
    int count4=0;
    while(count3>=0){
        if ( *(s1+count3)!='\0'){
            count3++;
        }
        else{
            break;
        }
    }
    while(count4>=0){
        if ( *(s2+count4)!='\0'){
            *(s1+count3)=*(s2+count4);
            count3++;
            count4++;
        }
        else{
            break;
        }
    }
    return s1;
}
/* my_strcat副程式
   宣告count3和count4都為0的變數
   使用while迴圈，先去找s1中的字串第幾個是'\0'
   找到之後從那一個之後的'\0'變為s2中的字串，直到s2中的字串也跑到'\0'，
   則停止while迴圈*/
char *my_strstr(const char *s1, const char *s2){
    int count5=0;
    int count6=0;
    while( *(s1+count6)!='\0'){
        char* temp2=s1;
        char* temp3=s2;
        while( *(s1+count5)== *temp3){
            count5++;
            temp3++;
            count6++;
        }
        if(!*temp3)
            return temp2;
        s1=temp2+1;
    }
}
/* my_strstr副程式
   宣告count5和count6都為0的變數
   使用while迴圈，去比較s1和s2中的字串是否有相同
   找到像同後，將s1中相同字串的字串都印出來*/
int main(){
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];
/* 宣告a1陣列為I love dog
       b1陣列為and cat.
       c1陣列為love及d1*/
    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];
/* 宣告a2陣列為I love dog
       b2陣列為and cat.
       c2陣列為love及d2*/
//以下則是印出來
    printf("Length of a1:%d\n",strlen(a1));
    printf("My_Length of a1:%d\n",my_strlen(a1));
    printf("\n");

    printf("Strcmp of a1 and a2:%d\n",strcmp(a1,a2));
    printf("My_Strcmp of a1 and a2:%d\n",my_strcmp(a1,a2));
    printf("\n");

    printf("Strcmp of a1 and b1:%d\n",strcmp(a1,b1));
    printf("My_Strcmp of a1 and b1:%d\n",my_strcmp(a1,b1));
    printf("\n");

    printf("Strcmp of c1 and a1:%d\n",strcmp(c1,a1));
    printf("My_Strcmp of c1 and a1:%d\n",my_strcmp(c1,a1));
    printf("\n");

    printf("Strcpy of d1 and a1:%s\n",strcpy(d1,a1));
    printf("My_Strcpy of d2 and a2:%s\n",my_strcpy(d2,a2));
    printf("\n");

    printf("Strcat of d1 and b1:%s\n",strcat(d1,b1));
    printf("My_Strcat of d2 and b2:%s\n",my_strcat(d2,b2));
    printf("\n");


    printf("Strstr of d1 and c1:%s\n",strstr(d1,c1));
    printf("My_Strstr of d2 and c2:%s\n",my_strstr(d2,c2));
    printf("\n");

    return 0;
}
