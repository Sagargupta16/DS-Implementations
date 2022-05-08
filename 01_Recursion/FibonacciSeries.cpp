#include<iostream>
using namespace std;

void fibo(int n){
    static int i=0,j=1,k=0;
    int x;
    k++;
    if(i==0 && j==1){
        cout<<i<<" ";
    }
    if(k==n){
        return;
    }
    else{
        cout<<j<<" ";
        x = j;
        j = j+i;
        i = x;
        fibo(n);
    }

}//  Time Comp. => O(n)

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-2)+fib(n-1);
}//nth term // O(2^n)



int main(){
    int n;
    cin>>n;
    cout<<fib(n-1);
    return 0;
}