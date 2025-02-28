class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() < 3){
                return nums.size();
            }
            int j=1;
            for(int i=2;i<nums.size();i++){
                if(nums[j-1] != nums[i]){
                    nums[++j] = nums[i];
                }
            }
            return ++j;
    
        }
    };