#include<stdio.h>
#include<stdlib.h>

struct all{
    char type;
    union all_data{
        int i;;
        float f;
        char s[16];
    }data;
};

void setA(struct all *ptr){
    int temp;
    scanf("%d",&temp);
    (ptr->data).i = temp;
}

void setB(struct all *ptr){
    float temp;
    scanf("%f",&temp);
    (ptr->data).f = temp;
}
void print(struct all *ptr){
    if(ptr->type == 'i'){
        printf("%d\n",(ptr->data).i);
    }
    if(ptr->type == 'f'){
        printf("%f\n",(ptr->data).f);
    }
    if(ptr->type == 'c'){
        printf("%s\n",(ptr->data).s);
    }

}
int main(){
    int choose = 0,count = 0,i;
    char type;
    struct all *ptr = malloc(sizeof(struct all));
    while(1){
        printf("Please Choose:(1.Add/2.Print/0.End) : ");
        scanf("%d%*c",&choose);
        if(choose == 0 ){
            printf("End Of Program.");
            return 0;
        }
        if(choose > 2){//input error system
            printf("Input Error!!!\n");
            continue;
        }
        if(choose == 1){
            printf("Choose Type : (i : int/f : float/s : char[16]) : ");
            scanf("%c",&type);
            switch(type){
                case 'i':
                    printf("Insert Data : ");
                    setA(&ptr[count]);
                    break;
                case 'f':
                    printf("Insert Data : ");
                    setB(&ptr[count]);
                    break;
                case 's':
                    printf("Insert Data : ");
                    //scanf("%s%*c",data.s);
                    break;
                default :
                    printf("Input Error!!\n");
                    continue;
            }
            count+=1;
        }
        if(choose == 2){
            for(i=0; i<count; i++){
				print(&ptr[i]);
			}
        }
    }
    return 0;
}


