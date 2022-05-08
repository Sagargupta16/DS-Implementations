#include <iostream>
using namespace std;

template<class T>
class Queue
{
private:
    T *A;
    int front,rear,size;
public:
    Queue(){
        front = -1;
        rear = -1;
        size = 10;
        A = new T[size];
    }
    Queue(int x){
        front=-1;
        rear=-1;
        size = x;
        A = new T[size];
    }
    bool isempty(){
        if (front == -1 && rear == -1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int x){
        if (isfull()){
            cout << "QUEUE is FULL ! " << endl;
            return;
        }
        if (rear == -1){
            front++;
        }
        rear++;
        A[rear] = x;
    }
    T deque(){
        if (isempty()){
            return -1;
        }
        T x = A[front];
        if (front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
        return x;
    }
    void Display(){
        if (isempty()){
            return;
        }
        for (int i = front; i <= rear; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }
    ~Queue(){
        delete[] A;
    }
};

int main()
{
    int n,c,z;
    cout << "Enter Max Size of QUEUE : ";
    cin >> n;
    Queue<int> Q(n);
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
            z=Q.deque();
            if(z==-1){
                cout << "QUEUE is EMPTY ! " << endl;
            }
            else{
                cout<<"Dequeued Element is : "<<z<<endl;
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