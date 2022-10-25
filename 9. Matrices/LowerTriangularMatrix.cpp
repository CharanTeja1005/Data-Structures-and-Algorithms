#include<iostream>
using namespace std;

// Row Major Representation

class LowerTriangularMatrix
{
    private:
    int n;
    int *A;
    public:
    LowerTriangularMatrix(int n)
    {
        this -> n = n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~LowerTriangularMatrix()
    {
        delete []A;
    }
};

void LowerTriangularMatrix::set(int i,int j,int x)
{
    if(i >= j)
        A[i*(i-1)/2 + j-1] = x;
}

int LowerTriangularMatrix::get(int i,int j)
{
    if(i >= j)
        return A[i*(i-1)/2 + j-1];
    else
        0;
}

void LowerTriangularMatrix::display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i >= j)
                cout<<A[i*(i-1)/2 + j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter the size of n dimensional Lower Triangular Matrix : ";
    cin>>d;
    LowerTriangularMatrix lm(d);
    cout<<"Enter the elements of the Matrix : "<<endl;
    int i,j;
    int x;
    for(i=1;i<=d;i++)
    {
        for(j=1;j<=d;j++)
        {
            cin>>x;
            lm.set(i,j,x);
        }
    }
    cout<<endl<<"The Lower Triangular Matrix Elements : "<<endl;
    lm.display();
    return 0;
}