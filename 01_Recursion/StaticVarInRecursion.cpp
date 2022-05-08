#include<iostream>
using namespace std;

int fun(int n){
    static int x = 0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main(){
    int a=5;
    cout<<fun(a);
    return 0;
}

/* Whatever x remained at last function call it will remain that only 
as x copy is only 1 */
// Static and Global for both same.