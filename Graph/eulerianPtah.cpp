#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


void DFS(unordered_map<int,vector<int>>&adj , int src,vector<int>&visited){
    visited[src] = true;

    for(auto &nbr : adj[src]){
        if(!visited[nbr]){
            DFS(adj,nbr,visited);
        }
    }


}

void printGraph(unordered_map<int,vector<int>>&adj,int src){
    queue<int>q;
    q.push(src);
    vector<int>visit(4,0);
    visit[src] = 1;

    while(!q.empty()){
        // int n = q.size();
        // for(int i=0;i<n;i++){
            int node  = q.front(); q.pop();
        // }
        
        cout<<node<<" - ";
        for(auto nbr : adj[node]){
            cout<<nbr<< " ";
            if(!visit[nbr]){

                q.push(nbr);
                visit[nbr] = 1;
            }
        }
        cout<<endl<<endl;
 
    }
   
    
}


void checkPath( unordered_map<int,vector<int>>&adj){
    int V = 3;
    vector<int>visited(V,0);
    DFS(adj,0,visited);

    for(const auto& i : visited){
        if(i == 0){
            cout<<"for euclarian path graph should be connected "<<endl;
            return;
        }
    }

    vector<int>degree(V , 0);
    for(int i=0;i<V;i++){
        // cout<<adj[i].size()<<" ";
        degree.push_back(adj[i].size());
    }
    int degreeOddCount = 0;

    for(auto const deg : degree){
        if(deg&1){
            cout<<deg<<" ";
            degreeOddCount++;
        }
    }
    if(degreeOddCount == 2){
        cout<<"There is  euclarian path "<<endl;
    }
    else 
        cout<<"there is no euclarian path  "<<endl;
    

}

int main(){
    unordered_map<int,vector<int>>adj;
    // unordered_map<int,int>visited;
    /*
        0 - 1, 2
        1 - 0, 2
        2 - 0, 1
    
    */
    adj[0].push_back(1);
    // adj[0].push_back(2);
    // adj[1].push_back(0);
    adj[1].push_back(2);
    // adj[2].push_back(1);
    // adj[2].push_back(0);

    // printGraph(adj,0);
    checkPath(adj);
   

   
    return 0;
}