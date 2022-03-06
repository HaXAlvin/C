#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int create(char *ptr1,int *ptr2){                       //新增的函數 
	gets(ptr1);
	*ptr2=*ptr2+1;
	return strlen(ptr1);
}
void format(char **ptr,int j){                         //印出的函數 
	int i;
	for(i=0;i<j;i++)
		printf("%s\n",ptr[i]);
}
void chage(char **ptr,int count){                       //氣泡排序法 
	int i,j;
	for(i=0;i<count-1;i++){
		for(j=0;j<count-i-1;j++)
		if(strcmp(ptr[j],ptr[j+1])>=0){
			char *s1=ptr[j];
			ptr[j]=ptr[j+1];
			ptr[j+1]=s1;
		}
	}
}
int main(){
	char **name;			//二維動態陣列-學生姓名存放的指標變數 
	char newname[100];		//存放新增名字的變數 
	int len;				//存放新增名字的長度的變數 
	int user;				//使用者輸入的變數 
	int count=0;     		//繼續空間現在有幾個的變數 
	int i,j;
	name=malloc(10*sizeof(char *));                 
	printf("1.新增 2.印出 3.排序 4.離開\n");
	while(scanf("%d%*c",&user)!=EOF && user!=4){                   //輸入4就是離開 
		switch(user){
			case 1:                                                //新增 
				len=create(newname,&count);
				name[count-1]=calloc(len,sizeof(char));
				strcpy(name[count-1],newname);						//複製newname長度 
				if(count==10)										//超過空間,新增 5 的空間長度 
					name=realloc(name,(count+5)*sizeof(char*));
				else if(count>10 && count%5==0)
					name=realloc(name,(count+5)*sizeof(char*));
				break;
			case 2:
				format(name,count);									//列出姓名 
				break;
			case 3:													
				chage(name,count);									//氣泡排序 
				break;
		}
		printf("1.新增 2.印出 3.排序 4.離開\n");
	}
	for(i=0;i<count;i++)
		free(name[i]);												//釋放一維 
	free(name);														//釋放二維 
	return 0;
} 
