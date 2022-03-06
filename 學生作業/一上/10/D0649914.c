#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
	srand(time(NULL));
	int temp=1;
	char user[100];                                                             //使用者輸入的變數 
	int i,j,com[4],com2[10]={0},user2[4],user3[10]={0},t=0,a=0,b=0;             
	//com電腦的值 com2判斷有無重複的值得變數  
	//user2 把他轉成int的變數 user3 判斷有無重複的變數
	while(1){
		if(temp==1){                              //判斷是不是還是原本的一局 如果不是 電腦才會進來random數值 
			for(i=0;i<10;i++){                    //當重開開始時 把判斷歸0 
				com2[i]=0;
			}
			for(i=0;i<4;i++){                     //賦予電腦數字的迴圈 
				com[i]=rand()%10;
				if(com2[com[i]] == 1){            //如果輸入的數字有重複的話 重新賦予值到陣列中 
					i--;
					continue;
				}
				com2[com[i]]= 1;
				printf("%d",com[i]);              // 保留給學長看有沒有問題的輸出 
 			}
 			temp=0;                                
 		}
 		if(t==0){                                 //用來區隔到底有沒有輸入錯誤  如果錯誤 直接回到這裡做初始化 
 			for(i=0;i<10;i++){                       
				user3[i]=0;
			}
			a=0;
			b=0;
		}
		printf(">> ");
			scanf("%s",&user);
			if(strlen(user)!=4){                 //如果輸入不等於4個字符的話 就錯誤 
				printf("INPUT ERROR\n");
				continue;
			}
		for(i=0;i<4;i++){
			user2[i]=user[i]-48;
			if(user3[user2[i]]==1){              //如果輸入有重複的話 就錯誤 
				printf("INPUT ERROR\n");         
				t=1;
				break;
			}
			user3[user2[i]]=1;
		}
		if(t==1){                                  //如果輸入錯誤就回到28行 
			t=0;
			continue;
		}
		for(i=0;i<4;i++){                           //計算 A有多少 B有多少 
			if(com[i]==user2[i]){
				a++;
			}
			else{
				for(j=0;j<10;j++){
					if(com2[j]==user3[j] && com2[j]!=0){
						b++;
					}
				}
			}
		}
		b/=4;                                     //因為如果有b的話 會重複4次 所以b/4 
		if(a==4){								  //A=4的話 就贏  否則印出幾A幾B 
			printf("YOU WIN\n");
			char c;
			while(1){                            //詢問要不要再玩一次 
				printf("Play Again?(Y/N)");
				scanf("%*c%c",&c);
				if(c=='N'){
					break;
				}
				else if(c== 'Y'){
					break;
				}
				else{
					continue;
				}
			}
			if(c=='N'){                        //不要玩 break 
				break;
			}
			else{							   //要玩 continue 
				temp=1;
				continue;
			}
		}
		else{
			printf("%dA%dB\n",a,b);
		}
	}
	return 0;
} 
