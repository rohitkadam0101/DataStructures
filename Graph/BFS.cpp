// Breadth first Search is done by Queue
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
bool visited[N];
vector<int> adj[N]; // adjacency list

int main(){
    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    int n,m;  //n=>vertices m=>edges
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    q.push(2); // for BFS we will pass starting vertex in this example we passed starting vertex as 1
    visited[2] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout<<curr<<endl;
        vector<int>::iterator it;
        for(it = adj[curr].begin();it!=adj[curr].end();++it){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    return 0;
}

