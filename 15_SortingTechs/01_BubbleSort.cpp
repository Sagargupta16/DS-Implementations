#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void BubbleSort(int A[],int n){
    int f;
    for(int i=0;i<n-1;i++){
        f=0;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                int t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
                f=1;
            }
        }
        if(f==0) break;
    }
}//O(n^2)

int main(){
    int A[]={5,8,1,7,3,6,2,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    BubbleSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}