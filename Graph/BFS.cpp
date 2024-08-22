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
    // void bfs(T src,unordered_map<T,bool>&visited){ // for non connected graph , we pass visited
    //     queue<T>q;
    //     // unordered_map<T,bool>visited; // for connected graph 

    //     // initial Step:
    //     q.push(src);
    //     visited[src] = true;
    //     while(!q.empty()){
    //         int frontNode = q.front();
    //         q.pop();
    //         cout<<frontNode<<",";

    //         // insert Neighbour
    //         for(auto neighbour:adjList[frontNode]){
    //             if(!visited[neighbour]){
    //                 q.push(neighbour);
    //                 visited[neighbour] = true;
    //             }
    //         }
    //     }
    // }

    void bfs(T src ,unordered_map<T,bool>&visited ){
        queue<T>q;
        // Step1:- push src node at queue;
        q.push(src);
        // Step2: - mark true as visited 
        visited[src] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<"->";

            // traverse its neighbour

            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
};

int main(){
    // By Adjacency List 

    Graph<int> g;
    //       (srcnode , destination , typeOfgraph)
    g.addEdge(0,1,1);
    // g.addEdge(0,2,0);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // g.addEdge(5,6,0);
    cout<<endl;
    g.printAdjacencyList();

    unordered_map<int,bool>visited;
    for(int i=0;i<4;i++){
        if(!visited[i])
            g.bfs(0,visited); // for disconnected graph 
    }
    


    
    cout<<endl;
}