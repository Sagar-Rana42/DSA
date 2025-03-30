class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int temp = 1<<i;
            int ct = 0;
            for(auto &n : nums){
                int c = temp & n;
                if(c != 0){
                    ct++;
                }
                
            }
            if(ct % 3 == 1){
                ans = ans | temp;
            }

        }
        return ans;
    }
};