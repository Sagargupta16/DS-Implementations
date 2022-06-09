#include<bits/stdc++.h>
using namespace std;

void join(vector<int>& set,int u, int v){
    if (set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }
    else{
        set[v] += set[u];
        set[u] = v;
    }
}

int find(vector<int>& set,int u){
    int x=u,v=0;
    while (set[x] > 0){
        x = set[x];
    }
    while (u != x){
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

int main()
{
    int n=7,mini=INT_MAX,k=0,u=0,v=0;
    vector<vector<int>> edges = {{1,2,25},{1,6,5},{2,3,12},
                                 {2,7,10},{3,4,8},{4,5,16},
                                 {4,7,14},{5,6,20},{5,7,18}};
    int ne = edges.size();

    vector<int> included(ne,0);
    vector<int> Set(n+1,-1);
    vector<vector<int>> B(n-1,vector<int>(3,0));

    for(int i=0;i<n-1;i++){
        mini=INT_MAX;
        for(int j=0;j<ne;j++){
            if(!included[j] && edges[j][2]<mini){
                mini = edges[j][2];
                u=edges[j][0];
                v=edges[j][1];
                k=j;
            }
        }
        int x = find(Set,u);
        int y = find(Set,v);
        if(x!=y){
            B[i][0]=u;
            B[i][1]=v;
            B[i][2]=mini;
            join(Set,x,y);

            included[k] = 1;
            continue;
        }
        included[k] = 1;
        i--;
    }

    for(int i=0;i<n;i++){
        cout<<B[i][0]<<"->"<<B[i][1]<<"("<<B[i][2]<<")"<<endl;
    }

    return 0;
}