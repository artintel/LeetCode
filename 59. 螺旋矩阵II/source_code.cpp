/*
 * @Author: Mayc
 * @Date: 2020-12-26 11:27:07
 * @LastEditTime: 2020-12-26 11:27:59
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\59. 螺旋矩阵II\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, up = 0, down = n - 1;
        int var = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while(var <= n * n){

            for(int i = left; i <= right; i++) matrix[up][i] = var++;
            up++;
            for(int i = up; i <= down; i++) matrix[i][right] = var++;
            right--;
            for(int i = right; i >= left; i--) matrix[down][i] = var++;
            down--;
            for(int i = down; i >= up; i--) matrix[i][left] = var++;
            left++;
        }
        return matrix;
    }
};