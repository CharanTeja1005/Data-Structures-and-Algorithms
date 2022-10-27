#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

struct Array* Union(struct Array *a1,struct Array *a2)
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
        else if(a1->A[i] > a2->A[j])
            a3->A[k++] = a2->A[j++];
        else
        {
            a3->A[k++] = a1->A[i];
            i++;
            j++;
        }
    }
    while(i<m)
        a3->A[k++] = a1->A[i++];
    while(j<n)
        a3->A[k++] = a2->A[j++];
    a3->length = k;
}

struct Array* Intersection(struct Array *a1,struct Array *a2)
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
            i++;
        else if(a1->A[i] > a2->A[j])
            j++;
        else
        {
            a3->A[k++] = a1->A[i];
            i++;
            j++;
        }
    }
    a3->length = k;
}

struct Array* Difference(struct Array *a1,struct Array *a2)
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
        else if(a1->A[i] > a2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    while(i<m)
        a3->A[k++] = a1->A[i++];
    a3->length = k;
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

int main()
{
    struct Array arr1 = {{0,1,2,3,4,5},20,6};
    display(arr1);
    struct Array arr2 = {{4,5,6,13,14,15},20,6};
    display(arr2);
    struct Array *arr3 = Union(&arr1,&arr2);
    display(*arr3);
    struct Array *arr4 = Intersection(&arr1,&arr2);
    display(*arr4);
    struct Array *arr5 = Difference(&arr1,&arr2);
    display(*arr5);
    struct Array *arr6 = Difference(&arr2,&arr1);
    display(*arr6);
    return 0;
}