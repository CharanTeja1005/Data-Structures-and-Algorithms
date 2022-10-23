#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void reverse(struct Array *a)
{
    int *b = (int *)malloc(a->length * sizeof(int));
    int i,j;
    for(i=a->length-1,j=0;i>=0;i--,j++)
    {
        b[j] = a->A[i];
    }
    for(i=0;i<a->length;i++)
    {
        a->A[i] = b[i];
    }
}


//Another approach
void reverse2(struct Array *a)
{
    int i,j;
    for(i=0,j=a->length-1;i<j;i++,j--)
    {
        swap(&a->A[i],&a->A[j]);
    }
}

int main()
{
    struct Array arr = {{0,1,2,3,4,5},20,6};
    display(arr);
    reverse(&arr);
    display(arr);
    reverse2(&arr);
    display(arr);

    return 0;
}