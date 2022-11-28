#include<iostream>
using namespace std;

void insert(int A[],int n)
{
    int temp = A[n];
    int i = n;
    while(i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i /= 2;
    }
    A[i] = temp;
}

int Delete(int A[],int n)
{
    int x = A[n];
    int val = A[1];
    A[1] = A[n];
    int i = 1;
    int j = i * 2;
    while(j < n-1)
    {
        if(A[j+1] > A[j])
            j += 1;
        if(A[i] < A[j])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = i * 2;
        }
        else
            break;
    }
    A[n] = val;
    return val;
}

int main()
{
    int A[] = {0,10,20,30,25,5,40,35};
    for(int i=2;i<=7;i++)
        insert(A,i);
    for(int i:A)
        cout<<i<<" ";
    cout<<endl;
    // Delete(A,10);
    for(int i=7;i>1;i--)
        Delete(A,i);
    for(int i:A)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}