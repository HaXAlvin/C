#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
	int i=0;
	while(s[i] != '\0'){
		i++;
	}
	return i;
}


int my_strcmp(const char*s1,const char*s2){
	if(*s1 == *s2){
		return 0;
	}
	else if(*s1 > *s2){
		return 1;
	}
	else{
		return -1;
	}

}

char *my_strcpy(char *s1, const char *s2){
	int i=0;
	while(s2[i] != '\0'){
		s1[i] = s2[i];
		i++;
	}
	s1[i] ='\0';
	return s1;
}

char *my_strcat(char *s1, const char *s2){
	int p=0, q;
	while(s1[p] != '\0'){
		p++;
	}
	for (q = 0; s2[q] != '\0'; q++)
 	{
 		s1[p+q] = s2[q];
 	}
 	s1[p+q] = '\0';
 	return s1;
}


char *my_strstr(const char *s1, const char *s2){
	int i=0,j=0;
	for(i=0;s1[i] != '\0';i++){
		if(s1[i] == s2[j]){
			while(s1[i++] == s2[j++]){
				if(s2[j] == '\0')
					return (char*)&s1[i-j];
			}
		}
	}
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
