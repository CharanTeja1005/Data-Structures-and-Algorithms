#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

int get(struct Array a,int index)
{
    if(index >= 0 && index < a.length)
    {
        return a.A[index];
    }
}

void set(struct Array *a,int index,int x)
{
    if(index >= 0 && index < a->length)
    {
        a->A[index] = x;
    }
}

int max(struct Array a)
{
    int max = a.A[0];
    int i;
    for(i=1;i<a.length;i++)
    {
        if(a.A[i] > max)
        {
            max = a.A[i];
        }
    }
    return max;
}

int min(struct Array a)
{
    int min = a.A[0];
    int i;
    for(i=1;i<a.length;i++)
    {
        if(a.A[i] < min)
        {
            min = a.A[i];
        }
    }
    return min;
}

int sum(struct Array a)
{
    int i,sum = 0;
    for(i=0;i<a.length;i++)
    {
        sum += a.A[i];
    }
    return sum;
}

float avg(struct Array a)
{
    int i,sum = 0;
    for(i=0;i<a.length;i++)
    {
        sum += a.A[i];
    }
    return sum/a.length;
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
    printf("%d\n",get(arr,4));
    set(&arr,2,8);
    display(arr);
    printf("%d\n",min(arr));
    printf("%d\n",max(arr));
    printf("%d\n",sum(arr));
    printf("%f\n",avg(arr));
    return 0;
}