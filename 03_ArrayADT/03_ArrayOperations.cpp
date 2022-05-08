//Insert,Append,Delete,Linear search , Binary Search.


#include<iostream>
using namespace std;

struct Array
{
    int A[10];
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

void Append(struct Array *arr,int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}//O(1)

void Insert(struct Array *arr,int index,int x){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}//O(n)

void Delete(struct Array *arr,int index){
    if(index>=0 && index<=arr->length){
        for(int i=index;i<=arr->length;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->A[arr->length]=0;
        arr->length--;
    }
}//O(n)

void swap(int *x,int *y){
    int temp= *x;
    *x = *y;
    *y = temp;
}//O(1);


int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]==key){
            return i;
        }
    }
    return -1;
}//O(n)

// for Improving Linear Search we can use 2 methods.
// 1. transposition :-  in this we swap searched element to 1 prior element.
// int LinearSearchT(struct Array *arr,int key){
//     for(int i=0;i<arr->length;i++){
//         if(arr->A[i]==key){
//             if(i>0){
//                 swap(&arr->A[i],&arr->A[i-1]);
//             }
//             return i;
//         }
//     }
//     return -1;
// }
// 2. move to head. :- in this we swap searched element to 1st element.
// int LinearSearchH(struct Array *arr,int key){
//     for(int i=0;i<arr->length;i++){
//         if(arr->A[i]==key){
//             if(i>0){
//                 swap(&arr->A[i],&arr->A[0]);
//             }
//             return i;
//         }
//     }
//     return -1;
// }
// These are used mostly when returning bool yes or no.

int BinarySearch(struct Array arr,int key){
    int l = 0,h = arr.length-1,mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(arr.A[mid]==key){
            return mid;
        }
        if(arr.A[mid]>key){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
        
    }
    return -1;
}//O(log(n));

int main(){
    struct Array arr;
    
    arr={{1,2,3,4,5,6},10,6};//Initialized
    Display(arr);

    Append(&arr,10);
    Display(arr);

    Insert(&arr,6,8);
    Display(arr);

    Delete(&arr,2);
    Display(arr);
    
    cout<<endl<<"Searched Element is at index : "<<LinearSearch(arr,2)<<endl;

    // LinearSearchT(&arr,5);
    // Display(arr);

    // LinearSearchH(&arr,5);
    // Display(arr);

    cout<<endl<<"Searched Element is at index : "<<BinarySearch(arr,7)<<endl;


    return 0;
}