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

int delete(struct Array *a,int index)
{
    int i;
    if(index >= 0 && index < a->length)
    {
        int x = a->A[index];
        for(i=index;i<a->length-1;i++)
        {
            a->A[i] = a->A[i+1];
        }
        a->length--;
        return x;
    }
    return -1;
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
    delete(&arr,3);
    delete(&arr,7);
    display(arr);
    return 0;
}