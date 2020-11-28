class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if( prices.size() == 0 || prices.size() == 1 ) return 0;
        int maxProfit = 0;
        int tempProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i - 1]){
                tempProfit += prices[i] - prices[i - 1];
            }
            else if(prices[i] < prices[i - 1]){
                maxProfit += tempProfit;
                tempProfit = 0;
            }
        }
        if(tempProfit != 0) maxProfit += tempProfit;
        return maxProfit;
    }
};