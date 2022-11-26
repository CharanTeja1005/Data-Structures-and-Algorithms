#include<iostream>
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

//   Insertion in Level Order

class Tree
{
private:
    Node *root;
public:
    Tree()
    {
        root = NULL;
    }
    void CreateTree();
    void Preorder()
    {
        Preorder(root);
    }
    void Preorder(Node *p);
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *p);
    void Postorder()
    {
        Postorder(root);
    }
    void Postorder(Node *p);
    void Levelorder()
    {
        Levelorder(root);
    }
    void Levelorder(Node *p);
    int Height()
    {
        return Height(root);
    }
    int Height(Node *root);
    void IPreorder()
    {
        IPreorder(root);
    }
    void IPreorder(Node *p);
    void IInorder()
    {
        IInorder(root);
    }
    void IInorder(Node *p);
    void IPostorder()
    {
        IPostorder(root);
    }
    void IPostorder(Node *p);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    cout<<"Enter the root value : ";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout<<"Enter left child value : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout<<"Enter right child value : ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p != NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree::Levelorder(Node *root)
{
    Queue q(100);
    cout<<root->data<<" ";
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    if(root == NULL)
        return 0;
    int x = Height(root->lchild);
    int y = Height(root->rchild);
    return (x>y) ? x+1 : y+1;
}

void Tree::IPreorder(Node *p)
{
    Stack st(100);
    while(p != NULL || !st.isEmpty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop()->rchild;
        }
    }
}

void Tree::IInorder(Node *p)
{
    Stack st(100);
    while(p != NULL || !st.isEmpty())
    {
        if(p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            p = st.pop();
            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}

void Tree::IPostorder(Node *p)
{
    Stack st(100);
    long int temp;
    while(p != NULL || !st.isEmpty())
    {
        if(p)
        {
            st.push(p);
            p = p->lchild;
        }
        else
        {
            temp = (long int)st.pop();
            if(temp > 0)
            {
                st.push(((Node *)(-temp)));
                p = ((Node *)temp)->rchild;
            }
            else
            {
                cout<<((Node *)(-temp))->data<<" ";
                p = NULL;
            }
        }
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    cout<<endl;
    cout<<"PreOrder Traversal : ";
    t.Preorder();
    cout<<endl;
    cout<<"Inorder Traversal : ";
    t.Inorder();
    cout<<endl;
    cout<<"Postorder Traversal : ";
    t.Postorder();
    cout<<endl;
    cout<<"Levelorder Traversal : ";
    t.Levelorder();
    cout<<endl;
    cout<<"The Height of Tree : "<<t.Height()<<endl;
    cout<<"Iterative Preorder Traversal : ";
    t.IPreorder();
    cout<<endl;
    cout<<"Iterative Inorder Traversal : ";
    t.IInorder();
    cout<<endl;
    cout<<"Iterative Postorder Traversal : ";
    t.IPostorder();
    cout<<endl;
    return 0;
}