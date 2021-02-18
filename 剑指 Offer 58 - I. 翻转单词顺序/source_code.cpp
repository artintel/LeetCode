/*
 * @Author: Mayc
 * @Date: 2021-02-18 15:15:58
 * @LastEditTime: 2021-02-18 15:16:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 58 - I. 翻转单词顺序\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans;
        stack<string> S;
        string temp;
        int flag = 0;
        int i = 0;
        while( i < n ){
            if( flag == 0 ){
                if( s[i] == ' ' ) {
                    i++;
                    continue;
                }
                temp += s[i];
                flag = 1;
            }
            else if ( flag == 1 ){
                if( s[i] == ' '){
                    S.push( temp );
                    temp = "";
                    flag = 0;
                }
                else temp += s[i];
            }
            i++;
        }
        if( temp.size() != 0 ) S.push( temp );
        while( !S.empty() ){
            ans += S.top();
            S.pop();
            if( !S.empty() ) ans += ' ';
        }
        return ans;
    }
};