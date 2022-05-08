//taylor series by Horner s rule
#include<iostream>
using namespace std;

float abc(float x, float n){
    static float s=1;
    if(n==0){
        return s;
    }
    else{
        s=1+(x/n)*s;
        return abc(x,n-1);
    }
}

int main(){
    float x,n;
    cin>>x>>n;
    cout<<abc(x,n-1);
    return 0;
}