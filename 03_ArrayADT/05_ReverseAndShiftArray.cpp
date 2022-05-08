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

void reverse(struct Array *arr){
    for(int i=0;i<arr->length/2;i++)
    {
        swap(arr->A[i],arr->A[arr->length-1-i]);
    }
}//O(n)

void leftShift(struct Array *arr){
    for(int i=1;i<arr->length;i++){
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]=0;
}//O(n)
void leftRotation(struct Array *arr){
    int x=arr->A[0];
    for(int i=1;i<arr->length;i++){
        arr->A[i-1]=arr->A[i];
    }
    arr->A[arr->length-1]=x;
}//O(n)

void rightShift(struct Array *arr){
    for(int i=arr->length-1;i>0;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=0;
}//O(n)
void rightRotation(struct Array *arr){
    int x=arr->A[arr->length-1];
    for(int i=arr->length-1;i>0;i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=x;
}//O(n)

int main(){
    struct Array arr;
    arr={{5,4,7,2,6,1,9,10,14,3,7,18,12,15},20,14};//Initialized
    
    Display(arr);
    reverse(&arr);
    Display(arr);

    leftShift(&arr);
    Display(arr);
    leftRotation(&arr);
    Display(arr);

    rightShift(&arr);
    Display(arr);
    rightRotation(&arr);
    Display(arr);

    return 0;
}