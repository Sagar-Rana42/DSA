#include<iostream>
#include<vector>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;
template<typename T>

class Graph {
    public:
    unordered_map<T, list<T>>adjList;

    void addEdge(T u, T v, bool direction){
        // direction = 0 -> undirected graph 
        // direction = 1 -> directed graph 

        adjList[u].push_back(v);
        if(direction == 0){
            // undirected edge 
            // create an edge from v to u
            adjList[v].push_back(u);
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
    void dfs(T src ,unordered_map<int,bool>&visited2 ){
        cout<<src<<",";
        visited2[src] = true;
        for(auto neighbour : adjList[src]){
            if(!visited2[neighbour]){
                dfs(neighbour,visited2);
            }
        }
        
    }
    
};

int main(){
    // By Adjacency List 

    Graph<int> g;
    //       (srcnode , destination  , typeOfgraph)
    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,6,0);
    // g.addEdge(7,4,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    cout<<endl;
    g.printAdjacencyList();

    cout<<"Printing DFS Traversl "<<endl;
    unordered_map<int,bool>visited2;
    for(int i=0;i<=4;i++){
        if(!visited2[i]){
            g.dfs(i,visited2);
        }
    }


    


    
    cout<<endl;
}

