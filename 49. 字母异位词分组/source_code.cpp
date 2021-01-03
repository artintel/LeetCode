/*
 * @Author: Mayc
 * @Date: 2021-01-03 11:30:46
 * @LastEditTime: 2021-01-03 11:30:54
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\49. 字母异位词分组\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};