#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp1(char *stringA, char *stringB);
int cmp2(char *stringA, char *stringB);
int leave(char *stringA, char *stringB); //離開
void sort(char **stringArray, int totalStrings, int (*cmp)(char[], char[]));
void exitAndFreeMemory(char **Strings, int numberOfStrings);

int actionCode, sortingCode, numberOfStrings, result;

int main() {
    int (*sortMethods[3]) (char a[], char b[]) = {leave, cmp1, cmp2};
    char instructionString[] = "請輸入字串數（輸入0結束):";
    char inputString[] = "";
    

    printf("%s", instructionString);

    while (scanf("%d", &numberOfStrings)) {
        getchar();
        if (numberOfStrings == 0) {
            printf("離開\n");
            break;
        }

        char **sArr = malloc(numberOfStrings * sizeof(char *));

        for (int i = 0; i < numberOfStrings; i++) {
            fgets(inputString, 100, stdin); 
            sArr[i] = (char *) malloc(strlen(inputString) + 1);
            strcpy(sArr[i], inputString);
        }

        printf("選擇排序方式(1. 以ASCII/2. 以字典序):");
        scanf("%d", &sortingCode);
        sort(sArr, numberOfStrings, sortMethods[sortingCode]);

        for (int j = 0; j < numberOfStrings; j++) {
            printf("%s", sArr[j]);
        }
        printf("請輸入字串數（輸入0結束):");
        // printf("%s", instructionString);
        exitAndFreeMemory(sArr, numberOfStrings);
    }
    return 0;
}

// ASCII
int cmp1(char *stringA, char *stringB) {
    return strcmp(stringA ,stringB);
}

// 字典序
int cmp2(char *stringA, char *stringB) {
    int stringLength = 0;
    
    if (strlen(stringA) >= strlen(stringB)) {
        stringLength = strlen(stringB);
    } else { 
        stringLength = strlen(stringA);
    }

    for (int i = 0; i < stringLength; i++) {
        if (isupper(stringA[i]) && isupper(stringB[i])) {
            if (stringA[i] > stringB[i]) {
                return 1;
            } else { continue; }
        }

        if ((isupper(stringA[i]) && islower(stringB[i])) || (islower(stringA[i]) && isupper(stringB[i]))) {
            if (tolower(stringA[i]) > tolower(stringB[i])) {
                return 1;
            } else { continue; }
        }
    }
    return 0;
}

int leave(char *stringA, char *stringB) {
    return 0;
}

void sort(char **stringArray, int totalStrings, int (*cmp)(char[], char[])) {
    for (int i = 0; i < totalStrings - 1; i++) {
        for (int j = 0; j < totalStrings - i - 1; j++) {
            if (cmp(stringArray[j], stringArray[j + 1]) > 0) {
                char *temp = stringArray[j];
                stringArray[j] = stringArray[j + 1];
                stringArray[j + 1] = temp;
            }
        }
    }
}

void exitAndFreeMemory(char **Strings, int numberOfStrings) {
    for (int i = 0; i < numberOfStrings; i++) {
        free(Strings[i]);
        // printf("Memory at %p has been released.\n", &Strings[i]);
    }
    free(Strings);
}