#include<iostream>
using namespace std;

template<class T>
class Node {
    public:
        T data;
        Node *next;
        Node(T d){
            data = d;
            next = NULL;
        }
};

template<class T>
class QueueList{
    private:
        Node<T> **tails;
        Node<T> *head;
        
    public:
        QueueList(int n){
            head=NULL;
            *tails= new Node<T>[n];
            for(int i=0;i<n;i++){
                tails[i]=NULL;
            }
        }
        void insertElement(T d,int p){
            Node<T> *c = new Node<T>(d);
            if(head==NULL){
                head = c;
                tails[p-1] = c;
            }
            else{

            }

        }

};



int main(){
    
    return 0;
}