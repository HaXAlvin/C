/*  109�~��  ��T�G�B
        �Ĥ@�g�@�~    */
#include<stdio.h>//���Y��
#include<stdlib.h>
typedef struct node* NodePtr;//�w�qNode�Ostruct node
typedef struct node//�w�qnode���c
{
    union arr//�w�q�p�X���c
    {
        int num;//���
        float Num;//���ׯB�I��
        char word[16];//�r���}�C
    } Arr;
    char t;//�Ψ��x�s��ƫ��A
    NodePtr nextPtr;
} Node;

void addNode(NodePtr* ptr)//�쵲��C���Ƶ{��
{
    char ty;
    NodePtr newPtr = malloc(sizeof(Node));//�ʺA�t�mNode
    newPtr->nextPtr = NULL;//�w�]��NULL
    while(1)
    {
        printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
        scanf("%c",&ty);//��ܫ��A
        getchar();
        if(ty=='i')//���int
        {
            printf("��J��ơG");
            scanf("%d", &(newPtr->Arr).num);//��J���
            newPtr->t=ty;//�x�s���A
            break;//���X�j��
        }
        if(ty=='f')//���float
        {
            printf("��J��ơG");
            scanf("%f", &(newPtr->Arr).Num);//��J���
            newPtr->t=ty;//�x�s���A
            break;//���X�j��
        }

        if(ty=='s')//���char
        {
            printf("��J��ơG");
            gets((newPtr->Arr).word);//��J���
            newPtr->t=ty;//�x�s���A
            break;//���X�j��
        }
        if(!(ty=='i'||ty=='s'||ty=='f'))//��Ji�Bf�Bs�H�~
            printf("��J���~�I\n");
    }
    if(*ptr == NULL)//�p�G��NULL
        *ptr = newPtr;
    else
    {
        NodePtr tempPtr = *ptr;
        while(tempPtr->nextPtr != NULL)//����NULL�j��
            tempPtr = tempPtr->nextPtr;//����
        tempPtr->nextPtr = newPtr;//������s��node
    }
}

void print(NodePtr node)//�L�X���Ƶ{��
{
    while(node)
    {
        if(node->t=='i')//�p�G���A��int
        {
            printf("%d ", (node->Arr).num);//�L�X(node->Arr).num
            node = node->nextPtr;//�Nnode���V�쥻��node->nextPtr
            printf("\n");
        }

        else if(node->t=='f')//�p�G���A��floar
        {
            printf("%f", (node->Arr).Num);//�L�X(node->Arr).Num
            node = node->nextPtr;//�Nnode���V�쥻��node->nextPtr
            printf("\n");
        }
        else if(node->t=='s')//�p�G���A��char
        {
            puts((node->Arr).word);//�L�X(node->Arr).word
            node = node->nextPtr;//�Nnode���V�쥻��node->nextPtr
        }

    }
}
void freeList(NodePtr* ptr) //����O����
{
    while(*ptr != NULL)
    {
        NodePtr temp = *ptr;//�N*ptr�O����temp
        *ptr = (*ptr)->nextPtr;//*ptr�����
        free(temp);//����O����
    }
}
int main()//�D�{��
{
    NodePtr head = NULL;
    int n=0,sum=0;//��i�ܼ�
    while(1)
    {
        printf("��ܡG(1.�s�W/2.�L�X/0.����)�G");
        scanf("%d",&n);
        if(n==1)//��ܷs�W
        {
            getchar();
            addNode(&head);
        }
        if(n==2)//��ܦL�X
        {
            print(head);
        }
        if(n<0||n>2)//��J0�B1�B2�H�~
            printf("��J���~�I\n");
        if(n==0)//��ܵ���
        {
            freeList(&head);
            printf("�����{��");
            return 0;//�^�ǡA�õ����{��
        }

    }

}
