#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp1(char *str1, char *str2){
    if (strcmp(str1, str2) > 0)
        return 1;
    return 0;
}

int cmp2(char *str1, char *str2){
    for (int i = 0; str1[i] || str2[i]; i++){

        if (toupper(str1[i]) > toupper(str2[i]))
            return 1;
        if (toupper(str1[i]) == toupper(str2[i])){
        	if (str1[i] > str2[i])
        		return 1;
		}

    }
    return 0;
}

void sort(char **str, int n, int (*cmp)(char *str1, char *str2)){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++){
            if (cmp (str[j], str[j+1])){
                char *temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            showString(str,n);
        }
}

void showString(char * *str, int n){
    for (int i = 0; i < n; i++)
        printf("%s\n", str[i]);
}

int main(){
    int n;
    while (1){
        printf("�п�J�r��ơ]��J0�����^:");
        scanf("%d", &n);
        if (n == 0)
            break;
        char **str;
        str = malloc(n * sizeof(char *));
        for (int i = 0; i < n; i++){
            str[i] = malloc(100 * sizeof(char));
            scanf("%s", str[i]);
        }
        printf("��ܱƧǤ覡�]1.�HASCII/2.�H�r��ǡ^: ");
        int order;
        scanf("%d", &order);
        if (order == 1)
            sort(str, n, cmp1);
        else
            sort(str, n, cmp2);
        showString(str, n);
    }
    return 0;
}
