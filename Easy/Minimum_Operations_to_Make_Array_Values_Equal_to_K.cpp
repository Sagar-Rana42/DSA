class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
           
            vector<int>mp(101 , 0);
            int ans  = 0;
            for(auto const& num : nums){
                if(num < k){
                    return -1;
                }
                if( num > k && mp[num] == 0){
                    ans++;
                }
                
                mp[num]++;
                
                
            }
            return ans;
        }
    };