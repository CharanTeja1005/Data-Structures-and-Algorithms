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

struct SparseMatrix* add(struct SparseMatrix *s1,struct SparseMatrix *s2)
{
    struct SparseMatrix *sum;
    if(s1->m != s2->m && s1->n != s2->n)
        return 0;
    sum = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    sum -> e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));
    int i,j,k;
    i = j = k = 0;
    while(i < s1->num && j < s2->num)
    {
        if(s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if(s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if(s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if(s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    while(i < s1->num)
    {
        sum->e[k++] = s1->e[i++];
    }
    while(j < s2->num)
    {
        sum->e[k++] = s2->e[j++];
    }
    sum->num = k;
    sum->m = s1->m;
    sum->n = s1->n;
    return sum;
}

int main()
{
    struct SparseMatrix s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);
    printf("First Matrix :\n");
    display(s1);
    printf("Second Matrix :\n");
    display(s2);
    printf("Sum Matrix :\n");
    display(*s3);
    return 0;
}