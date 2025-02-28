class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if(prices.size() < 2){
                return 0;
            }
            int profit = 0;
            int buy = prices[0];
            for(int i=1;i<prices.size();i++){
                if(buy > prices[i]){
                    buy = prices[i];
                }
                int prft = prices[i] - buy;
                profit = max(profit , prft);
            }
            return profit;
    
        }
    };