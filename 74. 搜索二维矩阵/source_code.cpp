/*
 * @Author: Mayc
 * @Date: 2020-12-29 08:33:56
 * @LastEditTime: 2020-12-29 08:34:04
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\74. 搜索二维矩阵\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int length = row * col;
        int mid;
        int i = 0, j = length - 1;
        while(i <= j){
            int mid = (i + j) >> 1;
            if(matrix[mid / col][mid % col] == target) return true;
            else if(matrix[mid / col][mid % col] > target) j = mid - 1;
            else i = mid + 1;
        }
        return false;
    }
};