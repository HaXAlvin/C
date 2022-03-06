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
/* my_strlen�Ƶ{��
   �ŧicount��0���ܼ�
   �ϥ� while�j�� �h���s1�����r��
   �p�Gs1�����r�ꤣ��'\0'�A�hcount�[1�A
   �p�Gs1�����r�꦳��'\0'�A�h����while�j��*/
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
/* my_strcmp�Ƶ{��
   �ŧicount1��0���ܼƩManswer���ܼ�
   �ϥ�while�j�� �h���s1�Ms2���r��j�p
   �p�Gs1�����r���s2�����٤p�A�h�tanswer��-1�B����while�j��
   �p�Gs1�����r���s2�����٤j�A�h�tanswer��1�B����while�j��
   �p�G�ۦP���ܡA�hcount1�[1�A�~��while�j��A
   ��s1�Ms2���r�곣'\0'�A�h����while�j��*/
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
/* my_strcp�Ƶ{��
   �ŧicount2��0���ܼ�
   �ϥ�while�j��A��s1�����r���ܦ�s2�����r��A�B��count2�[1
   �p�Gs2���r��]�쪺�O'\0'�A�h����while�j��*/
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
/* my_strcat�Ƶ{��
   �ŧicount3�Mcount4����0���ܼ�
   �ϥ�while�j��A���h��s1�����r��ĴX�ӬO'\0'
   ��줧��q���@�Ӥ��᪺'\0'�ܬ�s2�����r��A����s2�����r��]�]��'\0'�A
   �h����while�j��*/
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
/* my_strstr�Ƶ{��
   �ŧicount5�Mcount6����0���ܼ�
   �ϥ�while�j��A�h���s1�Ms2�����r��O�_���ۦP
   ��칳�P��A�Ns1���ۦP�r�ꪺ�r�곣�L�X��*/
int main(){
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];
/* �ŧia1�}�C��I love dog
       b1�}�C��and cat.
       c1�}�C��love��d1*/
    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];
/* �ŧia2�}�C��I love dog
       b2�}�C��and cat.
       c2�}�C��love��d2*/
//�H�U�h�O�L�X��
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
