#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    //�]���ܼ�
    char **firstArr,*tmp;
    int n = 10, choice, num = 0, i, j, ans;
    char a[100] = {0};
    firstArr = malloc(n * sizeof(char **));//�@��
    printf("�ǥͩm�W�n�O�t��\n");

    while(1){
        printf("1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
        scanf("%d", &choice);
        getchar();
        if(choice == 1){
            gets(a);
            firstArr[num] = calloc(strlen(a) + 1, sizeof(char));//�t�m�G��
            strcpy(firstArr[num], a);//�N�r���x�s
            num ++;
            if(num == n){
                n + 5;
            }
        }
        else if(choice == 2){
            for(i = 0; i < num; i ++)//�̧ǦL�X
                puts(firstArr[i]);
        }
        else if(choice == 3){
            for(i = num - 1; i > 0; i --){//�w�j�ƧǪk
                for(j = 0; j < i; j ++){
                    ans = strcmp(firstArr[j], firstArr[j + 1]);
                    if(ans > 0){
                        tmp = firstArr[j];
                        firstArr[j] = firstArr[j + 1];
                        firstArr[j + 1] = tmp;
                    }
                }
            }
        }
        else if(choice == 4){
            for(i = 0; i < num; i ++){//����
                free(firstArr[i]);
            }
            free(firstArr);
            return 0;
        }
    }
}
