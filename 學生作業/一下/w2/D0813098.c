#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int maxnum=10;
    int count=0;
    char** namelist=calloc(maxnum,sizeof(char*));
    int input;
    int true_or_flase;
    //�ŧi�ܼ�maxnum�Bcount�Binput�Btrue_or_flase��namelist�����ЩM�����O����t�m
    do{
        printf("1.�s�W 2.�L�X 3.�Ƨ� 4.���}\n");
        //�L�X1.�s�W 2.�L�X 3.�Ƨ� 4.���}
        scanf("%d", &input);
        //��Jinput
        if(input==1){
            char *temname=calloc(100,sizeof(char));
            getchar();
            gets(temname);
            *(namelist+count)=calloc((strlen(temname)+1),sizeof(char));
            *(namelist+count)=temname;
            count++;
            if(count>9){
                maxnum+=5;
            }
            true_or_flase=0;
        }

        /* �p�Ginput��J����1�A�h�@�H�U����
           �ŧi�����ܼ�temname�Υ����O����t�m�A��Ja�A
           ��(namelist+count)���O����t�m������temname+1��char�j�p
           �]��(namelist+count)��a
           ��count�[1�A�p�Gcount�j��9�A�h�� maxnum�A�[5�A
           ��true_or_flase��0*/

        else if(input==2){
            for(int temcount=0;temcount<count;temcount++){
                printf("%s\n", namelist[temcount]);
            }
            true_or_flase=0;
        }
        /* �p�Ginput��J����2�A�h�@�H�U����
           �ϥ�for�j��temcount�q0��temcount�p��count�Atemcount�[1
           �L�Xnamelist[temcount]�����r��
           ��true_or_flase��0*/
        else if(input==3){
            char* temp;
            for (int temcount=0;temcount<count;temcount++){
                for(int temcount1=0;temcount1<=temcount;temcount1++){
                    if(  strcmp(namelist[temcount1],namelist[temcount])>0 ){
                        temp=namelist[temcount];
                        namelist[temcount]=namelist[temcount1];
                        namelist[temcount1]=temp;
                    }
                }
            }
            true_or_flase=0;
        }
        /* �p�Ginput��J����3�A�h�@�H�U����
           �ŧi�����ܼ�temp
           �ϥΨ��for�j��A�@�ӱqtemcount�q0��temcount�p��count�Atemcount�[1�B�t�@��temcount1�q0��temcount1�p��temcount�Atemcount1�[1
           �Ϩ�Ӱ}�C�h�@����A�p�G��̤�e�̤j�A�h�洫����
           ��true_or_flase��0
           */
        else if(input==4){
            for (int temcount=0;temcount<maxnum;temcount++){
                free(namelist[temcount]);
            }
            free(namelist);
            true_or_flase=1;
        }
        /* �p�Ginput��J����4�A�h����O����Ŷ�
           ��true_or_flase��1*/
        else{
            printf("��J���~�Э��s��J\n");
            true_or_flase=0;
        }
        /* �_�h�A�L�X��J���~�Э��s��J
            ��true_or_flase��0*/
    }while(true_or_flase==0);
    return 0;
}
