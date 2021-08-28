// Kruskal algorithm is used to find Minimum spanning tree of the graph
// sort by weight and then detect cycle or not using DSU

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);


void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int a){
    if(a==parent[a]){
        return a;
    }
    return parent[a]  = find_set(parent[a]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b] =a;
        sz[a]+=sz[b];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back({w,x,y}); // taking weights x->y as input
    }
    sort(edges.begin(),edges.end()); //Sort based on weights(taken first as input)
    int final_weight = 0;
    for(auto i: edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x==y){
            continue; // cycle is detected so skip this edge
        }
        else{
            cout<<v<<" "<<w<<endl;
            final_weight+=w;
            union_set(u,v);
        }
    }
    cout<<final_weight<<endl;

}