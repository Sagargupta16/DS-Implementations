#include <iostream>
using namespace std;

template<class T>
class LLNode
{
public:
    T data;
    LLNode *next;
    LLNode(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class Queue
{
private:
    LLNode<T> *front,*rear;
public:
    Queue(){
        front=NULL;
        rear=NULL;
    }
    bool isempty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    void enqueue(T d){
        LLNode<T> *a = new LLNode<T>(d); 
        if (front == NULL){
            front=a;
            rear=a;
            return;
        }
        rear->next=a;
        rear=rear->next;
    }
    T dequeue(){
        T x = front->data;
        if(front==rear){
            delete front;
            front=NULL;
            rear=NULL;
        }
        else{
            LLNode<T> *a=front;
            front=front->next;
            delete a;
        }
        return x;
    }
};

class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int d){
        data=d;
        lchild=NULL;
        rchild=NULL;
    }
};

class BT{
public:
    Node *root;
    BT(){
        root=NULL;
    }
    void create(){
        Node *p,*t;
        int x;
        Queue<Node*> q;
        cout<<"Enter Root  Value : ";
        cin>>x;
        Node *a = new Node(x);
        root = a;
        q.enqueue(root);
        while(!q.isempty()){
            p=q.dequeue();
            cout<<"Enter Left  Child of "<<p->data<<" : ";
            cin>>x;
            if(x!=-1){
                Node *a=new Node(x);
                p->lchild=a;
                q.enqueue(a);
            }
            cout<<"Enter Right Child of "<<p->data<<" : ";
            cin>>x;
            if (x!=-1){
                Node *a = new Node(x);
                p->rchild = a;
                q.enqueue(a);
            }
        }
    }//O(n)
    void PreOrderDisplay(Node *x){
        if(x==NULL){
            return;
        }
        cout<<x->data<<" ";
        PreOrderDisplay(x->lchild);
        PreOrderDisplay(x->rchild);
    }//O(n)
    void InOrderDisplay(Node *x)
    {
        if (x==NULL){
            return;
        }
        InOrderDisplay(x->lchild);
        cout << x->data << " ";
        InOrderDisplay(x->rchild);
    }//O(n)
    void PostOrderDisplay(Node *x)
    {
        if (x == NULL){
            return;
        }
        PostOrderDisplay(x->lchild);
        PostOrderDisplay(x->rchild);
        cout << x->data << " ";
    }//O(n)
    void LevelOrderDisplay(Node *x)
    {
        if (x == NULL){
            return;
        }
        Queue<Node*> q;
        q.enqueue(x);
        
        while(!q.isempty()){
            Node *a = q.dequeue();
            cout<<a->data<<" ";
            if(a->lchild!=NULL){
                q.enqueue(a->lchild);
            }
            if(a->rchild!=NULL){
                q.enqueue(a->rchild);
            }
        }
    }//O(n)
    int height(Node* x){
        if(x==NULL){
            return 0;
        }
        int a=height(x->lchild);
        int b=height(x->rchild);
        if(a>b){
            return a+1;
        }
        else{
            return b+1;
        }
    }//O(n);
    int countNodes(Node* x){
        if(x==NULL){
            return 0;
        }
        int a = countNodes(x->lchild);
        int b = countNodes(x->rchild);
        return a+b+1;
    }//O(n)
    int countNodesdegree2(Node* x){
        if(x==NULL){
            return 0;
        }
        int a = countNodesdegree2(x->lchild);
        int b = countNodesdegree2(x->rchild);
        if(x->lchild!=NULL&&x->rchild!=NULL){
            return a+b+1;
        }
        else{
            return a+b;
        }
    }//O(n)
    //Leaf Node
    //degree 1
    int sumNodes(Node *x){
        if(x==NULL){
            return 0;
        }
        int a = sumNodes(x->lchild);
        int b = sumNodes(x->rchild);
        return a+b+x->data;
    }//O(n)
};

int main()
{
    BT b;
    b.create();
    cout<<"Pre-order   : ";
    b.PreOrderDisplay(b.root);
    cout<<endl;
    cout<<"In-order    : ";
    b.InOrderDisplay(b.root);
    cout<<endl;
    cout<<"Post-order  : ";
    b.PostOrderDisplay(b.root);
    cout<<endl;
    cout<<"Level-order : ";
    b.LevelOrderDisplay(b.root);
    cout<<endl;
    cout<<"Height : "<<b.height(b.root)<<endl;
    cout<<"count : "<<b.countNodes(b.root)<<endl;
    cout<<"count 2degree Nodes : "<<b.countNodesdegree2(b.root)<<endl;
    cout<<"Sum is  : "<<b.sumNodes(b.root)<<endl;
    
    return 0;
}