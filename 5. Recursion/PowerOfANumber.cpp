#include<iostream>
using namespace std;

int power(int m,int n)
{
    if(n == 0)
        return 1;
    return m * power(m,n - 1);
}

int fastpower(int m,int n)
{
    if(n == 0)
        return 1;
    else if(n % 2 == 0)
        return fastpower(m*m,n/2);
    return m * fastpower(m*m,(n-1)/2);
}

int main()
{
    int p1 = power(2,9);
    cout<<p1<<endl;
    int p2 = fastpower(2,9);
    cout<<p2<<endl;
    return 0;
}