#include<stdio.h>
#include<stdlib.h>

struct fraction {
    int mole;//���l
    int deno;//����
    int ans;//�̫᪺���Ƭ��@�Ӿ��
};

struct fraction add(struct fraction f1,struct fraction f2) { //�[�k
    struct fraction result;//�]�@�Ӧ^�ǭ�result
    result.mole = f1.mole*f2.deno + f1.deno*f2.mole;//���Ʀ^�ǭȪ����l��a*c + b*d
    result.deno = f1.deno*f2.deno;//���Ʀ^�ǭȪ�������b*d
    int x = result.mole;//�]�@�ӼȦs�s���Ʀ^�ǭȪ����l
    int y = result.deno;//�]�@�ӼȦs�s���Ʀ^�ǭȪ�����
    if((result.mole%result.deno)==0){//�p�G���l���H�������l�Ƭ�0
        result.ans = result.mole/result.deno;//�t�~�]�@�Ӿ�Ʀ^�ǭ�
    }
    if(result.deno<0){//�p�G�������t�ơA�h�n�令���l���t��
        result.deno = -result.deno;
        result.mole = -result.mole;
    }

    while(x%y!=0){//�D�̤j���]�ƥΨӬ���
        int temp = y;
        y = x%y;//y���̤j���]��
        x= temp;
    }
    if(y<0){//�p�G�̤j���]�Ƭ��t�ƫh�ഫ����
        y=-y;
    }
    result.mole = result.mole/y;//���Ʀ^�ǭȬ���
    result.deno = result.deno/y;//���Ʀ^�ǭȬ���
    return result;
};

struct fraction sub(struct fraction f1,struct fraction f2) { //��k
    struct fraction result;//�]�@�Ӧ^�ǭ�result
    result.mole = f1.mole*f2.deno - f1.deno*f2.mole;//���Ʀ^�ǭȪ����l��a*d - b*c
    result.deno = f1.deno*f2.deno;//���Ʀ^�ǭȪ�������b*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0){
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//�p�G�������t�ơA�h�n�令���l���t��
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//�D�̤j���]�ƥΨӬ���
        int temp = y;
        y = x%y;//y���̤j���]��
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//���Ʀ^�ǭȬ���
    result.deno = result.deno/y;//���Ʀ^�ǭȬ���
    return result;
};

struct fraction mult(struct fraction f1,struct fraction f2) { //���k
    struct fraction result;//�]�@�Ӧ^�ǭ�result
    result.mole = f1.mole*f2.mole;//���Ʀ^�ǭȪ����l��a*c
    result.deno = f1.deno*f2.deno;//���Ʀ^�ǭȪ�������b*d
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//�D�̤j���]�ƥΨӬ���
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){
        int temp = y;
        y = x%y;//y���̤j���]��
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//���Ʀ^�ǭȬ���
    result.deno = result.deno/y;//���Ʀ^�ǭȬ���
    return result;
};

struct fraction divide(struct fraction f1,struct fraction f2) { //���k
    struct fraction result;//�]�@�Ӧ^�ǭ�result
    result.mole = f1.mole*f2.deno;//���Ʀ^�ǭȪ����l��a*d
    result.deno = f1.deno*f2.mole;//���Ʀ^�ǭȪ�������b*c
    int x = result.mole;
    int y = result.deno;
    if((result.mole%result.deno)==0) {
        result.ans = result.mole/result.deno;
    }
    if(result.deno<0){//�p�G�������t�ơA�h�n�令���l���t��
        result.deno = -result.deno;
        result.mole = -result.mole;
    }
    while(x%y!=0){//�D�̤j���]�ƥΨӬ���
        int temp = y;
        y = x%y;//y���̤j���]��
        x= temp;
    }
    if(y<0){
        y=-y;
    }
    result.mole = result.mole/y;//���Ʀ^�ǭȬ���
    result.deno = result.deno/y;//���Ʀ^�ǭȬ���
    return result;
};

int main() {
    struct fraction frac1;
    struct fraction frac2;
    int choose=0;
    struct fraction result;
    while(1235) {
        printf("���(1.�[ / 2.�� / 3.�� / 4.�� / 0.���}):");
        scanf("%d",&choose);//�п�J���
        if((choose!=1)&&(choose!=2)&&(choose!=3)&&(choose!=4)&&(choose!=0)) { //�Y��J����1,2,3,4,0�A�h���s��J
            printf("��J���~�A�Э��s��J\n\n");
            continue;
        }
        if(choose==0) { //0.���}
            printf("���}���t��");
            return 0;
        }
        else if(choose==1) { //1.��ܥ[���B��
            printf("a/b + c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("�������i��0\n");
            } else {
                result = add(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d + %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==2) { //2.��ܴ�B��
            printf("a/b - c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("�������i��0\n");
            } else {
                result = sub(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d - %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==3) { //��ܭ����B��
            printf("a/b * c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)&&(frac2.deno==0)) {
                printf("�������i��0\n");
            } else {
                result = mult(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d * %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
        else if(choose==4) { //��ܰ����B��
            printf("a/b / c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d",&frac1.mole,&frac1.deno,&frac2.mole,&frac2.deno);
            if((frac1.deno==0)||(frac2.deno==0)) {
                printf("�������i��0\n");
            } else if(frac2.mole==0) {
                printf("���Ƥ��i��0\n");
            } else {
                result = divide(frac1,frac2);
                if((result.mole%result.deno)==0){
                    printf("%d/%d / %d/%d = %d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.ans);
                }
                else{
                    printf("%d/%d / %d/%d = %d/%d\n",frac1.mole,frac1.deno,frac2.mole,frac2.deno,result.mole,result.deno);
                }
            }
        }
    }


}



