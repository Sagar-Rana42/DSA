class Solution {
private:
    int searchIndex(vector<int>& nums,int target){
        int s = 0;
        int e = nums.size();

        int mid = s + (e - s) / 2;
        while (s <= e) {
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s =mid+1;
            }
            
            mid = s + (e - s) / 2;
        }
        return s;
        
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0]){
            return 0;
        }
        if(target > nums[nums.size()-1]){
            return nums.size();
        }
        

        int ans = searchIndex(nums, target);
        return ans;
        
    }
};