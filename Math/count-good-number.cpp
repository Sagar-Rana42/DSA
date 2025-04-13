class Solution {
    public:
        const  int  MOD = 1e9 + 7;
        int power(long long  a , long long b){
           if(b == 0){
                return 1;
           }
           long long half = power(a,b/2);
           long long ans =( half * half)  % MOD;
    
           if(b % 2 == 1){
            ans  = (ans * a) % MOD;
           }
    
           return ans;
            
        }
    
        int countGoodNumbers(long long n) {
            if(n == 1){
                return 5;
            }
    
            long long  evenPlace = (n+1)/2;
            long long  oddPlace = n/2;
            long long pow5 = power(5, evenPlace);
            long long pow4 = power(4, oddPlace);
    
            long long result = (pow5 * pow4) % MOD;
    
            return (int)result;
    
             
            
        }
    };