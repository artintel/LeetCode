/*
 * @Author: Mayc
 * @Date: 2021-02-18 15:24:32
 * @LastEditTime: 2021-02-18 15:24:42
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 58 - II. 左旋转字符串\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        string ans;
        for(int i = s.size() - 1; i >= 0; i--){
            ans += s[i];
        }
        return ans;
    }
};