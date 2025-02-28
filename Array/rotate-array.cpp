class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            if(k ==0){
                return ;
            }
            int actualRotate = k % n;
            if( actualRotate <= 0 ){
                return ;
            }
    
            vector<int>v;
            for(int i= n-actualRotate;i<n;i++){
                v.push_back(nums[i]);
            }
            for(int i=0;i<n-actualRotate;i++){
                v.push_back(nums[i]);
            }
            for(int i=0;i<n;i++){
                nums[i] = v[i];
            }
            
    
        }
    };