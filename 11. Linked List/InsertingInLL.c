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
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}

int count(struct Node *p)
{
    int c = 0;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return Rcount(p->next) + 1;
}

void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    printf("\n");
    Insert(first,3,10);
    Rdisplay(first);
    printf("\n");
    return 0;
}