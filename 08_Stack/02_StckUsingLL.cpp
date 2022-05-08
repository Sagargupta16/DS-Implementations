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

template <class T>
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertAtStart(T d)
    {
        Node *a = new Node(d);
        a->next = head;
        head = a;
    } // O(1)
    T deleteAtStart()
    {
        Node *a = head;
        T x = head->data;
        head = head->next;
        delete a;
        return x;
    } // O(1)
};

template <class T>
class Stack
{
private:
    int Top;
    LinkedList<T> l;

public:
    Stack()
    {
        Top = -1;
    }
    bool isempty()
    {
        if (Top == -1)
        {
            return true;
        }
        return false;
    }
    void push(int a)
    {
        l.insertAtStart(a);
        Top++;
    } // O(1) Constant time
    T pop()
    {
        if (Top == -1)
        {
            return -1;
        }
        Top--;
        return l.deleteAtStart();
    } // O(1) Constant time
    void display()
    {
        T a;
        if (Top == -1)
        {
            return;
        }
        a = pop();
        cout << a << endl;
        display();
        push(a);
    } // O(n)
};

int main()
{
    int c, x;
    Stack<int> s;

    cout << endl
         << "Stack Menu" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Quit" << endl;
    do
    {
        cout << endl
             << "Enter your choice : ";
        cin >> c;

        switch (c)
        {
        case 1:
            cout << "Enter Element you want to push : ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            x = s.pop();
            if (x == -1)
            {
                cout << "Stack is Empty ! " << endl;
            }
            else
            {
                cout << "Popped Element is : " << x << endl;
            }
            break;

        case 3:
            cout << "Elements in Stack are" << endl;
            s.display();
            break;

        case 4:
            break;

        default:
            cout << "Enter Valid Choice ! " << endl;
            break;
        }
    } while (c != 4);
    return 0;
}