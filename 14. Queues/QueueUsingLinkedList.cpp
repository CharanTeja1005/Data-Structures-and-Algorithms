#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    Node *t = new Node;
    if(t == NULL)
        cout<<"Queue is Full"<<endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::dequeue()
{
    int x = -1;
    if(front == NULL)
        cout<<"Queue is Empty"<<endl;
    else
    {
        Node *t;
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}

void Queue::display()
{
    Node *t = front;
    while(t)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
    cout<<endl;
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}