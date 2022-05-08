#include<iostream>
using namespace std;

struct Array
{
    int A[20];
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

int get(struct Array arr,int index){
    if(index<arr.length && index>=0){
        return arr.A[index];
    }
    return -1;
}//O(1)

void set(struct Array *arr,int index,int x){
    if(index<arr->length && index>=0){
        arr->A[index]=x;
    }
}//O(1)

int max(struct Array arr){
    int m=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]>m){
            m=arr.A[i];
        }
    }
    return m;
}//O(n)
int min(struct Array arr){
    int m=arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i]<m){
            m=arr.A[i];
        }
    }
    return m;
}//O(n)
int sum(struct Array arr){
    int s=0;
    for(int i=0;i<arr.length;i++){
        s=s+arr.A[i];
    }
    return s;
}//O(n)

double avg(struct Array arr){
    return double(sum(arr))/(arr.length-1);
}//O(n) if included sum function O

int main(){
    struct Array arr;
    arr={{5,4,7,2,6,1,9,10,14,3,7,18,12,15,13},20,15};//Initialized

    cout<<"Element at given index is : "<<get(arr,10)<<endl;
    set(&arr,10,11);
    Display(arr);

    cout<<"Max Element in array is : "<<max(arr)<<endl;
    cout<<"Min Element in array is : "<<min(arr)<<endl;
    cout<<"Sum of Element in array is : "<<sum(arr)<<endl;
    cout<<"Average of Element in array is : "<<avg(arr)<<endl;

    return 0;
}