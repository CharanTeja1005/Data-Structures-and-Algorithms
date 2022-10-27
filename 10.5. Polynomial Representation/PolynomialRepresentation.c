#include<stdio.h>
#include<stdlib.h>

struct term
{
    int coeff;
    int exp;
};

struct polynomial
{
    int n;
    struct term *t;
};

void create(struct polynomial *p)
{
    printf("Enter the non-zero terms in polynomial : ");
    scanf("%d",&p->n);
    p->t = (struct term *)malloc(p->n * sizeof(struct term));
    int i;
    for(i=0;i<p->n;i++)
    {
        printf("Term %d :\n",i+1);
        printf("Enter exponent : ");
        scanf("%d",&p->t[i].exp);
        printf("Enter coefficient : ");
        scanf("%d",&p->t[i].coeff);
    }
}

void display(struct polynomial p)
{
    int i = 0;
    while(i < p.n)
    {
        printf("%d x^%d",p.t[i].coeff,p.t[i].exp);
        i++;
        if(i != p.n)
            printf(" + ");
        else if(i = p.n)
            printf(" = 0");
    }
    printf("\n");
}

struct polynomial* add(struct polynomial *p1,struct polynomial *p2)
{
    struct polynomial *sum;
    sum = (struct polynomial *)malloc(sizeof(struct polynomial));
    sum->t = (struct term *)malloc(sizeof(struct term));
    int i,j,k;
    i = j = k = 0;
    while(i < p1->n && j < p2->n)
    {
        if(p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if(p1->t[i].exp < p2->t[j].exp)
            sum->t[k++] = p2->t[j++];
        else
        {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    while(i < p1->n)
    {
        sum->t[k++] = p1->t[i++];
    }
    while(j < p2->n)
    {
        sum->t[k++] = p2->t[j++];
    }
    sum->n = k;
    return sum;
}

int main()
{
    struct polynomial p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3 = add(&p1,&p2);
    printf("The first polynomial : ");
    display(p1);
    printf("The second polynomial : ");
    display(p2);
    printf("Sum polynomial : ");
    display(*p3);
    return 0;
}