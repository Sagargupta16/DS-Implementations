#include<iostream>
using namespace std;
struct Array
{
    int A[100];
    int size;
    int length;
};
struct Array duplicates(struct Array a){
    struct Array b={{},100,0};
    static int l=0;
    for(int i=0;i<a.length-1;i++){
        if(a.A[i]==a.A[i+1]&&a.A[i]!=l){
            l=a.A[i];
            b.A[b.length]=a.A[i];
            b.length++;
            i++;
        }
    }
    return b;
}//O(n)
void Display(struct Array arr){
    cout<<endl<<"Elements are : ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}//O(n)

int main(){
    struct Array arr,ar1;
    
    arr={{1,2,3,3,4,4,4,4,8,8,9},100,11};

    ar1 = duplicates(arr);
    
    Display(ar1);

    return 0;
}