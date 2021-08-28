// Cycle detection in undirected graph using DSU (disjoint set union)
// We cannot find cycle for directed graph because union operation has no directionality

#include<iostream> 
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+6; // Very large number
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
    parent[v]  = v; // Make V distinct disjoints sets 
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;  // if value and parent is same it means that it is absolute root of tree/set
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b); // find abs root
    // if(x==y){
    //     return; // return if both have same root
    // }
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b); // union of sets based on size 
        }
        parent[b]  = a; // make smallest size set mark to largest size graph
        sz[a]+=sz[b];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges; // make only array of edges as we need only edges
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v}); // push  edges in 2D form
    }
    bool cycle = false;
    for(auto i:edges){
        int u = i[0]; 
        int v  = i[1];
        int x =  find_set(u); // find parent root node of u
        int y = find_set(v);  // find parent node of v
        if(x==y){
            cycle = true; // if both have same parent then there is cycle
        }
        else{
            union_set(u,v);
        } //make union of two sets it is an imp set to make unions of initally defined N disjoint set based on input edges
    }
    if(cycle){
            cout<<"Cycle is present";
        }
        else{
            cout<<"No cycle";
    }
    return 0;
}