#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){
	int answer[5]={0},a=0,b=0,check[4]={10,10,10,10},correct=0,len=0,is_guess=1;
	char guess[10]={0};
	char play_again; 
	while(1){
		a=0,b=0;
		srand(time(NULL));
		do{
			for(int i=0;i<4;i++){		
				answer[i]=rand()%10;
			}	
		}while((answer[0]==answer[1])||(answer[0]==answer[2])||(answer[0]==answer[3])||(answer[1]==answer[2])||(answer[1]==answer[3])||(answer[2]==answer[3]));
		for(int i=0;i<4;i++){		
			printf("%d",answer[i]);
		}
		while(1){
			printf(">> ");
			scanf("%s",guess);
				for(int i=0;i<4;i++){
					check[i]=guess[i]-48;						
				}	
				len=strlen(guess);
			while(a!=4){
				if((len!=4)||(check[0]==check[1])||(check[0]==check[2])||(check[0]==check[3])||(check[1]==check[2])||(check[1]==check[3])||(check[2]==check[3])){
					printf("INPUT ERROR\n");
					break;
				}else{
					a=0,b=0;
					for(int j=0;j<4;j++){
						if(answer[j]==check[j]){
							a++;
						}else if(answer[j]!=check[j]){
							for(int k=0;k<4;k++){
								if(answer[j]==check[k]){
									b++;
								}
							}
						}
					}
					if(a!=4){
						printf("%dA%dB\n",a,b);	
					}			
				}	
				break;
			}
			if(a==4){
				break;
			}				
		}
		printf("YOU WIN\n");
		while(1){
			printf("Play Again?(Y/N)");
			scanf(" %c",&play_again);
			if(play_again=='Y'){
				break;
			}else if(play_again=='N'){
				return 0;
			}	
		}		
	}
	return 0;
}
