/*
 * @Author: Mayc
 * @Date: 2021-01-20 09:57:07
 * @LastEditTime: 2021-01-20 10:00:35
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\96. 不同的二叉搜索树\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void count_BStree(vector<int>& dp, int n) {
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
    }

    int numTrees(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n == 2) return 2;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        count_BStree(dp, n);
        return dp[n];
    }
};