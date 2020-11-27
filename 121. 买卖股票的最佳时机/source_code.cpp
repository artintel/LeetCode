class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int len = prices.size();
        int Max = 0;//最多能挣多少
        int min = prices[len - 1];
        for(int i = len - 2; i >= 0; i--){
            if(prices[i] < prices[i + 1]){
                
            }
            else
                prices[i] = prices[i + 1];
        }
        return Max;
    }
};

# 优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int len = prices.size();
        int Max = 0;
        for(int i = len - 2; i >= 0; i--){
            if(prices[i] < prices[i + 1]){
                Max = max(Max, prices[i + 1] - prices[i]);
                prices[i] = prices[i + 1];
            }
        }
        return Max;
    }
};