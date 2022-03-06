#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    int choose;
    int temp = 10;
    int a = 0;
    char name[100];
    char **dynaArr;
    dynaArr = malloc(temp *sizeof(char *));

    while(1)
    {
        printf("chose請選擇：1.新增 2.印出 3.排序 4.離開");//選擇功能
        scanf("%d",&choose);
        if(choose==1)//若選擇新增
        {
            if(a >= temp)
            {
                temp = temp+5;//空間不足增加空間
            }
            printf("輸入學生姓名:");
            getchar();
            gets(name);
            dynaArr[a] = calloc(strlen(name)+1 ,sizeof(char *));
            strcpy(dynaArr[a],name);
            a++;
        }
        else if(choose==2)//若選擇印出
        {
            printf("名單:\n");
            for(int i=0;i<a;i++)
            {
                puts(dynaArr[i]);
                printf("\n");
            }
        }
        else if(choose==3)//若選擇排序
        {
                for(int i=0;i<a;i++)//泡沫排序法
                {
                    for(int j=0;j<i;j++)
                    {
                        if((strcmp(dynaArr[j],dynaArr[j+1]))>0)
                        {
                            char t;
                            t = *dynaArr[j];
                            dynaArr[j] = dynaArr[j+1];
                            dynaArr[j+1] = &t;
                        }
                    }
                }
        }
        else if(choose==4)//若選擇離開
        {
            for(int i=0;i<a;i++)
            {
                free(dynaArr[i]);
            }
            free(dynaArr);
            break;
        }
    }
}
