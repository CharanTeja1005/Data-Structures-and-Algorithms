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

int add(struct Node *p)
{
    int sum = 0;
    while(p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Radd(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return Radd(p -> next) + p -> data;
}

int main()
{
    int a[] = {1,2,3,4,5};
    create(a,5);
    display(first);
    printf("\n");
    Rdisplay(first);
    printf("\n%d\n",add(first));
    printf("%d\n",Radd(first));
    return 0;
}