#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
	union tagB{
		int i;
		float f;
		char s[16];	
	}B;
};

int main(){
	char cmd;
	struct A *sa = malloc(sizeof(struct A));
	while(1){
        printf("選擇：(1.新增/2.印出/0.結束)：");
        cmd = getchar();
        if(cmd=='1'){
        	char a;
           	printf("選擇類型：(i：int/f：float/s：char[16])： ");
           	scanf("%c",&a);
           	if(a == 'i'){
           		printf("輸入資料：");
           		scanf("%d",(*sa).B.i);
			}
			else if(a == 'f'){
				printf("輸入資料：");
				scanf("%f",(*sa).B.f);
			}
			else if(a == 's'){
				printf("輸入資料：");
				scanf("%s",(*sa).B.s);
			}
			else{
				printf("輸入錯誤！\n");
			}
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='2'){
     		
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='0'){
        	printf("結束程式\n");
        	break;
		}
        else{
        	printf("輸入錯誤！\n");
            getchar(); // clear your 'Enter' key.  
        }

    }
	
}
