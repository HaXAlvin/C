#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
	//設定參數
	int count = 0;
	int i;
	//用迴圈判斷字串長度並記數
	for(i = 0; s[i] != 0; i++)
	{
		count++;
	}
	//回傳記數值
	return count;
}

int my_strcmp(const char*s1,const char*s2){
	//設定變數
	int i;
	//利用迴圈先判斷兩字串是否為'\0'， 再判斷兩字串是否相同
	for(i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if(s1[i] == s2[i])
		{
			continue;
		}
		else
		{
			break;
		}
	}
	//回傳計算的值
	return s1[i] - s2[i];

}

char *my_strcpy(char *s1, const char *s2){
	//設定變數
	int i = 0;
	// 若字串不等於'\0'則複製各個字串字元到第二個字串中
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	//新增字串'\0'
	s1[i] = '\0';
	//回傳複製完新的字串
	return s1;
}

char *my_strcat(char *s1, const char *s2){
	//設定變數
	int i,j;
	//先判斷第一個字串是否為'\0'
	for (i = 0; s1[i] != '\0'; i++);

    //在判斷第二個字串是否為'\0' 並連接起字串
    for (j = 0; s2[j] != '\0'; j++)
        s1[i+j] = s2[j];
    s1[i+j] = '\0';
    //回傳連結完的字串
    return s1;

}


char *my_strstr(const char *s1, const char *s2){
	//設定變數
	char* ns1 = (char*)s1;
	char* ns2 = (char*)s2;

	while(*ns1)
	{
		//設定flag回傳
		char* flag = ns1;
		//比較兩字串，若相等則往下比較
		while((*ns1 == *ns2) && (*ns1 != '\0'))
		{
			ns1++;
			ns2++;
		}
		//可能發生的三種情況
		//ns2已到'\0
		if(!*ns2)
		{
			//返回flag
			return flag;
		}
		//ns1已到'\0 ns2沒有
		if(!*ns1)
		{
			return NULL;
		}
		//都沒有相符，繼續往下
		ns1++;
	}
	//回傳值
	return NULL;
}

int main(){
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];

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
