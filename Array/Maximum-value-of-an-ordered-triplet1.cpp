class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0;
            
            if (n == 3) {
                long long sum = (nums[0] - (long long)nums[1]) * nums[2];
                return max(0LL, sum);
            }
            vector<long long> prefix(n, 0);
            vector<long long> suffix(n, 0);
            prefix[0] = nums[0];
    
            for (int i = 1; i < n; i++) {
                prefix[i] = max(prefix[i - 1], (long long)nums[i]);
            }
    
            suffix[n - 1] = nums[n - 1];
    
            for (int i = n - 2; i >= 0; i--) {
                suffix[i] = max(suffix[i + 1], (long long)nums[i]);
            }
    
            for (int i = 1; i < n - 1; i++) {  
                long long v = (prefix[i - 1] - nums[i]) * suffix[i + 1];
                ans = max(ans, v);
            }
    
            return ans;
        }
    };
    