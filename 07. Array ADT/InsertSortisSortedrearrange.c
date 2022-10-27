#include<stdio.h>

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

void insertSort(struct Array *a,int x)
{
    int i = a->length-1;
    if(a->size == a->length)
        return;
    while(i>=0 && a->A[i] > x)
    {
        a->A[i+1] = a->A[i];
        i--;
    }
    a->A[i+1] = x;
    a->length++;
}

int isSorted(struct Array a)
{
    int i;
    for(i=0;i<a.length-1;i++)
        if(a.A[i] > a.A[i+1])
            return 0;
    return 1;
}

void rearrange(struct Array *a)
{
    int i = 0;
    int j = a->length-1;
    while(i<j)
    {
        while(a->A[i] < 0) i++;
        while(a->A[j] > 0) j--;
        if(i < j)
        {
            swap(&a->A[i],&a->A[j]);
        }
    }
}

int main()
{
    struct Array arr = {{1000,-12,-66,-13,14,20},20,6};
    display(arr);
    rearrange(&arr);
    display(arr);
    insertSort(&arr,7);
    display(arr);
    isSorted(arr) ? printf("Is sorted\n") : printf("Not Sorted\n");
    return 0;
}