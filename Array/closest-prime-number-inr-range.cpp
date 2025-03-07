/* Approach 1 brute force */


class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            if(left == 1){
                left = 2;
            }
            if(left == right){
                return {-1,-1};
            }
            vector<int>isPrime;
            for(int i = left ; i <= right ;i++){
                bool isP = true;
                int count =0;
                for(int j=1; j<=sqrt(i);j++){
                    if( i%j == 0 ){
                        count++;
                        
                    }
                    if(count >= 2){
                        isP = false;
                        break;
                    }
                }
                if(isP){
                    isPrime.push_back(i);
                }
            }
            // now find difference 
            for(auto &n : isPrime)cout<<n<<" ";
            if(isPrime.size() < 2){
                return {-1,-1};
            }
            if(isPrime.size() == 2){
                return isPrime;
            }
            int diff = INT_MAX;
            int ans = -1;
            for(int i=0;i<isPrime.size()-1;i++){
                if(isPrime[i+1] - isPrime[i] < diff){
                    diff  = isPrime[i+1] - isPrime[i] ;
                    ans = i;
                }
            }
            return {isPrime[ans] , isPrime[ans+1]};
        }
    };


    /*   Approach 2 */
    /// sieve of erothesis 

class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            if(left == right ){
                return {-1,-1};
            }
            vector<bool>isPrime(right+1 , true);
            isPrime[0] = false;
            isPrime[1] = false;
            for(int i=2;i<=sqrt(right);i++){
                if(isPrime[i]){
                    for(int j=i;j*i <=right;j++){
                        isPrime[j*i] = false;
                    }
                }
            }
    
            vector<int>vec;
            for(int i=left;i<=right;i++){
                if(isPrime[i]){
                    vec.push_back(i);
                }
            }
    
            if(vec.size() < 2){
                return {-1,-1};
            }
            if(vec.size() == 2){
                return vec;
            }
            int diff = INT_MAX;
            int ans = -1;
            for(int i=0;i<vec.size()-1;i++){
                if(vec[i+1] - vec[i] < diff){
                    diff  = vec[i+1] - vec[i] ;
                    ans = i;
                }
            }
            return {vec[ans] , vec[ans+1]};
    
    
            return {-1,-1};
    
    
        }
    };
