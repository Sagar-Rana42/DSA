class Solution {
public:
    int findStair(int n){
        if(n < 0 ){
            return 0;
        }
        if( n == 0){
            return 1;
        }
        return findStair(n-1) + findStair(n-2);        
    }

    int solveMemonization(int n , vector<int>&dp){
          // base case
        if(n < 0){
            return 0;
        }   
        if(dp[n] != -1){
            return dp[n];
        }
        if(n==0){
            return 1;
        }

       dp[n] =   solveMemonization(n-1,dp) + solveMemonization(n-2,dp);
        return dp[n];      
    }
    int tabu(int n){
        //1:- create a dp vector
        vector<int>dp(n+1 , 0);

        //2:- base case analysis
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            int temp = 0;
            if(i -2 >=0){
                temp = dp[i-2];
            }
            dp[i] =   dp[i-1] + temp;
        }
        return dp[n];    

    }
    int spaceOpti(int n){
        int prev1 = 1;
        int prev2 = 1;

        int curr = 0;

        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;

            // shifting 
            prev2 = prev1;
            prev1 =curr;
        }
        return curr;

    }
    int climbStairs(int n) {

        // int ans = findStair(n);
        // vector<int>dp(n+1,-1);
        // int ans = solveMemonization(n , dp);
        // int ans = tabu(n);
        if(n ==0 || n==1){
            return 1;
        }
        int ans =  spaceOpti(n);

        return ans;
        
    }
};  
