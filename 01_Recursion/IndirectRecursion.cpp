#include<iostream>
using namespace std;

void funB(int n);

void funA(int n){
    if(n>0){
        cout<<n<<endl;
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
        cout<<n<<endl;
        funA(n/2);
    }
}


int main(){
    funA(20);
    return 0;
}

// various Function calling each other in Cyclic order

/* Time Complexity

here T1(n) = 1+T2(n-1)
T2(n-1) = 1 + T1((n-1)/2) .....

so, T1(n) =  1 + ( 1 + (1+ T12(1 or 0) )

so it will be kind of T(n)= n - k so, O(n)
*/

