class Solution {
public:
    int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        if(t == 0){
            return s.size();
        }
        vector<long long >vec(26,0);
        for(auto ch : s){
            vec[ch-'a']++;
        }
        while(t--){
            vector<long long >temp(26,0);
            for(int i=0;i<26;i++){
                
                int time = vec[i];
                if(time == 0){
                    continue;
                }
                else {
                    if(i == 25){ // for z
                        temp[0]  = (temp[0] + time) % MOD;
                        temp[1]  = (temp[1] + time) % MOD;
                    }  
                    else{
                        // vec[i]--;
                        temp[i+1] = (temp[i+1] + time) % MOD;
                    }
                    
                } 
                
            }
            vec = temp;
        }
        int ans = 0;

        for(auto const & num:vec){
            ans  = (ans + num) % MOD;
        }

        return ans;
    }
};