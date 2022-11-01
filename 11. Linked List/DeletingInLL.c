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

int delete(struct Node *p,int index)
{
    struct Node *q;
    int x = -1,i;
    if(index < 1 || index > count(p))
        return -1;
    if(index == 1)
    {
        q = first;
        x = q->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    printf("Deleted Element : %d\n",delete(first,3));
    display(first);
    return 0;
}