#include<iostream>
using namespace std;

class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(int a){
            n=a;
            A=new int[n];
        }
        void Set(int i,int j, int x){
            if(i==j){
                A[i-1]=x;
            }
        }
        int get(int i,int j){
            if(i==j){
                return A[i];
            }
            else{
                return 0;
            }
        }
        void display(){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        cout<<A[i]<<" ";
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }
        ~Diagonal(){
            delete []A;
        }
};

int main(){
    int n;
    cout<<"Enter Dimensions : ";
    cin>>n;

    Diagonal d(n);

    int x;
    cout<<"Enter All Elements : ";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>x;
            d.Set(i,j,x);
        }
    }

    d.display();
    return 0;
}