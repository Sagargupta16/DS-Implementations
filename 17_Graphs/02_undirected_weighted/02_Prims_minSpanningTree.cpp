#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    void addEdge(int a,int b,int w,vector<vector<int>>& A,int n){
        A[a][b]=w;
        A[b][a]=w;
    }
    void printGraph(vector<vector<int>>& A,int n){
        for(int i=1;i<n;i++){
            cout<<i<<"-> ";
            for(int j=0;j<n;j++){
                if(A[i][j]!=INT_MAX){
                    cout<<j<<"("<<A[i][j]<<") ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

void prims(vector<vector<int>> &A,vector<vector<int>>& B,int n)
{
    int mini=INT_MAX,u,v,x;
    vector<int> near(n+1, INT_MAX);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(A[i][j]<mini){
                mini=A[i][j];
                u=i;
                v=j;
            }
        }
    }
    B[0][0]=u;
    B[0][1]=v;
    B[0][2]=mini;
    near[u]=0;
    near[v]=0;

    for(int i=1;i<=n;i++){
        if(near[i]!=0){
            if(A[i][u]<A[i][v]){
                near[i]=u;
            }
            else{
                near[i]=v;
            }
        }
    }

    for(int i=1;i<n-1;i++){
        mini = INT_MAX;
        for(int j=1;j<=n;j++){
            if(near[j]!=0 && A[j][near[j]]<mini){
                mini = A[j][near[j]];
                x=j;
            }
        }
        B[i][0]=near[x];
        B[i][1]=x;
        B[i][2]=mini;
        near[x]=0;
        for(int j=1;j<=n;j++){
            if(near[j]!=0 && A[j][x]<A[j][near[j]]){
                near[j]=x;
            }
        }
    }
}

int main(){
    int n=7;
    vector<vector<int>> A(n+1,vector<int>(n+1,INT_MAX));
    vector<vector<int>> B(n-1,vector<int>(3,0));
    
    graph g;
    g.addEdge(1,2,25,A,n+1);
    g.addEdge(1,6,5,A,n+1);
    g.addEdge(2,3,12,A,n+1);
    g.addEdge(2,7,10,A,n+1);
    g.addEdge(3,4,8,A,n+1);
    g.addEdge(4,5,16,A,n+1);
    g.addEdge(4,7,14,A,n+1);
    g.addEdge(5,6,20,A,n+1);
    g.addEdge(5,7,18,A,n+1);
    g.printGraph(A,n+1);


    prims(A,B,n);

    
    cout<<B[0][0];
    for(int i=0;i<n-1;i++){
        cout<<"->"<<B[i][1]<<"("<<B[i][2]<<")";
    }
    return 0;
}