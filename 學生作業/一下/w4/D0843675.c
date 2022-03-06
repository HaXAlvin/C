#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct frac{//���Ʈ榡=���l+����
    int mole;//���l
    int deno;//����
};

void reduction(struct frac ans){//����
    int neg = 1;//���tflag
    int end = 0;//���쩳
    if(ans.mole<0&&ans.deno<0){//���l������̳����t�ɡA��̨������
        ans.mole=abs(ans.mole);
        ans.deno=abs(ans.deno);
    }
    else if(ans.mole<0||ans.deno<0){//���l������@���t�ɡA������ȡB�s�t��
        neg=-1;
        ans.mole=abs(ans.mole);
        ans.deno=abs(ans.deno);
    }

    if(ans.mole>ans.deno)//��j�p
        end=ans.deno;
    else
        end=ans.mole;

    if(ans.mole==0)//���פ��l���s�ɡA�L���0
        printf("0\n\n");
    else if(ans.deno%ans.mole==0&&ans.mole==ans.deno){//���l�����۵��ɡA�L���1
        printf("%d\n\n",neg);
    }
    else if(ans.deno%ans.mole==0){//���������l�����n���ɡA�L���t1/n
        ans.deno /= ans.mole;
        ans.mole=neg;
        printf("%d/%d\n\n",ans.mole,ans.deno);
    }
    else if(ans.mole%ans.deno==0){//���l�����������n���ɡA�L���tn
        printf("%d\n\n",ans.mole / ans.deno * neg);
    }
    else{//�u�����Ƭ���
        for(int factor = 2;factor<end;factor++){
            if(ans.mole%factor==0&&ans.deno%factor==0){
                ans.mole /= factor;
                ans.deno /= factor;
                factor--;
            }
        }
        printf("%d/%d\n\n",ans.mole * neg,ans.deno);
    }
}

struct frac add(struct frac a_b,struct frac c_d){//�[�k
    int mole = (a_b.mole * c_d.deno)+(c_d.mole * a_b.deno);//axd+cxb
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d + %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
};

struct frac minus(struct frac a_b,struct frac c_d){//��k
    int mole = (a_b.mole * c_d.deno)-(c_d.mole * a_b.deno);//axd-cxd
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d - %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

struct frac multi(struct frac a_b,struct frac c_d){//���k
    int mole = (a_b.mole * c_d.mole);//axc
    int deno = (a_b.deno * c_d.deno);//bxd
    struct frac answer = {mole,deno};
    printf("%d/%d * %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

struct frac divide(struct frac a_b,struct frac c_d){//���k
    int mole = (a_b.mole * c_d.deno);//axd
    int deno = (a_b.deno * c_d.mole);//bxc
    struct frac answer = {mole,deno};
    printf("%d/%d / %d/%d = ",a_b.mole,a_b.deno,c_d.mole,c_d.deno);
    return answer;
}

int main(){
    int option = 0;
    while(1){
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");
        scanf("%d",&option);
        if(option==0)
            return 0;
        else if(option==1||option==2||option==3||option==4){
            struct frac ab;//a/b
            struct frac cd;//c/d
            struct frac answer;

            switch(option){
            case 1:
                printf("a/b + c/d�A�п�Ja b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("�������i��0\n\n");
                    break;
                }
                answer=add(ab,cd);
                reduction(answer);
                break;
            case 2:
                printf("a/b - c/d�A�п�Ja b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("�������i��0\n\n");
                    break;
                }
                answer=minus(ab,cd);
                reduction(answer);
                break;
            case 3:
                printf("a/b * c/d�A�п�Ja b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("�������i��0\n\n");
                    break;
                }
                answer=multi(ab,cd);
                reduction(answer);
                break;
            case 4:
                printf("a/b / c/d�A�п�Ja b c d:");
                scanf("%d %d %d %d",&ab.mole,&ab.deno,&cd.mole,&cd.deno);
                if(ab.deno==0||cd.deno==0){
                    printf("�������i��0\n\n");
                    break;
                }
                else if(cd.mole==0){
                    printf("���Ƥ��i��0\n\n");
                    break;
                }
                answer=divide(ab,cd);
                reduction(answer);
                break;
            }
        }
        else
            printf("��J���~\n\n");
    }
}
