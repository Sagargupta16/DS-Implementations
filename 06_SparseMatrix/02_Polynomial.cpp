#include<iostream>
#include<math.h>
using namespace std;

class Ply{
    private:
        int n;
        int *coeff;
        int *exp;
    public:
        Ply(int x){
            n=x;
            coeff =  new int[n];
            exp =  new int[n];
        }
        void setdata(){
            for(int i=0;i<n;i++){
                cout<<"Enter coff and pow of first term: ";
                cin>>coeff[i]>>exp[i];
            }
        }
        void display(){
            for (int i = 0; i < n; i++)
            {
                cout<<"("<<coeff[i]<<"x^"<<exp[i]<<")";
                if(i!=n-1){
                    cout<<"+";
                }
            }
            cout<<endl;
        }
        int evaluate(int x){
            int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+(coeff[i]*(pow(x,exp[i])));
            }
            return sum;
        }
};

void add(Ply *p1,Ply *p2){
    
}

int main(){
    int n;
    cout<<"Enter number of Non zero terms : ";
    cin>>n;

    Ply p(n);

    p.setdata();

    p.display();

    cout<<p.evaluate(2);
    
    return 0;
}