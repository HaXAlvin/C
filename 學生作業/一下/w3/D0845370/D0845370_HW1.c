#include <stdio.h>

int add(int a, int b){ //�[�k
    return a + b;
}

int sub(int a, int b){ //��k
    return a - b;
}

int multi(int a, int b){ //���k
    return a * b;
}

int divide(int a, int b){ //���k
    return a / b;
}

int mod(int a, int b){ //���l��
    return a % b;
}

int main(){
    int (* opt[])(int, int) = {add,sub,multi,divide,mod}; //��ܫ���
    while(1){
        int a = 0,b = 0,choose = 0;
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���})�G");
        scanf("%d", &choose);
        if(choose == 0)
            return 0;
        printf("�п�J2�Ӿ�ơF");
        scanf("%d %d", &a, &b);
        if(choose == 1)
            printf("%d + %d = %d\n", a, b, opt[0](a, b));
        else if(choose == 2)
            printf("%d - %d = %d\n", a, b, opt[1](a, b));
        else if(choose == 3)
            printf("%d * %d = %d\n", a, b, opt[2](a, b));
        else if(choose == 4)
            printf("%d / %d = %d\n", a, b, opt[3](a, b));
        else if(choose == 5)
            printf("%d %% %d = %d\n", a, b, opt[4](a, b));
    }
}
