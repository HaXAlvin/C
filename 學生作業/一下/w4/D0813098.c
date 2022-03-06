#include<stdio.h>
typedef struct div
{
    int up;
    int down;
}div;//�@��������ƪ����c���Ƶ{��
int gcd(int up,int down)
{
    if(down==0){
        return up;
    }
    else{
        return gcd(down,up%down);
    }
}//�D�X�̤j���]�ƪ��Ƶ{��
div add(div a,div b, div divtem)
{
    divtem.up=a.up*b.down+a.down*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//����[�k���Ƶ{��
div multi(div a,div b, div divtem)
{
    divtem.up=a.up*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//�����k���Ƶ{��
div sub(div a,div b, div divtem)
{
    divtem.up=a.up*b.down-a.down*b.up;
    divtem.down=a.down*b.down;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//���󭼪k���Ƶ{��
div divide(div a,div b, div divtem)
{
    divtem.up=a.up*b.down;
    divtem.down=a.down*b.up;
    int tem_up=divtem.up;
    int tem_down=divtem.down;
    divtem.up=divtem.up/gcd(tem_up,tem_down);
    divtem.down=divtem.down/gcd(tem_up,tem_down);
    return divtem;
}//���󰣪k���Ƶ{��
int main()
{
    int input;
    while(1){
        struct div div1;
        struct div div2;
        struct div div3={0,0};//�ŧi���cdiv1�Bdiv2�Bdiv3
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");//�L�X���(1.�[/2.��/3.��/4.��/0.���}):
        scanf("%d", &input);
        if (input==0){
            break;
        }//�p�G��J�O0�A�h����
        else if(input==1){
            printf("a/b +  c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("�������ର0\n");
            }
            else {
                div3=add(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//�_�h�p�G�O1�A�h�}�l�Υ[�k�A�ϥΨ�[�k���Ƶ{��
        else if(input==2){
            printf("a/b -  c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("�������ର0\n");
            }
            else {
                div3=sub(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//�_�h�p�G�O2�A�h�}�l�δ�k�A�ϥΨ��k���Ƶ{��
        else if(input==3){
            printf("a/b *  c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("�������ର0\n");
            }
            else {
                div3=multi(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//�_�h�p�G�O3�A�h�}�l�έ��k�A�ϥΨ쭼�k���Ƶ{��
        else if(input==4){
            printf("a/b /  c/d�A�п�Ja b c d:");
            scanf("%d %d %d %d", &div1.up, &div1.down, &div2.up, &div2.down);
            if(div1.down==0||div2.down==0){
                printf("�������ର0\n");
            }
            else if( (div2.up*div2.down) ==0){
                printf("���Ƥ��ର0\n");
            }
            else {
                div3=divide(div1,div2,div3);
                if( div3.up ==0 || div3.down==1){
                    printf("%d/%d + %d/%d=%d\n", div1.up, div1.down, div2.up, div2.down, div3.up);
                }
                else {
                    if(div3.down<0){
                        div3.up=div3.up*-1;
                        div3.down=div3.down*-1;
                    }
                    printf("%d/%d + %d/%d=%d/%d\n", div1.up, div1.down, div2.up, div2.down, div3.up,div3.down);
                }
            }
        }//�_�h�p�G�O4�A�h�}�l�ΰ��k�A�ϥΨ찣�k���Ƶ{��
        else {
            printf("��J���~�A�Э��s��J\n");
        }//�_�h�L�X��J���~�A�Э��s��J
    }
    return 0;
}
