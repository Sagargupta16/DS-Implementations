#include<iostream>
using namespace std;

void fun(int n)
{
    if(n>0)
    {
        fun(n-1);
        cout<<n<<" ";
    }
}


int main(){
    int x=3;
    fun(x);

    return 0;
}

// value or result are returned at return type
// Converting HeadRecursion in loop is litter harder than TailRecursion.
// Here We See Whatever Function is called Last means f(0) than f(1) and  so on.