#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A{
	union tagB{
		int i;
		float f;
		char s[16];	
	}B;
};

int main(){
	char cmd;
	struct A *sa = malloc(sizeof(struct A));
	while(1){
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        cmd = getchar();
        if(cmd=='1'){
        	char a;
           	printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G ");
           	scanf("%c",&a);
           	if(a == 'i'){
           		printf("��J��ơG");
           		scanf("%d",(*sa).B.i);
			}
			else if(a == 'f'){
				printf("��J��ơG");
				scanf("%f",(*sa).B.f);
			}
			else if(a == 's'){
				printf("��J��ơG");
				scanf("%s",(*sa).B.s);
			}
			else{
				printf("��J���~�I\n");
			}
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='2'){
     		
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='0'){
        	printf("�����{��\n");
        	break;
		}
        else{
        	printf("��J���~�I\n");
            getchar(); // clear your 'Enter' key.  
        }

    }
	
}
