class Solution {
public:
    void swap(int& n, int& m){
        int temp = m;
        m = n;
        n = temp;
    }
    void rotate_outline(vector<vector<int>>& matrix, int end, int first){
        int index = first;
        int gap = end - first - 1;
        for(; index < end; index++){
            swap(matrix[first][index], matrix[index][end]);
            swap(matrix[first][index], matrix[end][end - index + first]);
            swap(matrix[first][index], matrix[end - index + first][first]);
        }
        
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int end = n - 1;
        for(int i = 0; i < n / 2; i++){
            rotate_outline(matrix, end, i);
            end = end - 1;
        }
        return;
    }
};


# 官方
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};