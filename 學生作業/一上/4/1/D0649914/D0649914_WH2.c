#include<stdio.h>
int main() {
	char record=0b11111111,change;
	int i,pass[8];
	change=0b00000010;
	record^=change;                                //事件編號一 11111111跟00000010做xor  變成11111101,因為小明大一下期末被當掉
	change=0b11111011;
	record&=change;                                //事件編號二 11111101跟11111011 做and 變成11111001 小明大二上修密碼學57分 被當了
	change=0b00000100;
	record|=change;                                //事件編號三 11111001跟00000100 做or 變成11111101 小明大二上求情加到60分
	change=0b11101111;
	record&=change;                                //事件編號四 11111101跟11101111 做and 變成11101101 小明大三上 50分
	change=0b10111111;                             
	record&=change;                                //事件編號五 11101101跟10111111 做and 變成10101101  小明大四上被當
	for(i=0;i<8;i++){
		change=((record>>i)&0b00000001);
		pass[i]=change;
	}
	printf("大一上:%d\n",pass[0]);
	printf("大一下:%d\n",pass[1]);
	printf("大二上:%d\n",pass[2]);
	printf("大二下:%d\n",pass[3]);
	printf("大三上:%d\n",pass[4]);
	printf("大三下:%d\n",pass[5]);
	printf("大四上:%d\n",pass[6]);
	printf("大四下:%d\n",pass[7]);
	return 0;
}
