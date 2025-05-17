#include<iostream>
#include<vector>
using namespace std;

vector<int>parent;
vector<int>rank;

int find(int u  ){
    if(u == parent[u]){
        return true;
    }
    return parent[u] = find(parent[u]);
}

void union1(int u , int v){
    int u_parent = find(u);
    int v_parent = find(v);

    if(rank[u_parent] > rank[v_parent]){
        rank[v_parent] = u_parent;
    }
    else if(rank[v_parent] > rank[u_parent]){
        rank[u_parent] = v_parent;
    }
    else{
        rank[u_parent]++;
    }
}


int main(){
    int n = 10;
    parent.resize(n);
    rank.resize(n,0);

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    
    

    return 0;
}