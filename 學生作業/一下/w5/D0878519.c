#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{//���c�}�C
    union{
        int score1;
        float score2;
        char name[16];
    }union1;
    int count;
}array;
int main()
{
    int i=0;
    array num[100];//�s�X���c
    int n;
    int m;
    while(1){//�@�����U�h�����J0
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d",&n);
        if(n==0)//����
            break;
        else if(n==1){//�s�W
            printf("��������G(1�Gint/2�Gfloat/3�Gchar[16])�G");//��ܿ�J����
            scanf("%d",&num[i].count);
            if(num[i].count==1){
                printf("��J��ơG");
                scanf("%d",&num[i].union1.score1);
            }
            if(num[i].count==2){
                printf("��J��ơG");
                scanf("%f",&num[i].union1.score2);
            }
            if(num[i].count==3){
                printf("��J��ơG");
                scanf("%s",&num[i].union1.name);
            }
            i++;
        }
        else if(n==2){//�L�X
            m=i;
            for(i=0;i<m;i++){//�ѳ̫e��J�L��̫��J
                if(num[i].count==1)
                    printf("%d\n",num[i].union1.score1);
                if(num[i].count==2)
                    printf("%f\n",num[i].union1.score2);
                if(num[i].count==3)
                    printf("%s\n",num[i].union1.name);
            }
        }
        else{//��J���~�N����
            printf("��J���~!\n");
            continue;
        }
    }
}
