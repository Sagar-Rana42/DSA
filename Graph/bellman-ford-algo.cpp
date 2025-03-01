
class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>ans(V , 1e8);
        ans[src] = 0;
        for(int i=1;i<=V-1;i++){
            
            for(auto &edge:edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(ans[u] != 1e8 && ans[u] + w < ans[v]){
                    ans[v] = ans[u] + w;
                }
            }
        }
        // check -ve cycle 
        
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(ans[u] != 1e8 && ans[u] + w < ans[v]){
               return {-1};
            }
        }
        return ans;
    }
};



