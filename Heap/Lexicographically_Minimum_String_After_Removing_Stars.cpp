class Solution {
public:
    class myComp{
        public:
        bool operator()(pair<char,int>&p1, pair<char,int>&p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }

            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char,int>,vector<pair<char,int>>,myComp>pq;

        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                int node = pq.top().second;pq.pop();
                s[node] = '*';
            }
            else{
                pq.push({s[i],i});
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i] != '*'){
                ans += s[i];
            }
        }
        return ans;
    }
};