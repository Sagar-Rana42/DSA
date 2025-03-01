class Solution {
    public:
        
        int Dijkstra(unordered_map<int,vector<pair<int,int>>>&adj , int n , int src ){
            set<pair<int,int>>st; // dist , node store krega
            vector<int>dist(n+1 , INT_MAX);
            st.insert({0,src});
            dist[src] = 0;
    
            while(!st.empty()){
                auto node = *(st.begin());
                int d = node.first;
                int nod = node.second;
    
                st.erase(st.begin()); // remove from set 
    
                for(auto &nbr : adj[nod]){
                    int nextDist = nbr.second;
                    int nextNode = nbr.first;
    
                    if(d + nextDist < dist[nextNode]){
    
                        // then find if , there is any entry from this node 
    
                        auto res = st.find({ dist[nextNode] , nextNode  });
                        if(res != st.end()){
                            st.erase(res);
                        }
                        // update in dist array 
                        dist[nextNode] = d + nextDist;
                        st.insert({d+nextDist , nextNode});
                    }
                }
    
            }
            int ans = *max_element(dist.begin() + 1, dist.end());
            return (ans == INT_MAX) ? -1 : ans; // Return -1 if unreachable
        }
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            unordered_map<int,vector<pair<int,int>>>adj;
    
            for(auto &vec : times){
                int u = vec[0];
                int v = vec[1];
                int w = vec[2];
    
                adj[u].push_back({v,w});
            }
         return   Dijkstra(adj,n , k);
    
        }
    };