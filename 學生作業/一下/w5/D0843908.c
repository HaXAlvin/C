#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _Struct{
    union Union{
        int save_int;
        float save_float;
        char save_s[16];
    }Union;
    char save;
}Struct;

int main(){
    //�ŧi�}�C
    Struct str[0];
    Struct *ptr = &str[0];
    //�Ĥ@���t�m�Ŷ�
    ptr = malloc(sizeof(struct _Struct));
    //while�� num ������
    int num = 1;
    while(1){
        //���
        int what;
        //��ܰʧ@�P���b
        while(1){
            printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
            scanf("%d%*c",&what);
            if(what!=1 && what!=2 && what!=0){
                printf("��J���~!\n");
                continue;
            }
            break;
        }
        if(what==0){
            printf("�����{��");
            free(ptr);
            return 0;
        }
        //����x�s�����P�x�s
        if(what==1){
            while(1){
                printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
                scanf("%c%*c",&str[num].save);
                if(str[num].save!='i'&&str[num].save!='f'&&str[num].save!='s'){
                    printf("��J���~!\n");
                    continue;
                }
                if(str[num].save=='i'){
                    printf("��J��ơG");
                    scanf("%d",&str[num].Union.save_int);
                }
                if(str[num].save=='f'){
                    printf("��J��ơG");
                    scanf("%f",&str[num].Union.save_float);
                }
                if(str[num].save=='s'){
                    printf("��J��ơG");
                    scanf("%s",&str[num].Union.save_s);
                }
                break;
            }
        }
        //�L�X
        if(what==2){
            for(int i=1;i<=num;i++){
                if(str[i].save=='i'){
                    printf("%d\n",str[i].Union.save_int);
                }else if(str[i].save=='f'){
                    printf("%f\n",str[i].Union.save_float);
                }else if(str[i].save=='s'){
                    printf("%s\n",str[i].Union.save_s);
                }
            }
        }
        num++;
        //�t�m�s�Ŷ�
        ptr = realloc(ptr, (num+1) * sizeof(struct _Struct));
    }
}
