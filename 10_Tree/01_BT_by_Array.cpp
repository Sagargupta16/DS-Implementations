#include<iostream>
#include<math>
using namespace std;

class BT_Array{
    private:
        char *A;
    public:
        BT_Array(int a){
            A = new char[pow(2,a)-1];
            A = {0};
        }
        void insert(char a){
            
        }


};

int main(){
    int h;
    cout<<"Enter Height of Tree : ";
    cin>>h;
    BT_Array b(h);
    return 0;
}