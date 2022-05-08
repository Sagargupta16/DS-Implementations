#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class linkedList{
    public:
        Node *head;
        linkedList()
        {
            head = NULL;
        }
        int listSize()
        {
            Node *p=head;
            int cnt = 0;
            while (p != NULL)
            {
                cnt++;
                p = p->next;
            }
            return cnt;
        } // O(n)

        void insertAtEnd(int d){
            struct Node *p = head;
            struct Node *a = new Node{d};
            if(p==NULL){
                head = a;
            }
            else{
                while(p->next!=NULL){
                    p=p->next;
                }
                p->next = a;
            }
        }//O(n) if we not keep tail;

        void insertAtStart(int d){
            struct Node *a = new Node{d};
            a->next = head;
            head = a;
        }//O(1);

        void insertAtIndex(int d,int index){
            struct Node *a = new Node{d};
            if(index==0){
                a->next=head;
                head=a;
                return;
            }
            struct Node *p = head;
            int cnt=1;
            while(cnt!=index-1){
                cnt++;
                if(p->next==NULL){
                    break;
                }
                p=p->next;
            }
            a->next = p->next;
            p->next = a;
            
        }//O(n)

        void insertInSorted(int d){
            struct Node *a = new Node{d};
            if (d<=head->data)
            {
                a->next = head;
                head = a;
                return;
            }
            struct Node *p = head;
            struct Node *q = head->next;
            while(q->data<d)
            {

                p = p->next;
                q = q->next;
                if (q == NULL)
                {
                    break;
                }
            }

            p->next = a;
            a->next = q;
        }//O(n)

        void deleteFirstNode(){
            struct Node *a = head;
            head=head->next; 
            delete a;
        }//O(1);

        void deleteAtindex(int n){
            struct Node *a = head;
            if(n==1){
                head = head->next;
                a->next = NULL;
                delete a;
                return;
            }
            struct Node *b = head->next;
            int cnt=1;
            while(cnt!=n-1){
                cnt++;
                a=a->next;
                b=b->next;
            }
            a->next=b->next;
            delete b;
        }//O(n)

        void displayList()
        {
            struct Node *p = head;
            while (p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        } // O(n)

        Node *reverseRecurse(Node *p)
        {
            Node *b;
            if (p == NULL)
            {
                return NULL;
            }
            if (p->next == NULL)
            {
                head=p;
                return p;
            }
            Node *a = reverseRecurse(p->next);
            a->next = p;
            p->next = NULL;
            return p;
        } // O(n);

        ~linkedList(){
            Node*p=head;
            while(head!=NULL){
                head=head->next;
                delete p;
                p=head;
            }
        }
};

void displayRecursive(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        displayRecursive(p->next);
    }
} // O(n)

void displayRecursiveReverse(Node *p)
{
    if (p != NULL)
    {
        displayRecursiveReverse(p->next);
        cout << p->data << " ";
    }
} // O(n)

int listSizeRec(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return listSizeRec(p->next) + 1;
    }
} // O(n)

int sumList(Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
} // O(n)

int maxList(Node *p)
{
    int max = p->data;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
} // O(n)

int minList(Node *p)
{
    int min = p->data;
    while (p != NULL)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
} // O(n)

Node *linearSearch( Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
} // O(n)
// Linked List can't have Binary Search
// Linear Search can be Improved by move to head;

bool isListSorted(Node *p)
{
    while (p->next != NULL)
    {
        if (p->data > p->next->data)
        {
            return false;
        }
        p = p->next;
    }
    return true;
} // O(n)

void removeDuplicateSortedList(Node *p)
{
    if(p==NULL){
        return;
    }
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
            continue;
        }
        q = q->next;
        p = p->next;
    }
} // O(n)

Node* reverseList(Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
} // O(n)

Node* concat(Node *p, Node *q)
{
    if(p==NULL){
        return q;
    }
    Node *a=p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    return a;

}

Node* merge(Node *p, Node *q)
{
    Node *r;
    Node *s;
    if(p->data<=q->data){
        r = p;
        s = p;
        p = p->next;
        s->next = NULL;
    }
    else{
        r = q;
        s = q;
        q = q->next;
        s->next=NULL;
    }
    while(p!=NULL && q!=NULL){
        if (p->data <= q->data)
        {
            s->next = p;
            p = p->next;
        }
        else
        {
            s->next = q;
            q = q->next;
        }
        s = s->next;
        s->next = NULL;
    }
    if(p==NULL){
        s->next=q;
    }
    else{
        s->next=p;
    }
    return r;
}//O(n+m)

bool isLoop(Node *p){
    if (p == NULL)
    {
        return 0;
    }
    Node* q=p->next;
    while(1){
        if(q==p){
            return true;
        }
        if(p==NULL || q==NULL ){
            return false;
        }
        if (q->next == NULL){
            return false;
        }
        p = p->next;
        q=q->next->next;
    }
}

int main(){
    linkedList l,m,n;
    int A[]={1,4,6,7,8,10,11};
    int a=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<a;i++){
        l.insertAtEnd(A[i]);
    }
    int B[] = {0,6,7,8,9,10};
    int b = sizeof(B) / sizeof(B[0]);
    for (int i = 0; i < b; i++)
    {
        m.insertAtEnd(B[i]);
    }
    n.head = merge(l.head, m.head);
    displayRecursive(n.head);
    cout<<endl;

    n.reverseRecurse(n.head);
    displayRecursive(n.head);
    cout<<endl;
    
    cout<<isLoop(l.head);
    return 0;
}