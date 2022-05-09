#include<iostream>
using namespace std;

void heapify(int A[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && A[l]>A[largest]){
        largest=l;
    }
    if(r<n && A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i) {
        swap(A[i],A[largest]);
        heapify(A,n,largest);
    }
}
void heapSort(int A[], int n){
    for (int i=n/2-1;i>=0;i--){
        heapify(A, n, i);
    }
    for (int i=n-1;i>=0;i--) {
        swap(A[0],A[i]);
        heapify(A,i,0);
    }
}

void Display(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[] = {5,8,11,4,9,2,1,54,7};
    int n = sizeof(A)/sizeof(A[0]);
    Display(A,n);
    heapSort(A,n);//O(nLog(n))
    Display(A,n);

    return 0;
}