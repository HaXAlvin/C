#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int flag,flag2,ans[10]={0};//�ѥ��ܥk�̧Ǭ�:�P�_��1,�P�_��2,�q���ͦ��|�Ӽƪ��}�C
    char input[10],in[10];//�ѥ��ܥk�̧Ǭ�:�ϥΪ̿�J�|�ӼƦr���}�C,Play Again?(Y/N)����J

    do{
        srand(time(NULL));
        for(int n1=0;n1<4;n1++){//�ͦ��|���H�����
            do{
                ans[n1]=rand()%10;
                flag=0;
                for(int n2=0;n2<n1;n2++){//�P�_�ͦ�����ƬO�_����e���ͦ�������
                    if(ans[n1]==ans[n2])
                        flag++;
                }
            }while(flag>0);//���ƫh���s�ͦ�
            //printf("%d ",ans[n1]);//�ˬd��>�L�X�ͦ����|�Ӽ�
        }
        //puts(" ");//�ˬd��>�L�X�ͦ����|�ӼƤ�����
        for(int i=0;i<4;i++){
            printf("%d",ans[i]);
        }
        puts("");
        do{
            do{
                flag=0;
                printf(">> ");
                scanf("%s",input);//�ϥΪ̿�J�|�ӼƦr

                if(strlen(input)!=4)//�ˬd�O�_���|�Ӽ�
                    flag++;
                else{//�_�h�ˬd���L���ƼƦr
                    for(int n1=0;n1<4;n1++){
                        flag2=0;
                        for(int n2=0;n2<4;n2++){
                            if(input[n1]==input[n2])
                                flag2++;
                        }
                        if(flag2>1){//�p�G�����ƫh���X�j��
                            flag++;
                            break;
                        }
                    }
                }
                if(flag>0)//�p�G��J�����|�ӼƩΦ����ƫhflag>0
                    puts("INPUT ERROR");
            }while(flag>0);//��J���~�A���ƿ�J

            flag=0;
            flag2=0;

            for(int n1=0;n1<4;n1++){//�P�_nAmB
                for(int n2=0;n2<4;n2++){
                    if(input[n1]-48==ans[n2])//�P�_��J�P���צ��ۦP�Ʀr���ƶq=n+m=flag
                        flag++;
                }
                if(input[n1]-48==ans[n1])//�P�_��J�P���צ��ۦP�Ʀr�B�����T��m���ƶq=n=flag2
                    flag2++;
            }

            if(flag2!=4)//�p�G���רS���������T
                printf("%dA%dB\n",flag2,flag-flag2);//flag2=n,flag=n+m
        }while(flag2!=4);//�p�G���רS���������T�A�h�����a�A����J

        printf("YOU WIN\nPlay Again?(Y/N)");//�߰ݬO�_�b���@��
        while(scanf("%s",in)&&(strcmp(in,"Y")!=0&&strcmp(in,"N")!=0)){//�p�G���a��J���OY or N�A�h���ƿ�J
            printf("Play Again?(Y/N)");
        }

    }while(strcmp(in,"Y")==0);//��J��Y�h�b���@���A�_�h���X�j��A�����C��
}

