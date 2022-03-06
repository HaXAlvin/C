#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int choose = 0,num = 0;
    char name[10];
    int i=0,j,k;
    char temp;
    char *list[10];

    while(1){
        printf("1.Enter Student Name\n2.Print out\n3.Sort Students Name\n4.Leave\n\n");
        printf("Enter A Number:");
        scanf("%d",&choose);
        printf("\n");
        switch(choose){
            case 1://enter student name
                printf("Please enter how many number of names to be recorded.\n");
                scanf("%d", &num);
                printf("Enter the name of students\n");
                for(k=0;k<num;k++){
                    scanf("%s",&list[k]);
                }
                printf("\n");
                break;
            case 2://print out students name
                for(i=0;i<num;i++){
                printf("%s",list[i]);
                }
                break;
            case 3://sort
                for(i=0; i < num-1 ; i++){
                    for(j=i+1; j< num; j++)
                    {
                        if(strcmp(name[i],name[j]) > 0)
                        {
                             strcpy(temp,name[i]);
                             strcpy(name[i],name[j]);
                             strcpy(name[j],temp);
                        }
                    }
                }
                break;

            case 4://leave program
                printf("Thx For Using ^.^ \n");
                return 0;

            default ://others choose input
                printf("Input Error!\n\n");
                break;
        }
    }
return 0;
}
