#include<iostream>
using namespace std;

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
    void create();
    void set(int i,int j,int x);
    int get(int i,int j);
    void display();
    ~DiagonalMatrix()
    {
        delete []A;
    }
};

void DiagonalMatrix::create()
{
    int i,x;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        A[i-1] = x;
    }
}

void DiagonalMatrix::set(int i,int j,int x)
{
    if(i > n || j > n)
    {
        cout<<"Row And Column not exist"<<endl;
        return;
    }
    if(i == j)
    {
        A[i-1] = x;
        cout<<"Element Set : "<<x;
    }
}

int DiagonalMatrix::get(int i,int j)
{
    if(i > n || j > n)
    {
        cout<<"Row And Column not exist"<<endl;
        return -1;
    }
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
    int c,size;
    int i,j,x;
    cout<<"Enter the size of n dimensional Diagonal Matrix : ";
    cin>>size;
    DiagonalMatrix d(size);
    while(c != 5)
    {
        cout<<"\nMenu\n";
        cout<<"1. Create\n2. Set\n3. Get\n4. Display\n5. Exit\n"<<endl;
        cout<<"Enter you choice : ";
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case 1: cout<<"Enter the diagonal elements of matrix : "<<endl;
                    d.create();
                    break;
            case 2: cout<<"Enter the row and column : "<<endl;
                    cin>>i;
                    cin>>j;
                    cin>>x;
                    d.set(i,j,x);
                    break;
            case 3: cout<<"Enter the row and column : "<<endl;
                    cin>>i;
                    cin>>j;
                    cout<<"Element at "<<i<<", "<<j<<" : "<<d.get(i,j);
                    break;
            case 4: cout<<"The elements of Matrix : "<<endl;
                    d.display();
                    break;
            case 5: cout<<"Program Terminated"<<endl;
                    exit(0);
            default: cout<<"Incorrect Choice, Try Again"<<endl;
                     break;
        }
    }
    return 0;
}