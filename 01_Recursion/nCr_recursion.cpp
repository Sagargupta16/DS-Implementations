#include<iostream>
using namespace std;

double ncr(double n , double r){
    if(n==r){
        return 1.00;
    }
    double x = n/(n-r);
    return x*ncr(n-1,r);
}// O(n)

int main(){
    double n,r;
    cin>>n>>r;
    cout<<ncr(n,r);
    return 0;
}