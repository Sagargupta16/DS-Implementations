#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

class Heap{
    public:
        void Insert(int A[],int n){
            int i = n;
            int t = A[i];
            while(i>1 && t>A[i/2]){
                A[i] = A[i/2];
                i=i/2;
            }
            A[i]=t;
        }
        int Delete(int A[],int n){
            int i = 1,y,z;
            int x = A[i];
            A[i] = A[n];
            n--;
            while(i<=n){
                if(A[i*2]>A[i*2+1] && A[i]<A[i*2]){
                    A[i] = A[i*2];
                    A[i*2] = x;
                    i=i*2;
                }
                else if(A[i*2]<A[i*2+1] && A[i]<A[i*2+1]){
                    A[i] = A[i*2+1];
                    A[i*2+1] = x;
                    i=i*2+1;
                }
                else{
                    break;
                }
            }
            return x;
        }
        void Display(int A[],int n){
            for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int A[100];
    int n = 1;

    Heap h;
    A[n]=10;
    h.Insert(A,n);

    h.Display(A, n);

    n++;
    A[n] = 12;
    h.Insert(A, n);

    h.Display(A, n);

    n++;
    A[n] = 15;
    h.Insert(A, n);

    h.Display(A, n);

    n++;
    A[n] = 8;
    h.Insert(A, n);

    h.Display(A, n);

    n++;
    A[n] = 11;
    h.Insert(A, n);

    h.Display(A, n);

    n++;
    A[n] = 9;
    h.Insert(A, n);

    h.Display(A, n);

    n++;
    A[n] = 4;
    h.Insert(A, n);

    h.Display(A,n);

    cout<<h.Delete(A,n)<<endl;
    n--;
    h.Display(A,n);
    return 0;
}