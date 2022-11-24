#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

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
    bool isEmpty();
};

void Stack::push(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = top;
    top = t;
}

int Stack::pop()
{
    int x = -1;
    if(top)
    {
        Node *t = top;
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}

bool Stack::isEmpty()
{
    return (top==NULL) ? true : false;
}

class Queue
{
private:
    Stack *st1,*st2;
public:
    Queue()
    {
        st1 = new Stack();
        st2 = new Stack();
    }
    void enqueue(int x);
    int dequeue();
};

void Queue::enqueue(int x)
{
    st1->push(x);
}

int Queue::dequeue()
{
    int x = -1;
    if(st2->isEmpty())
    {
        if(st1->isEmpty())
            return x;
        while(!st1->isEmpty())
        {
            st2->push(st1->pop());
        }
    }
    return st2->pop();
}

int main()
{
    Queue q;
    q.enqueue(6);
    q.enqueue(3);
    q.enqueue(9);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(18);
    q.enqueue(12);
    q.enqueue(10);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}