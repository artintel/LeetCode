/*
 * @Author: Mayc
 * @Date: 2021-01-07 08:49:56
 * @LastEditTime: 2021-01-07 08:53:41
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\64. 最小路径和\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 || j == 1){
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + grid[i - 1][j - 1];
                }
                else{
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};