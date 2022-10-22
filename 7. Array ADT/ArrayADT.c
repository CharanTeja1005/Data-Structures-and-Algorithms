#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
    printf("\n");
}

void append(struct Array *a,int x)
{
    if(a->length < a->size)
    {
        a->A[a->length++] = x;
    }
}

void insert(struct Array *a,int index,int x)
{
    int i;
    if(index >= 0 && index <= a->length)
    {
        for(i=a->length;i>index;i--)
        {
            a->A[i] = a->A[i-1];
        }
        a->A[index] = x;
        a->length++;
    }
}

int main()
{
    struct Array arr = {{1,2,3,4,5},10,5};
    display(arr);
    append(&arr,6);
    append(&arr,7);
    append(&arr,8);
    display(arr);
    insert(&arr,0,0);
    display(arr);
    return 0;
}