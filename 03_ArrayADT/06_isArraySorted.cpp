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

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}//O(1)

void insertInSortedArray(struct Array *arr,int value){
    if(arr->length==arr->size){
        return;
    }
    arr->A[arr->length++]=value;//appended in end;
    for(int i=arr->length-1;i>0;i--){
        if(arr->A[i]<=arr->A[i-1]){
            swap(arr->A[i],arr->A[i-1]);
        }
        else{
            break;
        }
    }
}//O(n);

int isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}//O(n)

void negativeLeftSide(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j-1){
        while(arr->A[i]<0){
            i++;
            if(i==arr->length){
                break;
            }
        }
        while(arr->A[j]>=0){
            j--;
            if(j==0){
                break;
            }
        }
        swap(arr->A[i],arr->A[j]);
    }
}//O(n)

int main(){
    struct Array arr;
    arr={{1,2,3,4,5,6,7,8,9,11,12,13,14},20,13};//Initialized

    Display(arr);
    insertSortedArray(&arr,10);
    Display(arr);

    cout<<"Is Array Sorted (1=true and 0=false) : "<<isSorted(arr)<<endl;

    struct Array arr2;
    arr2={{-6,3,-8,10,5,-7,-9,12,-4,2},20,10};//Initialized

    negativeLeftSide(&arr2);
    Display(arr2);


    return 0;
}