// It does so by repeatedly selecting the nearest unvisited 
// vertex and calculating the distance to all the unvisited neighboring vertices.
// dijkestra work in both directed or undirected Graph 
// but having non-negative weight 
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<set>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int,int>>>adjList;


    void addEdge(int u , int v , int wt , bool direction){
        // direction = 1 -> undirected graph
        // direction = 0 -> directed graph 
        adjList[u].push_back({v,wt});
        if(direction == 1){ // it can be change
            adjList[v].push_back({u,wt});
        }
    }
    
    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"-> ";
            for(auto nbr: node.second){
                cout<<"("<<nbr.first<<","<<nbr.second<<") ";
            }
            cout<<endl;
        }
    }

    // Dijkstra Algo 
    void shortestDist(int src, int n ){
        // create distance array
        vector<int>dist(n,INT_MAX);

        // create set 
        set<pair<int,int>>st;

        // initial step 
        dist[src]= 0;
        st.insert({0,src});

        while(!st.empty()){
            // we can use auto here 

            // fetch smallest dist from set 
            pair<int,int>front = *(st.begin());
            // int topElement = front.first;
            int nodeDistance = front.first;
            int node = front.second;

            //pop from set 

            st.erase(st.begin());

            for(auto nbr:adjList[node]){
                // check distance , is small 
                if(nodeDistance + nbr.second < dist[nbr.first]){
                    // distance update karna hai 
                    // set me insert karo && dist array me bhi update karo
                    // but first search in set 

                    auto result =st.find(make_pair(dist[nbr.first] , nbr.first));
                    if(result != st.end()){
                        st.erase(result);
                    }
                    // update in both place set && dist array 
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first] , nbr.first));

                }
            }
        }

        cout<<"Printing "<<endl;
        for(int i=0;i<dist.size();i++){
            cout<<dist[i]<<" ";
        }cout<<endl;

    }
};


int main(){

    Graph g;
    g.addEdge(6,3,2,1);
    g.addEdge(6,1,14,1);
    g.addEdge(3,1,9,1);
    g.addEdge(3,2,10,1); 
    g.addEdge(1,2,7,1);
    g.addEdge(2,4,15,1);   
    g.addEdge(4,3,11,1);
    g.addEdge(6,5,9,1);   
    g.addEdge(4,5,6,1);

    g.printAdjacencyList();

    g.shortestDist(6,7);
    
    
    return 0;

}