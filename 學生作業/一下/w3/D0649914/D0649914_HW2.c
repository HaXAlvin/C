#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void sort(char **arr,int n,int (*cmp)(char *,char *)){			//泡沫排序
	int k,i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(cmp(arr[j],arr[j+1])){
				char *c=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=c;
			}
		}

	}
}
int cmp1(char *a,char *b){						// Ascii碼方式排序
	if(strcmp(a,b)>=0)
		return 1;
	else
		return 0;
}
int cmp2(char *a,char *b){						// 字典方式排序
	int i,len;
	int len1=strlen(a);							//25~30 判斷哪個字串比較短為len
	int len2=strlen(b);
	if(len1>len2)
		len=len2;
	else
		len=len1;

	for(i=0;i<len;i++){							//字母一樣的話就換下一個字母
		char c1=*(a+i),c2=*(b+i);
		if(islower(c1))							//34~37為判斷是否為小寫，如果是就轉成大寫
			c1=toupper(*(a+i));
		if(islower(c2))
			c2=toupper(*(b+i));

		if(c1>c2){								//如果c1>c2 就交換 否則 判斷 原來的字母是否相等
			return 1;
		}
		else if(c1==c2){
			if(*(a+i)>*(b+i))					//如果原字母a+i是小寫的話 b+i為大寫 代表*(a+i)>*(b+i) 所以要交換 否則繼續執行下個字母
				return 1;
			else if(*(a+i)==*(b+i))
				continue;
			else
				return 0;
		}

	}
}
int main(){
	char **sArr;								//存放名字的動態陣列
	int n,num;									//n=使用者決定幾個單字的變數 num=決定排序方式的變數
	int i;
	while(1){
		printf("請輸入字串數(輸入0結束) : ");
		scanf("%d",&n);
		if(n==0){								//如果是0就離開
			break;
		}
		sArr=malloc(n*sizeof(char *));				//63~67 為宣告二維動態陣列，以及讀入單字
		for(i=0;i<n;i++){
			sArr[i]=malloc(100*sizeof(char));
			scanf("%s",sArr[i]);
		}

		printf("選擇排序方式(1. 以ASCII/2. 以字典序) : ");
		scanf("%d",&num);
		if(num==1){								//排序一的判斷
				sort(sArr,n,cmp1);
			for(i=0;i<n;i++)
				printf("%s\n",sArr[i]);
		}
		else{									//排序二的判斷
			sort(sArr,n,cmp2);
			for(i=0;i<n;i++)
				printf("%s\n",sArr[i]);
		}
	}

	return 0;
}
