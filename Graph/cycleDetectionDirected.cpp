// Cycle detection in directed graph is done with the help of stack instead of tracking parent
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isCycle(int src, vector<vector<int>>&adj,vector<bool>&visited,vector<int> stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i:adj[src]){
            if(!visited[i] && isCycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }

    }
    stack[src] = false;
    return false; // no cycle
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<bool>visited(n,0);
    for(int i=0;i<m;i++){
        int u,v; // Directed  u->v
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle = false;
    vector<int> stack(n,0); // to fill indices of elements
    for(int i=0;i<n;i++){
        if(!visited[i] && isCycle(i,adj,visited,stack)){
            cycle = true;
        }
    }
    if(cycle){
        cout<<"Cycle is Present";
    }
    else{
        cout<<"Cycle is not present";
    }

}