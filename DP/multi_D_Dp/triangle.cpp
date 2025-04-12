class Solution {
    public:
        int finiMinimum(vector<vector<int>>& triangle , int &n , int i ,int j,vector<vector<int>>&dp){
            if(i >=n || (i> 0 && j >= triangle[i-1].size()+1)  ){
                return 0;
            }
            if(dp[i][j] != -1){
                return dp[i][j];
            }
    
            int right = triangle[i][j] + finiMinimum(triangle,n,i+1,j,dp);
            int down = triangle[i][j] + finiMinimum(triangle,n,i+1,j+1,dp);
    
            return dp[i][j] = min(right , down);
        }
        int minimum(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<int> dp(triangle[n-1]); // start with the last row
    
            // bottom-up
            for (int i = n-2; i >= 0; --i) {
                for (int j = 0; j <= i; ++j) {
                    dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
                }
            }
    
            return dp[0];
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            
    
            // int ans = finiMinimum(triangle,n,0,0,dp);
            int ans = minimum(triangle);
            return ans;
        }
    };