#include <stdio.h>
#include <stdlib.h>
int main(){
	int lengths,columns,rows; 
	printf("輸入菱形對角線行數(3、5、7、9): ");
	scanf("%d",&lengths);
	//判斷對角線行數是否在規定值 
	while(1){
		if(lengths == 3){
		    break;	
		}else if(lengths == 5){
			break;	
		}else if(lengths == 7){
			break;	
		}else if(lengths == 9){
			break;	
		}else{
			printf("輸入錯誤!\n");
			printf("輸入菱形對角線行數(3、5、7、9):");
			scanf("%d",&lengths);
		}
	}
	//判斷行數是否在規定值
	printf("輸入行數(2 ~ 10) : ");
	scanf("%d",&columns);
	while((columns<2)||(columns>10)){
		printf("輸入錯誤!\n");
		printf("輸入行數(2 ~ 10) : ");
		scanf("%d",&columns);
	}
	//判斷列數是否在規定值
	printf("輸入列數(2 ~ 10) : ");
	scanf("%d",&rows);
	while((rows<2)||(rows>10)){
		printf("輸入錯誤!\n");
		printf("輸入列數(2 ~ 10) : ");
		scanf("%d",&rows);
	}
	printf("\n");
/*第一迴圈為判斷寫多少列
  第一迴圈中的第一迴圈與第二迴圈分別判斷上、下需迴圈幾次
  再分別判斷需寫多少行
  最內圈迴圈分別判斷需要多少空格和米字號 
*/ 
	for(int m=1;m<=rows;m++){
		for(int j=1;j<=(lengths+1)/2;j++){
			for(int i=1;i<=columns;i++){
				for(int k1=1;k1<=(lengths+1)/2-j;k1++){
					printf(" ");
				}
				for(int k2=1;k2<=2*j-1;k2++){
					printf("*");
				}
				for(int k1=1;k1<=(lengths+1)/2-j+1;k1++){
					printf(" ");
				}
		    }
		    printf("\n");
		}
	    for(int j=1;j<=(lengths-1)/2;j++){
			for(int i=1;i<=columns;i++){
				for(int k3=1;k3<=j;k3++){
					printf(" ");
				}
				for(int k4=1;k4<=lengths-2*j;k4++){
					printf("*");
				}
				for(int k3=1;k3<=j+1;k3++){
					printf(" ");
				}
		    }
			printf("\n");
    	}
    	printf("\n");
    }
	return 0;
} 
