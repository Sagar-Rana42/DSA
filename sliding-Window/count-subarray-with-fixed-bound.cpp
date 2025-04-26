class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            int n = nums.size();
    
            /*
            vector<vector<int>>store;
            for(int i=0;i<n;i++){
                vector<int>temp;
                for(int j=i;j<n;j++){
                    temp.push_back(nums[j]);
                    store.push_back(temp);
                }
                
            }
            long long count = 0;
            for(int i=0;i<store.size();i++){
                bool isMink , isMaxk = false;
                for(int j=0;j<store[i].size();j++){
                    if(store[i][j] == minK){
                        isMink = true;
                    }
                    if(store[i][j] == maxK){
                        isMaxk = true;
                    }
                    if(store[i][j] < minK || store[i][j] > maxK){
                        isMink = false;
                        break;
                    }
                }
                if(isMink && isMaxk){
                    count++;
                }
            }
            return count;
            */
            int minIndex = -1;
            int maxIndex= -1;
            int culprit = -1;
            long long ans = 0;
            long long temp = 0;
            for(int i=0;i<n;i++){
                if(nums[i] == minK){
                    minIndex = i;
                }
                if(nums[i] == maxK){
                    maxIndex = i;
                }
                if(nums[i] < minK || nums[i] > maxK){
                    culprit = i;
                }
                int smallest = min(minIndex, maxIndex);
                temp = smallest - culprit;
    
                ans += (temp <=0 ? 0 : temp);
            }
            return ans;
    
    
        }
    };