#include<stdio.h.>
#include<stdlib.h>
#include<string.h>

int main(){
    char**name;
    name = malloc(10 * sizeof(char*));
    //�����X�Ӥw�s�W�X�ӦW�r
    int i = 0;
    int newchar = 0;
    while(1){
        printf("1.�s�W\n2.�L�X\n3.�Ƨ�\n4.���}\n�п�J:");
        int num = 0;
        scanf("%d%*c",&num);
        if(num!=1&&num!=2&&num!=3&&num!=4){
            printf("\n��J���~\n\n");
            continue;
        }
        if(num==1){
            //�W�L10�ӦW�r�n�[�Ŷ�
            if(i==(10+5*newchar)){
                    printf("new\n");
                name = realloc(name,(i+5*(newchar+1))*sizeof(char*));
                newchar++;
            }
            //�W�r�Ȧs
            char tempname[500];
            //char*tempname_point;
            printf("\n�п�J:");
            scanf("%s",&tempname);
            //�W�r����
            int tempname_length = strlen(tempname);
            //���t�Ŷ����W�r
            name[i] = malloc(((tempname_length)+1) * sizeof(char));
            //�s�J�W�r
            strcpy(name[i],tempname);
            //free(tempname_point);
            i++;
            printf("\n");
        }
        if(num==2){
            printf("\n");
            //�L�X�Ҧ��W�r
            int o=0;
            while(o<i){
                int p=0;
                while(name[o][p]!='\0'){
                    printf("%c",name[o][p]);
                    p++;
                }
                printf("\n");
                o++;
            }
            printf("\n");
        }
        if(num==3){
            //�w�j�Ƨ�
            for(int j=i-1;j>0;j--){
                for(int k=0;k<j;k++){
                    if(strcmp(name[k],name[k+1])>0){
                        char*temp1 = name[k];
                        char*temp2 = name[k+1];
                        name[k] = temp2;
                        name[k+1] = temp1;
                    }
                }
            }
            printf("\n");
        }
        if(num==4){
            //�M�ŰʺA�O���� �����{��
            for(int j=0;j<(9+5*newchar);j++){
                free(name[i]);
            }
            free(name);
            return 0;
        }
    }
}
