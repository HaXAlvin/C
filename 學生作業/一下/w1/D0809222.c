#include<stdio.h>
#include<string.h>

size_t my_strlen(const char *s) {
    int count = 0;
	while (s[count] != '\0') {
		count++;
	}
	
	return count;
}

int my_strcmp(const char *s1,const char *s2) {
     while (*s1 && *s1 == *s2) { 
         s1++; 
         s2++; 
    }

    return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
}

char *my_strcpy(char *s1, const char *s2) {
    int i = 0;

    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;

    // char *c = &s1[0];
    // while(*s2) *s1++ = *s2++;
    // return c;
}

char *my_strcat(char *s1, const char *s2) {
    int i = my_strlen(s1);
    int j;

    for (j = 0; s2[j] != '\0'; j++) {
        s1[i + j] = s2[j];
    }
    s1[i + j] = '\0';

    return s1;

    // int i, j;
    // for (i = 0; s1[i] != '\0'; i++);
    // for (j = 0; s2[j] != '\0'; j++) {
    //     s1[i + j] = s2[j];
    // }
    // s1[i+j] = '\0';
    // return s1;
}

char *my_strstr(const char *s1, const char *s2) {
    int stringLength;
    stringLength = my_strlen(s2);
    while (*s1) {
        if (*s1 == *s2) {
            if (!strncmp(s1, s2, stringLength)) {
                return ((char *)s1);
            }
        }
        s1++;
    }
    return (NULL);
}

int main() {
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];

    printf("Length of a1:%lu\n", strlen(a1));
    printf("My_Length of a1:%zu\n", my_strlen(a1));
    printf("\n");

    printf("Strcmp of a1 and a2:%d\n", strcmp(a1,a2));
    printf("My_Strcmp of a1 and a2:%d\n", my_strcmp(a1,a2));
    printf("\n");

    printf("Strcmp of a1 and b1:%d\n", strcmp(a1,b1));
    printf("My_Strcmp of a1 and b1:%d\n", my_strcmp(a1,b1));
    printf("\n");

    printf("Strcmp of c1 and a1:%d\n", strcmp(c1,a1));
    printf("My_Strcmp of c1 and a1:%d\n", my_strcmp(c1,a1));
    printf("\n");

    printf("Strcpy of d1 and a1:%s\n", strcpy(d1,a1));
    printf("My_Strcpy of d2 and a2:%s\n", my_strcpy(d2,a2));
    printf("\n");

    printf("Strcat of d1 and b1:%s\n", strcat(d1,b1));
    printf("My_Strcat of d2 and b2:%s\n", my_strcat(d2,b2));
    printf("\n");

    printf("Strstr of d1 and c1:%s\n", strstr(d1,c1));
    printf("My_Strstr of d2 and c2:%s\n", my_strstr(d2,c2));
    printf("\n");

    return 0;
}
