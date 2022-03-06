#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ip{// ���l����
    int up, down;
};

int gcd(struct ip a){//�̤j���]��
    while(a.down != 0) {
        int temp = a.up % a.down;
        a.up = a.down;
        a.down = temp;
    }
    return a.up;
}

struct ip add(struct ip i, struct ip j){//�[�k
    int a, b;//�q��
    a = i.up * j.down + j.up * i.down;
    b = i.down * j.down;

    struct ip c = {
        a, b
    };
    int count = gcd(c);//²�Ƥ���
    int k;
    int h = c.up;//���l
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//����
    p = g/count;
    c.down = p;
    return c;

};

struct ip sub(struct ip i, struct ip j){//��k
    int a, b;//�q��
    a = i.up * j.down - j.up * i.down;
    b = i.down * j.down;

    struct ip c = {
        a, b
    };
    int count = gcd(c);//²�Ƥ���
    int k;
    int h = c.up;//���l
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//����
    p = g/count;
    c.down = p;
    return c;
};

struct ip multi(struct ip i, struct ip j){//���k
    int a, b;//�����ۭ�
    a = i.up * j.up;
    b = i.down * j.down;
    struct ip c = {
        a, b
    };
    int count = gcd(c);//²�Ƥ���
    int k;
    int h = c.up;//���l
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//����
    p = g/count;
    c.down = p;
    return c;
};

struct ip divi(struct ip i, struct ip j){//���k
    int a, b;//�����۰�
    a = i.up * j.down;
    b = i.down * j.up;
    struct ip c = {
        a, b
    };
    int count = gcd(c);//²�Ƥ���
    int k;
    int h = c.up;//���l
    k = h/count;
    c.up = k;
    int p;
    int g = c.down;//����
    p = g/count;
    c.down = p;
    return c;
};

int main(){
    int function;//�\��
    while(1){
        printf("���(1.�[/2.��/3.��/4.��/0.���}) : ");//��J�\��
        scanf("%d", &function);
        if(function == 1){
            printf("a/b + c/d�A�п�Ja b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//��J��Ӥ���
            if(b == 0 || d == 0){//����
                printf("�������i��0\n");
                continue;
            }
            struct ip first = {//�Ĥ@�Ӥ���
                a, b
            };
            struct ip second = {//�ĤG�Ӥ���
                c, d
            };
            struct ip op = add(first, second);
            if(op.down < 0){//���t������l
                op.up*= -1;
                op.down*= -1;
            }
            if(op.up % op.down != 0)//���G���O���,��X����
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//�Y�����,��X���
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 2){
            printf("a/b - c/d�A�п�Ja b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//��J��Ӥ���
            if(b == 0 || d == 0){//����
                printf("�������i��0\n");
                continue;
            }
            struct ip first = {//�Ĥ@�Ӥ���
                a, b
            };
            struct ip second = {//�ĤG�Ӥ���
                c, d
            };
            struct ip op = sub(first, second);
            if(op.down < 0){//���t������l
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//���G���O���,��X����
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//�Y�����,��X���
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 3){
            printf("a/b * c/d�A�п�Ja b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//��J��Ӥ���
            if(b == 0 || d == 0){//���b
                printf("�������i��0\n");
                continue;
            }
            struct ip first = {//�Ĥ@�Ӥ���
                a, b
            };
            struct ip second = {//�ĤG�Ӥ���
                c, d
            };
            struct ip op = multi(first, second);
            if(op.down < 0){//���t������l
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//���G���O���,��X����
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//�Y�����,��X���
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function == 4){
            printf("a/b / c/d�A�п�Ja b c d : ");
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);//��J��Ӥ���
            if(b == 0 || d == 0){//����
                printf("�������i��0\n\n");
                continue;
            }
            else if(c == 0){//����
                printf("���Ƥ��i��0\n\n");
                continue;
            }
            struct ip first = {//�Ĥ@�Ӥ���
                a, b
            };
            struct ip second = {//�Ĥ@�Ӥ���
                c, d
            };
            struct ip op = divi(first, second);
            if(op.down < 0){//���t������l
                op.down *= -1;
                op.up *= -1;
            }
            if(op.up % op.down != 0)//���G���O���,��X����
                printf("%d/%d + %d/%d = %d/%d\n\n",a,b,c,d,op.up, op.down);
            else//�Y�����,��X���
                printf("%d/%d + %d/%d = %d\n\n",a,b,c,d,op.up);
        }
        else if(function != 0 && function != 1 && function != 2 && function != 3 && function != 4)//��J���~���p
            printf("��J���~\n\n");
        else if(function == 0)//����
            return 0;
    }
}
