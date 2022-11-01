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

int isLoop(struct Node *f)
{
    struct Node *p,*q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;
    } 
    while (p && q && p != q);
    return p == q ? 1 : 0;
}

int main()
{
    struct Node *t1,*t2;
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    t1 = first->next;
    t2 = first->next->next->next->next;
    t2->next = t1; 
    isLoop(first) ? printf("LL is Loop\n") : printf("LL is not loop\n");
    return 0;
}