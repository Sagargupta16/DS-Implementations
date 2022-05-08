#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template<class T>
class LinkedList
{
private:
    Node<T> *head, *tail;

public:
    LinkedList()
    {
        tail = NULL;
        head = NULL;
    }
    void insertAtEnd(T d)
    {
        Node<T> *a = new Node<T>(d);
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
    T deleteAtStart()
    {
        Node<T> *a = head;
        T x = head->data;
        head = head->next;
        delete a;
        return x;
    } // O(1)
    void display()
    {
        Node<T> *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    } // O(n)
};

template<class T>
class Queue
{
private:
    int front, rear;
    LinkedList<T> l;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isempty(){
        if(rear==-1){
            return true;
        }
        return false;
    }
    void enqueue(T z)
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        l.insertAtEnd(z);
    } // O(1)
    T deque()
    {
        if (isempty())
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

template<class T>
class PriorityQueue{
    private :
        Queue<T> *A;
        int prio;
    public:
        PriorityQueue(int n){
            prio = n;
            A = new Queue<T>[prio]; 
        }
        void enqueueElement(T d,int p){
            A[p-1].enqueue(d);
        }
        T dequeueElement(){
            for(int i=0;i<prio;i++){
                if(!A[i].isempty()){
                    return A[i].deque();
                }
            }
            return -1;
        }
        void displayPrioritize(){
            for (int i = 0; i < prio; i++)
            {
                if (!A[i].isempty())
                {
                    A[i].Display();
                }
            }
        }

};



int main(){

    PriorityQueue<char> p(3);
    int c,x;
    char z;
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
            cout << "Enter Element you want to Insert and Priority : ";
            cin >> z >> x;
            p.enqueueElement(z,x);
            break;

        case 2:
            z = p.dequeueElement();
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
            p.displayPrioritize();
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