
class Solution {
    public:
        string addBinary(string a, string b) {
            string ans = "";
            int n = a.length();
            int m = b.length();
            reverse(a.begin(), a.end());
            reverse(b.begin() ,b.end());
            int i =0;
            int j  =0;
            int carry = 0;
    
            while(i < n || j < m ){
                carry += (i<n) ? a[i] - '0' : 0;
                carry += (j<m) ? b[j] - '0' : 0;
                ans.push_back((carry%2 +'0'));
                carry /= 2;
                i++,j++;
            }
            if(carry == 1){
                ans.push_back((carry%2 +'0'));
            }
            reverse(ans.begin() , ans.end());
            return ans;
    
            
           
        }
    };

 /*

class Solution {
    public:
        string addBinary(string a, string b) {
            if(a.length() == 0 || b.length() == 0){
                return (a.length()==0) ? b : a;
            }
    
            int n  = a.size()-1;
            int m = b.size()-1;
    
            string ans;
            int carry = 0;
    
            while( n >= 0 ||  m >= 0){
    
                carry += (n >= 0) ? a[n]-'0' : 0;
                carry += (m >= 0) ? b[m]-'0' : 0;
               
    
                // ans.push_back((  );
                char ch = (carry % 2 ) + '0';
                ans = ans +ch;
                carry = (carry)/2;
                n--;
                m--;
            }
            if(carry){
                ans += '1';
            }
            reverse(ans.begin() , ans.end());
            return ans;
        }
    };


*/