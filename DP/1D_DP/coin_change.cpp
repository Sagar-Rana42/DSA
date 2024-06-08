class Solution {
public:
    // int solveUsingRec(vector<int>&coins , int amount){
    //     // base case 
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(amount < 0){
    //         return INT_MAX;
    //     }
    //     int mini = INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int ans = solveUsingRec(coins,amount - coins[i]);
    //         if(ans != INT_MAX)
    //            mini = min(mini , ans+1);
    //     }
    //     return mini;

    // }
    int usingMem(vector<int>&coins , int amount, vector<int>&dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        // Check Answer is already present or not 
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = usingMem(coins , amount-coins[i] , dp);
            if(ans != INT_MAX){
                mini = min(mini,1+ans);
            }
        }
        dp[amount] = mini;

        return mini;
        
    }
    int usingTab(vector<int>& coins, int amount){
        // Step1: Create Dp array
        // dp[i] store minimum number of coin required to make a amount 
        vector<int>dp(amount+1 , INT_MAX);
        // Step2: base case check karo
        dp[0] = 0; // ifamount == 0 , it's means 0 coin required to make 0 amount   

        // Step 3: check range and flow of top down approach and code accordingly 
        for(int target =1;target <= amount;target++){
            int mini = INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(target - coins[i] >=0 ){
                    int ans= dp[target-coins[i]]; //change recursive call into dp 
                    if(ans != INT_MAX){
                        mini = min(mini,ans+1);
                    }
                }
            }
            dp[target] = mini;
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans  = solveUsingRec(coins , amount);

        // Step 1: Create a dp array 
        // vector<int>dp(amount+1 , -1);

        // int ans = usingMem(coins , amount , dp);

        int ans = usingTab(coins , amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
        
    }
};