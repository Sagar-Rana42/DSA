class Solution {
    public:
        string reverseWords(string s) {
            string ans  ="";
            string str = "";
            for(int i=s.size()-1;i>=0;i--){
                if(s[i] != ' '){
                    str += s[i];
                }        
                else if(s[i] == ' '){
                    if(!str.empty()){
                        reverse(str.begin() , str.end());
                        ans = ans + " " + str;
                        
                        str = "";
                    }
                }
                // cout<<"str = "<<str<<endl;
                   
            }
            // handle last case 
            if(!str.empty()){
                // worst case 
                // t.c = o(N)
                reverse(str.begin() , str.end());
                ans = ans + " " + str;
            }
            if(ans[0] == ' '){
                // in worst we have to shift all the char 
                // t.c = o(N)
                ans.erase(0,1);
               
            }
            return ans;
        }
    };