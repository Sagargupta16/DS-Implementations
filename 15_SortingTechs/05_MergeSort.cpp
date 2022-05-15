#include <iostream>
using namespace std;

void Display(int A[], int n){
    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
} // O(n)

// IterativeMergeSort
void IMerger(int A[],int l,int m,int h){
    int B[h+1];
    int i=l,j=m+1,k=l;
    while(i<=m && j<=h){
        if(A[i]<A[j]){
            B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(;i<=m;i++){
        B[k++]=A[i];
    }
    for(;j<=h;j++){
        B[k++]=A[j];
    }
    for(i=l;i<=h;i++){
        A[i]=B[i];
    }
}

void IMergeSort(int A[],int n){
    int p,i,l,m,h;
    for(p=2;p<=n;p*=2){
        for(i=0;i+p-1<n;i+=p){
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            IMerger(A,l,m,h);
        }
    }
    if(p/2<n){
        IMerger(A,0,p/2-1,n-1);
    }
}

// Recursive Merger Sort

void RMergeSort(int A[],int l,int h){
    if(l<h){
        int m=(l+h)/2;
        RMergeSort(A,l,m);
        RMergeSort(A,m+1,h);
        IMerger(A,l,m,h);
    }
}

int main()
{
    int A[] = {5, 8, 1, 7, 3, 6, 2, 9, 10, 4};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Array Before Sort : ";
    Display(A, n);

    RMergeSort(A,0,n-1);

    cout << "Array After  Sort : ";
    Display(A, n);

    return 0;
}