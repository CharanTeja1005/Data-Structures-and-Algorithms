#include<iostream>
using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;
    return fact(n-1) * n;
}

int nCr(int n,int r)
{
    int num = fact(n);
    int den = fact(r) * fact(n-r);
    return num/den;
}

int C(int n,int r)
{
    if(n==r || r==0)
        return 1;
    return C(n-1,r-1) + C(n-1,r);
}

int main()
{
    cout<<nCr(4,2)<<endl;
    cout<<C(4,2)<<endl;
    return 0;
}