#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int create(char *ptr1,int *ptr2){                       //�s�W����� 
	gets(ptr1);
	*ptr2=*ptr2+1;
	return strlen(ptr1);
}
void format(char **ptr,int j){                         //�L�X����� 
	int i;
	for(i=0;i<j;i++)
		printf("%s\n",ptr[i]);
}
void chage(char **ptr,int count){                       //��w�ƧǪk 
	int i,j;
	for(i=0;i<count-1;i++){
		for(j=0;j<count-i-1;j++)
		if(strcmp(ptr[j],ptr[j+1])>=0){
			char *s1=ptr[j];
			ptr[j]=ptr[j+1];
			ptr[j+1]=s1;
		}
	}
}
int main(){
	char **name;			//�G���ʺA�}�C-�ǥͩm�W�s�񪺫����ܼ� 
	char newname[100];		//�s��s�W�W�r���ܼ� 
	int len;				//�s��s�W�W�r�����ת��ܼ� 
	int user;				//�ϥΪ̿�J���ܼ� 
	int count=0;     		//�~��Ŷ��{�b���X�Ӫ��ܼ� 
	int i,j;
	name=malloc(10*sizeof(char *));                 
	printf("1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
	while(scanf("%d%*c",&user)!=EOF && user!=4){                   //��J4�N�O���} 
		switch(user){
			case 1:                                                //�s�W 
				len=create(newname,&count);
				name[count-1]=calloc(len,sizeof(char));
				strcpy(name[count-1],newname);						//�ƻsnewname���� 
				if(count==10)										//�W�L�Ŷ�,�s�W 5 ���Ŷ����� 
					name=realloc(name,(count+5)*sizeof(char*));
				else if(count>10 && count%5==0)
					name=realloc(name,(count+5)*sizeof(char*));
				break;
			case 2:
				format(name,count);									//�C�X�m�W 
				break;
			case 3:													
				chage(name,count);									//��w�Ƨ� 
				break;
		}
		printf("1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
	}
	for(i=0;i<count;i++)
		free(name[i]);												//����@�� 
	free(name);														//����G�� 
	return 0;
} 
