#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 100
int main(){
    char a= 'b';
    switch(a){
    case 'b':
        printf("hi");
    }
//    FILE *fp;
//    FILE *fw;
//    char line[MAX_TEXT];
//    char *result;
//
//    fp=fopen("gapminder.csv","r");
//    fw=fopen("write.csv","w");
//    if(!fp){
//        printf("Error");
//        exit(EXIT_FAILURE);
//    }
//    if(!fw){
//        printf("Error");
//        exit(EXIT_FAILURE);
//    }
//
//    while(fgets(line,MAX_TEXT,fp)!=NULL){
//        result = strtok(line,",");
//        int i=0;
//        while(result!= NULL){
//            i++;
//
//            printf("%-25s",result);
//            fprintf(fw,"%s,",result);
//
//            result = strtok(NULL,",");
//        }
//        puts("");
//        fprintf(fw,"\n");
//    }
//    fclose(fp);
//    fclose(fw);

}
