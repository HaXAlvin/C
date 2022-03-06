#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv){
    int dataNumber = 0;
    int once = 0;
    int arraySize =10;
    char cmd;
    char *(*studentArray) = (char**)calloc( sizeof(char *),arraySize);
    char input[1000];
    size_t len;
    while(1){
        printf("Type your command: ");
        cmd = getchar();
        if(cmd=='1'){
            if(dataNumber>5){
                once++;
                //realloc
                if (once == 5){
                    int i = (dataNumber/5 +1)*5;
                    printf("%d:%d",dataNumber,i);
                    arraySize = i;
                    char **newPtr = (char**)realloc((studentArray),sizeof(char *)*i);
                    free(studentArray);
                    studentArray = newPtr;
                    once = 0;
                }
            }
            printf("Type your data: ");
            scanf("%s",input);
            len = strlen(input);
            studentArray[dataNumber] = (char*)malloc(sizeof(char)*(len+1)); // dynamic array
            memcpy(studentArray[dataNumber],input,sizeof(char)*(len+1));
            dataNumber++;
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='2'){
            // Print all your data in array.
            int e =0;
            for(e = 0;e<dataNumber;e++){
                printf("Data[%d]: %s\n",e,studentArray[e]);
            }
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='3'){
            // sorting
            int r=0,t=0;
            for(r = 0;r<dataNumber;r++){
                for(t = 0;t<dataNumber-1;t++){
                    if( strcmp(studentArray[t],studentArray[t+1]) >  0 ){
                        char *ptr= studentArray[t];
                        studentArray[t] = studentArray[t+1];
                        studentArray[t+1] = ptr;
                    }
                }
            }
            int y =0;
            for(y = 0;y<dataNumber;y++){
                printf("Data[%d]: %s\n",y,studentArray[y]);
            }
            getchar(); // clear your 'Enter' key.
        }
        else if(cmd=='4'){
            getchar(); // clear your 'Enter' key.
            int u =0;
			for(u=0;u<dataNumber;u++){
				free(studentArray[u]);
			}
			free(studentArray);
			return 0;
        }
        else{
            getchar(); // clear your 'Enter' key.
            printf("You typing the wrong command.\n");
        }

    }

}
// n--------m
// |test
// |
// |
// |
