/*
 * @Author: Mayc
 * @Date: 2021-01-31 14:12:42
 * @LastEditTime: 2021-01-31 14:12:59
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 46. 把数字翻译成字符串\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int translateNum(int num) {
        int count = 0;
        if( num < 10 ) return 1;
        string nums = to_string(num);
        int n = nums.size();
        vector<int> dp(n, 1);
        for( int i = n - 2; i >= 0; i-- ){
            int temp = 0;
            temp = (nums[i] - '0') * 10 + (nums[i + 1] - '0');
            if( temp > 25 || temp < 10 ){
                dp[i] = dp[i + 1];
            }
            else if( i == n - 2 ){
                dp[i] = 2;
            }
            else if( i < n - 2 ){
                dp[i] = dp[i + 1] + dp[i + 2];
            }
        }
        return dp[0];
    }
};