#include<iostream>
using namespace std;

template<class T>
class Arithmetic
{
    // private:
    T a;
    T b;
    public:
    Arithmetic(T a,T b);
    T add();
    T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a,T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arithmetic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template<class T>
T Arithmetic<T>::sub()
{
    T c;
    c = a - b;
    return c;
}

int main()
{
    Arithmetic<int> arInt(10,5);
    cout<<arInt.add()<<endl<<arInt.sub()<<endl;
    Arithmetic<float> arFloat(10.224,2.334);
    cout<<arFloat.add()<<endl<<arFloat.sub()<<endl;
    return 0;
}