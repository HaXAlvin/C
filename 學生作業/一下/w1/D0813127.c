#include<stdio.h>
#include<string.h>

size_t my_strlen(const char* s)
{
    int count = 0;
    char tmp = *s;
    while (1) {  // 利用count當計數器讀到終止符號就回傳
        if (tmp == '\0') {
            return count;
        }
        count++;
        tmp = s[count];
    }
}

int my_strcmp(const char* s1, const char* s2)
{
    int count = 0;
    while (1) {
        if (s1[count] == '\0' && s2[count] == '\0') {  // 剛好同時結束且都沒有不同回傳0
            return 0;
        }
        if (s1[count] != s2[count]) {  // 逐個比較 遇到不同時比大小
            int a1 = s1[count], a2 = s2[count];  // s1大回傳1 s2大回傳-1
            if (a1 > a2) {
                return 1;
            }
            else {
                return -1;
            }
        }
        count++;
    }
}

char* my_strcpy(char* s1, const char* s2)
{
    int count = 0;
    while (1) {  // 將s2整個複製過去
        s1[count] = s2[count];
        if (s2[count] == '\0') {
            return s1;
        }
        count++;
    }
}

char* my_strcat(char* s1, const char* s2)
{
    int count = 0, len = my_strlen(s1);  // 先判斷s1長度 從最後一位直接補上s2
    while (1) {
        s1[len] = s2[count];
        if (s1[len] == '\0') {
            return s1;
        }
        count++;
        len++;
    }
}

char* my_strstr(const char* s1, const char* s2)
{
    int count = 0, num = 0, point, flag = 0, error = 0, memer;
    for (int i = 0; i < my_strlen(s1); i++) {
        if (s2[num] == s1[i]) {
            if (flag == 0) {
                point = i;  // 紀錄第一個相同單字的位置
                flag = 1;
                memer = i;
            }
            if (flag == 1 && i - 1 != memer && num != 0) {  // 判斷是否為連續的
                error = 1;
            }
            num++;
            memer = i;
        }
    }
    char str[100] = {0};  // 利用新的指標陣列存取需要的片段並回傳
    char* ptr = str;
    for (int i = point, j = 0; i < my_strlen(s1); i++, j++) {
        ptr[j] = s1[i];
    }
    if (num == my_strlen(s2) && error == 0) {
        return ptr;
    }
    else {
        return NULL;
    }
}

int main()
{
    char a1[20] = "I love dog ";
    char b1[20] = "and cat.";
    char c1[20] = "love";
    char d1[20];

    char a2[20] = "I love dog ";
    char b2[20] = "and cat.";
    char c2[20] = "love";
    char d2[20];

    printf("Length of a1:%d\n", strlen(a1));
    printf("My_Length of a1:%d\n", my_strlen(a1));
    printf("\n");

    printf("Strcmp of a1 and a2:%d\n", strcmp(a1, a2));
    printf("My_Strcmp of a1 and a2:%d\n", my_strcmp(a1, a2));
    printf("\n");

    printf("Strcmp of a1 and b1:%d\n", strcmp(a1, b1));
    printf("My_Strcmp of a1 and b1:%d\n", my_strcmp(a1, b1));
    printf("\n");

    printf("Strcmp of c1 and a1:%d\n", strcmp(c1, a1));
    printf("My_Strcmp of c1 and a1:%d\n", my_strcmp(c1, a1));
    printf("\n");

    printf("Strcpy of d1 and a1:%s\n", strcpy(d1, a1));
    printf("My_Strcpy of d2 and a2:%s\n", my_strcpy(d2, a2));
    printf("\n");

    printf("Strcat of d1 and b1:%s\n", strcat(d1, b1));
    printf("My_Strcat of d2 and b2:%s\n", my_strcat(d2, b2));
    printf("\n");


    printf("Strstr of d1 and c1:%s\n", strstr(d1, c1));
    printf("My_Strstr of d2 and c2:%s\n", my_strstr(d2, c2));
    printf("\n");

    return 0;
}
