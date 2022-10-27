#include<iostream>
using namespace std;

// struct DiagonalMatrix{
//     int A[20];
//     int n;
// };

class DiagonalMatrix
{
private:
    int n;
    int *A;
public:
    DiagonalMatrix(int n)
    {
        this -> n = n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~DiagonalMatrix()
    {
        delete []A;
    }
};

void DiagonalMatrix::set(int i,int j,int x)
{
    if(i == j)
        A[i-1] = x;
}

int DiagonalMatrix::get(int i,int j)
{
    if(i == j)
        return A[i-1];
    return 0;
}

void DiagonalMatrix::display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i == j)
                cout<<A[i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    DiagonalMatrix m(5);
    m.set(1,1,1);
    m.set(2,2,2);
    m.set(3,3,3);
    m.set(4,4,4);
    m.set(5,5,5);
    m.display();
    return 0;
}