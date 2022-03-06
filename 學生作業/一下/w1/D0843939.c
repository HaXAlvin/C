#include<stdio.h>
#include<string.h>

size_t my_strlen(const char*s){
	//�]�w�Ѽ�
	int count = 0;
	int i;
	//�ΰj��P�_�r����רðO��
	for(i = 0; s[i] != 0; i++)
	{
		count++;
	}
	//�^�ǰO�ƭ�
	return count;
}

int my_strcmp(const char*s1,const char*s2){
	//�]�w�ܼ�
	int i;
	//�Q�ΰj����P�_��r��O�_��'\0'�A �A�P�_��r��O�_�ۦP
	for(i = 0; (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		if(s1[i] == s2[i])
		{
			continue;
		}
		else
		{
			break;
		}
	}
	//�^�ǭp�⪺��
	return s1[i] - s2[i];

}

char *my_strcpy(char *s1, const char *s2){
	//�]�w�ܼ�
	int i = 0;
	// �Y�r�ꤣ����'\0'�h�ƻs�U�Ӧr��r����ĤG�Ӧr�ꤤ
	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	//�s�W�r��'\0'
	s1[i] = '\0';
	//�^�ǽƻs���s���r��
	return s1;
}

char *my_strcat(char *s1, const char *s2){
	//�]�w�ܼ�
	int i,j;
	//���P�_�Ĥ@�Ӧr��O�_��'\0'
	for (i = 0; s1[i] != '\0'; i++);

    //�b�P�_�ĤG�Ӧr��O�_��'\0' �ós���_�r��
    for (j = 0; s2[j] != '\0'; j++)
        s1[i+j] = s2[j];
    s1[i+j] = '\0';
    //�^�ǳs�������r��
    return s1;

}


char *my_strstr(const char *s1, const char *s2){
	//�]�w�ܼ�
	char* ns1 = (char*)s1;
	char* ns2 = (char*)s2;

	while(*ns1)
	{
		//�]�wflag�^��
		char* flag = ns1;
		//�����r��A�Y�۵��h���U���
		while((*ns1 == *ns2) && (*ns1 != '\0'))
		{
			ns1++;
			ns2++;
		}
		//�i��o�ͪ��T�ر��p
		//ns2�w��'\0
		if(!*ns2)
		{
			//��^flag
			return flag;
		}
		//ns1�w��'\0 ns2�S��
		if(!*ns1)
		{
			return NULL;
		}
		//���S���۲šA�~�򩹤U
		ns1++;
	}
	//�^�ǭ�
	return NULL;
}

int main(){
    char a1[20]="I love dog ";
    char b1[20]="and cat.";
    char c1[20]="love";
    char d1[20];

    char a2[20]="I love dog ";
    char b2[20]="and cat.";
    char c2[20]="love";
    char d2[20];

    printf("Length of a1:%d\n",strlen(a1));
    printf("My_Length of a1:%d\n",my_strlen(a1));
    printf("\n");

    printf("Strcmp of a1 and a2:%d\n",strcmp(a1,a2));
    printf("My_Strcmp of a1 and a2:%d\n",my_strcmp(a1,a2));
    printf("\n");

    printf("Strcmp of a1 and b1:%d\n",strcmp(a1,b1));
    printf("My_Strcmp of a1 and b1:%d\n",my_strcmp(a1,b1));
    printf("\n");

    printf("Strcmp of c1 and a1:%d\n",strcmp(c1,a1));
    printf("My_Strcmp of c1 and a1:%d\n",my_strcmp(c1,a1));
    printf("\n");

    printf("Strcpy of d1 and a1:%s\n",strcpy(d1,a1));
    printf("My_Strcpy of d2 and a2:%s\n",my_strcpy(d2,a2));
    printf("\n");

    printf("Strcat of d1 and b1:%s\n",strcat(d1,b1));
    printf("My_Strcat of d2 and b2:%s\n",my_strcat(d2,b2));
    printf("\n");


    printf("Strstr of d1 and c1:%s\n",strstr(d1,c1));
    printf("My_Strstr of d2 and c2:%s\n",my_strstr(d2,c2));
    printf("\n");

    return 0;
}
