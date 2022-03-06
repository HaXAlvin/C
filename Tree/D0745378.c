#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define FR "Input.txt"
#define FW "Output.txt"
#define MAXNode 100

typedef struct Node{//�`�I
    char value;
    struct Node *left,*right;
}Node;

Node* NodeMalloc(){//malloc + ��l��
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

FILE* FOPEN(char file[],char type[]){//�}��
    FILE *tmp;
    while( NULL == (tmp = fopen(file,type))){
        printf("Error Opening File\n");
        Sleep(1000);
    }
    return tmp;
}

//��InOrder�MPostOrder�إ�Tree
void ORDER(char postOrder[],char inOrder[],int *charPlace,Node *now,int from,int to){//from�Bto�O�`�I��value�bInOrder�����d��
    Node *nowLeft = NodeMalloc();
    Node *nowRight = NodeMalloc();
    (*charPlace)-=1;//��e�bpostOrder�����ؼ�
    if(to > from){//�d��D0�Y����e�����٨S����
        for(int i=from;i<=to;i++){//�M��d�򤺻P�{�b�ؼЬۦP�r����Index
            if(inOrder[i]==postOrder[*charPlace]){
                now->value = inOrder[i];

                if(i == to){//�Ȧ����l
                    free(nowRight);
                    now->left = nowLeft;//link
                    ORDER(postOrder,inOrder,charPlace,nowLeft,from,i-1);

                }else if(i == from){//�Ȧ��k�l
                    free(nowLeft);
                    now->right = nowRight;//link
                    ORDER(postOrder,inOrder,charPlace,nowRight,i+1,to);

                }else if(to>i && i>from){//�����k�l
                    now->right = nowRight;//link
                    now->left = nowLeft;//link
                    ORDER(postOrder,inOrder,charPlace,nowRight,i+1,to);//����k����
                    ORDER(postOrder,inOrder,charPlace,nowLeft,from,i-1);//�A�䥪����

                }else{
                    printf("Location Error\n");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }
    }else if (to == from){//�d��0�N��{�b���`�I�O��
        now->value = inOrder[from];
    }else{
        printf("Index Error\n");
        exit(EXIT_FAILURE);
    }
}

void PostOrder(Node *now,FILE *fw){//�HPostOrder�覡��XTree
    if(now->left)
        PostOrder(now->left,fw);
    if(now->right)
        PostOrder(now->right,fw);
    if(now){
        printf("%c",now->value);
        fprintf(fw,"%c",now->value);
    }
}
void InOrder(Node *now,FILE *fw){//�HInOrder�覡��XTree
    if(now->left)
        InOrder(now->left,fw);
    if(now){
        printf("%c",now->value);
        fprintf(fw,"%c",now->value);
    }
    if(now->right)
        InOrder(now->right,fw);

}
void PreOrder(Node *now,FILE *fw){//�HPreOrder�覡��XTree
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
    ORDER(postOrder,inOrder,&charPlace,tree,0,strlen(postOrder)-1);//�Ĥ@�Ӹ`�I�d��O����
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
