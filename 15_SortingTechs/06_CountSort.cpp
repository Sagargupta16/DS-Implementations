#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

void countSort(int A[],int n){
    int max=A[0];
    for(int i=1;i<n;i++){
        if(max<A[i]){
            max=A[i];
        }
    }
    int B[max+1]={0};
    for(int i=0;i<n;i++){
        B[A[i]]++;
    }
    int z=0,x=0;
    while(x!=max+1){
        if(B[x]!=0){
            A[z]=x;
            z++;
            B[x]--;
        }
        else{
            x++;
        }
    }
}//O(n) but Space Complexity high.

int main(){
    int A[]={5,8,1,7,3,6,2,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    countSort(A,n);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}