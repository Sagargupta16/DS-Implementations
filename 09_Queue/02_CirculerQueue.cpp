#include <iostream>
using namespace std;

class Queue
{
private:
    int *A;
    int front, rear, size, length;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        length = 0;
        size = 10;
        A = new int[size];
    }
    Queue(int x)
    {
        front = -1;
        rear = -1;
        length = 0;
        size = x;
        A = new int[size];
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
        A[rear] = z;
        length++;
    }//O(1)
    int dequeue()
    {
        if (isempty())
        {
            return -1;
        }
        int a = A[front];
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
        length--;
        return a;
    }//O(1)
    void Display()
    {
        if (isempty())
        {
            return;
        }
        for (int i = front; i!= rear; i++)
        {
            cout << A[i] << " ";
            if (i == size-1)
            {
                i = -1;
            }
        }
        cout << A[rear] << " ";
        cout << endl;
    }
    ~Queue()
    {
        delete[] A;
    }
};

int main()
{
    int n, c, z;
    cout << "Enter Max Size of QUEUE : ";
    cin >> n;
    Queue Q(n);
    cout << endl
         << "QUEUE MENU" << endl;
    cout << "1. Insert or Enque Element " << endl;
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
            if (Q.isfull())
            {
                cout << "Queue is FULL! " << endl;
            }
            else
            {
                cout << "Enter Element you want to Insert : ";
                cin >> z;
                Q.enqueue(z);
            }
            break;

        case 2:
            z = Q.dequeue();
            if (z == -1)
            {
                cout << "Queue is Empty ! " << endl;
            }
            else
            {
                cout << "Dequeued Element is : " << z << endl;
            }
            break;

        case 3:
            if (!Q.isempty())
            {
                cout << "Element In Queue Are : ";
                Q.Display();
            }
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