/*
 * @Author: Mayc
 * @Date: 2021-02-22 10:17:02
 * @LastEditTime: 2021-02-22 10:17:11
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\438. 找到字符串中所有字母异位词\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n_p = p.size();
        int n_s = s.size();
        vector<int> temp_p(128, 0);
        for(auto elem : p){
            temp_p[elem - 'a']++;
        }
        vector<int> ans;
        if( n_p > n_s ) return ans;
        for(int i = 0; i <= n_s - n_p; i++){
            vector<int> temp(128, 0);
            for(int j = i; j < i + n_p; j++){
                temp[s[j] - 'a']++;
            }
            if( temp == temp_p ) ans.emplace_back(i);
        }
        return ans;
    }
};