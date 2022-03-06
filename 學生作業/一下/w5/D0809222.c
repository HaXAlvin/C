#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    int intValue;
    float floatValue;
    char charValue[16];
} datas;
    
typedef struct {
    int dataType;
    datas value;
} listItem;

int *totalListItemsPtr;
 
void getUserInput(listItem *list);
void addItem(listItem *list);
void printItems(listItem *list);
void exitAndFreeMemory(listItem *list);
void checkActionInput(int actionCode, listItem *list);
void checkValueInput(int actionCode, listItem *list);

int main() {
    // initialize staffs
    int totalListItems = 0;
    totalListItemsPtr = &totalListItems;
    listItem *list = malloc(1 * sizeof(listItem));
    getUserInput(list);

    return 0;
}

void getUserInput(listItem *list) {
    int actionCode;

    printf("請選擇:(1.新增/2.印出/0.結束):");

    while (scanf("%d", &actionCode)) {
        checkActionInput(actionCode, list);
        if (actionCode == 1) {
            addItem(list);
        } else if (actionCode == 2) {
            printItems(list);
        } 
        // Keep looping until it hit 0
        if (actionCode == 0) {
            exitAndFreeMemory(list);
            break;
        }
        printf("請選擇:(1.新增/2.印出/0.結束):");
    }
}

void addItem(listItem *list) {
    int valueCode;  // The value code is passing as the data type of the struct

    printf("選擇類型:(1:int/2.float/3:char[16]):"); // Using 1, 2 and 3 to represent int, float and char[16]
    scanf("%d", &valueCode);
    checkValueInput(valueCode, list);
    list[*totalListItemsPtr].dataType = valueCode;

    printf("輸入資料:");

    switch (valueCode) {
        case 1:
            scanf("%d", &list[*totalListItemsPtr].value.intValue);
            break;
        case 2:
            scanf("%f", &list[*totalListItemsPtr].value.floatValue);
            break;
        case 3:
            scanf("%s", list[*totalListItemsPtr].value.charValue);
            // strcpy(list[* totalListItemsPtr].value.charValue, "abc");
            break;
    }
    *totalListItemsPtr += 1;
}

void printItems(listItem *list) {
    for (int i = 0; i < *totalListItemsPtr; i++) {
        switch (list[i].dataType) {
            case 1:
                printf("%d", list[i].value.intValue);
                break;
            case 2:
                printf("%.6f", list[i].value.floatValue);
                break;
            case 3:
                printf("%s", list[i].value.charValue);
                break;
        }
        if (i < *totalListItemsPtr) { printf("\n"); }
    }
}

void exitAndFreeMemory(listItem *list) {
    free(list);
    printf("結束程式\n");
    exit(0);
}

// Input checking functions //
void checkActionInput(int actionCode, listItem *list) {
    if (!(actionCode == 0 || actionCode == 1 || actionCode == 2)) {
        printf("輸入錯誤!\n");
        getUserInput(list);
    }
}

void checkValueInput(int valueCode, listItem *list) {
    if (!(valueCode == 1 || valueCode == 2 || valueCode == 3)) {
        printf("輸入錯誤!\n");
        addItem(list);
    }
}