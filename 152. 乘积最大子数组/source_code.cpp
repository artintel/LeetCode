/*
 * @Author: Mayc
 * @Date: 2021-02-01 12:19:56
 * @LastEditTime: 2021-02-01 12:20:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\152. 乘积最大子数组\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mn = nums[0];
        int ans = nums[0];
        for(int i = 1; i < n; i++){
            int maxF = mx, minF = mn;
            mx = max( maxF * nums[i], max( nums[i], minF * nums[i] ) );
            mn = min( maxF * nums[i], min( nums[i], minF * nums[i] ) );
            ans = max( mx, ans );
        }
        return ans;
    }
};