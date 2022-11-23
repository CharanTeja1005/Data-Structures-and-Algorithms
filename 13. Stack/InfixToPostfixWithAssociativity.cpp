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
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'))
        return true;
    else
        return false;
}

int outStackPrecedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 3;
    else if(x == '^')
        return 6;
    else if(x == '(')
        return 7;
    else
        return 0;
}

int inStackPrecedence(char x)
{
    if(x == '+' || x == '-')
        return 2;
    else if(x == '*' || x == '/')
        return 4;
    else if(x == '^')
        return 5;
    else if(x == '(')
        return 0;
    return -1;
}

string InfixToPostfix(char *infix)
{
    string postfix = new char[strlen(infix) + 2];
    int i = 0,j = 0;
    while(infix[i] != '\0')
    {
        char c = infix[i];
        if(isOperand(c))
            postfix += infix[i++];
        else
        {
            if(outStackPrecedence(c) > inStackPrecedence(st->top->data))
            {
                if(infix[i] == '(' || infix[i] == ')')
                    i++;
                else
                    st->push(infix[i++]);
            }
            else
            {
                if(infix[i] == '(' || infix[i] == ')')
                    i++;
                else
                    postfix += st->pop();
            }
        }
    }
    while(st->top->data != '#')
    {
        if(infix[i] == '(' || infix[i] == ')')
            st->pop();
        else
            postfix += st->pop();
    }
    return postfix;
}

int main()
{
    st = new Stack();
    char *infix = (char *)"((a+b)+c)-d^e^f";
    cout<<"The Infix Expression : "<<infix<<endl;
    st->push('#');
    string postfix = InfixToPostfix(infix);
    cout<<"The Postfix Expression : "<<postfix<<endl;
    return 0;
}