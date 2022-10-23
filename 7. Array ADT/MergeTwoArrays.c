#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

struct Array* merge(struct Array *a1,struct Array *a2)
{
    struct Array *a3 = (struct Array *)malloc(sizeof(struct Array));
    a3->size = 20;
    int i,j,k;
    i = j = k = 0;
    int m = a1->length;
    int n = a2->length;
    while(i < m && j < n)
    {
        if(a1->A[i] < a2->A[j])
            a3->A[k++] = a1->A[i++];
        else
            a3->A[k++] = a2->A[j++];
    }
    while(i<m)
        a3->A[k++] = a1->A[i++];
    while(j<n)
        a3->A[k++] = a2->A[j++];
    a3->length = a1->length + a2->length;
}

int main()
{
    struct Array arr1 = {{0,1,2,3,4,5},20,6};
    display(arr1);
    struct Array arr2 = {{10,11,12,13,14,15},20,6};
    display(arr2);
    struct Array *arr3 = merge(&arr1,&arr2);
    display(*arr3);
    return 0;
}