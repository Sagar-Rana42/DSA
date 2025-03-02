class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            if(nums1.size() == 0 || nums2.size() == 0){
                return (nums1.size()==0) ? nums2 : nums1; 
            }
            map<int,int>mp;
    
            for(auto &vec : nums1){
                int id = vec[0];
                int value = vec[1];
    
                if(mp.count(id)){
                    mp[id] += value;
                    
                }
                else{
                    mp[id] = value;
                }
                
            }
            for(auto &vec : nums2){
                int id = vec[0];
                int value = vec[1];
    
                if(mp.count(id)){
                    mp[id] += value;
                    
                }
                else{
                    mp[id] = value;
                }
                
            }
            vector<vector<int>>ans;
            for(auto &m : mp){
                ans.push_back({m.first , m.second});
            }
            return ans;
        }
    };