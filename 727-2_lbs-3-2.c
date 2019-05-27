#include <stdio.h>
#include <stdlib.h>
struct	node{
    int	value;
    struct	node *prev;
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


    if(l->head==NULL)
    {
        newnode->prev=NULL;
        l->head = newnode;

    }
    else if(l->head->next==NULL)
    {
        l->head->next=newnode;
        newnode->prev = l->head;
    }
    else
    {
        l->tail->next=newnode;
        newnode->prev = l->tail;
    }

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
int	push_front(struct list*	l,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    if(l->head==NULL)
    {
        newnode->prev=NULL;
        newnode->next=NULL;
        l->head=newnode;
        l->tail=newnode;
    }
    else
    {
        newnode->prev=NULL;
        newnode->next = l->head;
        l->head->prev=newnode;
        l->head = newnode;
    }
    return 0;
}
int	insertAfter(struct node*	n,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next=NULL;
    newnode->next = n->next;
    n->next->prev = newnode;
    n->next=newnode;
    newnode->prev=n;
    return 0;

}
int	insertBefore(struct node*	n,	int	val)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next=NULL;
    n->prev->next=newnode;
    newnode->prev=n->prev;
    newnode->next=n;
    n->prev=newnode;
    return 0;
}
int	remove_first(struct list*	l,	int	val)
{
    struct node* temp;
    temp= l->head;
    while(temp->value!=val)
    {
       temp = temp->next;
    }
    if(temp==l->head)
    {
        l->head=temp->next;
        temp->next->prev=NULL;

    }
    else if(temp==l->tail)
    {
        l->tail=temp->prev;
        temp->prev->next=NULL;

    }
    else
    {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    }

    free(temp);
    return 0;
}
int	remove_last(struct list*   l,	int	val)
{
    struct node* temp;
    temp= l->tail;
    while(temp->value!=val)
    {
       temp = temp->prev;
    }
    if(temp==l->head)
    {
        l->head=temp->next;
        temp->next->prev=NULL;

    }
    else if(temp==l->tail)
    {
        l->tail=temp->prev;
        temp->prev->next=NULL;

    }
    else
    {
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    }

    free(temp);
    return 0;
}
void	print_invers(struct list*	l)
{
    if (isEmpty(l)==1)
    {
    struct node *temp;
    temp = l->tail;
    while (temp->prev!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
     printf("%d\n",temp->value);
    }
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
    print_invers (&a);

    scanf("%d",&x);
    push_front(&a,x);
    print(&a);

    scanf("%d",&n);
    scanf("%d",&x);
    b=find_j(&a,n);
    insertAfter(b,x);
    print_invers (&a);

    scanf("%d",&n);
    scanf("%d",&x);
    b=find_j(&a,n);
    insertBefore(b,x);
    print (&a);

    scanf("%d",&n);
    remove_first(&a,n);
    print_invers(&a);

    scanf("%d",&n);
    remove_last(&a,n);
    print(&a);



    clear(&a);

    return 0;
}
