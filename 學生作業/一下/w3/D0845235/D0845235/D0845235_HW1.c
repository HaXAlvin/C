#include<stdlib.h>
#include<stdio.h>

int add(int a,int b){//�[�k
    return a + b;
}

int sub(int a,int b){//��k
    return a - b;
}

int multi(int a,int b){//���k
    return a * b;
}

int divide(int a,int b){//���k
    return a / b;
}

int mod(int a,int b){//���l��
    return a % b;
}

int main(){
    while(1235){
        int num=0,a=0,b=0,(*opt[6])(int,int)={add,sub,multi,divide,mod,};

        printf("�п�ܡ]1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}�^�G");
        scanf("%d",&num);//��J��ܡC
        if(num==0){//0.���}
            printf("���}���t�ΡA�w��U���A��");
            return 0;
        }
        while((num>5)||(num<0)){
            printf("��J���~�A�Э��s��J\n");//��J����1,2,3,4,5,0�A�h���s��J�C
            printf("�п�ܡ]1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}�^�G");
            scanf("%d",&num);//��J���
        }
        printf("�п�J2�Ӿ�ơG");
        scanf("%d %d",&a,&b);//��Ja,b
        if(num==1){//1.�[�k
            printf("%d + %d = %d\n",a,b,opt[0](a,b));
        }
        else if(num==2){//2.��k
            printf("%d - %d = %d\n",a,b,opt[1](a,b));
        }
        else if(num==3){//3.���k
            printf("%d * %d = %d\n",a,b,opt[2](a,b));
        }
        else if(num==4){//4.���k
            printf("%d / %d = %d\n",a,b,opt[3](a,b));
        }
        else if(num==5){//5.���l��
            printf("%d %% %d = %d\n",a,b,opt[4](a,b));
        }
    }


}
