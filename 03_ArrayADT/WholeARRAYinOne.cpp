#include<iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x,int *y){
    int temp= *x;
    *x = *y;
    *y = temp;
}//O(1);

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

int LinearSearch(struct Array arr,int key){
    for(int i=0;i<arr.length;i++){
        if(arr.A[i]==key){
            return i;
        }
    }
    return -1;
}//O(n)

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

bool isSorted(struct Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return false;
        }
    }
    return true;
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
    struct Array arr1;
    int choice;
    cout<<"Enter Size of an array (Max Capacity of Array): ";
    cin>>arr1.size;
    arr1.A= new int[arr1.size];
    arr1.length=0;

    while(1){
        cout<<endl<<"---Main Menu---"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Operations"<<endl;
        cout<<"6. 2 Array operations"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;

        if(choice==1){
            while(1){
                int ch1,val1,index1,num1;
                cout<<endl<<"---Insert Menu---"<<endl;
                cout<<"1. Insert at End(Append)"<<endl;
                cout<<"2. Insert at Index"<<endl;
                cout<<"3. Insert in Sorted Array"<<endl;
                cout<<"4. Change Value at Index"<<endl;
                cout<<"5. Insert n Elements"<<endl;
                cout<<"6. Back to Main Menu"<<endl;
                cout<<"Enter Your Choice : ";
                cin>>ch1;

                if(ch1==1){
                    cout<<"Enter Element You want to append : ";
                    cin>>val1;
                    Append(&arr1,val1);
                }
                else if(ch1==2){
                    cout<<"Enter Element You want to insert : ";
                    cin>>val1;
                    cout<<"Enter Index at that you want to insert : ";
                    cin>>index1;
                    Insert(&arr1,index1,val1);
                }
                else if(ch1==3){
                    cout<<"Enter Element You want to append : ";
                    cin>>val1;
                    insertInSortedArray(&arr1,val1);
                }
                else if(ch1==4){
                    cout<<"Enter Element You want to Set : ";
                    cin>>val1;
                    cout<<"Enter Index at that you want to Set : ";
                    cin>>index1;
                    Insert(&arr1,index1,val1);
                }
                else if(ch1==5){
                    cout<<"Enter Number of Elements You want to insert : ";
                    cin>>num1;
                    for(int i=0;i<num1;i++){
                        cin>>val1;
                        Append(&arr1,val1);
                    }
                }
                else if(ch1==6){
                    break;
                }
                else{
                    cout<<endl<<"Enter Valid Choice!"<<endl;
                }
            }
        }
        else if(choice==2){
            while(1){
                int ch2,index2;
                cout<<endl<<"---Insert Menu---"<<endl;
                cout<<"1. Delete at Index"<<endl;
                cout<<"2. Delete all values in Array"<<endl;
                cout<<"3. Back to Main Menu"<<endl;
                cout<<"Enter Your Choice : ";
                cin>>ch2;

                if(ch2==1){
                    cout<<"Enter Index at that you want to Delete : ";
                    cin>>index2;
                    Delete(&arr1,index2);
                }
                else if(ch2==2){
                    arr1.length=0;
                    cout<<"Array All Elements deleted";
                }
                else if(ch2==3){
                    break;
                }
                else{
                    cout<<endl<<"Enter Valid Choice!"<<endl;
                }
            }
        }
        else if(choice==3){
            while(1){
                int ch3,key,index3;
                cout<<endl<<"---Search Menu---"<<endl;
                cout<<"1. Binary Search (If Sorted Array)"<<endl;
                cout<<"2. Linear Search (If Unsorted Array)"<<endl;
                cout<<"3. Back to Main Menu"<<endl;
                cout<<"Enter Your Choice : ";
                cin>>ch3;

                if(ch3==1){
                    cout<<"Enter Key You want to search in an array :";
                    cin>>key;
                    int z=BinarySearch(arr1,key);
                    if(z==-1){
                        cout<<"Entered Key Not available in Array "<<endl;
                    }
                    else{
                        cout<<"Key available at Index : "<<z<<endl;
                    }
                }
                else if(ch3==2){
                    cout<<"Enter Key You want to search in an array :";
                    cin>>key;
                    int z=LinearSearch(arr1,key);
                    if(z==-1){
                        cout<<"Entered Key Not available in Array "<<endl;
                    }
                    else{
                        cout<<"Key available at Index : "<<z<<endl;
                    }
                }
                else if(ch3==3){
                    break;
                }
                else{
                    cout<<endl<<"Enter Valid Choice!"<<endl;
                }
            }
        }
        else if(choice==4){
            while(1){
                int ch4,index4;
                cout<<endl<<"---Display Menu---"<<endl;
                cout<<"1. Display Maximum Element in Array"<<endl;
                cout<<"2. Display Minimum Element in Array"<<endl;
                cout<<"3. Display Sum of Elements of Array"<<endl;
                cout<<"4. Display Average of Elements of Array"<<endl;
                cout<<"5. Display Element at Given Index"<<endl;
                cout<<"6. Display Whole Array"<<endl;
                cout<<"7. Back to Main Menu"<<endl;
                cout<<"Enter Your Choice : ";
                cin>>ch4;

                if(ch4==1){
                    cout<<"Max Element in Array is :"<<max(arr1);
                }
                else if(ch4==2){
                    cout<<"Min Element in Array is :"<<max(arr1);
                }
                else if(ch4==3){
                    cout<<"Sum of Elements in Array is :"<<sum(arr1);
                }
                else if(ch4==2){
                    cout<<"Average of Elements in Array is :"<<avg(arr1);
                }
                else if(ch4==5){
                    cout<<"Enter Index You want to see in an array :";
                    cin>>index3;
                    int z=get(arr1,index3);
                    if(z==-1){
                        cout<<"Entered Index is not a part of Array "<<endl;
                    }
                    else{
                        cout<<"Element available at Given Index is : "<<z<<endl;
                    }
                }
                else if(ch4==6){
                    Display(arr1);
                }
                else if(ch4==7){
                    break;
                }
                else{
                    cout<<endl<<"Enter Valid Choice!"<<endl;
                }
            }
        }
        else if(choice==5){
            while(1){
                int ch5;
                cout<<endl<<"---Operations Menu---"<<endl;
                cout<<"1. Reverse a Array"<<endl;
                cout<<"2. Left Rotation Array"<<endl;
                cout<<"3. Right Rotation Array"<<endl;
                cout<<"4. Left Shift Array"<<endl;
                cout<<"5. Right Shift Array"<<endl;
                cout<<"6. Negative numbers Left side in Array"<<endl;
                cout<<"7. Back to Main Menu"<<endl;
                cout<<"Enter Your Choice : ";
                cin>>ch5;

                if(ch5==1){
                    reverse(&arr1);
                    cout<<"Array Reversed"<<endl;
                }
                else if(ch5==2){
                    leftRotation(&arr1);
                    cout<<"Array Left Rotated"<<endl;
                }
                else if(ch5==3){
                    rightRotation(&arr1);
                    cout<<"Array Right Rotated"<<endl;
                }
                else if(ch5==4){
                    leftShift(&arr1);
                    cout<<"Array Left Shifted"<<endl;
                }
                else if(ch4==5){
                    rightShift(&arr1);
                    cout<<"Array Right Shifted"<<endl;
                }
                else if(ch4==6){
                    negativeLeftSide(&arr1);
                    cout<<"-Ve Left Side arranged in Array"<<endl;
                }
                else if(ch4==7){
                    break;
                }
                else{
                    cout<<endl<<"Enter Valid Choice!"<<endl;
                }
            }
        }
        else if(choice==6){

        }
        else if(choice==7){
            break;
        }
        else{
            cout<<"Enter Valid Choice!"<<endl;
        }
    }
    return 0;
}