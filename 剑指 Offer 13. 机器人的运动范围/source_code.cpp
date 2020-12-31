/*
 * @Author: Mayc
 * @Date: 2020-12-31 13:54:54
 * @LastEditTime: 2020-12-31 13:55:04
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 13. 机器人的运动范围\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<bool> ans( n * m, false );
        int count = max_moving( m, n, k, 0, 0, ans );
        return count;
    }
    int max_moving(int rows, int cols, int threshold, int row, int col, vector<bool>& ans){
        int count = 0;
        if ( check(rows, cols, threshold, row, col, ans) ){
            ans[row * cols + col] = true;
            count = 1 + max_moving(rows, cols, threshold, row + 1, col, ans)
                      + max_moving(rows, cols, threshold, row, col + 1, ans)
                      + max_moving(rows, cols, threshold, row - 1, col, ans)
                      + max_moving(rows, cols, threshold, row, col - 1, ans);
        }
        return count;
    }
    bool check(int rows, int cols, int threshold, int row, int col, vector<bool>& ans){
        if( row >= 0 && col >= 0 && row < rows && col < cols && !ans[row * cols + col] && getDigitSum(row, col) <= threshold )
            return true;
        return false;
    }

    int getDigitSum(int row, int col){
        int row_t = 0, col_t = 0;
        while( row ){
            row_t += row % 10;
            row /= 10;
        }
        while( col ){
            col_t += col % 10;
            col /= 10;
        }
        return row_t + col_t;
    }
};