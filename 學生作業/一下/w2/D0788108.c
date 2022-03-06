#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	// 初始話
	int condition;
	int name_count = 0;
	int count = 2;
	char **name_ptr;
	name_ptr = malloc(10 * sizeof(char *));


	while (scanf("%d", &condition)){
		getchar();
		if (condition == 4){
			for (int i = 0; i < name_count; i++){
				free(name_ptr);
			}
			free(name_ptr);
			break;
		}

		else if (condition == 1){
			//因為是5個一數所以5＊count
			//count 原本是2如果它大於10(5*2), count就++,所以就會name_ptr就會realloc成15(5*3)
			if (name_count >= 5 * count){
				count++;
				name_ptr = realloc(name_ptr, 5 * count * sizeof(char *));
			}

			char name[100];
			fgets(name, 100, stdin);
			int len = strlen(name);
			// len+1 是因為要加\0
			name_ptr[name_count] = malloc((len+1) * sizeof(char));
			strcpy(name_ptr[name_count], name);
			name_count++;
		}
		else if (condition == 2){
			for (int i = 0; i < name_count; i++){
				printf("%s", name_ptr[i]);

			}
		}
		
		else if (condition == 3){
			for (int i = 0; i < name_count-1; i++){
				for (int j = 0; j < name_count-i-1; j++){
					int temp = strcmp(name_ptr[j], name_ptr[j+1]);
					char* ptr;
					if (temp > 0){
						ptr = name_ptr[j];
						name_ptr[j] = name_ptr[j + 1];
						name_ptr[j + 1] = ptr;
					}
				}
			}
		} 
	}
	return 0;
}