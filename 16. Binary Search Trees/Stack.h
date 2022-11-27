#include<iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node()
    {
        lchild = rchild = NULL;
    }
    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

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
    Node* stackTop();
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

Node* Stack::stackTop()
{
    if(top == -1)
    {
        return new Node(INT32_MAX);
    }
    return S[top];
}