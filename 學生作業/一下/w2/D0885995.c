#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void add(char **a,int b) //����ĺ�ʽ
{
    char temp[500]; //������g
    gets(temp);
    int len=strlen(temp); //������ִ��L��
    a[b-1]=malloc((len+1)*sizeof(char)); //����һ�����g�ڶ��S��еĵڶ��S
    strcpy(a[b-1],temp); //�}�u�Mȥ
    return;

}
void sort(char **a,int b) //����ĺ�ʾ
{
    //��ĭ����
    for (int i=0;i<b;i++){
        for (int j=0;j<i;j++){
            if (strcmp(*(a+i),*(a+j))==-1){
                char temp[500]; //������ִ�
                char *ptr1=a[i];
                char *ptr2=a[j];
                char *ptr; //�����ָ��
                strcpy(temp,a[i]);
                //ָ�˻��Qλ��
                ptr=ptr1;
                ptr1=ptr2;
                strcpy(a[i],a[j]);
                ptr2=ptr1;
                strcpy(a[j],temp);
            }
        }
    }
}


int main()
{
    int n,count=0,num1=10;
    char **nameArr;
    nameArr=malloc(10*sizeof(char*));//������һ�S
    printf("�W��������ӛϵ�y\n");
    while (1){
        printf("1.����2.ӡ��3.����4.�x�_:");
        scanf("%d%*c",&n); //�Д�����һ������

        if (n==1){ //����
            count++;
            if (count>num1){
                nameArr=realloc(nameArr,(count+5)*sizeof(char*)); //λ�ò���r����5�����g
                num1+=5;
            }
            add(nameArr,count);
        }
        else if (n==2){ //����
            for (int i=0;i<=count-1;i++){
                printf("%s\n",nameArr[i]);
            }
        }
        else if (n==3){ //����
            sort(nameArr,count);
            printf("�������\n");
        }
        else if (n==4){ //�x�_�Kጷ�
            for (int j=0;j<count;j++){
                free(nameArr[j]);
            }
            free(nameArr);
            break;
        }

        else
            printf("\nݔ���e�`\n\n");
    }
}
