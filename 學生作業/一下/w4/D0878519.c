#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct tem{//���l����
    int Den;
    int Mol;
}tem;
tem add(tem n,tem m){//�[�k
    int a,b;
    tem ans;
    ans.Mol=n.Mol*m.Den+m.Mol*n.Den;
    ans.Den=n.Den*m.Den;
    if(ans.Den<0){//�t���\���l
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem reduce(tem n,tem m){//��k
    tem ans;
    ans.Den=n.Den*m.Den;
    ans.Mol=n.Mol*m.Den-m.Mol*n.Den;
        if(ans.Den<0){//�t���\���l
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem multiply(tem n,tem m){//���k
    tem ans;
    ans.Den=n.Den*m.Den;
    ans.Mol=n.Mol*m.Mol;
        if(ans.Den<0){//�t���\���l
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
tem divide(tem n,tem m){//���k
    tem ans;
    ans.Den=n.Den*m.Mol;
    ans.Mol=n.Mol*m.Den;
        if(ans.Den<0){//�t���\���l
        ans.Mol=-ans.Mol;
        ans.Den=-ans.Den;
    }
    return ans;
}
int main()
{
    int i;
    tem n;
    tem m;
    tem ans;

    while(i){
        printf("���(1.�[/2.��/3.��/4.��/0.���})�G");//���
        scanf("%d",&i);
        if(i==0){
            break;
        }
        else if(i==1){//�[�k
            printf("a/b + c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//������0�N����
                printf("�������i��0\n");
                continue;
            }
            ans=add(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==2){//��k
            printf("a/b - c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//������0�N����
                printf("�������i��0\n");
                continue;
            }
            ans=reduce(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==3){//���k
            printf("a/b * c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Den==0){//������0�N����
                printf("�������i��0\n");
                continue;
            }
            ans=multiply(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else if(i==4){//���k
            printf("a/b / c/d�A�п�Ja b c d�G");
            scanf("%d %d %d %d",&n.Mol,&n.Den,&m.Mol,&m.Den);
            if(m.Mol==0){//���Ƭ�0�N����
                printf("���Ƥ��i��0\n");
                continue;
            }
            if(m.Den==0){//������0�N����
                printf("�������i��0\n");
                continue;
            }
            ans=divide(n,m);
            printf("%d/%d\n",ans.Mol,ans.Den);
        }
        else//��J�O���Ʀr�|�X�{
            printf("��J���~\n");
    }
    return 0;
}
