#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void QuickSort(int A[],int n){
    
}//O(n*Log(n))

int main(){
    int A[]={5,8,1,7,3,6,2,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    QuickSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}