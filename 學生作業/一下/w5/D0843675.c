#include<stdio.h>
#include<string.h>
#include<stdlib.h>

union dic{//整數、小數、字元陣列
    int num;
    float numwithdot;
    char word[16];
};

enum type{//整數、小數、字元陣列
    I,F,S,
};

struct array{//message、類別
    union dic kind;
    enum type t;
};

struct array add(struct array* Ptr,int* times){
    char wordtype;
    while(1){
        printf("選擇類型:(i:int/f:float/s:char[16]:");
        scanf("%c%*c",&wordtype);
        if(wordtype=='i'||wordtype=='f'||wordtype=='s')
            break;
        printf("輸入錯誤!\n");
    }
    if(wordtype=='i'){//輸入轉判別
        printf("輸入資料:");
        scanf("%d",&Ptr[*times].kind.num);
        Ptr[*times].t=I;
    }
    else if(wordtype=='f'){
        printf("輸入資料:");
        scanf("%f",&Ptr[*times].kind.numwithdot);
        Ptr[*times].t=F;
    }
    else if(wordtype=='s'){
        printf("輸入資料:");
        getchar();
        gets(Ptr[*times].kind.word);
        Ptr[*times].t=S;
    }
}

int main(){
    int times = 0;//起始零
    int* timesPtr = &times;
    int option = 0;//選項
    struct array* Ptr;//宣告動態陣列

    while(1){
        printf("選擇:(1.新增/2.印出/0.結束):");
        scanf("%d%*c",&option);
        if(option==0){//free(struct)
            printf("結束程式\n");
            free(Ptr);
            return 0;
        }
        else if(option==1){
            if(times==0){//起始零
                Ptr = malloc(1*sizeof(struct array));
            }
            else{//新增
                Ptr = realloc(Ptr,(times+1)*sizeof(struct array));
            }
            add(Ptr,timesPtr);//callbyreference
            times++;//次數加
        }
        else if(option==2){//列印
            for(int a = 0;a<times;a++){
                if(Ptr[a].t==I)//判別
                    printf("%d\n",Ptr[a].kind.num);
                else if(Ptr[a].t==F)
                    printf("%f\n",Ptr[a].kind.numwithdot);
                else if(Ptr[a].t==S)
                    puts(Ptr[a].kind.word);
            }
        }
        else//防呆
            printf("輸入錯誤!\n");
    }
}
