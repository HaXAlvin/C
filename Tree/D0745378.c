#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define FR "Input.txt"
#define FW "Output.txt"
#define MAXNode 100

typedef struct Node{//節點
    char value;
    struct Node *left,*right;
}Node;

Node* NodeMalloc(){//malloc + 初始化
    Node *tmp = (Node*)malloc(sizeof(Node));
    if(tmp == NULL){
        printf("Malloc Error\n");
        exit(EXIT_FAILURE);
    }
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->value = 0;
    return tmp;
}

FILE* FOPEN(char file[],char type[]){//開檔
    FILE *tmp;
    while( NULL == (tmp = fopen(file,type))){
        printf("Error Opening File\n");
        Sleep(1000);
    }
    return tmp;
}

//用InOrder和PostOrder建立Tree
void ORDER(char postOrder[],char inOrder[],int *charPlace,Node *now,int from,int to){//from、to是節點的value在InOrder中的範圍
    Node *nowLeft = NodeMalloc();
    Node *nowRight = NodeMalloc();
    (*charPlace)-=1;//當前在postOrder中的目標
    if(to > from){//範圍非0即為當前分支還沒結束
        for(int i=from;i<=to;i++){//尋找範圍內與現在目標相同字元的Index
            if(inOrder[i]==postOrder[*charPlace]){
                now->value = inOrder[i];

                if(i == to){//僅有左子
                    free(nowRight);
                    now->left = nowLeft;//link
                    ORDER(postOrder,inOrder,charPlace,nowLeft,from,i-1);

                }else if(i == from){//僅有右子
                    free(nowLeft);
                    now->right = nowRight;//link
                    ORDER(postOrder,inOrder,charPlace,nowRight,i+1,to);

                }else if(to>i && i>from){//有左右子
                    now->right = nowRight;//link
                    now->left = nowLeft;//link
                    ORDER(postOrder,inOrder,charPlace,nowRight,i+1,to);//先找右分支
                    ORDER(postOrder,inOrder,charPlace,nowLeft,from,i-1);//再找左分支

                }else{
                    printf("Location Error\n");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }
    }else if (to == from){//範圍為0代表現在的節點是葉
        now->value = inOrder[from];
    }else{
        printf("Index Error\n");
        exit(EXIT_FAILURE);
    }
}

void PostOrder(Node *now,FILE *fw){//以PostOrder方式輸出Tree
    if(now->left)
        PostOrder(now->left,fw);
    if(now->right)
        PostOrder(now->right,fw);
    if(now){
        printf("%c",now->value);
        fprintf(fw,"%c",now->value);
    }
}
void InOrder(Node *now,FILE *fw){//以InOrder方式輸出Tree
    if(now->left)
        InOrder(now->left,fw);
    if(now){
        printf("%c",now->value);
        fprintf(fw,"%c",now->value);
    }
    if(now->right)
        InOrder(now->right,fw);

}
void PreOrder(Node *now,FILE *fw){//以PreOrder方式輸出Tree
    if(now){
        printf("%c",now->value);
        fprintf(fw,"%c",now->value);
    }
    if(now->left)
        PreOrder(now->left,fw);

    if(now->right)
        PreOrder(now->right,fw);

}

int main()
{
    char inOrder[MAXNode]={0};
    char postOrder[MAXNode]={0};
    FILE *fr=FOPEN(FR,"r");
    FILE *fw=FOPEN(FW,"w");
    fscanf(fr,"%s",inOrder);//LVR
    fscanf(fr,"%s",postOrder);//LRV

    Node *tree = NodeMalloc();
    int charPlace = strlen(postOrder);
    ORDER(postOrder,inOrder,&charPlace,tree,0,strlen(postOrder)-1);//第一個節點範圍是全部
    PreOrder(tree,fw);
    puts("");
//    InOrder(tree,fw);
//    puts("");
//    PostOrder(tree,fw);
    return 0;
}

/*
ABCDEFGHI
BCAEDGHFI
*/
