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
    void enqueue(int z)
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        l.insertAtEnd(z);
    } // O(1)
    int deque()
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
    cout << "1. Insert or Enqueue Element " << endl;
    cout << "2. Deque Element " << endl;
    cout << "3. Display " << endl;
    cout << "4. Quit " << endl;
    do
    {
        cout << "Enter Your Choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter Element you want to Insert : ";
            cin >> z;
            Q.enqueue(z);
            break;

        case 2:
            z = Q.deque();
            if (z == -1)
            {
                cout << "Queue is Empty ! " << endl;
            }
            else
            {
                cout << "Dequeued ELement is : " << z << endl;
            }
            break;

        case 3:
            Q.Display();
            break;

        case 4:
            break;

        default:
            cout << "Enter Valid Choice !" << endl;
            break;
        }
    } while (c != 4);

    return 0;
}
