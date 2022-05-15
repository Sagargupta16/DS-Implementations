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

void RadixSort(int A[],int n){
    int max=A[0];
    for(int i=1;i<n;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    int p=0;//Passses
    while(max!=0){
        max=max/10;
        p++;
    }
    Node* B[10];
    int x=1;
    while(p--){
        for(int i=0;i<9;i++){
            B[i]=NULL;
        }
        for(int i=0;i<n;i++){
            if(B[(A[i]/x)%10]==NULL){
                B[(A[i]/x)%10]=new Node(A[i]);
            }
            else{
                Node* z = B[(A[i]/x)%10];
                while(z->next!=NULL){
                    z=z->next;
                }
                z->next = new Node(A[i]);
            }
        }
        x=x*10;
        int y=0;
        for(int i=0;i<10;i++){
            while(B[i]!=NULL){
                A[y]=B[i]->data;
                Node* m = B[i];
                B[i]=B[i]->next;
                delete B[i];
                y++;
            }
        }
    }
}//O(n) even Space Complexity small

int main(){
    int A[]={237,146,678,1994,235,193,673,642,123,235};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    RadixSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}