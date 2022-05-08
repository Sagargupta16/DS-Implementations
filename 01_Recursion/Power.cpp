#include<iostream>
using namespace std;

int pow(int n,int m){
    if(m==0){
        return 1;
    }
    else{
        return n*pow(n,m-1);
    }
}//Less faster Version

int pow1(int n,int m){
    if(m==0){
        return 1;
    }
    else if(m%2==0){
        return pow1(n*n,m/2);
    }
    else{
        return n*pow1(n*n,(m-1)/2);
    }
}//Faster Version 

int main(){
    int n,m;
    cin>>n>>m;
    cout<<pow(n,m)<<endl;

    cout<<pow1(n,m)<<endl;
    
    return 0;
}