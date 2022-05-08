#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class CircularlinkedList
{
public:
    Node *head;
    CircularlinkedList()
    {
        head = NULL;
    }
    void insertAtIndex(int d, int index)
    {
        struct Node *a = new Node{d};
        struct Node *p = head;
        if(head==NULL){
            head=a;
            head->next=head;
            return;
        }
        if (index == 0)
        {
            while(p->next!=head){
                p = p->next;
            }
            p->next=a;
            a->next=head;
            return;
        }
        while (index!=1)
        {
            index--;
            p = p->next;
        }
        a->next = p->next;
        p->next = a;
    }//O(n)

    void deleteAtIndex(int index){
        struct Node* a = head;
        if(head==NULL){
            return;
        }
        if(head->next==head){
            head=NULL;
            delete a;
            return;
        }
        if(index==0){
            struct Node *c= head;
            while(a->next!=head){
                a=a->next;
            }
            head = head->next;
            a->next=head;
            delete c;
            return;
        }
        struct Node* b=head->next;
        while(index!=1)
        {
            index--;
            a = a->next;
            b = b->next;
        }
        a->next=b->next;
        delete b;
    }

    void display(){
        if(head==NULL){
            return;
        }
        struct Node *p=head;
        while(p->next!=head){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<p->data<<endl;
    }//O(n)

    
};

int main(){
    CircularlinkedList c;
    
    c.insertAtIndex(1,0);
    c.insertAtIndex(2,1);
    c.insertAtIndex(3,2);
    c.insertAtIndex(4,3);
    c.insertAtIndex(5,0);
    c.insertAtIndex(6,0);
    c.insertAtIndex(7,2);
    c.display();
    c.deleteAtIndex(4);
    c.display();
    return 0;
}