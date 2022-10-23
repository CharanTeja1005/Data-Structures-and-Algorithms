#include<stdio.h>

struct Array
{
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

int iterative_binary_search(struct Array *a,int key)
{
    int l = 0;
    int h = a->length-1;
    int mid;
    while(l<=h)
    {
        mid = (l + h)/2;
        if(a->A[mid] == key)
            return mid;
        else if (a->A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int recursive_binary_search(struct Array a,int l,int h,int key)
{
    int mid = (l + h)/2;
    if(l<=h)
    {
        if(a.A[mid] == key)
            return mid;
        else if (a.A[mid] > key)
            return recursive_binary_search(a,l,mid-1,key);
        else
            return recursive_binary_search(a,mid+1,h,key);
    }
    return -1;
}

int main()
{
    struct Array arr = {{0,1,2,3,4,5},20,6};
    display(arr);
    printf("%d\n",recursive_binary_search(arr,0,arr.length-1,3));
    printf("%d\n",recursive_binary_search(arr,0,arr.length-1,8));
    return 0;
}