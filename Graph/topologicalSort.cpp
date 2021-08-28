#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Topological sort is only for DAG(directed acyclic graph)

int main(){
    int n,m,cnt=0;
    cin>>n>>m; //vertices,edges
    vector<int>adj[n]; // adjacency list
    vector<int>indeg(n,0);
    for(int i=0;i<m;i++){
        int u,v;  // u->v edge
        cin>>u>>v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i]==0){  // if indegree is zero it is leaf so we can push it into queue
            q.push(i);  // we are pushing the index not actual element
        }
    }
    while(!q.empty()){
        cnt++;
        int x  = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it:adj[x]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }

    }
}