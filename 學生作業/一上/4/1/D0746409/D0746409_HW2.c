#include<stdio.h>
int main()
{
	char origin = 0b11111111;/*�]�w�]�ܼ�*/
	char pass = 0b00000001;/*pass �n�d1*/
	char fail = 0b11111110;/*fail �n�d0*/
	char first1 = origin | pass;/*�@�Wpass�ҥH��1�d1*/
	char first2 = first1 <<1 & fail;/*����1�� 1�Ufail ��0�d0*/
	char second1 = first2 <<1 | pass;/*����1 pass �d1*/
	char second2 = second1 <<1 | pass;;/*����1 pass �d1*/
	char third1 = second2 <<1 & fail;/*����1 fail �d0*/
	char third2 = third1 <<1 | pass;;/*����1 pass �d1*/
	char forth1 = third2 <<1 &fail;/*����1 fail �d0*/
	char forth2 = forth1 <<1 | pass;;/*����1 pass �d1*/
	printf("%d ",0b10110101);
	printf ("%d\n", forth2);/*�B�⵲�G*/
	/*char ans = 0b10110101;
	printf ("%d", ans);*/
	return 0;
}
