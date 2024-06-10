class Solution {
public:

    int findPath(int i , int j , int m , int n){ // recursive method 
        // base case 
        if(i < 0 || i>= m || j < 0 || j >= n){
            return 0;
        }
        if(i == m-1  && j == n-1){
            return 1;
        }
        int rightPath = findPath(i,j+1 ,m,n);
        int downPath = findPath(i+1,j,m,n);

        return rightPath + downPath;
    }
    int memonisation(int i, int j,int m,int n, vector<vector<int>>&dp){
        if(i<0 || i>= m || j<0 || j>=n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int rightPath = memonisation(i,j+1 ,m,n,dp);
        int downPath = memonisation(i+1,j,m,n,dp);

        dp[i][j] = rightPath + downPath;
        return dp[i][j];
 
    }

    int uniquePaths(int m, int n) {

        // int ans = findPath(0,0,m,n);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans = memonisation(0,0,m,n,dp);
        return ans;
        
    }
};