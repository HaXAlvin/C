#include<stdio.h>
#include<stdlib.h>

struct number_1{
	char type;
    union number_u{
		int i_u;
		float f_u;
		char c_u[16];
	}u;
};


void setA(struct number_1 *p){
	int temp;
	scanf("%d",&temp);
	(p->u).i_u = temp;
}
void setB(struct number_1 *p){
	float temp;
	scanf("%f",&temp);
	(p->u).f_u = temp;
}

void printdata(struct number_1 *p){
    if(p->type == 'i'){
        printf("%d\n",(p->u).i_u);
    }
    if(p->type == 'f'){
        printf("%f\n",(p->u).f_u);
    }

}


int main(void) {
	int choose,count=0,i;
	char type;
	struct number_1 *p = malloc( sizeof(struct number_1));

	while(1){

        printf("Choose:1.Add/2.Print/3.End:");
        scanf("%d",&choose);
        getchar();
        if(choose == 2){
            for (i=0; i<count; i++){
                printdata(&p[i]);
            }

	}


    }
}
