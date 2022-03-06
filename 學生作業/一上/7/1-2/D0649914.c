#include<stdio.h>
int main(){
	int i,j,k,diamond,row,line,star,star2,space,space2;
	for(i=1;i<4;){                                          //3次判斷 當超過或等於4的話 跳出迴圈 
		if(i==1){                                           //判斷現在是不是要輸入菱形的長度 
			printf("輸入菱形對角線長度(3、5、7、9): ");
			scanf("%d",&diamond);
			if(diamond !=3 && diamond !=5 && diamond !=7 && diamond !=9){       //判斷菱形是不是長度3、5、7、9 如果不是印出錯誤 直接回去迴圈 
				printf("輸入錯誤!\n");
				continue;
			}
			else{
				i++;
			}
		}
		else if(i==2){                                     //判斷現在是不是要輸入行數                                    
			printf("輸入行數(2 ~ 10):");
			scanf("%d",&row);
			if(row>=2 && row<=10){                         //判斷列數是不是介於2~10 如果不是印出錯誤 直接回去迴圈 
				i++;
			}
			else{
				printf("輸入錯誤\n");
				continue;
			}
		}
		else if(i==3){                                     //判斷現在是不是要輸入列數 
			printf("輸入列數(2 ~ 10):");
			scanf("%d",&line);
			if(line>=2 && line<=10){                       //判斷列數是不是介於2~10 如果不是印出錯誤 直接回去迴圈
				i++;
			}
			else{
				printf("輸入錯誤\n");
				continue;
			}	
		}
	}
	printf("\n");
	for(i=1;i<=line;i++){                                           //印出有多少列的迴圈 
		for(j=1,star2=1,space2=(diamond+1)/2;j<=diamond;j++){       //印出菱形的迴圈  跑的數量=diamond的數量 
			if(j<=(diamond+1)/2){                                   //判斷印出上半部菱形的條件 
				for(k=1;k<=row;k++){								//印出上半部菱形的迴圈 
					for(space=space2;space>1;space--){
						printf(" ");
					}
					for(star=1;star<=star2;star++){
						printf("*");
					}
					for(space=space2;space>=1;space--){
						printf(" ");
					}
				}
				if(j!=(diamond+1)/2){
					star2+=2;
					space2--;
				}
			}
			else{                                 				    //判斷印出下半部菱形的條件
				for(k=1;k<=row;k++){								//印出下半部菱形的迴圈 
					for(space=0;space<space2;space++){
						printf(" ");
					}
					for(star=star2-2;star>=1;star--){
						printf("*");
					}
					for(space=0;space<=space2;space++){
						printf(" ");
					}
				}
				star2-=2;
				space2++;
			}
			printf("\n");											//行的換行 
		}
		printf("\n");											    //列的換行 
	}
	return 0;
}
