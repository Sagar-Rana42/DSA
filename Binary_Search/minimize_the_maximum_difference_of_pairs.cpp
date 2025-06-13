class Solution {
public:
    bool isValid(vector<int>& nums, int mid,  int p,int n){
        int i= 0;
        int count = 0;
        while(i < n-1){
            if(nums[i+1]-nums[i] <= mid){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        return (count>=p) ? true : false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int l   = 0;
        int r   = nums[n-1] - nums[0];
        int res = INT_MAX;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(nums,mid,p,n)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};