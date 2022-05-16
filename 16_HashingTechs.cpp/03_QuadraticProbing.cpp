#include<iostream>
using namespace std;

class QuadProbing{
    private:
        int *A;
        int size;
    public:
        QuadProbing(int s){
            size = 2*s;
            A = new int[size];
            for(int i=0;i<size;i++){
                A[i]=0;
            }
        }
        void insert(int d){
            int i=0;
            if(A[d%size]==0){
                A[d%size]=d;
                return;
            }
            while(A[(d+i*i)%size]){
                i++;
            }
            A[(d+i*i)%size]=d;
        }
        bool search(int d){
            int i=0;
            while(A[(d+i*i)%size]){
                if(A[(d+i*i)%size]==d){
                    return true;
                }
                i++;
            }
            return false;
        }
        void display(){
            for(int i=0;i<size;i++){
                cout<<A[i]<<" ";
            }
        }
};

int main(){
    int A[] = {63,583,291,350,482,3282,2954,2727,9574};
    int n = sizeof(A)/sizeof(A[0]);
    QuadProbing l(n);
    for(int i=0;i<n;i++){
        l.insert(A[i]);
    }
    l.display();
    cout<<endl;
    if(l.search(222)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }

    return 0;
}