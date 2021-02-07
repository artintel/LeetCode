/*
 * @Author: Mayc
 * @Date: 2021-02-07 13:50:06
 * @LastEditTime: 2021-02-07 14:13:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\221. 最大正方形\source_code.cpp
 * @这是一个漂亮的注释头
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_edge = 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                if(matrix[i - 1][j - 1] == '1'){
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    max_edge = max(max_edge, dp[i][j]);
                }
            }
        }
        return max_edge * max_edge;
    }
};

class Solution {
public:

    vector<vector<char>> group( const int& _size ){
        vector<vector<char>> g(_size, vector<char> (_size, '1'));
        return g;
    }

    bool map_edge( vector<vector<char>>& g, vector<vector<char>>& matrix, const int& row, const int& col, const int& edge ){
        int temp_i = edge + row;
        int temp_j = edge + col;
        for(int i = row, i_g = 0; i < temp_i, i_g < edge; i++, i_g++ ){
            for(int j = col, j_g = 0; j < temp_j, j_g < edge; j++, j_g++){
                if( g[i_g][j_g] != matrix[i][j] ) {
                    return false;
                }
            }
        }
        return true;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int min_edge = min( rows, cols );
        int count = 0;
        int edge = 1;
        int flag = 0;
        vector<vector<char>> g;
        while( edge <= min_edge ){
            g = group(edge);
            for(int i = 0; i <= rows - edge; i += 1){
                for(int j = 0; j <= cols - edge; j += 1){
                    if( map_edge(g, matrix, i, j, edge) ){
                        flag = 1;
                        cout << "edge: " << edge << endl;
                        count = edge;
                        break;
                    }
                }
                if( flag == 1 ){
                    flag = 0;
                    break;
                }
            }
            flag = 0;
            edge++;
        }
        return count * count;
    }
};