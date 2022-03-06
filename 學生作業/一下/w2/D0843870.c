#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addname(char **name_add,int num_add)//新增名字
{
    char tmp[100];//暫存名字
    int i;
    gets(tmp);//將名字存入陣列
    name_add[num_add] = (char*)malloc((strlen(tmp) + 1)*sizeof(char));//配置可存入字元長度+1個的char記憶體空間
    for (i = 0; i <= strlen(tmp);i++)
        name_add[num_add][i] = tmp[i]; //將暫存陣列的字元一個一個存入name_add
}
void print(char **name_print,int num_print)//印出名字列表
{
    int i;
    //從最舊輸入的開始輸出
    for (i = 0; i < num_print;i++)
        printf("%s\n", name_print[i]);
}
void sort(char **name_sort,int num_sort)//將名字排序
{
    int i,j;
    char *tmp;//暫存
    //bubblesort
    for (j = num_sort-1; j >0;j--)
        for (i = 0; i < j; i++)
        {
            if(strcmp(name_sort[i],name_sort[i+1])>0)
            {
                //僅互換字串初始位置
                tmp = name_sort[i+1];
                name_sort[i + 1] = name_sort[i];
                name_sort[i] = tmp;
            }
        }
}
int main()//main
{
    int mode;//mode
    int num = 0;//number of names
    int limit = 10;//only save 10 names initialy
    int i;
    char **name;
    name = (char**)calloc(limit, sizeof(char*));//配置limit個可存入char*的記憶體空間
    while(1)
    {
        printf("學生姓名登記系統\n""1.新增\n""2.印出\n""3.排序\n""4.離開\n""請輸入:");//print how to use
        scanf("%d", &mode);//get mode
        getchar();
        switch(mode)
        {
            case 1://addname mode
                if(num>=limit)//若num>=limit就再配置5個空間
                {
                    limit += 5;
                    name=(char**)realloc(name, limit * sizeof(char *));
                }  
                addname(name,num);
                ++num;//num+1
                break;
            case 2://print mode
                print(name, num);
                break;
            case 3://sort mode
                sort(name, num);
                break;
            case 4://exit mode
                //釋放二維指標的記憶體
                for (i = 0; i < num;i++)
                {
                    free(name[i]);
                }
                //釋放第一維
                free(name);
                return 0;//end main
        }
    }
}