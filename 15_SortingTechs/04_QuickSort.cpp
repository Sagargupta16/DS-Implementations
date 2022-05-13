#include<iostream>
using namespace std;

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}//O(n)

int partition(int A[],int l,int h){
    int p = A[l];
    int i=l+1,j=h;
    while(i<=j){
        while(A[i]<p){
            i++;
            if(i>j) break;
        }
        while(A[j]>p){
            j--;
            if(i>j) break;
        }
        if(i>j) break;
        swap(A[i],A[j]);
        i++;
        j--;
    }
    swap(A[l],A[j]);
    return j;
}

void QuickSort(int A[],int l,int h){
    if(l<h){
        int j = partition(A,l,h);
        QuickSort(A,l,j-1);
        QuickSort(A,j+1,h);
    }
}//O(nLog(n))

int main(){
    int A[]={5,8,1,7,3,6,2,9,10,4};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Array Before Sort : ";
    Display(A,n);

    QuickSort(A,0,n-1);

    cout<<"Array After  Sort : ";
    Display(A,n);

    return 0;
}