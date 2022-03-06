#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp1(char *sArr1,char *sArr2)//ASCII比較
{
	if(strcmp(sArr1, sArr2)>0)
		return 1;
	else
		return 0;
}
int cmp2(char *sArr1, char *sArr2)//字典序比較
{
	int i;
	float tmp1, tmp2;//將2個字元暫存成浮點數
	for (i = 0;;i++)
	{
		//若字元為小寫則減掉31.5再存入tmp A:65 a:65.5 B:66 b:66.5....
		if(sArr1[i]>96)
			tmp1 = sArr1[i]-31.5;
		else
			tmp1 = sArr1[i];
		if(sArr2[i]>96)
			tmp2 = sArr2[i]-31.5;
		else
			tmp2 = sArr2[i];
		//比較大小
		if(tmp1>tmp2)
			return 1;
		else if(tmp1<tmp2)
			return 0;
		else if(sArr1[i]=='\0'&&sArr2[i]=='\0')
			return 0;
	}
}
void sort(char **sArr,int n,int (*cmp)(char*,char*))//bubblesort 比較的方法由主程式傳入
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
	int (*cmp[])(char*, char*) = {cmp1, cmp2};//宣告函式指標陣列
	while(1)
	{
		printf("請輸入字串數(輸入0結束):");
		scanf("%d", &num);//讀取字串數
		getchar();
		word = (char **)calloc(num, sizeof(char *));//分配二維空間
		for (i = 0; i < num;i++)//分配一維空間
			word[i] = (char *)calloc(100, sizeof(char));
		if(num==0)
			return 0;
		for (i = 0; i < num; i++)
			scanf("%s", word[i]);//讀取字串
		printf("請選擇排序方式(1. 以ASCII/2. 以字典序):");
		scanf("%d", &sort_mode);//讀取排序方法
		sort(word, num, cmp[sort_mode - 1]);//進行排序
		for (i = 0; i < num;i++)
			printf("%s\n", word[i]);
		//釋放記憶體
		for (i = 0; i < num;i++)
			free(word[i]);
		free(word);
	}
}