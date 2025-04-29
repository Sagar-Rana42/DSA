class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            if(k > n){
                return 0;
            }
            int maxValue = *max_element(nums.begin() , nums.end());
            int i=0;
            int j=0;
            int count = 0;
            long long ans =0;
    
            while(j < n){
                if(nums[j] == maxValue){
                    count++;
                }
                while(count >= k){
                    ans += n-j;
                    if(nums[i] == maxValue){
                        count--;
                    }
                    i++;
                }
                j++;
            }
            return ans;
    
        }
    };