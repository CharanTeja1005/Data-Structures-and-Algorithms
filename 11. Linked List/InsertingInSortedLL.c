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
    printf("NULL\n");
}

void Rdisplay(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    SortedInsert(first,35);
    SortedInsert(first,25);
    SortedInsert(first,15);
    SortedInsert(first,18);
    display(first);
    return 0;
}