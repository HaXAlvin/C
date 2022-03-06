#include <stdio.h>
int main() {

    int num, num1, num2, i, c2, j, j2, j3, j4;
    printf("輸入菱形對角線長度(3、5、7、9):");
    scanf("%d",&num);
    for(;;) {
        if(num!=3 && num!=5 && num!=7 && num!=9) {
            printf("輸入錯誤!\n");
            printf("輸入菱形對角線長度(3、5、7、9):");
            scanf("%d",&num);
            continue;
        }
        if(num==3 || num==5 || num==7 || num==9)
            break;
    }
    printf("輸入行數(2~10):");
    scanf("%d",&num1);
    for(;;) {
        if(num1<2 || num1>10) {
            printf("輸入錯誤!\n");
            printf("輸入行數(2~10):");
            scanf("%d",&num1);
            continue;
        }
        if(num1>=2 && num1<=10)
            break;
    }
    printf("輸入列數(2~10):");
    scanf("%d",&num2);
    for(;;) {
        if(num2<2 || num2>10) {
            printf("輸入錯誤!\n");
            printf("輸入列數(2~10):");
            scanf("%d",&num2);
            continue;
        }
        if(num2>=2 && num2<=10)
            break;
    }

    while(num2>0) {
        for( j=1; j<=num; j+=2) {
            c2=num1;
            while(c2>0) {

                j4=j;
                j2=(num-j)/2;
                while(j2>0) {
                    printf(" ");
                    j2--;
                }
                while(j4>0) {
                    printf("*");
                    j4--;
                }
                j2=(num-j)/2;
                while(j2>0) {
                    printf(" ");
                    j2--;
                }
                printf(" ");
                c2--;
            }
            printf("\n");
        }


        for( j=num-2; j>0; j-=2) {
            c2=num1;
            while(c2>0) {

                j4=j;
                j2=(num-j)/2;
                while(j2>0) {
                    printf(" ");
                    j2--;
                }
                while(j4>0) {
                    printf("*");
                    j4--;
                }
                j2=(num-j)/2;
                while(j2>0) {
                    printf(" ");
                    j2--;
                }
                printf(" ");
                c2--;
            }
            printf("\n");

        }
        printf("\n");
        num2--;
    }




    return 0;
}
