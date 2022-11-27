#include<iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    int height;
    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
    }
};

class AVLT
{
private:
    Node *root;
public:
    AVLT()
    {
        root = NULL;
    }
    void Insert(int key)
    {
        root = Insert(root,key);
    }
    Node* Insert(Node *p,int key);
    void Inorder()
    {
        Inorder(root);
    }
    void Inorder(Node *p);
    int SubTreeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node* LLRotation(Node *p);
    Node* LRRotation(Node *p);
    Node* RRRotation(Node *p);
    Node* RLRotation(Node *p);
};

void AVLT::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int AVLT::SubTreeHeight(Node *p)
{
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl>hr ? hl+1 : hr+1;
}

int AVLT::BalanceFactor(Node *p)
{
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

Node* AVLT::LLRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = SubTreeHeight(p);
    pl->height = SubTreeHeight(pl);
    if(root == p)
        root = pl;
    return pl;
}

Node* AVLT::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = SubTreeHeight(p);
    pl->height = SubTreeHeight(pl);
    if(root == p)
        root = plr;
    return plr;
}

Node* AVLT::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    pr->lchild = p;
    p->rchild = prl;
    p->height = SubTreeHeight(p);
    pr->height = SubTreeHeight(pr);
    if(root == p)
        root = pr;
    return pr;
}

Node* AVLT::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;
    p->height = SubTreeHeight(p);
    pr->height = SubTreeHeight(pr);
    if(root == p)
        root = prl;
    return prl;
}

Node* AVLT::Insert(Node *p,int key)
{
    if(p == NULL)
    {
        Node *t = new Node(key);
        t->height = 1;
        return t;
    }
    if(key < p->data)
        p->lchild = Insert(p->lchild,key);
    else if(key > p->data)
        p->rchild = Insert(p->rchild,key);
    p->height = SubTreeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)  //LL Rotation
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == -1)    //LR Rotation
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)   //RR Rotation
        return RRRotation(p);
    else if(BalanceFactor(p) == -1 && BalanceFactor(p->lchild) == -1)   //RL Rotation
        return RLRotation(p);
    return p;
}

int main()
{
    AVLT avlt;
    // avlt.Insert(50);
    // avlt.Insert(40);
    // avlt.Insert(30);
    // avlt.Insert(20);
    // avlt.Insert(10);
    avlt.Insert(10);
    avlt.Insert(20);
    avlt.Insert(30);
    avlt.Insert(25);
    avlt.Insert(28);
    avlt.Insert(27);
    avlt.Insert(5);
    cout<<"Inorder Traversal of AVL Tree : ";
    avlt.Inorder();
    cout<<endl;
    return 0;
}