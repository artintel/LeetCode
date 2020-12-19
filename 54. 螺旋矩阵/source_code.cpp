class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int size_row = matrix.size();//行
        if(size_row == 0) return ans;
        else if(size_row == 1) return matrix[0];
        int size_col = matrix[0].size();//列
        int step_row = size_row - 1;//行步数
        int step_col = size_col;//列步数
        int step = 1;
        int i = 0, j = 0;
        while(step_row >= 0 && step_col >= 0){
            // cout << step_col << " " << step_row << endl;
            if(step == 1){
                int temp = step_col;
                while(temp > 0){
                    ans.emplace_back(matrix[i][j++]);
                    temp--;
                }
                j--;
                i++;
                step_col--;
                step = 2;
            }
            else if (step == 2){
                int temp = step_row;
                while(temp > 0){
                    ans.emplace_back(matrix[i++][j]);
                    temp--;
                }
                i--;
                j--;
                step_row--;
                step = 3;
            }
            else if (step == 3){
                int temp = step_col;
                while(temp > 0){
                    ans.emplace_back(matrix[i][j--]);
                    temp--;
                }
                j++;
                i--;
                step_col--;
                step = 4;
            }
            else if (step == 4){
                int temp = step_row;
                while(temp > 0){
                    ans.emplace_back(matrix[i--][j]);
                    temp--;
                }
                i++;
                j++;
                step_row--;
                step = 1;
            }
        }
        return ans;
    }
};