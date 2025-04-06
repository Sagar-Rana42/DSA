class Solution {
    public:
    
     ////////////////////// ++++++++    Approach 1 ++++++++++++++++
        /*
        int ans = 0;
        void findXORSum(vector<int>& nums, int start, int res){
            if(start >= nums.size()){
                ans = ans + res;
                return;
            }
            findXORSum(nums, start+1,res^nums[start]);
            findXORSum(nums, start+1,res);   
        } 
        */
    
        int subsetXORSum(vector<int>& nums) {
    
            // ++++++++++++ Approach 2 +++++++++++
            int ans = 0;
            for(auto const &num : nums){
                ans |= num;
            }     
            return ans<<nums.size()-1;;
        }
        
    };