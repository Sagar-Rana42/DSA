class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int>mp;
            int n = answers.size();
            if(n == 1) return answers[0]+1;
            for(auto &i : answers){
                if(mp.count(i) && mp[i] == 0){
                    mp[i] = i;
                }
               else if(mp.count(i)){
                    mp[i]--;
                }
                else{
                    mp[i]= i;
                }
            }
            int result = 0;
            for(auto &ans : mp){
                result += ans.second;
            }
            return result+n;
        }
    };