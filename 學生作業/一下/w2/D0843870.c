#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addname(char **name_add,int num_add)//�s�W�W�r
{
    char tmp[100];//�Ȧs�W�r
    int i;
    gets(tmp);//�N�W�r�s�J�}�C
    name_add[num_add] = (char*)malloc((strlen(tmp) + 1)*sizeof(char));//�t�m�i�s�J�r������+1�Ӫ�char�O����Ŷ�
    for (i = 0; i <= strlen(tmp);i++)
        name_add[num_add][i] = tmp[i]; //�N�Ȧs�}�C���r���@�Ӥ@�Ӧs�Jname_add
}
void print(char **name_print,int num_print)//�L�X�W�r�C��
{
    int i;
    //�q���¿�J���}�l��X
    for (i = 0; i < num_print;i++)
        printf("%s\n", name_print[i]);
}
void sort(char **name_sort,int num_sort)//�N�W�r�Ƨ�
{
    int i,j;
    char *tmp;//�Ȧs
    //bubblesort
    for (j = num_sort-1; j >0;j--)
        for (i = 0; i < j; i++)
        {
            if(strcmp(name_sort[i],name_sort[i+1])>0)
            {
                //�Ȥ����r���l��m
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
    name = (char**)calloc(limit, sizeof(char*));//�t�mlimit�ӥi�s�Jchar*���O����Ŷ�
    while(1)
    {
        printf("�ǥͩm�W�n�O�t��\n""1.�s�W\n""2.�L�X\n""3.�Ƨ�\n""4.���}\n""�п�J:");//print how to use
        scanf("%d", &mode);//get mode
        getchar();
        switch(mode)
        {
            case 1://addname mode
                if(num>=limit)//�Ynum>=limit�N�A�t�m5�ӪŶ�
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
                //����G�����Ъ��O����
                for (i = 0; i < num;i++)
                {
                    free(name[i]);
                }
                //����Ĥ@��
                free(name);
                return 0;//end main
        }
    }
}