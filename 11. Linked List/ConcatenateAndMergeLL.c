#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first,*second,*third=NULL;

struct Node *create(struct Node *head,int a[],int n)
{
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = NULL;
    last = head;
    int i;
    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;
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

void concat(struct Node *p,struct Node *q)
{
    third = p;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p != NULL && q != NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p != NULL)
        last->next = p;
    else
        last->next = q;
}

int main()
{
    int a[] = {1,3,5,7,9};
    first = create(first,a,5);
    int b[] = {2,4,6,8,10};
    second = create(second,b,5);
    display(first);
    display(second);
    // concat(first,second);
    // display(third);
    merge(first,second);
    display(third);
    return 0;
}