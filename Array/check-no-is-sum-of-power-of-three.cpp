//  Approach 1  

class Solution {
    public:
        bool checkPowersOfThree(int n) {
           int power = 0;
    
           while( pow(3,power) <= n){
                power++;
           }
           while(n > 0){
                if(n >= pow(3,power)){
                    n = n - pow(3,power);
                }
                if(n >= pow(3,power)){
                    return false;
                }
                power--;
           }
           return true;
        }
};

// Approach-2

class Solution {
    public:
        bool checkPowersOfThree(int n) {
           while( n > 0){
                if(n % 3 == 2){
                    return false;
                }
                n /= 3;
           }
           return true;
    
          
        }
    };