/*
 * @Author: Mayc
 * @Date: 2021-01-26 10:19:59
 * @LastEditTime: 2021-01-26 10:20:08
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 42. 连续子数组的最大和\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int MAX = nums[0];
        vector<int> dp(n, nums[0]);
        for(int i = 1; i < n; i++){
            if(dp[i - 1] < 0){
                dp[i] = nums[i];
            }
            else{
                dp[i] = dp[i - 1] + nums[i];
            }
            MAX = max(MAX, dp[i]);
        }
        return MAX;
    }
};