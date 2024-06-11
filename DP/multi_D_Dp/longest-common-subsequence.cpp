class Solution {
public:
    int solveRecursion(string a , string b,int i , int j  ){
        if(i >= a.length()){
            return 0;
        }
        if(j >= b.length()){
            return 0;
        }
        
        if(a[i] == b[j]){
            return 1 + solveRecursion(a,b,i+1,j+1);
        }
        else{
            return 0 + max(solveRecursion(a,b,i+1,j) , solveRecursion(a,b,i,j+1));
        }
       
    
    }
    int solveUsingMem(string &a , string &b , int i , int j,vector<vector<int>>&dp ){
        if(i >= a.length()){
            return 0;
        }
        if(j >= b.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j]){
            ans =  1 + solveUsingMem(a,b,i+1,j+1,dp);
        }
        else{
            ans =  0 + max(solveUsingMem(a,b,i+1,j,dp) , solveUsingMem(a,b,i,j+1,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    };
    // using tabulation
    int findCommonSubsequence(string a , string b){ 
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1, 0));

        for(int i=a.length()-1;i>=0;i--){
             int ans = 0;
            for(int j=b.length()-1;j>=0;j--){              
                if(a[i] == b[j]){
                    ans =  1 + dp[i+1][j+1];
                }
                else{
                    ans =  0 + max(dp[i+1][j] , dp[i][j+1]);
                }
                dp[i][j] = ans;               
            }           
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i =0;
        int j = 0;
        // return solveRecursion(text1,text2,i,j);
        // Step1:- Create a dp array 
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(), -1));
        // return solveUsingMem(text1 , text2 , i,j,dp);
        return findCommonSubsequence(text1,text2);
        
    }
};