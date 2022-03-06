#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	int i, j , t,temp;
	int c,n,cmp;

	char name[n];
	char** table;

	//table[] = malloc(sizeof(char) *n);

	scanf("%d",&c);

	switch(c){
		case 1:
			printf("How many students?");
			scanf("%d",&n);
			table = malloc(sizeof(char *) *10);//一維
			t = n - 10;
			while (t > 5)
			{
				table = malloc(sizeof(char *) *5);
				t = t-5;
				printf("%d",t);
			}
			for(i = 0 ; i < n;i++)
			{
				scanf("%s",&name);
				table[i]= name;
				printf("%s\n",	table[i]);
			}
		case 2:
			for(i=0;i<n;i++){
				printf("table[%d] = %s\n", i , table[i]);
			}

		case 3:

			cmp=strcmp(table[i],table[j]);
			for (i = 0 ;i < n;i++)
			{
				for (j = 1 ;j <i;j++ )
				{  //strcmp > 0 , 前者較小
					if (cmp > 0 )
					{
				        temp = &table[j];
				        &table[j] = &table[i];
				        &table[i] = temp;
			      	}
				}
			}
			for(i=0;i<n;i++){
				printf("table[%d] = %s\n", i , table[i]);
			}
		case 4:
			for(i=0;i<n;i++)
			{
				free(table[i]);
			}
			free(table);
		break;
	}
	return 0;
}

