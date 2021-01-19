/*
 * @Author: Mayc
 * @Date: 2021-01-19 09:02:24
 * @LastEditTime: 2021-01-19 09:02:32
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\20. 有效的括号\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        int n = s.size();
        if( n < 2 ) return false;
        for(int i = 0; i < n; i++){
            if(ans.empty()){
                ans.push(s[i]);
            }
            else{
                if((ans.top() == '(' && s[i] == ')') || (ans.top() == '{' && s[i] == '}') || (ans.top() == '[' && s[i] == ']')){
                    ans.pop();
                }
                else{
                    ans.push(s[i]);
                }
            }
        }
        if(ans.empty()) return true;
        else return false;
    }
};