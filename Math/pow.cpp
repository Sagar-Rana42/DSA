class Solution {
    public:
        double myPow(double x, int n) {
           if(x == 0 && n == 0) return 0.0;
           if(n == 0) return 1.0;
           if(n == 1) return x*1.0;
           if(x == 0) return 0.0;
    
           if(x == -1 && !(n&1)) return 1.0;
           if(x == -1 && (n& 1)) return -1.0;
    
           long N = n*1.0;
    
           if(N < 0){
                N = -N;
                x = 1.0/x;
           }
           double ans =1.0;
          
    
           while( N > 0){
                if(N % 2 == 1){
                    ans *= x;
                    // cout<<"ans = "<<ans<<endl;
                }
    
                x *= x;
                N /=2;
           }
           return ans;
           
           
    
        }
    };