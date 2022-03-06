#include <stdio.h>
#include <stdlib.h>
int main(){
	char passornot = 0b11111111;
	int happening1 = 0b11111101, happening2 = 0b11111011, happening3 = 0b11111101, happening4 = 0b11101111, happening5 = 0b10111111; //事件造成的影響 會過寫1 反之寫0
	//1. 在大一下時，小明因為微積分翹了太多節課，期末拿了58分，被當掉了
	int changing1 = passornot & happening1;
	//2. 在大二上時，修了密碼學，但因為要算很多數學，一直算錯，拿了57分，被當
	int changing2 = changing1 & happening2;
	//3. 在大二上的學期末，跑到密碼學老師的辦公室跟他求情，老師幫他加到60分
	int changing3 = changing2 | happening3;
	//4. 在大三上時，因為在英文課一直睡覺，期末拿了50分，被當掉了
	int changing4 = changing3 & happening4;
	//5. 在大四上時，修了深度學習，但學習狀況不佳，期末只拿了40分，被當了
	int finalchanging = changing4 & happening5;
	int solo1 = 0b00000001 , solo2 = 0b00000010 , solo3 = 0b00000100 , solo4 = 0b00001000 , solo5 = 0b00010000 , solo6 = 0b00100000 , solo7 = 0b01000000 , solo8 = 0b10000000;
	//每個單元個別判斷是否為pass 
	if((solo1&finalchanging)>0){
		printf("大一上 : 1\n");
	}else{
		printf("大一上 : 0\n");
	}
	if((solo2&finalchanging)>0){
		printf("大一下 : 1\n");
	}else{
		printf("大一下 : 0\n");
	}
	if((solo3&finalchanging)>0){
		printf("大二上 : 1\n");
	}else{
		printf("大二上 : 0\n");
	}
	if((solo4&finalchanging)>0){
		printf("大二下 : 1\n");
	}else{
		printf("大二下 : 0\n");
	}
	if((solo5&finalchanging)>0){
		printf("大三上 : 1\n");
	}else{
		printf("大三上 : 0\n");
	}
	if((solo6&finalchanging)>0){
		printf("大三下 : 1\n");
	}else{
		printf("大三下 : 0\n");
	}if((solo7&finalchanging)>0){
		printf("大四上 : 1\n");
	}else{
		printf("大四上 : 0\n");
	}if((solo8&finalchanging)>0){
		printf("大四下 : 1\n");
	}else{
		printf("大四下 : 0\n");
	}	
    return 0;
}
