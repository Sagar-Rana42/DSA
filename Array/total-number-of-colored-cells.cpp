class Solution {
    public:
        long long coloredCells(int n) {
            if( n == 1){
                return 1;
            }
            return pow(n,2) + pow(n-1,2);
        }
    };