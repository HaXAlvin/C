#include<stdio.h>

struct fraction {  //分數結構 
	int son;
	int mom;
};

//輾轉相除法 + 約分 + 負號放分子
struct fraction Euclid(struct fraction ans){
	int temp;
	int m = ans.son;
	int n = ans.mom;
	if (m < 0) {
		m = m * -1;
	}
	if (n < 0) {
		n = n * -1;
	}
	if (m < n) {  //大數對小數求於
		temp = m;
		m = n;
		n = temp;
	}
	while (m % n != 0) {  //最後的n為兩數的最大公因數
		temp = m % n;
		m = n;
		n = temp;

	}

	//約分
	ans.son = ans.son / n;
	ans.mom = ans.mom / n;

	//負號統一放分子 
	if (ans.mom < 0) {
		ans.mom = ans.mom * -1;
		ans.son = ans.son * -1;
	}

	return ans;
}

//加法函式 
struct fraction add(struct fraction front, struct fraction back) {
	front.son = front.son * back.mom;  //分子通分
	back.son = back.son * front.mom;   //分子通分
	front.mom = front.mom * back.mom;  //分母通分
	back.mom = front.mom;              //分母通分

	struct fraction ans;  //放相加後的分數
	ans.son = front.son + back.son;
	ans.mom = front.mom;

	return Euclid(ans);
};
//減法函式 
struct fraction sub(struct fraction front, struct fraction back) {
	front.son = front.son * back.mom;  //分子通分
	back.son = back.son * front.mom;   //分子通分
	front.mom = front.mom * back.mom;  //分母通分
	back.mom = front.mom;              //分母通分

	struct fraction ans;  //放相減後的分數 
	ans.son = front.son - back.son;
	ans.mom = front.mom;

	return Euclid(ans);
};
//乘法函式 
struct fraction mul(struct fraction front, struct fraction back) {
	struct fraction ans;
	ans.son = front.son * back.son;
	ans.mom = front.mom * back.mom;

	return Euclid(ans);
};
//除法函式 
struct fraction div(struct fraction front, struct fraction back) {
	//分數除法，後項分子分母顛倒 
	int change;
	change = back.son;
	back.son = back.mom;
	back.mom = change;
	
	struct fraction ans = mul(front, back);  //顛倒後使用分數乘法函式

	return Euclid(ans);
};

int main() {
	
	while (1) {
		int choose = 0;
		printf("選擇(1.加/2.減/3.乘/4.除/0.離開)：");
		scanf("%d", &choose);
		
		char mark[6] = {0, '+', '-', '*', '/' };

		printf("a/b %c c/d，請輸入a b c d：", mark[choose]);
		if (choose == 0) {
			break;
		}
		else if(choose < 0 || choose  >= 5){
			printf("輸入錯誤\n\n");
			continue;
		}

		struct fraction front;  //存放前面的a分子、b分母
		struct fraction back;   //存放後面的c分子、d分母
		scanf("%d %d %d %d", &front.son, &front.mom, &back.son, &back.mom);
		if (front.mom == 0 || back.mom == 0) {
			printf("分母不可為0\n\n");
			continue;
		}
		if ((choose == 3 || choose == 4) && back.son == 0) {
			printf("除數不可為0\n\n");
			continue;
		}

		struct fraction ans;  //放結果

		if (choose == 1) {  //加
			ans = add(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d + %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d + %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 2) {  //減
			ans = sub(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d - %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d - %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 3) {  //乘
			ans = mul(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d * %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d * %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
		else if (choose == 4) {  //除
			ans = div(front, back);
			if (ans.son % ans.mom == 0) {
				printf("%d/%d / %d/%d = %d\n\n", front.son, front.mom, back.son, back.mom, ans.son);
			}
			else {
				printf("%d/%d / %d/%d = %d/%d\n\n", front.son, front.mom, back.son, back.mom, ans.son, ans.mom);
			}
		}
	}

	return 0;
}
