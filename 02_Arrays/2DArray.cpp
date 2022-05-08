#include<iostream>
using namespace std;
int main(){

    //1st method; static
    int A[3][4]={{10,20,30,40},{50,60,70,80},{90,10,11,12}};
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //2nd method; 1st part static and another dynamic
    int *B[3];
    B[0]=new int[4];
    B[1]=new int[4];
    B[2]=new int[4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            B[i][j]=A[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //3rd Method dynamic or double pointer method
    int **C;
    C = new int*[3];
    C[0]=new int[4];
    C[1]=new int[4];
    C[2]=new int[4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            C[i][j]=A[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    // All Can be called as 2d static arrays like A[x][y] , B[x][y] , C[x][y]

    return 0;
}