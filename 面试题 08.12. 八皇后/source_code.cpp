class Solution {
public:

    void trace_back(vector<vector<int>>& ans, vector<int>& temp, vector<int>& flag, const int& n) {
        if (temp.size() == n) {
            ans.emplace_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            int j = 0;
            for( j = 0; j < temp.size(); j++){
                if(max(temp[j], i) - min(temp[j], i) - (temp.size() - j) == 0) break;
            }
            if( j != temp.size() ) continue;
            if (flag[i] == 1) continue;
            flag[i] = 1;
            temp.emplace_back(i);
            trace_back(ans, temp, flag, n);
            temp.pop_back();
            flag[i] = 0;
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> flag(n, 0);
        trace_back(ans, temp, flag, n);
        vector<vector<string>> s;
        vector<string> s_temp;
        int rows = ans.size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < n; j++) {
                string chess(n, '.');
                chess[ans[i][j]] = 'Q';
                s_temp.push_back(chess);
            }
            s.emplace_back(s_temp);
            s_temp.clear();
        }
        return s;
    }
};