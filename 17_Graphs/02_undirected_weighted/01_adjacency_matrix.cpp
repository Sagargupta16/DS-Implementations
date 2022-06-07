#include<iostream>
#include<vector>
#include<queue>
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
                if(A[i][j]!=0){
                    cout<<j<<"("<<A[i][j]<<") ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void BFS(int i,vector<vector<int>>& A,int n){
        queue<int> q;
        int B[n]={0};
        int u;
        cout<<i<<" ";
        B[i]=1;
        q.push(i);
        while(!q.empty()){
            u = q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(A[u][j]!=0 && B[j]==0){
                    cout<<j<<" ";
                    B[j]=1;
                    q.push(j);
                }
            }
        }
        cout<<endl;
    }//O(n^2);
    void DFS(int i,int B[],vector<vector<int>>& A,int n){
        if(B[i]==1){
            return;
        }
        cout<<i<<" ";
        B[i]=1;
        for(int j=0;j<n;j++){
            if(A[i][j]!=0){
                DFS(j,B,A,n);
            }
        }
    }
};

int main(){
    int n=8;
    vector<int> a(n,0);
    vector<vector<int>> A(n,a);
    graph g;
    g.addEdge(1,2,6,A,n);
    g.addEdge(1,3,3,A,n);
    g.addEdge(1,4,4,A,n);
    g.addEdge(2,3,9,A,n);
    g.addEdge(3,4,12,A,n);
    g.addEdge(3,5,15,A,n);
    g.addEdge(4,5,76,A,n);
    g.addEdge(5,6,1,A,n);
    g.addEdge(5,7,6,A,n);

    g.printGraph(A,n);

    g.BFS(5,A,n);

    int B[n]={0};
    g.DFS(5,B,A,n);cout<<endl;

    return 0;
}