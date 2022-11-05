#include<stdio.h>
#include<stdlib.h>

int r,c;

struct Node
{
    int row;
    int col;
    int val;
    struct Node *next;
}*A,*B;

void create()
{
    int num;
    printf("Enter the number of non-zero elements in Sparse Matrix : ");
    scanf("%d",&num);
    int i,j,row;
    struct Node *p,*last = NULL;
    printf("Enter the elements of Matrix : \n");
    for(i=0;i<num;i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the row : ");
        scanf("%d",&p->row);
        printf("Enter the column : ");
        scanf("%d",&p->col);
        printf("Enter the element : ");
        scanf("%d",&p->val);
        p->next = NULL;
        if(A == NULL)
        {
            A = last = p;
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
    int num;
    printf("Enter the number of non-zero elements in Sparse Matrix : ");
    scanf("%d",&num);
    int i,j,row;
    struct Node *p,*last = NULL;
    printf("Enter the elements of Matrix : \n");
    for(i=0;i<num;i++)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the row : ");
        scanf("%d",&p->row);
        printf("Enter the column : ");
        scanf("%d",&p->col);
        printf("Enter the element : ");
        scanf("%d",&p->val);
        p->next = NULL;
        if(B == NULL)
        {
            B = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
}

void display(struct Node *a)
{
    int i,j;
    struct Node *p = a;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i == p->row && j == p->col)
            {
                printf("%d ",p->val);
                if(p->next != NULL)
                    p = p->next;
            }
            else
                printf("0 ");
            
        }
        printf("\n");
    }
}

struct Node *add(struct Node *s1,struct Node *s2)
{
    struct Node *sum = NULL,*p,*last = NULL;
    while(s1 != NULL && s2 != NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        if(s1->row < s2->row)
        {
            // p->row = s1->row;
            // p->col = s1->col;
            // p->val = s1->val;
            p = s1;
            s1 = s1->next;
        }
        else if(s1->row > s2->row)
        {
            // p->row = s2->row;
            // p->col = s2->col;
            // p->val = s2->val;
            p = s2;
            s2 = s2->next;
        }
        else
        {
            if(s1->col < s2->col)
            {
                // p->row = s1->row;
                // p->col = s1->col;
                // p->val = s1->val;
                p = s1;
                s1 = s1->next;
            }
            else if(s1->col > s2->col)
            {
                // p->row = s2->row;
                // p->col = s2->col;
                // p->val = s2->val;
                p = s2;
                s2 = s2->next;
            }
            else
            {
                p->row = s1->row;
                p->col = s2->col;
                p->val = s1->val + s2->val;
                s1 = s1->next;
                s2 = s2->next;
            }
        }
        p->next = NULL;
        if(sum == NULL)
        {
            sum = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
    }
    if(s1 != NULL)
        last->next = s1;
    else
        last->next = s2;
    return sum;
}

int main()
{
    printf("Enter the dimensions of Matrix : ");
    scanf("%d x %d",&r,&c);
    struct Node *sum;
    create();
    display(A);
    Create();
    display(B);
    sum = add(A,B);
    printf("Sum of two Matrices : \n");
    display(sum);
    return 0;
}