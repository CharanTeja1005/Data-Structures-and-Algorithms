#include<iostream>
using namespace std;

int sum(int n)
{
    if(n == 0)
        return 0;
    return sum(n - 1) + n;
}

int Isum(int n)
{
    int s = 0;
    for(int i=1;i<=n;i++)
    {
        s += i;
    }
    return s;
}

int main()
{
    int n = sum(5);
    cout<<n<<endl;
    int m = Isum(5);
    cout<<m<<endl;
    return 0;
}