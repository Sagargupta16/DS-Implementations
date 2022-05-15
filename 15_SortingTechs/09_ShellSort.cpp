#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void shellSort(int A[],int n){
    int gap,i,j;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            int t = A[i];
            j = i-gap;
            while(j>=0 && A[j]>t){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=t;
        }
    }
}//O(nLog(n))

int main(){
    int A[]={5,8,1,7,13,16,2,9,10,4,3,6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    shellSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}