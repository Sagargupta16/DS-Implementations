#include<iostream>
using namespace std;

float fact(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
float pow(int n,int m){
    if(m==0){
        return 1;
    }
    else if(m%2==0){
        return pow(n*n,m/2);
    }
    else{
        return n*pow(n*n,(m-1)/2);
    }
}
float ts(int x,int n){
    if(n==1){
        return 1;
    }
    else{
        return pow(x,n-1)/fact(n-1) + ts(x,n-1);
    }
}


float e(int x,int n){

    static float p=1,f=1;
    float r;
    if(n==0){
        return 1;
    }
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }

}//Alternative without 3 functions



int main(){
    int x,n;
    cin>>x>>n;
    cout<<ts(x,n)<<endl;
    cout<<e(x,n-1)<<endl;
    return 0;
}

/* Time Complexity for 1st method
T(n)=1+ T1(n-1)+T2(n-1)+T(n-1)
T1(n-1)=1+T1(n-2) :- T1(n-1) =  1 + 1 + .....  + n-1 times :-  n-1
T2(n-1)=1+T2((n-1)/2) :- T2(n-1) = 1 + 1 + ....  this will be log(n-1)
so ..  T(n) = 1 + n-1 + log(n-1) ....
T(n) = 1+2+3.....n-1  log(0)+log(1)...log(n-1) + n
so T(n) = n^2 + nlogn-n + n
so T(n) = n^2 ==> O(n^2)

Time Complexity for 2nd method
T(n)=1+T(n-1) ===> T(n)= n ===> O(n);