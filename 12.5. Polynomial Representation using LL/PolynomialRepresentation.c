#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
}*poly = NULL;

void create()
{
    struct Node *p,*last = NULL;
    int num;
    printf("Enter the non zero terms in polynomial : ");
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
        if(poly == NULL)
        {
            poly = last = p;
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
    printf("The polynomial : ");
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

int main()
{
    create();
    display(poly);
    return 0;
}