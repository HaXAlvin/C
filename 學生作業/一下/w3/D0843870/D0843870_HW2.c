#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp1(char *sArr1,char *sArr2)//ASCII���
{
	if(strcmp(sArr1, sArr2)>0)
		return 1;
	else
		return 0;
}
int cmp2(char *sArr1, char *sArr2)//�r��Ǥ��
{
	int i;
	float tmp1, tmp2;//�N2�Ӧr���Ȧs���B�I��
	for (i = 0;;i++)
	{
		//�Y�r�����p�g�h�31.5�A�s�Jtmp A:65 a:65.5 B:66 b:66.5....
		if(sArr1[i]>96)
			tmp1 = sArr1[i]-31.5;
		else
			tmp1 = sArr1[i];
		if(sArr2[i]>96)
			tmp2 = sArr2[i]-31.5;
		else
			tmp2 = sArr2[i];
		//����j�p
		if(tmp1>tmp2)
			return 1;
		else if(tmp1<tmp2)
			return 0;
		else if(sArr1[i]=='\0'&&sArr2[i]=='\0')
			return 0;
	}
}
void sort(char **sArr,int n,int (*cmp)(char*,char*))//bubblesort �������k�ѥD�{���ǤJ
{
	int i, j;
	char *tmp;
	for (i = 0; i < n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(cmp(sArr[j],sArr[j+1]))
			{
				tmp = sArr[j];
				sArr[j] = sArr[j + 1];
				sArr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	char **word;
	int num,i,sort_mode;
	int (*cmp[])(char*, char*) = {cmp1, cmp2};//�ŧi�禡���а}�C
	while(1)
	{
		printf("�п�J�r���(��J0����):");
		scanf("%d", &num);//Ū���r���
		getchar();
		word = (char **)calloc(num, sizeof(char *));//���t�G���Ŷ�
		for (i = 0; i < num;i++)//���t�@���Ŷ�
			word[i] = (char *)calloc(100, sizeof(char));
		if(num==0)
			return 0;
		for (i = 0; i < num; i++)
			scanf("%s", word[i]);//Ū���r��
		printf("�п�ܱƧǤ覡(1. �HASCII/2. �H�r���):");
		scanf("%d", &sort_mode);//Ū���ƧǤ�k
		sort(word, num, cmp[sort_mode - 1]);//�i��Ƨ�
		for (i = 0; i < num;i++)
			printf("%s\n", word[i]);
		//����O����
		for (i = 0; i < num;i++)
			free(word[i]);
		free(word);
	}
}