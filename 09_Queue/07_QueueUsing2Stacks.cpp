#include <iostream>
using namespace std;
class Stack
{
private:
    int Top, size;
    int *ar;
 
public:
    void StackInitializer(int a)
    {
        Top = -1;
        size = a;
        ar = new int[size];
    }
    bool isempty()
    {
        if (Top == -1)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (Top == size - 1)
        {
            return true;
        }
        return false;
    }
    void push(int a)
    {
        if (isfull())
        {
            return;
        }
        Top++;
        ar[Top] = a;
    }
    int pop()
    {
        if (isempty())
        {
            return -1;
        }
        Top--;
        return ar[Top + 1];
    }
    ~Stack()
    {
        delete[] ar;
    }
};

class Queue
{
private:
    int front, rear, size, length;
    Stack s1, s2;

public:
    Queue(int x)
    {
        front = -1;
        rear = -1;
        length = 0;
        size = x;
        s1.StackInitializer(x);
        s2.StackInitializer(x);
    }
    bool isempty()
    {
        if (length == 0)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (length == size)
        {
            return true;
        }
        return false;
    }
    void enqueue(int z)
    {
        if (isfull())
        {
            cout << "QUEUE is FULL ! " << endl;
            return;
        }
        else if (isempty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        s1.push(z);
        length++;
    } // O(1) Constant time;
    int deque()
    {
        if (isempty())
        {
            return -1;
        }
        if (length == 1)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        while (!s1.isempty())
        {
            s2.push(s1.pop());
        }
        int z = s2.pop();
        while (!s2.isempty())
        {
            s1.push(s2.pop());
        }
        length--;
        return z;
    } // O(n) Linear time
    void Display()
    {
        if (isempty())
        {
            return;
        }
        while (!s1.isempty())
        {
            s2.push(s1.pop());
        }
        while (!s2.isempty())
        {
            int z = s2.pop();
            cout << z << " ";
            s1.push(z);
        }
        cout << endl;
    }//O(n)
};

int main()
{
    int n, c;
    cout << "Enter Max Size of QUEUE : ";
    cin >> n;
    Queue Q(n);
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
            int z;
            cin >> z;
            Q.enqueue(z);
            break;

        case 2:
            if (Q.isempty())
            {
                cout << "QUEUE is Empty! " << endl;
            }
            else
            {
                cout << "Dequeued Element is : " << Q.deque() << endl;
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