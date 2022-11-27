#include<iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node(int key)
    {
        data = key;
        lchild = rchild = NULL;
    }
};

class BST
{
private:
    Node *root;
public:
    BST()
    {
        root = NULL;
    }
    void Insert(int key);
    void RInsert(int key)
    {
        root = RInsert(root,key);
    }
    Node* RInsert(Node *p,int key);
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *p);
    void Preorder()
    {
        Preorder(root);
    }
    void Preorder(Node *p);
    void Postorder()
    {
        Postorder(root);
    }
    void Postorder(Node *p);
    bool Search(int key);
    void Delete(int key)
    {
        root = Delete(root,key);
    }
    Node* Delete(Node *p,int key);
};

void BST::Insert(int key)
{
    Node *t = root,*p,*r;
    if(root == NULL)
    {
        p = new Node(key);
        root = p;
        return;
    }
    while(t)
    {
        r = t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
        {
            cout<<"Value already in BST"<<endl;
            return;
        }
    }
    p = new Node(key);
    if(key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

Node* BST::RInsert(Node *p,int key)
{
    if(p == NULL)
    {
        Node *t = new Node(key);
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild,key);
    return p;
}

void BST::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void BST::Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void BST::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

bool BST::Search(int key)
{
    Node *t = root;
    while(t)
    {
        if(key == t->data)
            return true;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

int Height(Node *p)
{
    if(p == NULL)
        return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return x>y ? x+1 : y+1;
}

Node* InorderPredecessor(Node *p)
{
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

Node* InorderSuccessor(Node *p)
{
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

Node* BST::Delete(Node *p,int key)
{
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            Node *q = InorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else
        {
            Node *q = InorderSuccessor(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    BST bst;
    bst.Insert(30);
    bst.Insert(15);
    bst.Insert(50);
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.RInsert(5);
    bst.RInsert(18);
    bst.RInsert(25);
    bst.RInsert(35);
    bst.RInsert(45);
    bst.RInsert(55);
    bst.RInsert(60);
    cout<<"Inorder Traversal : ";
    bst.Inorder();
    cout<<endl;
    bst.Delete(25);
    bst.Delete(10);
    bst.Delete(30);
    bst.Delete(50);
    cout<<"Inorder Traversal : ";
    bst.Inorder();
    cout<<endl;
    bst.Search(40) ? cout<<"Element found in BST"<<endl : cout<<"Element not found in BST"<<endl;
    bst.Search(100) ? cout<<"Element found in BST"<<endl : cout<<"Element not found in BST"<<endl;
    return 0;
}