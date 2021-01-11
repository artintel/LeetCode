/*
 * @Author: Mayc
 * @Date: 2021-01-11 18:01:49
 * @LastEditTime: 2021-01-11 18:03:21
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\79. 单词搜索\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    bool trace_back(vector<vector<char>>& board, string& word, vector<bool>& flag, int row, int col, int& rows, int& cols, int length, int& n){
        if(length == n) return true;
        if(row < 0 || col < 0 || row >= rows || col >= cols || flag[row * cols + col] == true || board[row][col] != word[length]) return false;
        flag[row * cols + col] = true;
        length++;
        if(trace_back(board, word, flag, row + 1, col, rows, cols, length, n) ||
                trace_back(board, word, flag, row - 1, col, rows, cols, length, n) ||
                trace_back(board, word, flag, row, col + 1, rows, cols, length, n) ||
                trace_back(board, word, flag, row, col - 1, rows, cols, length, n))
                return true;
        flag[row * cols + col] = false;
        length--;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<bool> flag(m * n, false);
        int length = 0;
        int Length = word.length();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(trace_back(board, word, flag, i, j, m, n, 0, Length)){
                    return true;
                }
            }
        }
        return false;
    }
};