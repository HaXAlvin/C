#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct array
{
    union function
    {
        int i;
        float f;
        char c[16];
    };
    int i1;
    char c1;
};//�ŧi array�����c�禡�A�䤤�]�t����ܼơB�r��M�@��union(�Ψ��x�s���)
int main()
{
    struct array *arr=malloc(sizeof(struct array));;//�ŧi���c�W
    int count=0;//�ŧi�ܼ�
    while(1){
        printf("���(1.�s�W/2.�L�X/0.����):");//�L�X���(1.�s�W/2.�L�X/0.����):
        scanf("%d", &arr[count].i1);
        if(arr[count].i1==0){
            free(arr);
            break;
        }//�p�G��J����0�A�h����j��
        else if(arr[count].i1==1){
            while(1){
                printf("�������(i.int/f.float/c.char[16]):");
                getchar();
                scanf("%c", &arr[count].c1);

                if (arr[count].c1=='i'){
                    printf("��J���:");
                    scanf("%d", &arr[count].i);
                    break;
                }
                else if(arr[count].c1=='f'){
                    printf("��J���:");
                    scanf("%f", &arr[count].f);
                    break;
                }
                else if(arr[count].c1=='c'){
                    printf("��J���:");
                    scanf("%s", &arr[count].c);
                    break;
                }
                else {
                    printf("��J���~�A�Э��s��J\n");
                }
            }
        }//�p�G��J����1�A�h�L�X�������(i.int/f.float/c.char[16]):�A�B���ϥΪ̿�J
        else if(arr[count].i1==2){
            for(int countdown=0;countdown<count;countdown++){
                if(arr[countdown].c1=='i'){
                    printf("%d\n", arr[countdown].i);
                }
                else if(arr[countdown].c1=='f'){
                    printf("%f\n", arr[countdown].f);
                }
                else if(arr[countdown].c1=='c'){
                    printf("%s\n", arr[countdown].c);
                }
            }
        }//�p�G��J����2�A�h�L�X�Ҧ��s�W��
        else {
            printf("��J���~�A�Э��s��J\n");
        }//�_�h�L�X��J���~�A�Э��s��J
        count++;
    }
    return 0;
}
