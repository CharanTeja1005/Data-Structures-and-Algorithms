#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
    T *stack;
    int size;
    int top;
public:
    Stack()
    {
        this->size = 5;
        this->top = -1;
        this->stack = new T[this->size];
    }
    Stack(T size)
    {
        this->size = size;
        this->top = -1;
        this->stack = new T[this->size];
    }
    void push(T x);
    T pop();
    T peek(int pos);
    T stackTop();
    bool isEmpty();
    bool isFull();
};

template<class T>
void Stack<T>::push(T x)
{
    if(isFull())
        cout<<"Stack Overflow!"<<endl;
    else
    {
        stack[++top] = x;
    }
}

template<class T>
T Stack<T>::pop()
{
    if(isEmpty())
        return -1;
    else
        return stack[top--];
}

template<class T>
T Stack<T>::peek(int pos)
{
    if(top - pos + 1 < 0)
        return -1;
    else
        return stack[top - pos + 1];
}

template<class T>
T Stack<T>::stackTop()
{
    if(isEmpty())
        return -1;
    else
        return stack[top];
}

template<class T>
bool Stack<T>::isEmpty()
{
    if(top == -1)
        return true;
    else
        return false;
}

template<class T>
bool Stack<T>::isFull()
{
    if(top == size - 1)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cout<<"Enter size of Stack : ";
    cin>>n;
    Stack<int> st[n];
    int c,x;
    while(1)
    {
        cout<<endl<<"Stack Menu :"<<endl;
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Top\n5. isEmpty\n6. isFull\n7. Exit\n";
        cout<<"Enter your choice : ";
        cin>>c;
        cout<<endl;
        switch(c)
        {
            case 1: cout<<"Enter the element to be pushed : ";
                    cin>>x;
                    st->push(x);
                    break;
            case 2: x = st->pop();
                    x == -1 ?
                    cout<<"Stack underflow!"<<endl :
                    cout<<"Popped Element : "<<x<<endl;
                    break;
            case 3: cout<<"Enter the position to be peeked : ";
                    cin>>x;
                    x = st->peek(x);
                    (x == -1) ?
                    cout<<"Invalid Index!"<<endl :
                    cout<<"Peeked element : "<<x<<endl;
                    break;
            case 4: x = st->stackTop();
                    (x == -1) ?
                    cout<<"Stack underflow!"<<endl :
                    cout<<"Stack Top Element : "<<x<<endl;
                    break;
            case 5: (st->isEmpty()) ?
                    cout<<"Stack is Empty!"<<endl :
                    cout<<"Stack is not empty!"<<endl;
                    break;
            case 6: (st->isFull()) ?
                    cout<<"Stack is Full!"<<endl :
                    cout<<"Stack is not full!"<<endl;
                    break;
            case 7: cout<<"Program Terminated!!!"<<endl;
                    exit(0);
                    break;
            default:cout<<"Incorrect Choice! Try Again!"<<endl;
                    break;
        }
    }
    return 0;
}