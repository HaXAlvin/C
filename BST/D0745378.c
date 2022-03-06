#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *Left,*Right;
} Node;

Node* MALLOC() {
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->value = -1;
    tmp->Left = NULL;
    tmp->Right = NULL;
    return tmp;
}

void insert(Node *head,int input) {
    Node *now = head;
    if(input < now->value) {
        if(now->Left) {
            insert(now->Left,input);
        } else {
            now->Left = MALLOC();
            now->Left->value = input;
            printf("%p %d\n",now->Left,now->Left->value);
        }
    } else if(input > now->value) {
        if(now->Right) {
            insert(now->Right,input);
        } else {
            now->Right = MALLOC();
            now->Right->value = input;
            printf("%p %d\n",now->Right,now->Right->value);
        }

    }
//    printf("%p %d\n",now,now->value);

}

void search(Node *ptr,int need) {
//    printf("iiiiiiiiii%p %d\n",ptr,ptr->value);
    while(ptr) {
        if(need > ptr->value) {
            ptr = ptr->Right;
//            printf("toright\n");
        } else if(need < ptr->value) {
            ptr = ptr ->Left;
//            printf("toleft\n");
        } else {
            printf("found\n");
            return;
        }
    }
    printf("nofound\n");
}
Node* del(Node *head,int need) {
    Node *pre = NULL,*left_max=NULL,*right_min=NULL,*ptr = head;
    if(!head) {
        printf("tree is empty\n");
        return NULL;
    }
    while(ptr) {
        if(need > ptr->value) {
            if(!ptr->Right) {
                printf("no found\n");
                return head;
            } else {
                pre = ptr;
                ptr = ptr->Right;
            }
        } else if (need < ptr->value) {
            if(!ptr->Left) {
                printf("no found\n");
                return head;
            } else {
                pre = ptr;
                ptr = ptr->Left;
            }
        } else if (need == ptr->value) {
            break;
        }
    }

    if(!pre) {
        Node *tmp = NULL;
        if(ptr->Left) {
            left_max = ptr->Left;
            while(left_max->Right) {
                tmp = left_max;
                left_max = left_max->Right;
            }
            if(tmp) {
                tmp->Right = left_max->Left;
                left_max->Left = ptr->Left;
                left_max->Right = ptr->Right;

            } else {
//                left_max->Left = NULL;
                left_max->Right = ptr->Right;
            }
            return left_max;

        } else if (ptr->Right) {
            right_min = ptr->Right;
            while(right_min->Left) {
                tmp = right_min;
                right_min = right_min->Left;
            }
            if(tmp) {
                tmp->Left = right_min->Right;
                right_min->Left = ptr->Left;
                right_min->Right = ptr->Right;
            } else {
//                right_min->Right=NULL;
                right_min->Left = ptr->Left;
            }
            return right_min;

        } else if (!ptr->Right && !ptr->Left) {
//            if(pre->value > ptr->value) {
//                pre->Left = NULL;
//            } else {
//                pre->Right = NULL;
//            }
            return NULL;
        }
    } else {
        Node *tmp = NULL;
        if(ptr->Left) {
            left_max = ptr->Left;
            while(left_max->Right) {
                tmp = left_max;
                left_max = left_max->Right;
            }
            if(tmp) {
                tmp->Right = left_max->Left;
                left_max->Left = ptr->Left;
                left_max->Right = ptr->Right;
                if(pre->Left == ptr){
                    pre->Left = left_max;
                }else{
                    pre->Right = left_max;
                }

            } else {
//                left_max->Left = NULL;
                left_max->Right = ptr->Right;
                if(pre->Left == ptr){
                    pre->Left = left_max;
                }else{
                    pre->Right = left_max;
                }
            }

        } else if (ptr->Right) {
            right_min = ptr->Right;
            while(right_min->Left) {
                tmp = right_min;
                right_min = right_min->Left;
            }
            if(tmp) {
                tmp->Left = right_min->Right;
                right_min->Right = ptr->Right;
                right_min->Left = ptr->Left;
                if(pre->Left == ptr){
                    pre->Left = right_min;
                }else{
                    pre->Right = right_min;
                }

            } else {
                right_min->Left = ptr->Left;
                if(pre->Left == ptr){
                    pre->Left = right_min;
                }else{
                    pre->Right = right_min;
                }
            }
        }else if (!ptr->Right && !ptr->Left) {
            if(pre->value > ptr->value) {
                pre->Left = NULL;
            } else {
                pre->Right = NULL;
            }

        }
        return head;
    }
}

void inorder(Node *now){
    if(!now)
        return;
    if(now->Left){
        inorder(now->Left);
    }
    if(now){
        printf("%d\n",now->value);
    }
    if(now->Right){
        inorder(now->Right);
    }
}
int main() {
    int input,found=-1;
    Node *Tree = NULL;
    printf("insert:\n");
    while(scanf("%d",&input)&&input!=0) {
        if(!Tree) {
            Tree = MALLOC();
            Tree->value = input;
            printf("%p %d\n",Tree,Tree->value);
        } else {
            insert(Tree,input);
        }
    }
    Node *tmp = Tree;
    inorder(tmp);
//    printf("ppp%p\n",Tree);
//    while(1){
    printf("search:");
    Node *ptr = Tree;
    scanf("%d",&input);
    search(ptr,input);
    while(1){
        printf("del:");
        scanf("%d",&input);
        Tree = del(Tree,input);
        tmp = Tree;
        inorder(tmp);
    }
//    }
}
