#include<iostream>
using namespace std;

struct Array
{
    int A[100];
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

bool LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]==key){
            return false;
        }
    }
    return true;
}//O(n)

struct Array unsortedUnion(struct Array a1,struct Array a2){
    struct Array x={{},100,0};
    for(int i=0;i<a1.length;i++){
        x.A[x.length++]=a1.A[i];
    }
    for(int i=0;i<a2.length;i++){
        if(LinearSearch(x,a2.A[i])){
            x.A[x.length++]=a2.A[i];
        }
    }
    return x;
}//O(n^2) including search time

struct Array sortedUnion(struct Array a1,struct Array a2){
    struct Array a3={{},100,0};
    int i=0,j=0;
    while(a1.length+a2.length!=i+j){
        if((a1.A[i]<a2.A[j]||j==a2.length)&& i!=a1.length){
            a3.A[a3.length++]=a1.A[i];
            i++;
        }
        else if((a1.A[i]>a2.A[j]||i==a1.length)&& j!=a2.length){
            a3.A[a3.length++]=a2.A[j];
            j++;
        }
        else{
            i++;
        }
    }
    return a3;
}//ThetaO(n);

struct Array unsortedInterSection(struct Array a1,struct Array a2){
    struct Array x={{},100,0};
    for(int i=0;i<a1.length;i++){
        for(int j=0;j<a2.length;j++){
            if(a1.A[i]==a2.A[j]){
                x.A[x.length++]=a1.A[i];
            }
        }
    }
    return x;
}//O(n^2);

struct Array sortedInterSection(struct Array a1,struct Array a2){
    struct Array a3={{},100,0};
    int i=0,j=0;
    while(a1.length+a2.length!=i+j){
        if(i==a1.length || j==a2.length){
            break;
        }
        if(a1.A[i]<a2.A[j]){
            i++;
        }
        else if(a1.A[i]>a2.A[j]){
            j++;
        }
        else{
            a3.A[a3.length++]=a1.A[i];
            i++;
            j++;
        }
    }
    return a3;
}//Theta(n)

struct Array unsortedDifference(struct Array a1,struct Array a2){
    struct Array a3={{},100,0};
    for(int i=0;i<a1.length;i++){
        for(int j=0;j<a2.length;j++){
            if(a1.A[i]==a2.A[j]){
                break;
            }
            if(j==a2.length-1){
                a3.A[a3.length++]=a1.A[i];
            }
        }
    }
    return a3;
}//O(n^2)
struct Array sortedDifference(struct Array a1,struct Array a2){
    struct Array a3={{},100,0};
    int i=0,j=0;
    while(a1.length!=i){
        if(j==a2.length){
            a3.A[a3.length++]=a1.A[i];
            i++;
        }
        else if(a1.A[i]==a2.A[j]){
            i++;
            j++;
        }
        else{
            if(a1.A[i]>a2.A[j]){
                j++;
            }
            else{
                a3.A[a3.length++]=a1.A[i];
                i++;
            }
        }
    }
    return a3;
}//Theta(n)


int main(){
    struct Array arr1,arr2,arr3,arr4,arr5;

    //Unsorted Part
    arr1={{2,3,6,8,10,12,14,17,19,21},100,10};
    arr2={{1,3,5,8,10,12,13,17,16,19,20},100,11};
    arr3=unsortedUnion(arr1,arr2);
    Display(arr3);
    arr3=unsortedInterSection(arr1,arr2);
    Display(arr3);
    arr3=unsortedDifference(arr1,arr2);
    Display(arr3);

    //Sorted Part
    arr4={{1,3,5,7,9,11,12,14},100,8};
    arr5={{2,4,5,7,10,12,13,14,15,16},100,10};
    arr3=sortedUnion(arr4,arr5);
    Display(arr3);
    arr3=sortedInterSection(arr4,arr5);
    Display(arr3);
    arr3=sortedDifference(arr4,arr5);
    Display(arr3);

    return 0;
}