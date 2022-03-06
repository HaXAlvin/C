#include<stdio.h>
int main()
{
	char origin = 0b11111111;/*設預設變數*/
	char pass = 0b00000001;/*pass 要留1*/
	char fail = 0b11111110;/*fail 要留0*/
	char first1 = origin | pass;/*一上pass所以有1留1*/
	char first2 = first1 <<1 & fail;/*往左1格 1下fail 有0留0*/
	char second1 = first2 <<1 | pass;/*往左1 pass 留1*/
	char second2 = second1 <<1 | pass;;/*往左1 pass 留1*/
	char third1 = second2 <<1 & fail;/*往左1 fail 留0*/
	char third2 = third1 <<1 | pass;;/*往左1 pass 留1*/
	char forth1 = third2 <<1 &fail;/*往左1 fail 留0*/
	char forth2 = forth1 <<1 | pass;;/*往左1 pass 留1*/
	printf("%d ",0b10110101);
	printf ("%d\n", forth2);/*運算結果*/
	/*char ans = 0b10110101;
	printf ("%d", ans);*/
	return 0;
}
