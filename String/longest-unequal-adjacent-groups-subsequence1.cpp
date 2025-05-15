class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n  = words.size();
        if(n == 1){
            return words;
        }
        if(n == 2 && groups[0] != groups[1]){
            return words;
        }
        if(n == 2 && groups[0] == groups[1]){
            return {words[0]};
        }
        string prev = words[0];
        int pre = groups[0];
        vector<string>ans;
        ans.push_back(prev);
        for(int i=1;i<n;i++){
           if(groups[i] != pre){
                ans.push_back(words[i]);
           }
           pre = groups[i];
        }
        return ans;
    }
};