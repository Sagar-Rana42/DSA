class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return;
        }
        int i = 0;
        int j = 0;
        int r = n-1;

        while(j < r){
            if(nums[j] == 1){
                j++;
            }
            else if(nums[j] == 0){
                swap(nums[i],nums[j]);
                i++;j++;
            }
            else{
                swap(nums[r],nums[j]);
                r--;
            }
        }
    }
};