#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void insertionSort(int A[],int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int x = A[i];
        while(j>=0 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}//O(n^2)


int main(){
    int A[]={5,8,1,7,3,6,2,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    insertionSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}