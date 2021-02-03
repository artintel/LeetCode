/*
 * @Author: Mayc
 * @Date: 2021-02-03 16:51:26
 * @LastEditTime: 2021-02-03 16:51:49
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 50. 第一个只出现一次的字符\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> ans(26, 0);
        int n = s.size();
        if( n <= 0 ) return ' ';
        for(int i = 0; i < s.size(); i++){
            ans[ s[i] - 'a' ]++;
        }
        for(int i = 0; i < n; i++){
            if(  ans[s[i] - 'a'] == 1 ) return s[i];
        }
        return ' ';
    }
};