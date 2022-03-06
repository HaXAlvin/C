#include<stdio.h>
#include<stdlib.h>
typedef struct _list{                     	//聽說是要這樣創立結構 有char 有union 照題目 讚 好學生 這給一百了阿 
	char c;
	union{
		int num1;
		float num2;
		char str[16];	
	};
}list;
int create(list *com){ 					 		//新增的函式 
	printf("選擇類型 : (i : int/f :float/s : char[16]) :");
	scanf("%c%*c",&com->c);						//把資料型態存入結構的 c 裡	
	if(com->c=='i'||com->c=='f'||com->c=='s')
		printf("輸入資料 : ");
	if(com->c=='i'){							//依型態進入if裡 進行資料輸入 如輸入錯誤回傳-1否則為0 
		int n;
		scanf("%d",&com->num1);
	}
	else if(com->c=='f'){
		scanf("%f",&com->num2);
	}
	else if(com->c=='s'){
		scanf("%s",&com->str);
	}
	else{
		printf("輸入錯誤!\n");
		return -1; 
	}
	return 0;
}
int main(){
	int n,i=0;								//n為使用者輸入要新增還印出或離開 i為計算動態指標陣列到第幾個了 
	list *user;								//動態陣列指標 
	while(1){
		printf("選擇: (1.新增/2.印出/0.結束) :") ;
		scanf("%d%*c",&n);
		if(n==0){											// 0為結束 1為新增 2為印出 否則輸入錯誤 
			break;
		}
		else if(n==1){											 
			int num=-1;
			if(i==0){
				user=(list*)malloc(1*sizeof(list));			//第一次的話用malloc其餘為realloc 
			}
			else{
				user=(list*)realloc(user,(i+1)*sizeof(list));
			}
			while(num==-1){								//當是-1的時候 代表輸入錯誤就重新進入迴圈哦~~~ 
				num=create(&user[i]);	
			}
			i++;										 
		}
		else if(n==2){
			int k;
			for(k=0;k<i;k++){							//依照型態印出值 
				if((user+k)->c=='i')
					printf("%d\n",(user+k)->num1);
				else if((user+k)->c=='f')
					printf("%f\n",(user+k)->num2);
				else if((user+k)->c=='s'){
					printf("%s\n",(user+k)->str);
				}
			}
		}
		else
			printf("輸入錯誤!\n");
	}
	printf("結束程式\n");
	free(user);											//釋放記憶體  
	return 0;
}
