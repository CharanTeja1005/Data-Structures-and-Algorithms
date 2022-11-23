#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
    char data;
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
    void push(char x);
    char pop();
}*st = NULL;

void Stack::push(char x)
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

char Stack::pop()
{
    struct Node *t;
    char x = -1;
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

int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}

char* InToPost(char *infix)
{
    char *postfix = new char[strlen(infix) + 2];
    int i = 0,j = 0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i]) > pre(st->top->data))
                st->push(infix[i++]);
            else
                postfix[j++] = st->pop();
        }
    }
    while(st->top->data != '#')
    {
        postfix[j++] = st->pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    st = new Stack();
    char *infix = (char *)"a-b*c-d/e";
    st->push('#');
    char *postfix = InToPost(infix);
    cout<<"The Postfix Expression : "<<postfix<<endl;
    return 0;
}