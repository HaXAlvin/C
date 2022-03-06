#include<stdio.h>
#include<math.h>

struct Fractional{
    int num;//���l
    int den;//����
};

struct Fractional reduction(struct Fractional answer){//���������²(���Ȧp�� ���t�Ƨڤ]�b�o�̳B�z �ҥH�ݷ|��struct�B�⤣�ξ�߭t�ƪ���m
    int t;//���s
    int ans_num = answer.num;
    int ans_den = answer.den;
    if(ans_den<0){//���N����ܬ����� �]���ݷ|�n�D�X�̤j���]��
        ans_den = ans_den * -1;
    }
    if(ans_num<0){//���N����ܬ����� �]���ݷ|�n�D�X�̤j���]��
        ans_num = ans_num * -1;
    }
    if(ans_num<ans_den){//���Ѥp�ƨ�j
        t=ans_num;
        ans_num=ans_den;
        ans_den=t;
    }
    while(ans_num%ans_den!=0){//�S�����b���� �@���� ex:1/3 �o�ɪ�t=1 ���l�O=3 ����=1 �̤j���]�ƬO��������=t �N���ɤF
        t=ans_num%ans_den;
        ans_num=ans_den;
        ans_den=t;
    }

    answer.num=answer.num/ans_den;//���̤j���]��
    answer.den=answer.den/ans_den;//���̤j���]

    if(answer.den<0){
        answer.num=answer.num*-1;//�쥻�N�L�ܬ����ƭn�ܦ^��
        answer.den=answer.den*-1;//�P�W
    }
    return answer;
};
struct Fractional add(struct Fractional first,struct Fractional second){//�[�k(first=a/b;second=c/d

    first.num=first.num*second.den;//���N�Ʀr�q���~����l�ۥ[1/2 3/4
    second.num=second.num*first.den;//���������ۦP
    first.den=first.den*second.den;
    second.den=first.den;//���ɪ��e�̤����N�O�q���᪺�F
    struct Fractional answer;
    answer.num=first.num+second.num;//���ת����l
    answer.den=first.den;//���ת�����
    return reduction(answer);
};
struct Fractional subb(struct Fractional first,struct Fractional second){//��k
    first.num=first.num*second.den;//�P�W
    second.num = second.num * first.den;
    first.den=first.den*second.den;
    second.den=first.den;
    struct Fractional answer;
    answer.num=first.num-second.num;
    answer.den=first.den;
    return reduction(answer);
};
struct Fractional mult(struct Fractional first,struct Fractional second){//���k

    struct Fractional answer;
    answer.num=first.num*second.num;
    answer.den=first.den*second.den;
    return reduction(answer);
};
struct Fractional div(struct Fractional first,struct Fractional second){//���k
    struct answer;
    //�N�ĤG�������l�������(���k�����O���Ʈ��W�ӭn�˼�)
    int t;
    t=second.num;
    second.num=second.den;
    second.den=t;
    struct Fractional answer;
    answer=mult(first,second);
    return reduction(answer);
};
int main(){
    int choose;
    struct Fractional answer;
    struct Fractional first;
    struct Fractional second;
    while(1){
        printf("���(1.�[/2.��/3.��/4.��/0.���}):");
        scanf("%d",&choose);
        if(choose>4||choose<0){
            printf("��J���~\n");
        }
        if(choose==0){
            break;
        }
        else if(choose==1){
            printf("a/b + c/d�A�п�� a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=add(first,second);
            if(answer.num%answer.den==0){
                printf("%d/%d + %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d + %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==2){
            printf("a/b - c/d�A�п�� a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=subb(first,second);
            if(answer.num%answer.den==0){
                printf("%d/%d - %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d - %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==3){
            printf("a/b * c/d�A�п�� a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=mult(first,second);
            if(answer.num%answer.den==0){

                printf("%d/%d * %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d * %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
        else if(choose==4){
            printf("a/b / c/d�A�п�� a b c d :");
            scanf("%d %d %d %d",&first.num,&first.den,&second.num,&second.den);
            answer=div(first,second);
            if(answer.den==0){
                printf("�������i��0\n");
            }
            else if(answer.num==0){
                printf("���Ƥ��i��0\n");
            }
            else if(answer.num%answer.den==0){
                printf("%d/%d / %d/%d = %d\n\n",first.num,first.den,second.num,second.den,(answer.num/answer.den));
            }
            else{
                printf("%d/%d / %d/%d = %d/%d\n\n",first.num,first.den,second.num,second.den,answer.num,answer.den);
            }
        }
    }
    return 0;
}
