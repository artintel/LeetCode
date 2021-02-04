/*
 * @Author: Mayc
 * @Date: 2021-02-04 11:59:44
 * @LastEditTime: 2021-02-04 11:59:58
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\200. 岛屿数量\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, const int& rows, const int& cols){
        grid[i][j] = '0';
        int left = i;
        int right = j;

        if( left > 0 && grid[left - 1][right] == '1' ){
            dfs( grid, left - 1, right, rows, cols );
        }
        if( right + 1 < cols && grid[left][right + 1] == '1' ){
            dfs( grid, left, right + 1, rows, cols );
        }
        if( left + 1 < rows && grid[left + 1][right] == '1' ){
            dfs( grid, left + 1, right, rows, cols );
        }
        if( right > 0 && grid[left][right - 1] == '1' ){
            dfs( grid, left, right - 1, rows, cols );
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int rows = grid.size();
        if( rows <= 0 ) return 0;
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return count;
    }
};