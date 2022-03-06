#include<stdio.h>
int main()
{
    int lon=0,col=0,row=0;
    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf("%d",&lon);
    while(lon!=3&&lon!=5&&lon!=7&&lon!=9){
        printf("輸入錯誤\n");
        printf("輸入菱形對角線長度(3、5、7、9):");
        scanf("%d",&lon);
    }

    printf("輸入行數(2~10):");
    scanf("%d",&col);
    while(col<2||col>10){
        printf("輸入錯誤!\n");
        printf("輸入行數(2~10)");
        scanf("%d",&col);
    }

    printf("輸入列數(2~10):");
    scanf("%d",&row);
    while(row<2||row>10){
        printf("輸入錯誤!\n");
        printf("輸入列數(2~10)");
        scanf("%d",&row);
    }

 int a=0,I,J,K,b,p,q=0,T=0;

 q=++lon/2-1;
 for(K=0;K<col;K++)//輸出行數
 {

  for(T=0,I=1,b=1;I<lon;I++)//拼出菱形
  {
   for(J=0;J<row;J++)//第一排輸出幾個*
   {
    a=(lon-b)/2;
    for(p=0;p<a;p++)//先輸出p個空白
        printf(" ");

    for(p=0;p<b;p++)//輸出b個*
     printf("*");

    for(p=-1;p<a;p++)//輸出p+1個空白
        printf(" ");
   }


   if(T==0)//到中線前往下加兩顆星星
    b+=2;
   else if(T==1)//到中線後往下減兩顆星星
    b-=2;
   if(I==q)//到中線後T++
    T++;
   printf("\n");
  }

  printf("\n");
 }

}










