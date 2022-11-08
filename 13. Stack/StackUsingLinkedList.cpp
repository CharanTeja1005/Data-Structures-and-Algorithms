#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

template<class T>
class Stack
{
private:
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
};

template<class T>
void Stack<T>::push(int x)
{
    Node *t = new Node;
    if(t == NULL)
    {
        cout<<"Stack Overflow!"<<endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template<class T>
int Stack<T>::pop()
{
    if(top == NULL)
    {
        return -1;
    }
    else
    {
        int x = top->data;
        Node *t = top;
        top = top->next;
        free(t);
        return x;
    }
}

template<class T>
void Stack<T>::display()
{
    if(top == NULL)
    {
        cout<<"Stack Underflow!"<<endl;
    }
    else
    {
        Node *p = top;
        while(p != NULL)
        {
            cout<<p->data;
            p = p->next;
            if(p == NULL)
                cout<<" -> NULL"<<endl;
            else
                cout<<" -> ";
        }
    }
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
        cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n";
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
            case 3: cout<<"Elements of stack : ";
                    st->display();
                    break;
            case 4: cout<<"Program Terminated!!!"<<endl;
                    exit(0);
                    break;
            default:cout<<"Incorrect Choice! Try Again!"<<endl;
                    break;
        }
    }
    return 0;
}