#include<stdio.h>
int main()
{
    int lon=0,col=0,row=0;
    printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
    scanf("%d",&lon);
    while(lon!=3&&lon!=5&&lon!=7&&lon!=9){
        printf("��J���~\n");
        printf("��J�٧ι﨤�u����(3�B5�B7�B9):");
        scanf("%d",&lon);
    }

    printf("��J���(2~10):");
    scanf("%d",&col);
    while(col<2||col>10){
        printf("��J���~!\n");
        printf("��J���(2~10)");
        scanf("%d",&col);
    }

    printf("��J�C��(2~10):");
    scanf("%d",&row);
    while(row<2||row>10){
        printf("��J���~!\n");
        printf("��J�C��(2~10)");
        scanf("%d",&row);
    }

 int a=0,I,J,K,b,p,q=0,T=0;

 q=++lon/2-1;
 for(K=0;K<col;K++)//��X���
 {

  for(T=0,I=1,b=1;I<lon;I++)//���X�٧�
  {
   for(J=0;J<row;J++)//�Ĥ@�ƿ�X�X��*
   {
    a=(lon-b)/2;
    for(p=0;p<a;p++)//����Xp�Ӫť�
        printf(" ");

    for(p=0;p<b;p++)//��Xb��*
     printf("*");

    for(p=-1;p<a;p++)//��Xp+1�Ӫť�
        printf(" ");
   }


   if(T==0)//�줤�u�e���U�[�����P�P
    b+=2;
   else if(T==1)//�줤�u�᩹�U������P�P
    b-=2;
   if(I==q)//�줤�u��T++
    T++;
   printf("\n");
  }

  printf("\n");
 }

}










