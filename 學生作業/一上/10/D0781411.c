#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
	srand(time(NULL));
	int an[4];
	int i;
	i=0;
	int j;
	j=0;
	int a=0;
	int b=0;
	int k;
	char re[6]={'0','0','0','0','\0'};
	int con_flag=0;
	char con='Y';
	int re_flag=1;
	while(con=='Y')
	{
		int repeat_flag=0;//�k�s
		int Com[10]={0};//�k�s
		if(re_flag==1)//�n���nre (���諸�ɭԷ|re)   �H����4�Ӥ����ƼƦr~
		{
			for(i=0;i<4;i++)
			{
				an[i]=rand()%10;
				for(j=0;j<i;j++)
				{
					if(an[i]==an[j])
					{
						i--;
					}
				}
			}
		}
		for(i=0;i<4;i++){
            printf("%d",an[i]);
        }
        puts("");
		re_flag=0;
		printf(">> ");
		scanf("%s%*c",re);
		Com[re[0]-'0'-1]++;  //�p�⭫��
		Com[re[1]-'0'-1]++;
		Com[re[2]-'0'-1]++;
		Com[re[3]-'0'-1]++;
		for(i=0;i<10;i++)
		{
			if(Com[i]>=2)
			{
				repeat_flag=1;
			}
		}
		if(strlen(re)>4||strlen(re)<4||repeat_flag==1) //���Ƹ���׿��~�N���~
		{
			printf("INPUT ERROR\n");
			con_flag=1;
		}
		for(i=0;i<4;i++)
		{
			if(re[i]-'0'==an[i]) //�P�_a
			{
				a++;
			}
			for(j=0;j<4;j++)
			{
				if(re[j]-'0'==an[i]&&re[i]-'0'!=an[i]) //�P�_b
				{
					b++;
				}
			}
		}
		if(con_flag==0&&a!=4)
		{
			printf("%dA%dB\n",a,b);
		}
		if(a<4)
		{
			a=0;
		}
		while(a==4)
		{
			printf("YOU WIN\n");
			printf("Play Again?(Y/N)");
			scanf("%c%*c",&con);
			a=0;
			re_flag=1;
		}
		while(con!='N'&&con!='Y')
		{
			printf("Play Again?(Y/N)");
			scanf("%c%*c",&con);
		}
		con_flag=0;
		b=0;
	}
}
