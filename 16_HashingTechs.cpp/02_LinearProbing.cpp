#include<iostream>
using namespace std;

class LinearProbing{
    private:
        int *A;
        int size;
    public:
        LinearProbing(int s){
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
            while(A[(d+i)%size]){
                i++;
            }
            A[(d+i)%size]=d;
        }
        bool search(int d){
            int i=0;
            while(A[(d+i)%size]){
                if(A[(d+i)%size]==d){
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
    int A[] = {66, 67, 268, 69, 70, 71, 72, 73, 74, 75, 76, 77, 578, 79, 80, 181, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 949};
    int n = sizeof(A)/sizeof(A[0]);
    LinearProbing l(n);
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