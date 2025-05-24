class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0;
    
        int n     = nums.size();
        int count = 0;
        int loss  = INT_MAX;

        for(auto num : nums){
            if((num^k )> num){
                ans += (num^k);
                count++;
            }
            else{
                ans += num;
            }
            loss = min(loss , abs(num - (num^k)));
        }
        
        if(count&1){
            ans -= loss;
        }
        return ans;
    }
};