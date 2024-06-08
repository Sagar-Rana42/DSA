class Solution {
public:
    int solveRecurssion(vector<int>& nums , int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        int include = solveRecurssion(nums,n-2) + nums[n];
        int exclude = solveRecurssion(nums , n-1) +0;

        return max(include,exclude);

    }
    int solveMem(vector<int>& nums, int n ,vector<int>& dp){
        // Step2: Check Base case

        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        // Step 3: check answer already present is not 
        if(dp[n] != -1){
            return dp[n];
        }
        int include = solveMem(nums,n-2,dp) + nums[n];
        int exclude = solveMem(nums , n-1,dp) +0;

        dp[n] = max(include,exclude);
        return dp[n];

    }
    int solveTabu(vector<int>&nums , int n){
        // Step 1:- Create a dp array 
        vector<int>dp(n+1, 0);

        // Step2:- Base case 

        dp[0] = nums[0];
        
        
        for(int i=1;i<=n;i++){
            int temp = 0;
            if(i - 2 >=0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1] +0;

            dp[i] = max(include, exclude);
        }
        return dp[n];
    }


    int spaceOpti(vector<int>& nums , int n){

        int prev2 = 0;
        int prev1 = nums[0];

        int curr = 0;

        for(int i=1;i<=n;i++){
            int temp = 0;

            if(i-2>=0){
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = prev1 + 0;

            curr = max(include,exclude);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size()-1;

        // return solveRecurssion(nums,n);
        // Step1: Create Dp array 
        // vector<int>dp(n+1 , -1);
        // return solveMem(nums, n , dp);

        // return solveTabu(nums,n);

        return spaceOpti(nums,n);

        
    }
};