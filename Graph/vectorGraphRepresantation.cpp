#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int x, int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "
             << v << "\n head ";
        for (auto x : adj[v])
           cout << "-> " << x;
        printf("\n");
    }
}


int main(){
    int V;
    cin>>V;
    vector<int>adj[V]; //V=> size of vertices list of vertices
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