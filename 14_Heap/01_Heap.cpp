#include<iostream>
using namespace std;
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
        }//O(Log(n))
        int Delete(int A[],int n){
            int i = 1,y,z;
            int x = A[1];
            A[1]=A[n];
            n--;
            while(i<n){
                if(A[i]<A[2*i] || A[i]<A[2*i+1]){
                    if(A[2*i]>A[2*i+1]){
                        y = A[i];
                        A[i] = A[2*i];
                        A[2*i] = y;
                        i = 2*i;
                    }
                    else{
                        y = A[i];
                        A[i] = A[2*i+1];
                        A[2*i+1] = y;
                        i = 2*i+1;
                    }
                }
                else{
                    break;
                }
            }
            return x;
        }//O(Log(n))
        void Display(int A[],int n){
            for(int i=1;i<=n;i++){
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    int A[10]={0,10,20,30,25,5,40,35,10,12};
    int n = 1;
    Heap h;

    for(n=1;n<8;n++){
        h.Insert(A,n);
        h.Display(A,n);
    }
    n--;

    cout<<h.Delete(A,n)<<endl;
    n--;
    h.Display(A,n);
    return 0;
}