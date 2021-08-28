// Done with function stack
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool visited[N];
vector<int>adj[N];

void dfs(int x){
    visited[x] = true;
    cout<<x<<" "; // for preorder
    vector<int>::iterator it;
    for(it=adj[x].begin();it!=adj[x].end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }
    // for post order print x here
    
    
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    dfs(2);
    return 0;
}

