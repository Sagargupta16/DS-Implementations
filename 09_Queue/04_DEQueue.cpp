#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedList
{
private:
    struct Node *head, *tail;

public:
    LinkedList()
    {
        tail = NULL;
        head = NULL;
    }
    void insertAtHead(int d){
        Node *a = new Node(d);
        if (head == NULL)
        {
            tail = a;
            head = a;
        }
        else
        {
            a->next=head;
            head=a;
        }
    }//O(1)
    void insertAtEnd(int d)
    {
        Node *a = new Node(d);
        if (head == NULL)
        {
            tail = a;
            head = a;
        }
        else
        {
            tail->next = a;
            tail = tail->next;
        }
    } // O(1)
    int deleteAtStart()
    {
        Node *a = head;
        int x = head->data;
        head = head->next;
        delete a;
        return x;
    } // O(1)
    int deleteAtEnd(){
        Node *a=head;
        int x = tail->data;
        if(head==tail){
            delete head;
            head=NULL;
            tail==NULL;
        }
        else{
            while(a->next!=tail){
                a=a->next;
            }
            a->next=NULL;
            delete tail;
            tail=a;
        }
        return x;
    } // O(n)
    void display()
    {
        Node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    } // O(n)
};

class Queue
{
private:
    int front, rear;
    LinkedList l;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enqueueAtEnd(int z)
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        l.insertAtEnd(z);
    } // O(1)
    void enqueueAtHead(int z)
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        l.insertAtHead(z);
    } // O(1)
    int dequeAtHead()
    {
        if (rear == -1)
        {
            return -1;
        }
        if (rear == front)
        {
            front == -1;
        }
        rear--;
        return l.deleteAtStart();
    } // O(1)
    int dequeAtEnd()
    {
        if (rear == -1)
        {
            return -1;
        }
        if (rear == front)
        {
            front == -1;
        }
        rear--;
        return l.deleteAtEnd();
    } // O(1)
    void Display()
    {
        if (front != -1)
        {
            l.display();
        }
    }
};

int main()
{
    int c, z;
    Queue Q;
    cout << endl
         << "QUEUE MENU" << endl;
    cout << "1. Insert or Enqueue Element In Front " << endl;
    cout << "2. Insert or Enqueue Element In End " << endl;
    cout << "3. Deque Element In Front " << endl;
    cout << "4. Deque Element In End " << endl;
    cout << "5. Display " << endl;
    cout << "6. Quit " << endl;
    do
    {
        cout << "Enter Your Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter Element you want to Insert : ";
            cin >> z;
            Q.enqueueAtHead(z);
            break;

        case 2:
            cout << "Enter Element you want to Insert : ";
            cin >> z;
            Q.enqueueAtEnd(z);
            break;

        case 3:
            z = Q.dequeAtHead();
            if (z == -1)
            {
                cout << "Queue is Empty ! " << endl;
            }
            else
            {
                cout << "Dequeued ELement is : " << z << endl;
            }
            break;

        case 4:
            z = Q.dequeAtEnd();
            if (z == -1)
            {
                cout << "Queue is Empty ! " << endl;
            }
            else
            {
                cout << "Dequeued ELement is : " << z << endl;
            }
            break;

        case 5:
            Q.Display();
            break;

        case 6:
            break;

        default:
            cout << "Enter Valid Choice !" << endl;
            break;
        }
    } while (c != 6);

    return 0;
}
