class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans = 0;
            int n = nums.size();
    
            int i=0;
            int j = 0;
            long long sum = 0;
            long long count =0;
    
            while(j < n){
                sum += nums[j];
                count++;
                long long value = sum * count;
                if(count > 1 && value < k){
                    ans += count;
                }
               else  if(count >= 1 && value < k){
                    ans++;
                }
                while(value >= k){
                    count--;
                    sum  = sum - nums[i];
                    i++;
                    value = sum*count;
                    if(count > 1 && value < k){
                        ans += count;
                    }
                    else  if(count >= 1 && value < k){
                        ans++;
                    }            
                } 
                j++;
            }
            return ans;
        }
    };