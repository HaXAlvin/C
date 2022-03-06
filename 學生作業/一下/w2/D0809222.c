#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 30

int totalStudents = 0;
char **studentNames;

void addStudent();
void addAnotherStudent();
void displayStudentsInfo();
void sortStudentsList();
void exitAndFreeMemory();
void openSystemMenu();

int main() {
    studentNames = (char **) malloc(10 * sizeof(char));
    openSystemMenu();
    printf("\nThanks for using :)\n\n");

    return 0;
}

void addStudent() {
    int *totalStudentsPtr = &totalStudents;
    char studentName[MAX_STRING_LENGTH];

    printf("Please enter student name: ");
    fgets(studentName, MAX_STRING_LENGTH, stdin);

    studentNames[*totalStudentsPtr] = (char *) malloc(strlen(studentName) + 1);
    strcpy(studentNames[*totalStudentsPtr], studentName);

    *totalStudentsPtr += 1;
    printf("Success!\n");

    // Allocate extra five slots
    if (*totalStudentsPtr > 5 && *totalStudentsPtr % 5 == 0) {
        printf("Extre memory allocated.\n");
        studentNames = realloc(studentNames, (*totalStudentsPtr + 5) * sizeof(char));
    }

    // Add another student or return to main menu
    addAnotherStudent();
}

void addAnotherStudent() {
    int actionCode;

    printf("\n1. Add another new student\n2. Back to main menu\n\nPlease select: ");
    scanf("%d", &actionCode);
    getchar();

    switch (actionCode) {
        case 1:
            addStudent();
            break;
        case 2:
            openSystemMenu();
        default:
            break;
    }
}

void displayStudentsInfo() {
    int studentId = 1;

    printf("\n|*|*|*|*| Student List |*|*|*|*|\n\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%d. %s", studentId, studentNames[i]);
        studentId++;
    }
    openSystemMenu();
}

void sortStudentsList() {
    for (int i = 0; i < totalStudents; i++) {
        for (int j = i + 1; j < totalStudents; j++){
            if (strcmp(studentNames[i] ,studentNames[j]) > 0) {
                char *temp = studentNames[i];
                studentNames[i] = studentNames[j];
                studentNames[j] = temp;
            }
        }
    }

    // Print sorted student list and return to main menu
    printf("\nStudents list updated.\n");
    displayStudentsInfo();
}

void exitAndFreeMemory() {
    printf("\n");

    // Deallocate stored memories and display its address.
    for (int i = 0; i < totalStudents; i++) {
        free(studentNames[i]);
        //printf("123\n");
        printf("Memory at %p has been released.\n", &studentNames[i]);
    }
    free(studentNames);
}

void openSystemMenu() {
    int actionCode;

    printf("\n|*|*|*|*| System Menu |*|*|*|*|\n\n1. Add new student\n2. Display all students\n3. Sort student list\n0. Exit\n\nPlease select: ");
    scanf("%d", &actionCode);
    getchar();

    switch (actionCode) {
        case 0:
            exitAndFreeMemory();
            return;
            break;
        case 1:
            addStudent();
            break;
        case 2:
            displayStudentsInfo();
            break;
        case 3:
            sortStudentsList();
            break;
        default:
            break;
    }
}

// int compareString(const void *stringA, const void *stringB ) {
//     return strcmp(*(const char **)stringA, *(const char **)stringB);
// }
