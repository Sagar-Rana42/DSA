#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

class Graph {
    public:
    unordered_map<int, set<int>>adjList;

    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected graph 
        // direction = 1 -> directed graph 

        adjList[u].insert(v);
        if(direction == 0){
            // undirected edge 
            // create an edge from v to u
            adjList[v].insert(u);
        }
    }
    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"-> ";
            for(auto neighbour: node.second){
                cout<<neighbour<<" ";
            }cout<<endl;
        }
    }
    
};

int main(){
    // By Adjacency List 

    Graph g;
    //       (srcnode , destination ,  typeOfgraph)
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
    cout<<endl;
    g.printAdjacencyList();
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjacencyList();
    cout<<endl;

    



    // Adjaency Matrix  

    // int n;
    // cout<<"Enter the number of node: "<<endl;
    // cin>>n;

    // vector<vector<int>> adj(n,vector<int>(n,0));

    // int e;
    // cout<<" Enter the number of edges: "<<endl;
    // cin>>e;

    // for(int i=0;i<e;i++){
    //     int u ,v ;
    //     cin>>u>>v;
    //     //Marks  
    //     adj[u][v] = 1;

    // } 
    // // Printing 

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }cout<<endl;
    // }




    return 0;
}