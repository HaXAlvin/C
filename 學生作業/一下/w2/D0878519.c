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
    printf("學生姓名登記系統\n");
    printf("輸入1.新增 2.印出 3.排序 4.離開\n");
    while(scanf("%d",&i)!=EOF){
        if(i==1)//新增名字
        {
            scanf("%s",&name2);
            n=strlen(name2);
            name[j]=malloc((n+1)*sizeof(char *));
            strcpy(name[j],name2);
            j++;
        }
        if(i==2)//印出
        {
            k=j;
            for(j=0;j<k;j++)
                printf("%s\n",name[j]);

        }
        if(i==3)//排序
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
        if(i==4)//釋放
        {
            for(j=0;j<n+1;j++){
                free(name[j]);
            }
            free(name);
            return 0;
        }
    }

}
