#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
    int Top,size;
    T *ar;
public:
    Stack(){
        Top = -1;
        size = 10;
        ar = new T[size];
    }
    Stack(int d){
        Top=-1;
        size=d;
        ar = new T[size]; 
    }
    bool isempty(){
        if(Top==-1){
            return true;
        }
        return false;
    }
    bool isfull(){
        if(Top==size-1){
            return true;
        }
        return false;
    }
    void push(T a){
        if (isfull()){
            cout << "Stack is Full " << endl;
            return;
        }
        Top++;
        ar[Top] = a;
    }
    T pop(){
        if (isempty()){
            return -1;
        }
        else{
            Top--;
            return ar[Top + 1];
        }
    }
    void display(){
        int a;
        if (isempty()){
            return;
        }
        a = pop();
        cout << a << endl;
        display();
        push(a);
    }
};

int main(){
    int c,x,n;
    cout<<"Enter Max Size of Stack : ";
    cin>>n;
    Stack<int> s(n);

    cout << endl
         << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Display" << endl;
    cout << "4. Quit" << endl;

    do
    {
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter Element you want to push : ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            x=s.pop();
            if(x==-1){
                cout << "Stack is Empty !" << endl;
            }
            else{
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
    } while (c!=4);
    return 0;
}