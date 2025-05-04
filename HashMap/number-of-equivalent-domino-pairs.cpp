class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dom) {
    
            // +++++++++++  Approach 1 ++++++++++++


            /*
                long long  count = 0;
                for(long i=0;i<dom.size();i++){
                    int a = dom[i][0];
                    int b = dom[i][1];
                    for(long j=i+1;j<dom.size();j++){
                    int c = dom[j][0];
                    int d = dom[j][1];
                    if( (a == c && b == d) ||  (a == d and b == c)){
                            count++;
                    }
                    }
                }
    
                return count;
            */
    
// +++++++++++++++++++++ Approach 2 ++++++++++++++++++++ 

            // unordered_map<int,int>mp;
            map<pair<int,int>,int>mp;
            long long ans = 0;
            for(const auto &num:dom){
                pair<int,int>a = make_pair(num[0] , num[1]);
                pair<int,int>b = make_pair(num[1] , num[0]);
                if(mp.count(a)){
                    ans += mp[a];
                    mp[a]++;
                }
                else if(mp.count(b)){
                    ans += mp[b];
                    mp[b]++;
                }
                else{
                    mp[a] = 1;
                }
                
               
                
            }
    
            return ans;
        }
    };