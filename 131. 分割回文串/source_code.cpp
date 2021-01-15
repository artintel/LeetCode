/*
 * @Author: Mayc
 * @Date: 2021-01-15 11:02:57
 * @LastEditTime: 2021-01-15 11:03:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\131. 分割回文串\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool is_partition(const string& s, int start, int end){
        while(start < end){
            if(s[start] == s[end]){
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }

    void partition(vector<vector<string>>& ans, const string& s, vector<string>& temp, int start, int& length){
        if(start == length) {
            ans.emplace_back(temp);
            return;
        }
        for(int i = start; i < length; i++){
            if(is_partition(s, start, i)){
                temp.emplace_back(s.substr(start, i - start + 1));
                partition(ans, s, temp, i + 1, length);
                temp.pop_back();
            }
            else{
                continue;
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> temp;
        if(n <= 0) return ans;
        partition(ans, s, temp, 0, n);
        return ans;
    }
};