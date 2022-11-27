#include<iostream>
#include "Stack.h"
using namespace std;

Node* createPre(int pre[],int n)
{
    Stack st(100);
    Node *t,*p;
    int i = 0;
    Node *root = new Node(pre[i++]);
    p = root;
    while(i < n)
    {
        if(pre[i] < p->data)
        {
            t = new Node(pre[i++]);
            p->lchild = t;
            st.push(p);
            p = t;
        }
        else
        {
            if(pre[i] > p->data && pre[i] < st.stackTop()->data)
            {
                t = new Node(pre[i++]);
                p->rchild = t;
                p = t;
            }
            else
            {
                p = st.pop();
            }
        }
    }
    return root;
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int main()
{
    int pre[] = {30,20,10,15,25,40,50,45};
    Node *bst = createPre(pre,sizeof(pre)/sizeof(int));
    cout<<"The Inorder Traversal of BST : ";
    Inorder(bst);
    cout<<endl;
    return 0;
}