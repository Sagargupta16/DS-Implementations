// Creating array in heap with ADT.


#include<iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};


void Display(struct Array arr){
    cout<<endl<<"Elements are : ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}//O(n)


int main(){

    struct Array arr;
    int n;
    cout<<"Enter Size of an array : " ;
    cin>>arr.size;
    arr.A= new int[arr.size];
    arr.length=0;

    cout<<"Enter Number of Numbers : ";
    cin>>n;

    cout<<"Enter All Elements :";
    for(int i=0;i<n;i++){
        cin>>arr.A[i];
    }
    arr.length=n;

    Display(arr);


    return 0;
}