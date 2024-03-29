#include<iostream>
using namespace std;
int F[10];

// int ifib(int n)
// {
//     int t0=0,t1=1,s;
//     for(int i=2;i<=n;i++)
//     {
//         s = t0 + t1;
//         t0 = t1;
//         t1 = s;
//     }
//     return s;
// }

int ifib(int n)
{
    int t0=0,t1=1,s;
    for(int i=0;i<n;i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return t0;
}

int rfib(int n)
{
    if(n <= 1)
        return n;
    return rfib(n-2) + rfib(n-1);
}

int mfib(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    if(F[n-2] == -1)
        F[n-2] = mfib(n-2);
    if(F[n-1] == -1)
        F[n-1] = mfib(n-1);
    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
}

int main()
{
    for(int i=0;i<10;i++)
    {
        F[i] = -1;
    }
    cout<<ifib(5)<<endl;
    cout<<rfib(5)<<endl;
    cout<<mfib(5)<<endl;
    return 0;
}