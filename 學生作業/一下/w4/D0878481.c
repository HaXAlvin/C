#include<stdio.h>
#include<stdlib.h>
struct div{
    int a,b;
};
int test(int x,int y){//����۰��k
    x=abs(x);
    y=abs(y);
    while((x!=0)&&(y!=0)){//��x,y�������s��
        if (x>y){
            x=x%y;//�۰����l��
        }
        else {
            y=y%x;
        }
    }
    if (x==0){//�p���@�����s�ɡA�h�̤j���]�ƫh���t�@��
        return y;
    }
    else{
        return x;
    }


}

void addandsub(int first,int second,int third,int forth,int i){
    int temp1,temp2,gcd,k=0;
    struct div answer;
    third=third*second;
    first=first*forth;
    if (i==1){//�Y���[�k
        answer.a=first+third;
    }
    else {//��k
        answer.a=first-third;
        if (answer.a<0){
            k=1;
        }
    }
    answer.b=second*forth;
    temp1=answer.a;
    temp2=answer.b;
    gcd=test(answer.a,answer.b);//��̤j���]��
    if (k==0){//�����t��
        if (temp2/gcd!=1)//���������@
            printf(" %d/%d\n\n",temp1/gcd,temp2/gcd);
        else//�������@
            printf(" %d\n\n",temp1/gcd);
    }
    else {//�Y���t�ơA�b���l�[�W�t��
        if (temp2/gcd!=1)//���������@
            printf(" -%d/%d\n\n",temp1/gcd,abs(temp2/gcd));
        else//�������@
            printf(" -%d\n\n",temp1/gcd);
    }
    return;
}

void multianddiv(int first,int second,int third,int forth,int i){
    struct div answer;
    int temp[4];//�s��J�Ʀr
    int x;//�p�⦳�X�ӭt��
    int gcd,temp1,temp2,temp3;
    temp[0]=first;
    temp[1]=second;
    temp[2]=third;
    temp[3]=forth;
    for (int k=0;k<4;k++){
        if (temp[k]<0){
            x++;//�������X�Ӭ��t��
        }
    }

    if (i==4){//�Y�����k�h���N�Ĥ@���Ȱ��˼�
        temp3=forth;
        forth=third;
        third=temp3;

    }
    answer.a=first*third;//�O������Ƶ��c��

    answer.b=second*forth;

    gcd=test(answer.a,answer.b);//�D�X�̤j���]��

    if (x%2==0){//�Y�t�Ƭ�����
        if (answer.b/gcd!=1)//���p���������@
            printf(" %d/%d\n\n",abs(answer.a/gcd),abs(answer.b/gcd));
        else
            printf(" %d\n\n",abs(answer.a/gcd));
    }
    else {//�t�Ƭ��_��
        if (answer.b/gcd!=1)//���p���������@
            printf(" -%d/%d\n\n",abs(answer.a/gcd),abs(answer.b/gcd));
        else
            printf(" -%d\n\n",abs(answer.a/gcd));
    }
    return;
}

int main(){
    struct div num[2];
    int input;
    while(1){
        printf("�п��(1.�[�k/2.��k/3.���k/4.���k/0.���}):");
        scanf("%d",&input);
        getchar();
        if (input==0){
            break;
        }
        if (input>4){//���b
            printf("��J���~\n\n");
            continue;
        }
        switch(input){//��ܥ[���
            case 1:
                printf("a/b + c/d�A��Ja b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 2:
                printf("a/b - c/d�A��Ja b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 3:
                printf("a/b * c/d�A��Ja b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            case 4:
                printf("a/b / c/d�A��Ja b c d:");
                scanf("%d %d %d %d",&num[0].a,&num[0].b,&num[1].a,&num[1].b);
                break;
            }
        if ((num[0].b==0)||(num[1].b==0)){//���b
            printf("�������i��0\n\n");
            continue;
        }
        else if ((input==4)&&(num[1].a==0)){//���b
            printf("���Ƥ��i��0\n\n");
            continue;
        }
        else {
            if (input==1){//�ǤJ�[��k�Ƶ{��
                printf("%d/%d + %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==2){
                printf("%d/%d - %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                addandsub(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }
            else if (input==3){//�ǤJ�����k�Ƶ{��
                printf("%d/%d * %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);

            }
            else {//�ǤJ�����k�Ƶ{��
                printf("%d/%d / %d/%d =",num[0].a,num[0].b,num[1].a,num[1].b);
                multianddiv(num[0].a,num[0].b,num[1].a,num[1].b,input);
            }

        }

    }



}
