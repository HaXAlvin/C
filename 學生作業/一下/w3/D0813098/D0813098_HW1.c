#include<stdio.h>
#include<string.h>
int add(int value, int value1)
{
    return value+value1;
}
//�ŧiadd���Ƶ{���A�N�ǤJ����ӼƦr�ۥ[
int sub(int value, int value1)
{
    return value-value1;
}
//�ŧisub���Ƶ{���A�N�ǤJ����ӼƦr�۴�
int multi(int value, int value1)
{
    return value*value1;
}
//�ŧimulti���Ƶ{���A�N�ǤJ����ӼƦr�ۭ�
int div(int value, int value1)
{
    return value/value1;
}
//�ŧidiv���Ƶ{���A�N�ǤJ����ӼƦr�۰�
int mod(int value, int value1)
{
    return value%value1;
}
//�ŧimod���Ƶ{���A�N�ǤJ����ӼƦr�ۨ��l��
int main()
{
    int input,input1,input2; //�ŧi�ܼ�input�Minput1�Minput2
    int(*opt[])(int value,int value1)={add,sub,multi,div,mod};//�ŧi�@�Ө�ƫ��а}�C
    while(1){
        printf("1.�[�k/2.��k/3.���k/4.���k/5.���l��/0.���}:");
        scanf("%d", &input);
        if(input==1){
            printf("�п�J��ӼƦr:");
            scanf("%d %d", &input1, &input2);
            printf("%d + %d = %d\n", input1, input2, opt[0](input1,input2));
        }
        else if(input==2){
            printf("�п�J��ӼƦr:");
            scanf("%d %d", &input1, &input2);
            printf("%d - %d = %d\n", input1, input2, opt[1](input1,input2));
        }
        else if(input==3){
            printf("�п�J��ӼƦr:");
            scanf("%d %d", &input1, &input2);
            printf("%d * %d = %d\n", input1, input2, opt[2](input1,input2));
        }
        else if(input==4){
            printf("�п�J��ӼƦr:");
            scanf("%d %d", &input1, &input2);
            printf("%d / %d = %d\n", input1, input2, opt[3](input1,input2));
        }
        else if(input==5){
            printf("�п�J��ӼƦr:");
            scanf("%d %d", &input1, &input2);
            printf("%d %% %d = %d\n", input1, input2, opt[4](input1,input2));
        }
        else if(input==0){
            break;
        }
        else {
            printf("��J���~ �Э��s��J\n");
        }
        /* �ϥ�WHHILE�j��A
           ���ۿ�JINPUT
           �p�GINPUT��1�B2�B3�B4�B5�A�h�L�X�п�J��ӼƦr:�A���ۿ�J��ӼƦr�A�b�L�X��ƪ��[�B��B���B���B���l��
           �p�GINPUT��0�A�h����j��
           �_�h�N�|�L�X��J���~ �Э��s��J*/
    }
    return 0;
}
