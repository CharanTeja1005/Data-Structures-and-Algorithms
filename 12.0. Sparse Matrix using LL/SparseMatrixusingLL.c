#include<stdio.h>
#include<stdlib.h>

int r,c;

struct Node
{
    int row;
    int col;
    int val;
    struct Node *next;
}*A;

void create()
{
    printf("Enter the dimensions of Matrix : ");
    scanf("%d x %d",&r,&c);
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

void display(struct Node *A)
{
    int i,j;
    struct Node *p = A;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i == p->row && j == p->col)
            {
                printf("%d ",p->val);
                p = p->next;
            }
            else
                printf("0 ");
            
        }
        printf("\n");
    }
}

int main()
{
    create();
    display(A);
    return 0;
}