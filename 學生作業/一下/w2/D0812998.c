#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char **name;
    char a[100],tmp[100];
    name=malloc(10*sizeof(char *));
    int choose,i=0,len,j,k,len2,flag=1;
    while(1)
    {
        printf("1.新增 2.印出 3.排序 4.離開\n");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                scanf("%s",&a);
                printf("kkkk\n");
                len=strlen(a);

                if(i>=10&&i%5==0)
                {
                    //printf("111");
                    name=realloc(name,(10+flag*5)*sizeof(char *));
                    //printf("111");
                    flag++;
                }

                name[i]=calloc(len+1,sizeof(char));

                strcpy(name[i],a);
                //printf("%s\n",name[i]);
                i++;
                break;
            case 2:
                for(j=0;j<i;j++)
                {
                    printf("%s\n",name[j]);
                }
                break;
            case 3:
                for(k=0;k<i;k++)
                {
                    for(j=1;j<i;j++)
                    {
                        if(strcmp(name[j-1],name[j])>0)
                        {
                            strcpy(tmp,name[j]);
                            len=strlen(name[j-1]);
                            name[j]=realloc(name[j],len+1*sizeof(char));
                            strcpy(name[j],name[j-1]);
                            len2=strlen(tmp);
                            name[j-1]=realloc(name[j-1],len2+1*sizeof(char));
                            strcpy(name[j-1],tmp);
                        }
                    }
                }
                for(j=0;j<i;j++)
                {
                    printf("%s\n",name[j]);
                }
                break;
            case 4:
                for(j=0;j<10;j++)
                {
                    free(name[j]);
                }
                free(name);
                return 0;


        }
    }
}
