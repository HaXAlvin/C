#include <stdio.h>
#include <stdlib.h>
typedef struct _value{
    union _data{
        int n;
        float f;
        char c[16];
    }data;
    enum _type{
        INT,
        FLOAT,
        STRING
    }type;
}value;
typedef value *value_ptr;
int count = 0, n = 0;
value_ptr getData(value_ptr list, char t){
    list = list == NULL ? malloc(sizeof(value)) : realloc(list, (count + 1) * sizeof(value));
    if (t == 'i')
        list[count].type = INT, scanf("%d", &list[count].data.n);
    else if (t == 'f')
        list[count].type = FLOAT, scanf("%f", &list[count].data.f);
    else if  (t == 's')
        list[count].type = STRING, scanf("%s", list[count].data.c);
    return list;
}
int main(){
    char c = 'i';
    value_ptr list = NULL;
    while (printf("選擇：（1.新增/2.印出/0.離開）： ")&& scanf("%d", &n)){
        getchar();
        if (n == 1){
            do{
                if (c != 'i' && c != 'f' && c != 's' )
                    printf("輸入錯誤!\n");
                printf("選擇類型：（i: int/f: float/s: char[16]): ");
                scanf("%c", &c);
                getchar();
            } while (c != 'i' && c != 'f' && c != 's');
            printf("輸入資料： ");
            list = getData(list, c);
            count++;
        }
        else if (n == 2)
            for (int i = 0; i < count; i++)
                list[i].type == INT ? printf("%d\n", list[i].data.n) : list[i].type == FLOAT ? printf("%f\n", list[i].data.f) : printf("%s\n", list[i].data.c);

        else if (n == 0){
            printf("結束程式\n");
            free(list);
            break;
        }
        else
            printf("輸入錯誤!\n");
    }
    return 0;
}
