// Make 2D matrix if there is an edge A[i][j] = 1 else A[i][j] = 0

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printGraph(vector<vector<int>>adj,int V){
    cout<<"Adjacency Matrix: "<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void addEdge(vector<vector<int>>&adj, int x,int y){
    adj[x][y] = 1;
    adj[y][x] = 1;
}
int main(){
    int V;
    cin>>V;
    vector<vector<int>>adj(V,vector<int>(V,0)); // V*V matrix initialized as zero
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}