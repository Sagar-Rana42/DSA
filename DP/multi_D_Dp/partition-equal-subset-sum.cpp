class Solution {
    public:
        bool solveRecursion(vector<int>&nums , int index, int target){
            int n = nums.size();
    
            if(index >= n){
                return false;
            }
            if(target < 0){
                return false;
            }
            if(target == 0 ){
                return true;
            }
            bool include = solveRecursion(nums,index+1,target-nums[index]);
            bool exclude = solveRecursion(nums,index+1 , target);
    
            return (include || exclude);
        }
        bool solveUsingMem(vector<int>&nums , int index , int target , vector<vector<int>>&dp){
            int n = nums.size();
            if(index >= n){
                return false;
            }
            if(target < 0){
                return false;
            }
            if(target == 0 ){
                return true;
            }
            if(dp[index][target] != -1){
                return dp[index][target];
            }
            bool include = solveUsingMem(nums,index+1,target-nums[index],dp);
            bool exclude = solveUsingMem(nums ,index+1, target , dp);
    
            dp[index][target] = (include || exclude);
            return dp[index][target];
        }
        bool solveUsingTabu(vector<int>&nums , int target){
            int n =nums.size();
            // Step 1: create a dp array 
            vector<vector<int>>dp(n+1,vector<int>(target+1 , 0));
            
    
            // Step2: 
            for(int i=0;i<nums.size();i++){
                dp[i][0] = 1;
            }
    
            // step 3:- 
            for(int index = n-1;index>=0;index--){
                for(int t=1;t<=target;t++){
                    bool include =0;
                    if(t-nums[index] >=0){
                        include = dp[index+1][t-nums[index]];
    
                    }
                    
                    bool exclude = dp[index+1][t];
    
                    dp[index][t] = (include || exclude);
                }
            }
            return dp[0][target];
        }
        bool solveSO(vector<int>&nums,int target){
    
            int n = nums.size();
    
            vector<int>curr(target+1,0);
            vector<int>next(target+1,0);
    
            for(int i=0;i<nums.size();i++){
                next[0] = 1;
            }
            for(int index = n-1;index>=0;index--){
                for(int t = 1;t<=target;t++){
                    bool include = 0;
                    if(t-nums[index] >= 0){
                        include = next[t-nums[index]];
                    }
                    bool exclude = next[t];
                    curr[t] = (include || exclude);    
                }
                // shifting
                next = curr;
            }
            return curr[target];
    
        }
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(int i=0;i<nums.size();i++){
                sum += nums[i];
            }
            if(sum & 1){
                return false;
            }
            int target = sum /2;
            int index = 0;
            // bool ans =  solveRecursion(nums,index,target);
            // Step 1: Create a dp array 
            // vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
            // bool ans = solveUsingMem(nums, index , target , dp);
    
            bool ans = solveSO(nums,target);
            return ans;
        }
    };