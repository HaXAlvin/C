#include<stdio.h>
#include<stdlib.h>

typedef struct div{
    int mole,deno;//���l����
}Div;
Div add(Div fra1,Div fra2){//�[
    Div ans;
    if (fra1.deno != fra2.deno){//�������P
        ans.deno = fra1.deno * fra2.deno;
        ans.mole = fra1.mole * fra2.deno + fra2.mole * fra1.deno;
    }
    else {//�����ۦP
        ans.deno = fra1.deno;
        ans.mole = fra1.mole + fra2.mole;
    }

    return ans;
}
Div sub(Div fra1,Div fra2){//��
    Div ans;
    if (fra1.deno != fra2.deno){//�������P
        ans.deno = fra1.deno * fra2.deno;
        ans.mole = fra1.mole * fra2.deno - fra2.mole * fra1.deno;
    }
    else {//�����ۦP
        ans.deno = fra1.deno;
        ans.mole = fra1.mole - fra2.mole;
    }
    return ans;
};
Div multi(Div fra1,Div fra2){//��
    Div ans;
    ans.deno = fra1.deno * fra2.deno;
    ans.mole = fra1.mole * fra2.mole;
    return ans;
};
Div divide(Div fra1,Div fra2){//��
    Div ans;
    ans.deno = fra1.deno * fra2.mole;
    ans.mole = fra1.mole * fra2.deno;
    return ans;
};
Div gcd(Div ans){//����--����۰��k
    int m,d,c,k,i;
    m = ans.mole;
    d = ans.deno;
    if (m < 0) m*=(-1);
    if (d < 0) d*=(-1);
    for (i = 0;c > 0;i++){
        c = d % m;
        d = m;
        k = m;
        m = c;
    }
    ans.mole /= k;
    ans.deno /= k;
    return ans;
};
int main(){
    int opt,n;
    Div fra1;
    Div fra2;
    Div ans;
    char sign[] = "+-*/";//�B��Ÿ�
    while (opt != 0){
        do{
            n = 0;
            do{
                n = 0;
                printf("���(1.�[/2.��/3.��/4.��/0.���}):");
                scanf("%d",&opt);
                if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 0){//�ﶵ���b
                    printf("��J���~\n\n");
                    n = 1;
                }
            }while(n == 1);
            if (opt == 0) return 0;
            printf("a/b %c c/d�A�п�Ja b c d:",sign[opt-1]);
            scanf("%d %d %d %d",&fra1.mole,&fra1.deno,&fra2.mole,&fra2.deno);
            if (opt == 4 && fra2.mole == 0){//���l���b
                printf("���Ƥ��i��0\n\n");
                n = 1;
            }
            else if (fra2.deno == 0){
                printf("�������i��0\n\n");//�������b
                n = 1;
            }
        }while (n == 1);

        switch(opt){
            case 1:
                ans = add(fra1,fra2);//�[
                ans = gcd(ans);
                if (ans.deno < 0){//�t���b���l
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 2:
                ans = sub(fra1,fra2);//��
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 3:
                ans = multi(fra1,fra2);//��
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=(-1);
                    ans.deno*=(-1);
                }
                break;
            case 4:
                ans = divide(fra1,fra2);//��
                ans = gcd(ans);
                if (ans.deno < 0){
                    ans.mole*=-1;
                    ans.deno*=(-1);
                }
                break;
        }
        printf("%d/%d %c %d/%d = ",fra1.mole,fra1.deno,sign[opt-1],fra2.mole,fra2.deno);
        if (ans.deno == 1) printf("%d\n",ans.mole);//���
        else printf("%d/%d\n",ans.mole,ans.deno);//����
        printf("\n");
    }
}
