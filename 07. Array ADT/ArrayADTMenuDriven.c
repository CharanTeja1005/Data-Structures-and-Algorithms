#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

int main()
{
    struct Array arr;
    int c;
    int x,index;

    printf("Enter Size of Array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    while(ch<6)
    {
        printf("\n\nMenu\n");
        printf("1. Display\n2. Append\n3. Insert\n4. Delete\n5. Search\n6. Get\n7. Set\n8. Max\n9. Min\n10. Reverse\n11. Exit\n");
        printf("Enter you choice ");
        scanf("%d",&c);

        switch(c)
        {
            case 1: printf("Enter an element and index");
            scanf("%d%d",&x,&index);
            Insert(&arr,index,x);
            break;
            case 2: printf("Enter index ");
            scanf("%d",&index);
            x=Delete(&arr,index);
            printf("Deleted Element is %d\n",x);
            break;
            case 3:printf("Enter element to search ");
            scanf("%d",&x);
            index=LinearSearch(&arr1,x);
            printf("Element index %d",index);
            break;
            case 4:printf("Sum is %d\n",Sum(arr1));
            break;
            case 5:Display(arr1);
        }
    }
    return 0;
}