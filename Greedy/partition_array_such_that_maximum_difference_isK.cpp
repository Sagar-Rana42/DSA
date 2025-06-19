class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int i = 0;
        int count = 0;
        while (i < n){
            int curr = nums[i];
            int j = i+1;
            while(j<n && nums[j]-curr <= k){
                j++;
            }
            i = j;
            count++;
        } 
        return count;
    }
};