#include<iostream>
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
    Stack(){
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

bool isParenthesisBalanced(string s){
    Stack<char> a;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            a.push(s[i]);
        }
        else if (s[i]==')'){
            char z = a.pop();
            if(z!='('){
                return false;
            }
        }
    }
    if(a.isempty()){
        return true;
    }
    return false;
}

int main(){
    string s;
    cout<<"Enter Expression : ";
    getline(cin,s);

    if(isParenthesisBalanced(s)){
        cout<<"Yes Given Expression is Balanced ! "<<endl;
    }
    else{
        cout<<"No Given Expression is Not Balanced ! "<<endl;
    }
    return 0;
}