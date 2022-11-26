#include<iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node*[size];
    }
    void enqueue(Node *x);
    Node* dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node *x)
{
    if(rear == size-1)
        cout<<"Queue is Full"<<endl;
    else
        Q[++rear] = x;
}

Node* Queue::dequeue()
{
    Node *t = NULL;
    if(front == rear)
        cout<<"Queue is Empty"<<endl;
    else
        t = Q[++front];
    return t;
}

bool Queue::isEmpty()
{
    if(front == rear)
        return true;
    else
        return false;
}