#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;// меньше
    struct node *right;// больше
    struct node *parent;// батя
};

//работа со списком
struct	node_list
{
    struct	node_list *next;
    struct	node *adres;
};

struct list
{
    struct node_list *head;
    struct node_list *tail;
};

void init_list(struct list*	l)
{
    l->head=NULL;
    l->tail=NULL;
}

int	push_back(struct list*	l, struct node *val)
{
    struct node_list *newnode;
    newnode = (struct node_list*)malloc(sizeof(struct node_list));
    newnode->adres = val;
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
void	clear_list(struct list*	l)
{

    struct node_list *temp;
    struct node_list *temp2;
    temp = l->head;
    while (temp->next!=NULL)
    {
        temp2 = temp;
        temp=temp2->next;
        free(temp2);

    }
    free(temp);
    init_list(l);
}

void	print_list(struct list*	l)
{
    if (isEmpty(l)==1)
    {
    struct node_list *temp;
    temp = l->head;
    while (temp->next!=NULL)
    {
        if(temp->adres!=NULL)
        {
             printf("%d ",temp->adres->value);
        }
       else
       {
           printf("_ ");
       }
                temp = temp->next;
    }
     if(temp->adres!=NULL)
        {
             printf("%d\n",temp->adres->value);
        }
       else
       {
           printf("_\n");
       }
    }
    clear_list(l);
}
int queue_host(struct list *l)
{
    struct node_list *temp;
    if (isEmpty(l)==0) return 0;
    temp = l->head;
    while(temp!=NULL)
    {
        if(temp->adres!=NULL) return 1;
        temp=temp->next;
    }
    return 0;
}
//конец работы со списком
struct tree
{
    int number;//количесвто элементов
    struct node *root;// адрес корня
};

void	init(struct tree*	t)
{
    t->number = 0;
    t->root = NULL;
}
int find (struct tree*	t,	int	val, struct	node**	n )
{
    struct node *temp;
    temp = t->root;
    if(temp==NULL)return 1;
    while(temp!=NULL)
    {
        if(temp->value==val)
        {
            (*n)=temp;
            return 0;
        }
        else if(temp->value>val)
        {
                temp = temp->left;
        }
        else
        {
             temp = temp->right;
        }
    }
    return 1;

}
int	insert(struct tree*	t,	int	val)
{
    struct node *b;
    if (find(t, val, &b)==0) return 1;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    struct node *temp;

    if(t->root ==NULL)
    {
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->parent = NULL;
        t->root= newnode;
        t->number++;
        return 0;
    }
    else
    {
        temp= t->root;
        while(1)
        {
            if(temp->value>val)
            {
                if(temp->left==NULL)
                {
                    newnode->parent = temp;
                    newnode->left = NULL;
                    newnode->right = NULL;
                    temp->left = newnode;
                    t->number++;
                    return 0;

                }
                else
                    {
                        temp =temp->left;
                    }
            }
            else if(temp->value<val)
            {
                if(temp->right==NULL)
                {
                    newnode->parent = temp;
                    newnode->left = NULL;
                    newnode->right = NULL;
                    temp->right = newnode;
                    t->number++;
                    return 0;

                }
                else
                    {
                        temp =temp->right;
                    }

            }

        }

    }

}

void	print(struct node*	n)
{
    if (n==NULL)
    {
        printf("-\n");
        return;
    }
    struct list queue1;
    struct list queue2;
    init_list(&queue1);
    init_list(&queue2);
    push_back(&queue1,n);
    while(queue_host(&queue1)|| queue_host(&queue2))
    {
        if(isEmpty(&queue2)==0)
        {
             struct node_list *temp;
             temp = queue1.head;
             while(temp->next!=NULL)
             {
                 if(temp->adres!=NULL)
                 {
                    push_back(&queue2,temp->adres->left);
                    push_back(&queue2,temp->adres->right);

                 }
                 else
                 {
                    push_back(&queue2,NULL);
                    push_back(&queue2,NULL);
                 }
                 temp=temp->next;
             }
             if(temp->adres!=NULL)
                 {
                    push_back(&queue2,temp->adres->left);
                    push_back(&queue2,temp->adres->right);

                 }
                 else
                 {
                    push_back(&queue2,NULL);
                    push_back(&queue2,NULL);
                 }
                print_list(&queue1);
            }
            else if(isEmpty(&queue1)==0)
        {
             struct node_list *temp;
             temp = queue2.head;
             while(temp->next!=NULL)
             {
                 if(temp->adres!=NULL)
                 {
                    push_back(&queue1,temp->adres->left);
                    push_back(&queue1,temp->adres->right);

                 }
                 else
                 {
                    push_back(&queue1,NULL);
                    push_back(&queue1,NULL);
                 }
                 temp= temp->next;
             }
             if(temp->adres!=NULL)
                 {
                    push_back(&queue1,temp->adres->left);
                    push_back(&queue1,temp->adres->right);

                 }
                 else
                 {
                    push_back(&queue1,NULL);
                    push_back(&queue1,NULL);
                 }
                print_list(&queue2);

            }
    }
}
void	printTree(struct tree*	t)
{
    print(t->root);
}

void	clear( struct tree*	t)
{

    struct list queue1;
    struct list queue2;
    init_list(&queue1);
    init_list(&queue2);
    push_back(&queue1, t->root);
    while(queue_host(&queue1)|| queue_host(&queue2))
    {
        if(isEmpty(&queue2)==0)
        {
             struct node_list *temp;
             temp = queue1.head;
             while(temp->next!=NULL)
             {
                 if(temp->adres!=NULL)
                 {
                    push_back(&queue2,temp->adres->left);
                    push_back(&queue2,temp->adres->right);
                    free(temp->adres);

                 }
                 else
                 {
                    push_back(&queue2,NULL);
                    push_back(&queue2,NULL);
                 }

                 temp=temp->next;
             }
             if(temp->adres!=NULL)
                 {
                    push_back(&queue2,temp->adres->left);
                    push_back(&queue2,temp->adres->right);
                    free(temp->adres);
                 }
                 else
                 {
                    push_back(&queue2,NULL);
                    push_back(&queue2,NULL);
                 }
                clear_list(&queue1);
            }
            else if(isEmpty(&queue1)==0)
        {
             struct node_list *temp;
             temp = queue2.head;
             while(temp->next!=NULL)
             {
                 if(temp->adres!=NULL)
                 {
                    push_back(&queue1,temp->adres->left);
                    push_back(&queue1,temp->adres->right);
                    free(temp->adres);
                 }
                 else
                 {
                    push_back(&queue1,NULL);
                    push_back(&queue1,NULL);
                 }
                 temp= temp->next;
             }
             if(temp->adres!=NULL)
                 {
                    push_back(&queue1,temp->adres->left);
                    push_back(&queue1,temp->adres->right);
                    free(temp->adres);
                 }
                 else
                 {
                    push_back(&queue1,NULL);
                    push_back(&queue1,NULL);
                 }
                clear_list(&queue2);

            }
    }
    init(t);
}
int	remove_1(struct tree*	t,	int	val)
{
    struct node *temp;
    if (find(t, val, &temp)==1) return 1;
    if ((t->root==temp)&& (temp->left==NULL)&&(temp->right==NULL))
    {
        free(temp);
        init(t);
        return 0;
    }
    if((t->root==temp)&& (temp->left==NULL)&&(temp->right!=NULL))
    {
        t->root=temp->right;
        t->root->parent=NULL;
        free(temp);
        t->number--;
        return 0;
    }
    if((t->root==temp)&& (temp->left!=NULL)&&(temp->right==NULL))
    {
        t->root=temp->left;
        t->root->parent=NULL;
        free(temp);
        t->number--;
        return 0;
    }
     if((t->root==temp)&& (temp->left!=NULL)&&(temp->right!=NULL))
     {
         struct node *min;
         min = temp ->right;
         while(min->left!=NULL)
         {
             min = min->left;
         }
         temp->value = min->value;
         if(min->right!=NULL)
         {
             min->parent->right=min->right;
             min->right->parent=min->parent;
             free(min);
             t->number--;
             return 0;
         }
         else
         {
             min->parent->left =NULL;
             free(min);
             t->number--;
             return 0;
         }
     }
     if(temp->parent!=NULL)//общага для детишек
     {
         if((temp->left==NULL)&&(temp->right==NULL))
         {
             if(temp->parent->left==temp)
             {
                 temp->parent->left=NULL;
                 free(temp);
                 t->number--;
                 return 0;
             }
             if(temp->parent->right==temp)
             {
                 temp->parent->right=NULL;
                 free(temp);
                 t->number--;
                 return 0;
             }
         }
         if((temp->left==NULL)&&(temp->right!=NULL))
         {
             if(temp->parent->left==temp)
             {
                 temp->parent->left = temp->right;
                 temp->right->parent=temp->parent;
                 free(temp);
                 t->number--;
                 return 0;
             }
             if(temp->parent->right==temp)
             {
                 temp->parent->right = temp->right;
                 temp->right->parent=temp->parent;
                 free(temp);
                 t->number--;
                 return 0;
             }
        }
        if((temp->left!=NULL)&&(temp->right==NULL))
         {
             if(temp->parent->left==temp)
             {
                 temp->parent->left = temp->left;
                 temp->left->parent=temp->parent;
                 free(temp);
                 t->number--;
                 return 0;
             }
             if(temp->parent->right==temp)
             {
                 temp->parent->right = temp->left;
                 temp->left->parent=temp->parent;
                 free(temp);
                 t->number--;
                 return 0;
             }
         }
         if((temp->left!=NULL)&&(temp->right!=NULL))
            {
                struct node *min;
                min = temp ->right;
                while(min->left!=NULL)
                {
                    min = min->left;
                }
                temp->value=min->value;
                if(min->right==NULL)
                {
                    min->parent->left=NULL;
                    free(min);
                    t->number--;
                    return 0;
                }
                else
                {
                    min->parent->right=min->right;
                    min->right->parent=min->parent;
                    free(min);
                    t->number--;
                    return 0;
                }
            }

     }

}
int	remove_min( struct tree* t, struct node*	n)
{
    struct node *min;
    min = n;
    int k;
    while(min->left!=NULL)
        {
        min = min->left;
        }
        if(min->right!=NULL)
        {
            k=min->value;
            min->value=min->right->value;
            min->right = NULL;
            free(min->right);
            t->number--;
            return k;
        }
        else
            {
                min->parent->left=NULL;
                k=min->value;
                free(min);
                t->number--;
                return k;
            }
}
int rotate_right(struct tree* t, struct node	*n)
 {
     if(n->left==NULL)return 1;
     if(n==t->root)
     {
         n->left->parent=NULL;
         t->root=n->left;
     }
     else
    {
        if (n->parent->left==n) n->parent->left=n->left;
        else n->parent->right=n->left;
        n->left->parent=n->parent;

    }
    struct node *temp;
    temp=n->left->right;
    n->parent = n->left;
    n->left->right=n;
    n->left=temp;
    return 0;
 }
 int rotate_left(struct tree* t, struct node	*n)
 {
     if(n->right==NULL)return 1;
     if(n==t->root)
     {
         n->right->parent=NULL;
         t->root=n->right;
     }
     else
    {
        if (n->parent->left==n) n->parent->left=n->right;
        else n->parent->right=n->right;
        n->right->parent=n->parent;
    }
    struct node *temp;
    temp=n->right->left;
    n->parent = n->right;
    n->right->left=n;
    n->right=temp;
    return 0;
 }
int main()
{
    struct tree a;
    init(&a);
    for(int i=0; i<4;i++)//1
    {
         int n;
         scanf("%d",&n);
         insert(&a,n);
    }
    printTree(&a);

    for(int i=0; i<3;i++)//2
    {
         int n;
         scanf("%d",&n);
         insert(&a,n);
    }
    printTree(&a);

    int m;//5
    scanf("%d",&m);
    struct node *b=NULL;
    find (&a,m,&b);
    if(b==NULL) printf("_\n");
    else
    {
        if (b->parent==NULL) printf("_ ");
        else printf("%d ",b->parent->value);
        if (b->left==NULL) printf("_ ");
        else printf("%d ",b->left->value);
        if (b->right==NULL) printf("_\n");
        else printf("%d\n",b->right->value);
    }

    scanf("%d",&m);//6
    b=NULL;
    find (&a,m,&b);
    if(b==NULL) printf("-\n");
    else
    {
        if (b->parent==NULL) printf("_ ");
        else printf("%d ",b->parent->value);
        if (b->left==NULL) printf("_ ");
        else printf("%d ",b->left->value);
        if (b->right==NULL) printf("_\n");
        else printf("%d\n",b->right->value);
    }

    scanf("%d",&m);//7
    remove_1(&a,m);
    printTree(&a);

    while(rotate_left(&a,a.root)!=1) m=0;//8
    printTree(&a);

    while(rotate_right(&a,a.root)!=1) m=0;//9
    printTree(&a);

    printf("%d\n",a.number);//10

    clear(&a);
    printTree(&a);

    return 0;
}

