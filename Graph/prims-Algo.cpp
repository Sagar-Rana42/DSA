//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    typedef pair<int,int> P;
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        unordered_map<int,bool>mp;
        int ans = 0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});
       
        
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            if(mp[node] == true){
                continue;
            }
            ans += wt;
            mp[node] = true;
            
            for(auto nbr:adj[node]){
                int newWt = nbr[1] ;
                int newNode =nbr[0] ;
                if(!mp.count(newNode)){
                    
                    pq.push({newWt , newNode});
                    
                }
               
            }
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends