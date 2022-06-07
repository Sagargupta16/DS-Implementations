#include<iostream>
#include<queue>
using namespace std;

class graph{
public:
    void addEdge(int a,int b,int A[],int n){
        A[a*n+b]=1;
        A[b*n+a]=1;
    }
    void printGraph(int A[],int n){
        for(int i=1;i<n;i++){
            cout<<i<<"-> ";
            for(int j=0;j<n;j++){
                if(A[i*n+j]==1){
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void BFS(int i,int A[],int n){
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
                if(A[u*n+j]==1 && B[j]==0){
                    cout<<j<<" ";
                    B[j]=1;
                    q.push(j);
                }
            }
        }
        cout<<endl;
    }//O(n^2);
    void DFS(int i,int B[],int A[],int n){
        if(B[i]==1){
            return;
        }
        cout<<i<<" ";
        B[i]=1;
        for(int j=0;j<n;j++){
            if(A[i*n+j]==1){
                DFS(j,B,A,n);
            }
        }
    }
    void dfst(int i,int A[],int n){
        int B[n]={0};
        DFS(i,B,A,n);
    }
};

int main(){
    int n=8;
    int A[n*n]={0};
    graph g;
    g.addEdge(1,2,A,n);
    g.addEdge(1,3,A,n);
    g.addEdge(1,4,A,n);
    g.addEdge(2,3,A,n);
    g.addEdge(3,4,A,n);
    g.addEdge(3,5,A,n);
    g.addEdge(4,5,A,n);
    g.addEdge(5,6,A,n);
    g.addEdge(5,7,A,n);
    g.addEdge(6,4,A,n);
    

    g.printGraph(A,n);

    g.BFS(5,A,n);

    g.dfst(5,A,n);cout<<endl;

    return 0;
}