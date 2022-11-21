#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

template <class T>
class Stack
{
public:
    Node *top;
    int size;
public:
    Stack()
    {
        top = NULL;
    }
    void push(char x);
    char pop();
};

template<class T>
void Stack<T>::push(char x)
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
char Stack<T>::pop()
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

bool isBalanced(char *exp)
{
    Stack<char> st;
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i] == '(')
            st.push(exp[i]);
        else if(exp[i] == ')')
        {
            if(st.top == NULL)
                return false;
            st.pop();
        }
    }
    return st.top==NULL ? true : false;
}

int main()
{
    char exp1[] = "((a+b)*(c+d))";
    char exp2[] = "((a+b)*(c+d)";
    if(isBalanced(exp1))
        cout<<"Expression is Balanced"<<endl;
    else
        cout<<"Expression is not Balanced"<<endl;
    if(isBalanced(exp2))
        cout<<"Expression is Balanced"<<endl;
    else
        cout<<"Expression is not Balanced"<<endl;
    return 0;
}