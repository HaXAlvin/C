#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct NID{
    char title;
    union ID{
        char ID_07[8];
        char ID_05[6];
    };
};
int main(){
    struct NID list[100]={0};
    //test01
    int count=0,len;
    while(scanf("%1c",&list[count].title)!=EOF){
        switch(list[count].title){
        case 'T':
            scanf("%s%*c",list[count].ID_07);
            break;
        case 'D':
            scanf("%s%*c",list[count].ID_07);
            break;
        }
        if(list[count].title == 'T'){
            printf("Good morning, teacher.\n");
        }else{
            int x = (list[count].ID_07[0]-'0')*10 + list[count].ID_07[1]-'7';
            char gender[6];
            if(!x){
                printf("Hi, my friend.\n");
            }else if(x>0){
                strcpy(gender,list[count].ID_07[2]%2?"girl":"boy");
                printf("Hi, young %s. I am %d year%c older than you.\n",gender,x,x==1?0:'s');
            }else{
                strcpy(gender,list[count].ID_07[2]%2?"woman":"man");
                printf("Hi, old %s. I am %d year%c younger than you.\n",gender,abs(x),x==-1?0:'s');
            }
        }
        count++;
    }
    //test02
    return 0;
}
