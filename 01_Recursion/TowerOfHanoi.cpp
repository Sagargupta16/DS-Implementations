#include<iostream>
using namespace std;

void toh(int n,int a,int b,int c){
    if(n>0){
        toh(n-1,a,c,b);
        cout<<"From "<<a<<" to "<<c<<endl;
        toh(n-1,b,a,c);
    }
}
/* Time Complexity is 
T(n)=1+2*T(n-1)
T(n-1)=1+2*T(n-2).....

so T(n)=1+2*(1+2*(.........T(0)))= 1+2+4+8+....2^(n-1)
T(n) = 2^n-1 so O(2^n)

*/

int main(){
    int n;
    cin>>n;
    int a,b,c;
    a=1,b=2,c=3;
    toh(n,a,b,c);
    return 0;
}