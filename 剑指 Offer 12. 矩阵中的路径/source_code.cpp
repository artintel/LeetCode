/*
 * @Author: Mayc
 * @Date: 2020-12-30 14:41:36
 * @LastEditTime: 2020-12-30 14:42:14
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 12. 矩阵中的路径\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        vector<bool> ans(rows * cols, false);
        int row, col;
        int Length = 0;
        for(row = 0; row < rows; row++){
            for(col = 0; col < cols; col++){
                if(exist_path(board, word, rows, cols, row, col, Length, ans) == true) return true;
            }
        }
        return false;
    }
    bool exist_path(vector<vector<char>>& board, string word,int rows,int cols,int row,int col, int& Length, vector<bool>& ans){
        
        if(word[Length] == '\0') return true;
        bool flag = false;

        if( col >= 0 && col < cols && row >= 0 && row < rows && word[Length] == board[row][col] && ans[row * cols + col] != true ){
            Length++;
            ans[row * cols + col] = true;
            flag = exist_path(board, word, rows, cols, row + 1, col, Length, ans) 
                || exist_path(board, word, rows, cols, row, col + 1, Length, ans)
                || exist_path(board, word, rows, cols, row - 1, col, Length, ans) 
                || exist_path(board, word, rows, cols, row, col - 1, Length, ans);
            if(flag == false){
                --Length;
                ans[row * cols + col] = false;
            }
        }

        return flag;

    }
};