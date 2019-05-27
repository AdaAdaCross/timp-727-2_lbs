#include <stdio.h>
#include <stdlib.h>

struct	node{
    int	value;
    struct	node *next;
            };

struct list
{
    struct node *head;
    struct node *tail;
};

void init(struct list*	l)
{
    l->head=NULL;
    l->tail=NULL;
}
int	push_back(struct list*	l,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next=NULL;

    if(l->head==NULL) l->head = newnode;
    else if(l->head->next==NULL)l->head->next=newnode;
    else l->tail->next=newnode;

    l->tail = newnode;
    return 0;

}
int	isEmpty(struct list*	l)
{
    if(l->head==NULL)
    {
        return 0;
    }
    else return 1;
}
void	print(struct list*	l)
{
    if (isEmpty(l)==1)
    {
    struct node *temp;
    temp = l->head;
    while (temp->next!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
     printf("%d\n",temp->value);
    }
}

void	clear(struct list*	l)
{

    struct node *temp;
    struct node *temp2;
    temp = l->head;
    while (temp->next!=NULL)
    {
        temp2 = temp;
        temp=temp2->next;
        free(temp2);

    }
    free(temp);
    init(l);
}
int	push_front(struct list*	l,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    if(l->head==NULL)
    {
        l->head=newnode;
        l->tail=newnode;
    }
    else
    {
        newnode->next = l->head;
        l->head = newnode;
    }
    return 0;
}
struct node*	find(struct list*	l,	int	val)
{
   if (isEmpty(l)==1)
    {
    struct node *temp;
    temp = l->head;
    while (temp->next!=NULL)
    {
        if(temp->value==val) return temp;
        temp = temp->next;
    }
    if(temp->value==val) return temp;
    }
    return NULL;
}
int	insertAfter(struct node*	n,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next=NULL;
    newnode->next = n->next;
    n->next=newnode;

    return 0;

}
int	remve(struct list*	l,	int	val)
{
    struct node* temp1;
    struct node* temp2;
    temp1= l->head;
    temp2 = temp1->next;
    while(temp2->value!=val)
    {
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    temp1->next= temp2->next;
    free(temp2);
    return 0;
}
struct node*	find_j(struct list*	l,	int	val)
{
    struct node *temp;
    int n=1;
    temp = l->head;
    while (n<val)
    {
       temp = temp->next;
       n++;
    }
    return temp;

}
int main()
{
    struct list a;
    struct node *b;
    int n,x,i;
    init(&a);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        push_back(&a,x);
    }
    print (&a);
    int k1,k2,k3;
    scanf("%d %d %d",&k1, &k2, &k3);
    b= find(&a,k1);
    if (b==NULL)
    {
        printf("0");
    }
    else printf("1");
    b= find(&a,k2);
    if (b==NULL)
    {
        printf("0");
    }
    else printf("1");

    b= find(&a,k3);
    if (b==NULL)
    {
        printf("0\n");
    }
    else printf("1\n");
    scanf("%d",&x);
    push_back(&a,x);
    print (&a);
    scanf("%d",&x);
    push_front(&a,x);
    print (&a);
    scanf("%d",&n);
    scanf("%d",&x);
    b=find_j(&a,n);
    insertAfter(b,x);
    print (&a);
    scanf("%d",&n);
    remve(&a,n);
    print (&a);
    clear(&a);
    return 0;
}

