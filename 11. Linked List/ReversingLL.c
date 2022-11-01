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
        Rdisplay(p->next);
        printf("%d ",p->data);
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

void Reverse(struct Node *p)
{
    int *A;
    A = (int *)malloc(sizeof(int) * count(first));
    struct Node *q = p;
    int i = 0;
    while(q)
    {
        A[i++] = q->data;
        q = q->next;
    }
    i--;
    q = p;
    while(q)
    {
        q->data = A[i--];
        q = q->next;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL,*r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void RRReverse(struct Node *q,struct Node *p)
{
    if(p)
    {
        RRReverse(p,p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    Reverse(first);
    display(first);
    Reverse2(first);
    display(first);
    RRReverse(NULL,first);
    display(first);
    return 0;
}