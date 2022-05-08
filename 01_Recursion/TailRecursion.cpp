#include<iostream>
using namespace std;

void fun(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        fun(n-1);
    }
}


int main(){
    int x=3;
    fun(x);

    return 0;
}

// Perform First than Call
// Means result will be given in Calling Time 

//In Case of Tail Recursion Loop is more efficient. on basis of Space Complexity
//In this we will do action Whatever Function called first like for n than n-1 and son on.
