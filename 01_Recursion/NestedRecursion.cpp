#include<iostream>
using namespace std;

int fun(int n){
    if(n==0){
        return 0;
    }
    else{
        cout<<"else : "<<n<<endl;
        return fun(fun(n-1));
    }
}

int main(){
    fun(5);
    return 0;
}




/* Time Complexity
T(0) = 0 ;
T(n) =1+T(T(n-1))  

T(n-1)=1+T(T(n-2))...
at some point..
T(n)=1+T(1+T(1+T(1+T(.......1+T(0)))))

T(0)=0,T(1)=1+T(T(0))=1+T(0)=1
T(2)=1+T(T(1))=1+T(1)=1+1=2

so, T(n)=n means O(n);

*/