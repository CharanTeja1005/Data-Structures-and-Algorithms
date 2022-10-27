#include<iostream>

using namespace std;

class Rectangle
{
    private:
    int length;
    int breadth;
    public:
    Rectangle(int l,int b);
    int area();
    int perimeter();
    // Rectangle(int l,int b)
    // {
    //     length = l;
    //     breadth = b;
    // }
    // int area()
    // {
    //     return length * breadth;
    // }
    // int perimeter()
    // {
    //     return 2*(length+breadth);
    // }
};

Rectangle::Rectangle(int l,int b)
{
    this->length = l;
    this->breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

int main()
{
    Rectangle r(10,5);
    cout<<r.area()<<endl<<r.perimeter();
    return 0;
}