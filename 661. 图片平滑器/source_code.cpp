class Solution {
public:
    int pool(int w, int l, vector<vector<int>>& ans) {
        int sum = 0;
        int count = 0;
        for (int i = w - 1; i <= w + 1; i++) {
            for (int j = l - 1; j <= l + 1; j++) {
                if (ans[i][j] == -1) continue;
                sum += ans[i][j];
                count++;
            }
        }
        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {

        int size_w = M.size();    //rol
        int size_l = M[0].size(); //row
        vector<vector<int>> dp(size_w + 2, vector<int>(size_l + 2, -1));
        for (int i = 1; i <= size_w; i++) {
            for (int j = 1; j <= size_l; j++) {
                dp[i][j] = M[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= size_w; i++) {
            for (int j = 1; j <= size_l; j++) {
                M[i - 1][j - 1] = pool(i, j, dp);
            }
        }

        return M;
    }
};