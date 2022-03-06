#include<stdio.h>
#include<stdlib.h>
typedef union{
    int i;
    float f;
    char s[16];
} Value;
/*�W����J��ƪ��U�اΦ�*/
typedef struct node* NodePtr;
typedef struct node{
    char type;
    Value num;
    NodePtr nextptr;
}Node;
/*�W���C�ӵ��c�����ܼ�*/
void add(NodePtr* ptr){
    NodePtr newptr = malloc(sizeof(Node));
    newptr->nextptr = NULL;

    printf("��������G(i�Gint/f�Gfloat/s�Gchar[16])�G");
    getchar();
    scanf("%c", &newptr->type);

    if((newptr->type) != 'i' && (newptr->type)!= 'f' && (newptr->type)!= 's'){
        printf("��J���~!\n");
        return ;
    }
    printf("��J��ơG");
    if((newptr->type)=='i'){
        scanf("%d", &(newptr->num.i));
    }
    else if((newptr->type)=='f'){
        scanf("%f", &(newptr->num.f));
    }
    else if((newptr->type)=='s'){
        scanf("%s", (newptr->num.s));
    }
    if(*ptr == NULL){
        *ptr = newptr;
    }
    else{
        NodePtr temp = *ptr;
        while(temp->nextptr != NULL)
            temp = temp->nextptr;
        temp->nextptr=newptr;
    }
}
/*�W��add���ƨ禡
  �b�̪�ɫŧi�@�ӦW��newptr�����c���ХB�Ũ�j�p
  �L�X��������G(i�Gint/f�Gfloat/s�Gchar[16])�G�A�ϥΪ̿�J�n���򫬺A
  �Y���Oi�Bf�Bs �h�L�X��J���~!�A�������ƨ禡
  �L�X��J��ơG�A�p�G���A��i�h��%d�A�p�G���A��f�h��%f�A�p�G���A��s�h��%s
  �Y�ǤJ��ptr���ONULL�h��ptr����newptr(�}�Y)
  �_�h�b�O�@�ӫ��е��ctemp�A��temp��ptr�����F��(�����쵲�����F��)
  �htemp�̪�nextptr�N�|���V�ڭ̷s�W�����е��cnewptr(�s�W�Ȫ����c)
  */
void show(NodePtr ptr){
    while(ptr!=NULL){
        if(ptr->type=='i'){
            printf("%d\n", (ptr->num.i));
        }
        else if(ptr->type=='f'){
            printf("%f\n", (ptr->num.f));
        }
        else if(ptr->type=='s'){
            printf("%s\n", (ptr->num.s));
        }
        ptr=ptr->nextptr;
    }
    printf("\n");
}
/*�W��show���ƨ禡
  �ϥ�while�j��@���](����Optr����NULL)
  �p�Gptr�����A��i�A�h��%d�L�X��
  �p�Gptr�����A��f�A�h��%f�L�X��
  �p�Gptr�����A��s�A�h��%s�L�X��
  �A��ptr��ptr����nextptr
  �]��nextptr���V�U�@�ӭȦs�����е��c
  �o�˴N��L�X�U�@�ӫ��е��c������
  ����ptr��NULL*/
void free_act(NodePtr ptr){
    while(ptr != NULL){
        NodePtr temp=ptr;
        ptr=ptr->nextptr;
        free(temp);
    }
}
/*�W��free_act���ƨ禡
  �ϥ�while�j��@���](����Optr����NULL)
  �O�@�ӫ��е��ctemp�A��temp��ptr�A�A��ptr��ptr����nextptr(�]��nextptr���V�U�@�ӫ��е��c)�A�A�hfree temp
  (�p�G�S������temp�s��ptr�A����free���ܡA�o��nextptr�N�L�k���V�U�@�ӫ��е��c�A�ӨϤU�@�Ӥ��᪺���е��c�L�k�Qfree)*/
int main(){
    NodePtr head= NULL;
    int input;
    while(1){
        printf("1.�s�W, 2.�L�X, 0.����: ");
        scanf("%d", &input);
        if(input==1){
            add(&head);
        }
        else if(input==2){
            show(head);
        }
        else if(input==0){
            free_act(head);
            break;
        }
        else {
            printf("��J�����~!\n");
        }
    }
    return 0;
}
/*�W���D�禡
  �ŧihead�����е��c�Minput���ܼ�
  �ϥ�while�j��@���]
  �p�Ginput��1�ɩI�sadd���ƨ禡
  �_�h�p�Ginput��2�ɩI�sshow���ƨ禡
  �_�h�p�Ginput��3�ɩI�sfree_act���ƨ禡�A�B����j��
  �_�h�A�L�X��J�����~!*/
