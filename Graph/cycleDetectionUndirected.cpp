// Cycle detection in undirected graph
// keep on traversing the graph if you found an already visited node expect an parent node then there is an cycle
#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
// not using vector<int>a[] because we cannot pass it as reference as array of references is illegal in c++
bool isCycle(int src,vector<vector<int>> &adj,vector<bool>&visited,int parent){
    visited[src] = true;
    for(auto i:adj[src]){
        if(i!=parent){
            if(visited[i]){
                return true; // if it is not parent and it is visited means there is an cycle
            }
            if(!visited[i] && isCycle(i,adj,visited,src)){  // parent will be src for adj[i]
                return true;
            }
        }
    }
    return false;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<bool>visited(n,0);
    for(int i=0;i<m;i++){
        int u,v; // undirected
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCycle(i,adj,visited,-1)){
                cycle = true;
            }
        }
    }
    if(cycle){
        cout<<"Cycle is present";
    }
    else{
        cout<<"No Cycle";
    }
    return 0;

    
}