#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            data = d;
            next = NULL;
        }
};

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void binSort(int A[],int n){
    int max=A[0];
    for(int i=1;i<n;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    Node* B[max+1]={NULL};
    for(int i=0;i<n;i++){
        if(B[A[i]]==NULL){
            B[A[i]]=new Node(A[i]);
        }
        else{
            Node* z = B[A[i]];
            while(z->next!=NULL){
                z=z->next;
            }
            z->next = new Node(A[i]);
        }
    }
    int x=0;
    for(int i=0;i<max+1;i++){
        while(B[i]!=NULL){
            A[x]=B[i]->data;
            Node* m = B[i];
            B[i]=B[i]->next;
            delete B[i];
            x++;
        }
    }
}//O(n) but Space Complexity high.

int main(){
    int A[]={5,8,1,7,3,3,3,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    binSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}