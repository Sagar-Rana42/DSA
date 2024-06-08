class Solution {
public:
    unordered_set<string>st;
     int dp[301];
    
    bool breakWord(int idx, string s){
        int n = s.length();
        if(idx >= n){
            return true;
        }

        if(st.find(s) != st.end()){ // if we find answer 
            return true;
        }
        // if we not find answer , check 
        for(int i=1;i<=n;i++){
            string path = s.substr(idx,i);
            if((st.find(path) != st.end()) && breakWord(idx+i,s)){
                return true;
            }
        }
        return false;

    }
    bool memo(int idx, string s){
        int n = s.length();
        if(idx >= n){
            return true;
        }

        if(st.find(s) != st.end()){ // if we find answer 
            return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(int i=1;i<=n;i++){
            string path = s.substr(idx,i);
            if((st.find(path) != st.end()) && memo(idx+i,s)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        

        for(auto &word : wordDict){
            st.insert(word);
        }
        // return breakWord(0 ,s);

        // create a dp array 
        // vector<bool>dp(301,0);
       
        memset(dp,-1,sizeof(dp));

        return memo(0,s);
    }
};