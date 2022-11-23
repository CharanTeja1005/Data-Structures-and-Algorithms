#include<bits/stdc++.h>
using namespace std;

int precedence(char x)
{
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    return 0;
}

string InfixToPostfix(string infix)
{
    stack<char> st;
    string postfix;
    for(int i=0;i<infix.length();i++)
    {
        char c = infix[i];
        if((c >= 'a' && c <= 'x') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix += c;
        else if(c == '(')
            st.push(c);
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(infix[i]) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<"The Infix Expression : "<<infix<<endl;
    string postfix = InfixToPostfix(infix);
    cout<<"The Postfix Expresion : "<<postfix<<endl;
    return 0;
}