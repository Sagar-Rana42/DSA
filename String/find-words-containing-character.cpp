
// ++++++++++++++++++++++++  Approach 1 ++++++++++++++++++++++++++++++   // 
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int i = 0;
        for(auto str : words){
            if(str.find(x) != string::npos){
                ans.push_back(i);
            }
            i++;
        }
        return ans;
    }
};

// ++++++++++++++++++++++ Approach 2 ++++++++++++++++++++++++++++++++

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        int i = 0;
        for(auto str : words){
            for(auto ch : str){
                if(ch == x){
                    ans.push_back(i);
                    break;
                }
            }
            i++;
        }
        return ans;;
    }
};