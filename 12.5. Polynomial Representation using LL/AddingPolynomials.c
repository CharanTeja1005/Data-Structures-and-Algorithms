#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly1 = NULL,*poly2 = NULL;

void create()
{
    struct Node *p,*last = NULL;
    int num;
    printf("Enter the non zero terms in first polynomial : ");
    scanf("%d",&num);
    int i;
    for(i=0;i<num;i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        printf("Term %d:\n",i+1);
        printf("Enter coefficient : ");
        scanf("%d",&p->coeff);
        printf("Enter exponent : ");
        scanf("%d",&p->exp);
        p->next = NULL;
        if(poly1 == NULL)
        {
            poly1 = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
}

void Create()
{
    struct Node *p,*last = NULL;
    int num;
    printf("Enter the non zero terms in second polynomial : ");
    scanf("%d",&num);
    int i;
    for(i=0;i<num;i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        printf("Term %d:\n",i+1);
        printf("Enter coefficient : ");
        scanf("%d",&p->coeff);
        printf("Enter exponent : ");
        scanf("%d",&p->exp);
        p->next = NULL;
        if(poly2 == NULL)
        {
            poly2 = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
}

void display(struct Node *p)
{
    while(p)
    {
        printf("%d x^%d",p->coeff,p->exp);
        if(p->next == NULL)
            printf(" = 0\n");
        else
            printf(" + ");
        p = p->next;
    }
}

struct Node *add(struct Node *p,struct Node *q)
{
    struct Node *sum = NULL,*t = NULL,*last = NULL;
    while(p != NULL && q != NULL)
    {
        if(p->exp > q->exp)
        {
            t = p;
            p = p->next;
        }
        else if(p->exp < q->exp)
        {
            t = q;
            q = q->next;
        }
        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->exp = p->exp;
            t->coeff = p->coeff + q->coeff;
            p = p->next;
            q = q->next;
        }
        t->next = NULL;
        if(sum != NULL)
        {
            last->next = t;
            last = t;
        }
        else
        {
            sum = last = t;
        }
    }
    if(p != NULL)
        last->next = p;
    else if(q != NULL)
        last->next = q;
    return sum;
}

int main()
{
    create();
    Create();
    struct Node *sum = NULL;
    printf("The first polynomial : ");
    display(poly1);
    printf("The second polynomial : ");
    display(poly2);
    sum = add(poly1,poly2);
    printf("Sum of two polynomials : ");
    display(sum);
    return 0;
}