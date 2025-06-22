class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int n = s.size();
        int rem = n % k;

        for(int i=0;i<n;i+=k){
            if(i+k <= n){
                ans.push_back(s.substr(i,k));
            }
        }
        if(rem == 0) return ans;
        string temp;
        for(int i=n-rem;i<n;i++){
            temp += s[i];
        }
        while(temp.size() != k){
            temp += fill;
        }
        ans.push_back(temp);

        return ans;
    }
};