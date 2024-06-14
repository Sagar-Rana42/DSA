class Solution {
public:
   int n;
    int findNumber(vector<int>&nums , int i, int p){
        // base case 
        

        if( i >= n){
            return 0;
        }
        int include = 0;
        if(p ==-1 || nums[i] > nums[p]){
            include = 1 + findNumber(nums,i+1,i);
        }
        int exclude = findNumber(nums,i+1,p);

        return max(include,exclude);
    }
    int memo(vector<int>&nums,int i, int p , vector<vector<int>>&dp){
        if( i >= n){
            return 0;
        }
        if(p!= - 1 &&  dp[i][p] != -1){
            return dp[i][p];
        }
        // dp[0][p] = 1;
        int include = 0;
        if(p ==-1 || nums[i] > nums[p]){
            include = 1 + memo(nums,i+1,i,dp);
        }
        int exclude = memo(nums,i+1,p,dp);
        if(p != -1)
            dp[i][p] = max(include,exclude);
            return  dp[i][p];


    }

    int bottomUpApproach(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        for(int curr = n-1; curr>=0; curr--) {
            for(int prev = curr - 1; prev >= -1; prev--) {
                //include
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev])
                    include = 1 + dp[curr+1][curr + 1];

                //excude
                int exclude = 0 + dp[curr+1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);   
            }
        }
        return dp[0][0];
    }

    // solve optiimal
    int findLength(vector<int>&num){
        if(num.size() <= 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(num[0]);

        for(int i=1;i<num.size();i++){
            if(num[i] > ans.back()){
                // include
                ans.push_back(num[i]);
            }
            else{
                // override kar do
                // find index of just greater element
                int index = lower_bound(ans.begin(),ans.end(),num[i]) - ans.begin();
                ans[index] = num[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();

        // return findNumber(nums,0,-1);
        // vector<vector<int>>dp(n+1,vector<int>(n+1 , -1));

        // return memo(nums,0,-1,dp);4
        // return bottomUpApproach(nums);

        return findLength(nums);
        
    }
};