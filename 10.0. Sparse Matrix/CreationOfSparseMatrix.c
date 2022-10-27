#include<stdio.h>
#include<stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct SparseMatrix
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct SparseMatrix *s)
{
    printf("Enter the dimensions of matrix : ");
    scanf("%d x %d",&s->m,&s->n);
    printf("Enter the number of non-zero elements : ");
    scanf("%d",&s->num);
    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
    int i,j;
    printf("Enter the elements of matrix : \n");
    for(i=0;i<s->num;i++)
    {
        printf("Enter the row : ");
        scanf("%d",&s->e[i].i);
        printf("Enter the column : ");
        scanf("%d",&s->e[i].j);
        printf("Enter the element : ");
        scanf("%d",&s->e[i].x);
    }
}

void display(struct SparseMatrix s)
{
    int i,j,k=0;
    printf("The elements of Sparse Matrix : \n\n");
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i == s.e[k].i - 1 && j == s.e[k].j - 1)
            // if(i == s.e[k].i && j == s.e[k].j)
                printf("%d ",s.e[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct SparseMatrix s;
    create(&s);
    display(s);
    return 0;
}