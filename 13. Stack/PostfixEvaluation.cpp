#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *top;
public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
}*st = NULL;

void Stack::push(int x)
{
    Node *t = new Node();
    if(t == NULL)
        cout<<"Stack oVerflow"<<endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    struct Node *t;
    int x = -1;
    if(top == NULL)
        cout<<"Stack Underflow"<<endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

bool isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    else
        return true;
}

int postfixEval(string postfix)
{
    st = new Stack();
    for(int i=0;postfix[i] != '\0';i++)
    {
        if(isOperand(postfix[i]))
            st->push(postfix[i]-'0');
        else
        {
            int x2 = st->pop();
            int x1 = st->pop();
            switch(postfix[i])
            {
                case '+' :  st->push(x1+x2);
                            break;
                case '-' :  st->push(x1-x2);
                            break;
                case '*' :  st->push(x1*x2);
                            break;
                case '/' :  st->push(x1/x2);
                            break;
            }
        }
    }
    return st->pop();
}

int main()
{
    string postfix = "35*62/+4-";
    cout<<"The Postfix Expression : "<<postfix<<endl;
    cout<<"The Evaluated Value : "<<postfixEval(postfix)<<endl;
    return 0;
}