#include<iostream>
using namespace std;

class Node{
    public:
        Node *prev;
        int data;
        Node *next;
        Node(int d){
            data = d;
            prev=NULL;
            next=NULL;
        }
};

class DoubleLinkedList{
    private:
        Node *head,*tail;
        int length;
    public: 
        DoubleLinkedList(){
            head=NULL;
            tail=NULL;
            length = 0;
        }
        void insertAtHead(int d){
            Node *a = new Node(d);
            if(head==NULL){
                head=a;
                tail=a;
                return;
            }
            a->next=head;
            head->prev=a;
            head = a;
            length++;
        }//O(1)
        void insertAtEnd(int d){
            Node *a = new Node(d);
            if (head == NULL){
                head = a;
                tail = a;
                return;
            }
            tail->next = a;
            a->prev = tail;
            tail=tail->next;
            length++;
        }//O(1)
        void insertAtIndex(int d,int i){
            if(i<0 || i>length){
                cout<<"Index Out of Range ! "<<endl;
                return;
            }
            if (i == 0){
                insertAtHead(d);
                return;
            }
            if(i == length){
                insertAtEnd(d);
                return;
            }
            Node *a = new Node(d);
            Node *b = head;
            i--;
            while(i--){
                b=b->next;
            }
            a->next = b->next;
            a->prev = b;
            b->next = a;
            length++;
        }//O(n)

        void deleteAtStart(){
            if(length==0){
                cout<<"List is Empty! "<<endl;
                return;
            }
            Node * a = head;
            head=head->next;
            head->prev=NULL;
            delete a;
            length--;
        }//O(1)
        void deleteAtEnd(){
            if (length == 0){
                cout << "List is Empty! " << endl;
                return;
            }
            Node *a = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete a;
            length--;
        }//O(1)
        void deleteAtIndex(int i){
            if(i<0 || i>length){
                cout << "Index Out of Range ! " << endl;
                return;
            }
            if(i==0){
                deleteAtStart();
                return;
            }
            if(i==length){
                deleteAtEnd();
                return;
            }
            Node *b=head;
            while(i--){
                b=b->next;
            }
            b->prev->next=b->next;
            b->next->prev=b->prev;
            delete b;
            length--;
        }//O(n);

        void displayList(){
            Node *a = head;
            while(a!=NULL){
                cout<<a->data<<" ";
                a=a->next;
            }
            cout<<endl;
        }//O(n)

        void reverseDoubleLinkedList(){
            if(length==0 || length==1){
                return;
            }
            tail=head;
            Node * a = head;
            Node * b;
            while(a!=NULL){
                b = a;
                a = a->next;
                b->next = b->prev;
                b->prev = a;
            }
            head=b;
        }//O(n)
};

int main(){
    DoubleLinkedList dl;
    int A[]={10,11,12,13,14,15,16};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++){
        dl.insertAtEnd(A[i]);
    }
    int c, d, index;
    cout << endl << " Double Linked List Menu" << endl;
    cout << "1. Insert in Start " << endl;
    cout << "2. Insert at Index " << endl;
    cout << "3. Insert at End " << endl;
    cout << "4. Delete From Start " << endl;
    cout << "5. Delete at Index " << endl;
    cout << "6. Delete at End " << endl;
    cout << "7. Reverse a List " << endl;
    cout << "8. Display Linked List " << endl;
    cout << "9. Quit" << endl;
    do
    {
        cout << "Enter your Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            dl.insertAtHead(d);
            break;

        case 2:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            cout << "Enter Index at which you want to Insert : ";
            cin >> index;
            dl.insertAtIndex(d, index);
            break;

        case 3:
            cout << "Enter data You want to Insert : ";
            cin >> d;
            dl.insertAtEnd(d);
            break;

        case 4:
            dl.deleteAtStart();
            break;

        case 5:
            cout << "Enter Index at which you want to Delete Node : ";
            cin >> index;
            dl.deleteAtIndex(index);
            break;

        case 6:
            dl.deleteAtEnd();
            break;

        case 7:
            dl.reverseDoubleLinkedList();
            break;

        case 8:
            cout << "Elements are : ";
            dl.displayList();
            break;

        case 9:
            break;

        default:
            cout << "Enter Valid Choice!" << endl;
            break;
        }
    }while(c != 9);

    return 0;

}