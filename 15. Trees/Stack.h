#include<iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    struct Node **S;
public:
    Stack()
    {
        top = -1;
        size = 10;
        S = new Node*[size];
    }
    Stack(int size)
    {
        top = -1;
        this->size = size;
        S = new Node*[this->size];
    }
    void push(Node *x);
    Node* pop();
    bool isEmpty();
};

void Stack::push(Node *x)
{
    if(top == size-1)
        cout<<"Stack is Full"<<endl;
    else
        S[++top] = x;
}

Node* Stack::pop()
{
    Node *t = NULL;
    if(top == -1)
        cout<<"Stack is Empty"<<endl;
    else
        t = S[top--];
    return t;
}

bool Stack::isEmpty()
{
    return top==-1 ? true : false;
}