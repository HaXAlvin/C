#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,n,k;
    int j=0;
    char *temp;
    char **name;
    char  name2[20];
    name =malloc(10*sizeof(char *));
    printf("�ǥͩm�W�n�O�t��\n");
    printf("��J1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
    while(scanf("%d",&i)!=EOF){
        if(i==1)//�s�W�W�r
        {
            scanf("%s",&name2);
            n=strlen(name2);
            name[j]=malloc((n+1)*sizeof(char *));
            strcpy(name[j],name2);
            j++;
        }
        if(i==2)//�L�X
        {
            k=j;
            for(j=0;j<k;j++)
                printf("%s\n",name[j]);

        }
        if(i==3)//�Ƨ�
        {
            int p;
            for(p=0;p<j;p++){
                for(j=0;j<p;j++){
                    if(strcmp(name[j],name[j+1])>0){
                        temp=name[j];
                        name[j]=name[j+1];
                        name[j+1]=temp;
                    }
                }
            }

        }
        if(i==4)//����
        {
            for(j=0;j<n+1;j++){
                free(name[j]);
            }
            free(name);
            return 0;
        }
    }

}
