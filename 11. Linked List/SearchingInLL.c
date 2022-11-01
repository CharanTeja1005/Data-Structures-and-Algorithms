#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first;

void create(int a[],int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    int i;
    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL");
}

void Rdisplay(struct Node *p)
{
    if(p != NULL)
    {
        Rdisplay(p->next);
        printf("%d ",p->data);
    }
}

struct Node *LinearSearch(struct Node *p,int key)
{
    while(p)
    {
        if(p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *RLinearSearch(struct Node *p,int key)
{
    if(p == NULL)
        return NULL;
    if(p->data == key)
        return p;
    return RLinearSearch(p->next,key);
}

struct Node *LinearS(struct Node *p,int key)
{
    struct Node *q;
    while(p != NULL)
    {
        if(p->data == key)
        {
            q = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    struct Node *temp = LinearSearch(first,25);
    printf("\n");
    temp == NULL ? printf("Key not found\n") : printf("Key found %d\n",temp->data);
    struct Node *q = RLinearSearch(first,2);
    q == NULL ? printf("Key not found\n") : printf("Key found %d\n",q->data);
    struct Node *t = LinearS(first,5);
    t == NULL ? printf("Key not found\n") : printf("Key found %d\n",t->data);
    return 0;
}