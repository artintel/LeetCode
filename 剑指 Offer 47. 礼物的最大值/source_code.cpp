/*
 * @Author: Mayc
 * @Date: 2021-02-01 13:26:21
 * @LastEditTime: 2021-02-01 13:26:29
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 47. 礼物的最大值\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp( rows + 1, vector<int>( cols + 1, 0 ) );
        for(int i = 1; i <= rows; i++ ){
            for(int j = 1; j <= cols; j++ ){
                dp[i][j] = max( grid[i - 1][j - 1] + dp[i][j - 1], grid[i - 1][j - 1] + dp[i - 1][j] );
            }
        }
        return dp[rows][cols];
    }
};