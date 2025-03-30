class Solution {
    public:
        vector<int> partitionLabels(string s) {
            int  n = s.size();
            if(n == 1){
                return {1};
            }
            if(n == 2 && s[0] == s[1]){
                return {1};
            }
            if(n == 2 && s[0] != s[1]){
                return {2};
            }
            unordered_map<char,int>mp;
            vector<int>ans;
    
            for(int i=0;i<n;i++){
                mp[s[i]] = i;
            }
            int i =0;
            while(i < n){
                int start = i;
                char ch = s[i];
                int max = mp[ch];
                // if(max == start)
                if(max == n-1){
                    ans.push_back(max+1 - start);
                    return ans;
                }
                string str = s.substr(start , max+1 - start);
                for(int j=0;j<str.size();j++){
                    if(mp[str[j]] > max){
                        max = mp[str[j]];
                       
                        str = s.substr(start,max+1-start);
                    }
                }
                ans.push_back(str.size());
               
                i = max+1;
            }
            return ans;
    
    
    
        }
    };