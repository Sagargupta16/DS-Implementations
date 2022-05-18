#include<iostream>
#include<cmath>
using namespace std;
int prime(int n){
    if (n & 1)
        n -= 2;
    else
        n--;
 
    int i, j;
    for (i = n; i >= 2; i -= 2) {
        if (i % 2 == 0)
            continue;
        for (j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }
    return 2;
}
class DoubleHashing{
    private:
        int *A;
        int size;
        int p;
    public:
        DoubleHashing(int s){
            size = 2*s;
            A = new int[size];
            for(int i=0;i<size;i++){
                A[i]=0;
            }
            p=prime(size);//prime number less than s;
        }
        void insert(int d){
            int i=0;
            if(A[d%size]==0){
                A[d%size]=d;
                return;
            }
            while(A[(d+i*(p-(d%p)))%size]){
                i++;
                cout<<"c"<<endl;
            }
            A[(d+i*(p-(d%p)))%size]=d;
        }
        bool search(int d){
            int i=0;
            while(A[(d+i*(p-(d%p)))%size]){
                if(A[(d+i*(p-(d%p)))%size]==d){
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
    int A[] = {5,25,15,35,95,65,45};
    int n = sizeof(A)/sizeof(A[0]);
    DoubleHashing l(n);
    for(int i=0;i<n;i++){
        l.insert(A[i]);
    }
    l.display();
    cout<<endl;
    if(l.search(45)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found"<<endl;
    }
    return 0;
}