/*
 * @Author: Mayc
 * @Date: 2021-02-22 12:56:33
 * @LastEditTime: 2021-02-22 12:56:40
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 63. 股票的最大利润\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n <= 0 ) return 0;
        int pre_min = prices[0];
        int max_money = 0;
        for(int i = 1; i < n; i++){
            if( prices[i] > pre_min ) {
                max_money = max( max_money, prices[i] - pre_min );
            }
            pre_min = min(pre_min, prices[i]);
        }
        return max_money;
    }
};