/*
 * @Author: Mayc
 * @Date: 2021-01-20 10:45:07
 * @LastEditTime: 2021-01-20 10:45:15
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 38. 字符串的排列\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    void trace_back(vector<string>& ans, string& temp, vector<int>& flag, const string& s, int& n){
        if(temp.size() == n){
            ans.emplace_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(flag[i] == 1 || (i != 0 && s[i] == s[i - 1] && flag[i - 1] != 1)) continue;
            flag[i] = 1;
            temp.push_back(s[i]);
            trace_back(ans, temp, flag, s, n);
            flag[i] = 0;
            temp.pop_back();
        }
    }

    vector<string> permutation(string s) {
        vector<string> ans;
        int n = s.size();
        vector<int> flag(n, 0);
        string temp = "";
        sort(s.begin(), s.end());
        trace_back(ans, temp, flag, s, n);
        return ans;
    }
};