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

//Normal Linear Search
int linear_search(struct Array *a,int key)
{
    int i;
    for(i=0;i<a->length;i++)
    {
        if(key == a->A[i])
            return i;
    }
    return -1;
}

//Transposition Linear Search
int transposition_linear_search(struct Array *a,int key)
{
    int i;
    for(i=0;i<a->length;i++)
    {
        if(key == a->A[i])
        {
            swap(&a->A[i],&a->A[i-1]);
            return i;
        }
    }
    return -1;
}

//Move to Front/head
int front_linear_search(struct Array *a,int key)
{
    int i;
    for(i=0;i<a->length;i++)
    {
        if(key == a->A[i])
        {
            swap(&a->A[i],&a->A[0]);
            return 0;
        }
    }
    return -1;
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
    struct Array arr = {{0,1,2,3,4,5},20,6};
    display(arr);
    printf("%d\n",front_linear_search(&arr,3));
    printf("%d\n",front_linear_search(&arr,8));
    display(arr);
    return 0;
}