#include<iostream>
using namespace std;

void fun(int n){
    if(n>0){
        cout<<n<<endl;
        fun(n-1);
        fun(n-1);
    }
}


int main(){
    
    fun(3);
    return 0;
}

//If a Function Calling itself Multiple Time it is Called Tree Recursion.

/* Time Complexity 
T(n)=T(n-1)+T(n-1)+1
T(n-1)=T(n-2)+T(n-2)+1 .......

so, T(n)= 1 + 2*(1+2*(.....(1+2*(T(0)))))
so it will be like :-  2^0 + 2^1 + 2^2.......+2^(n-1)+ (2^n * T(0))   T(0)=1
so , this is  = 2^(n+1) - 1   means Order of or O(2^n) 
This Order is only for this problem other Tree problem may have different complexity.

Space Complexity is O(n) as if Seen on Tracing by creating Tree it take max n+1 storage in Stack.
 
*/
