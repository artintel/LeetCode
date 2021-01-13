/*
 * @Author: Mayc
 * @Date: 2021-01-13 10:56:55
 * @LastEditTime: 2021-01-13 11:11:54
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 29. 顺时针打印矩阵\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        if (rows == 0) return ans;
        int cols = matrix[0].size();
        spiralOrder(matrix, 0, rows, cols, ans);
        return ans;
    }
    void spiralOrder(vector<vector<int>>& matrix, int start, int& rows, int& cols, vector<int>& ans){
        if( rows <= start * 2 || cols <= start * 2 ) return;
        if(rows > start * 2){
            // 方向1
            for(int i = start; i < cols - start; i++){
                ans.emplace_back(matrix[start][i]);
            }
            // 方向2
            if(start < rows - start - 1)
                for(int i = start + 1; i < rows - start; i++){
                    ans.emplace_back(matrix[i][cols - start - 1]);
                }
            else return;
            // 方向3
            if(start < cols - start - 1)
                for(int i = cols - start - 2; i >= start; i--){
                    ans.emplace_back(matrix[rows - start - 1][i]);
                }
            else return;
            // 方向4
            if( start < rows - start - 1)
                for(int i = rows - start - 2; i > start; i--){
                    ans.emplace_back(matrix[i][start]);
                }
            else return;
        }
        spiralOrder(matrix, start + 1, rows, cols, ans);
        return;
    }
};

/*  剑指Offer */
class Solution {
public:
    void spiralOrder(vector<vector<int>>& matrix, int& cols, int& rows, int start, vector<int>& ans){
        int endX = cols - start - 1;
        int endY = rows - start - 1;

        for( int i = start; i <= endX; ++i ){
            ans.emplace_back(matrix[start][i]);
        }
        if(start < endY){
            for( int i = start + 1; i <= endY; i++ ){
                ans.emplace_back(matrix[i][endX]);
            }
        }
        if(start < endX && start < endY){
            for( int i = endX - 1; i >= start; --i ){
                ans.emplace_back(matrix[endY][i]);
            }
        }
        if(start < endX && start < endY - 1){
            for( int i = endY - 1; i >= start + 1; --i ){
                ans.emplace_back(matrix[i][start]);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        vector<int> ans;
        if( rows == 0 ) return ans;
        int cols = matrix[0].size();
        int start = 0;
        while( cols > start * 2 && rows > start * 2 ){
            spiralOrder(matrix, cols, rows, start, ans);
            ++start;
        }
        return ans;
    }
};