#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int temp=10;
    char name[200];
    char**ptr_name;
    ptr_name=malloc(temp*sizeof(char*));
    int name_count;
    int count=0;
    for(int fnct=0;;)
    {
        printf("\n1.�s�W\n2.�L�X\n3.�Ƨ�\n4.���}\n�п�J�n�ϥΪ��t�οﶵ:");
        scanf("%d",&fnct);
        if(fnct==1)
        {
            if(count>=temp)
            {
                temp=temp+5;
            }
            printf("�п�J�ǥͩm�W:");
            getchar();
            gets(name);
            name_count=strlen(name)+1;
            ptr_name[count]=calloc(name_count,sizeof(char));
            strcpy(ptr_name[count],name);
            count++;
        }
        else if (fnct==2)
        {
            for(int i=0; i<count; i++)
            {
                printf("\n%d.",i+1);
                puts(ptr_name[i]);
            }
        }
        else if (fnct==3)
        {
            for(int i=0;i<count; i++)
            {
                for(int j=0;j<i; j++)
                {
                    if((strcmp(ptr_name[j],ptr_name[j+1]))>0)
                    {
                        char temp_name[200];
                        strcpy(temp_name,ptr_name[j]);
                        strcpy(ptr_name[j],ptr_name[j+1]);
                        strcpy(ptr_name[j+1],temp_name);
                    }
                }
            }

        }
        else if(fnct==4)
        {
            for(int i=0;i<count;i++)
            {
                free(ptr_name[i]);
            }
            free(ptr_name);
            break;
        }




    }
}
