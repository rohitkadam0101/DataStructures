// With the use of Class and adjacency list
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int V; // no of vertices
        list<int>*l; // pointer for adjacency list
        Graph(int V){
            this->V = V; 
            l = new list<int>[V]; // list of size of V or V lists;
        }
        void addEdge(int x,int y){
            l[x].push_back(y); // if there is an edge from x to y
            l[y].push_back(x);
        }
        void print(){
            for(int i=0;i<V;i++){
                cout<<i<<" -> ";
                for(int x:l[i]){
                    cout<<x<<"->";
                }
                cout<<endl;
            }
        }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.print();
    return 0;
}
