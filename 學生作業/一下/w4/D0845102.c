#include <stdio.h>
#include <stdlib.h>
//找公因數遞迴式
int devide(int n,int m)
{
    if(!m)
    {
        return n;
    }
    return devide(m,n%m);
}
//分子/分母
    struct fraction
    {
        int frac;
        int deno;
    };
    //加法器
    struct fraction add_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.deno+ e2.frac* e1.deno;
        result.deno= e1.deno* e2.deno;
        //找出公因數
        int factor=devide(result.frac,result.deno);
        //除以公因數來約分
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;

    };
    //減法器,與加法器大致雷同
    struct fraction min_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.deno- e2.frac* e1.deno;
        result.deno= e1.deno* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //乘法器,與加法器大致雷同
    struct fraction multi_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.frac* e2.frac;
        result.deno= e1.deno* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //除法器,與加法器大致雷同
    struct fraction dvid_fraction(struct fraction e1,struct fraction e2)
    {
        struct fraction result;
        result.frac= e1.deno* e2.frac;
        result.deno= e1.frac* e2.deno;
        int factor=devide(result.frac,result.deno);
        result.frac=result.frac/factor;
        result.deno=result.deno/factor;
        return result;
    };
    //印出答案的副程式
    void print(int num_1,int num_2,int num_3,int num_4,int a, int b,char temp)//a是分子,b是分母
    {
        if((((a)*(b)<0)||(b<0))&&(temp!='-'))//若分子*分母小於零或分母小於零, 後面是de負號的bug
        {
            a*=-1;
            b*=-1;
        }
        if(temp=='-')//若分子和分母都是負數
        {
            if(b<a)
                a*=-1;
            b*=-1;

        }
        if((a>0)&&(b<0))//當分子是正分母是負
        {
            a*=-1;
            b*=-1;
        }
        if((a<0)&&(b<0))
            b*=-1;
        if(b==1)//如果答案是整數
        {
            printf("%d/%d %c %d/%d=%d\n\n",num_1,num_2,temp,num_3,num_4,a);
        }
        else//如果答案是分數
        {
            printf("%d/%d %c %d/%d= %d/%d\n\n",num_1,num_2,temp,num_3,num_4,a,b);
        }
    }
    int main()
    {
        struct fraction fraction_1,fraction_2,fraction_final;
        int num_1,num_2,num_3,num_4;
        char temp;
        while(1)
        {
            int option=-1;
            printf("選擇(1.加/2.減/3.乘/4.除/0.離開:");
            scanf("%d",&option);
            if(option==1)
            {
                printf("a/b + c/d，請輸入a b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))//分母不可為0
                {
                    printf("分母不可為0\n");
                }
                else
                {
                    //帶入數字
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=add_fraction(fraction_1,fraction_2);
                    temp='+';//最後要印出加號
                    print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==2)
            {
                printf("a/b - c/d，請輸入a b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("分母不可為0\n");
                }
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=min_fraction(fraction_1,fraction_2);
                    temp='-';//最後要印出負號
                    print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==3)
            {
                printf("a/b * c/d，請輸入a b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("分母不可為0\n");
                }
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=multi_fraction(fraction_1,fraction_2);
                    temp='*';//最後要印出乘號
                     print(num_1,num_2,num_3,num_4,fraction_final.frac,fraction_final.deno,temp);
                }
            }
            else if(option==4)
            {
                printf("a/b / c/d，請輸入a b c d: ");
                scanf("%d %d %d %d",&num_1,&num_2,&num_3,&num_4);
                getchar();
                if((num_2==0)||(num_4==0))
                {
                    printf("分母不可為0\n\n");
                }
                else if(num_3==0)
                    printf("除數不可為0\n\n");
                else
                {
                    fraction_1.frac=num_1;
                    fraction_1.deno=num_2;
                    fraction_2.frac=num_3;
                    fraction_2.deno=num_4;
                    fraction_final=dvid_fraction(fraction_1,fraction_2);
                    temp='/';//最後要印出除號
                    print(num_1,num_2,num_3,num_4,fraction_final.deno,fraction_final.frac,temp);
                }
            }
            else if(option==0)
            {
                return 0;
            }
            else
            {
                printf("輸入錯誤\n");
            }
        }
    }
