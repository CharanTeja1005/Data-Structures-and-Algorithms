#include<iostream>
using namespace std;
// Column Major Representation

class UpperTriangularMatrix
{
    private:
    int n;
    int *A;
    public:
    UpperTriangularMatrix(int n)
    {
        this -> n = n;
        A = new int[n];
    }
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~UpperTriangularMatrix()
    {
        delete []A;
    }
};

void UpperTriangularMatrix::set(int i,int j,int x)
{
    if(i <= j)
        A[j*(j-1)/2 + i-1] = x;
}

int UpperTriangularMatrix::get(int i,int j)
{
    if(i <= j)
        return A[j*(j-1)/2 + i-1];
    else
        0;
}

void UpperTriangularMatrix::display()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i <= j)
                cout<<A[j*(j-1)/2 + i-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter the size of n dimensional Upper Triangular Matrix : ";
    cin>>d;
    UpperTriangularMatrix lm(d);
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
    cout<<endl<<"The Upper Triangular Matrix Elements : "<<endl;
    lm.display();
    return 0;
}