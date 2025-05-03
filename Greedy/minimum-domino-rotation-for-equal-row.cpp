// Approach 1 

class Solution {
    public:
        
        int  rotate(vector<int> &tops, vector<int>& bottoms, int ans){
            int n = tops.size();
            vector<int>frequency(7,0);
            for(const auto num : tops){
                frequency[num]++;
            }
            
            bool isPossible = false;
            int count = 0;
            for(int i=1;i<=6;i++){
                int freq = frequency[i];
                int count = 0;
                if(freq > 0){
                    for(int j=0;j<n;j++){
                        if(tops[j] == i){
                            continue;
                        }
                        else if(i== bottoms[j]){
                            count++;
                        }
    
                        
    
                    }
                    if(count+freq == n){
                        isPossible = true;
                        ans = min(ans, count);
                    }
                    
                }
            }
            if(isPossible){
                return ans;
            }
            return -1;
            
        }
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    
            int result= INT_MAX;
            int a = rotate(tops,bottoms,INT_MAX);
            // cout<<"a = "<<a<<endl;
            if(a != -1){
                result = min(a,result);
            }
    
            int b = rotate(bottoms,tops,INT_MAX);
            // cout<<"b = "<<b<<endl;
            if(b != -1)
                    result = min(b,result);
                    
            return  (result == INT_MAX) ? -1 : result;
            
            
        }
    };




    