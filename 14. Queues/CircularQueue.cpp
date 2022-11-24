#include<iostream>
using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    CircularQueue()
    {
        front = rear = 0;
        size = 5;
        Q = new int[size];
    }
    CircularQueue(int size)
    {
        front = rear = 0;
        this->size = size;
        this->Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void CircularQueue::enqueue(int x)
{
    if(front == (rear+1)%size)
        cout<<"CircularQueue is Full"<<endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

int CircularQueue::dequeue()
{
    int x = -1;
    if(front == rear)
        cout<<"CircularQueue is Empty"<<endl;
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::display()
{
    int i = front + 1;
    do
    {
        cout<<Q[i]<<" ";
        i = (i+1)%size;
    }
    while(i!=(rear+1)%size);
    cout<<endl;
}

int main()
{
    CircularQueue q(5);
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