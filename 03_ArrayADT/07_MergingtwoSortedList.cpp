#include<iostream>
using namespace std;

struct Array
{
    int A[100];
    int size;
    int length;
};
// void append(){}
// void concat(){}
// void compare(){}
// void copy(){}
void Display(struct Array arr){
    cout<<endl<<"Elements are : ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}//O(n)

struct Array merge(struct Array a1,struct Array a2){
    struct Array a3={{},100,0};
    int i=0,j=0;
    while(a1.length+a2.length!=a3.length){
        if(a1.A[i]<=a2.A[j]||j==a2.length){
            a3.A[a3.length++]=a1.A[i];
            i++;
        }
        else{
            a3.A[a3.length++]=a2.A[j];
            j++;
        }
    }
    return a3;
}//Theta(m+n)

int main(){
    struct Array arr1,arr2,arr3;
    arr1={{2,4,6,8,10,12,14,17,19,21,23},100,11};
    arr2={{1,3,5,7,9,11,13,15,16,18},100,10};

    arr3=merge(arr1,arr2);
    Display(arr3);

    return 0;
}