#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int count = 0, max = 10;
    char **name;
    name = calloc(max, sizeof(char *));
    while (1) {  // �D���
        printf("1. �s�W\n");
        printf("2. �L�X\n");
        printf("3. �Ƨ�\n");
        printf("4. ���}\n");
        int select;
        printf("��J : ");
        scanf("%d%*c", &select);
        printf("\n");
        if (select == 1) {
            if (count >= max) {  // �w�]���а}�C��10�A�����ɦ۰ʸ�5��
                max += 5;
                name = realloc(name, max * sizeof(char *));
            }
            char name1[100] = {0};
            gets(name1);
            printf("\n");
            name[count] = calloc(strlen(name1)+1, sizeof(char));
            strcpy(name[count], name1);  // �N��J���r��ƻs����а}�C
            count++;
            continue;
        }
        else if (select == 2) {  // �L�X�Ҧ���J
            for (int i = 0; i < count; i++) {
                printf("%s\n", name[i]);
            }
            printf("\n");
            continue;
        }
        else if (select == 3) {  // �Ƨ�(�w�j)
            for (int i = count - 1; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if (strcmp(name[j], name[j + 1]) == 1) {
                        char *tmp = name[j];
                        name[j] = name[j + 1];
                        name[j + 1] = tmp;
                    }
                }
            }
            continue;
        }
        else if (select == 4) {  // ����O���� & ���}
            for (int i = 0; i < max; i++) {
                free(name[i]);
            }
            free(name);
            break;
        }
        else {  // �����J�W�w�H�~���ﶵ
            printf("ERROR\n\n");
            continue;
        }
    }
    return 0;
}
