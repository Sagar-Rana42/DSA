class Solution {
    public:
        int hammingWeight(int n) {
            if(n == 1) return 1;
            int ans = 0;
            while(n > 0){
                if(n %2 == 1){
                    ans++;
                }
                n /= 2;
            }
            return ans;
        }
    };


/*
    class Solution {
        public:
            int hammingWeight(int n) {
                int count = 0;
                while (n != 0)
                {
                    int lastBit = n &1;
                    if(lastBit){
                        count++;
                    }
                    n = n>>1;
        
                }
                return count;
            }
        };

        */