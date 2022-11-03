#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void create(int a[],int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;

    int i;
    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        t->prev = last;
        last = t;
    }
}

void display(struct Node *p)
{
    printf("NULL");
    while(p != NULL)
    {
        printf(" <-> %d",p->data);
        p = p->next;
    }
    printf(" <-> NULL\n");
}

int length(struct Node *p)
{
    int l = 0;
    while(p != NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

void insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > length(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = t->next = NULL;

    if(index == 0)
    {
        if(first == NULL)
            first = t;
        else
        {
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p = p->next;
            printf("%d ",p->data);
        }
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int delete(struct Node *p,int index)
{
    int x = -1,i;
    if(index < 0 || index > length(p))
        return x;
    if(index == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p = p->next;
            printf("%d ",p->data);
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void reverse(struct Node *p)
{
    struct Node *t;
    while(p)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if(p != NULL && p->next == NULL)
            first = p;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    printf("Length : %d\n",length(first));
    insert(first,5,6);
    display(first);
    printf("Deleted : %d\n",delete(first,6));
    display(first);
    reverse(first);
    display(first);
    return 0;
}