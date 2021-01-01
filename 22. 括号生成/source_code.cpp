/*
 * @Author: Mayc
 * @Date: 2021-01-01 10:11:06
 * @LastEditTime: 2021-01-01 10:11:14
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\22. 括号生成\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    void trace_back(vector<string>& ans, string& cur, int start, int end, int n){
        if(cur.length() == 2 * n){
            ans.push_back(cur);
            return;
        }
        if( start < n ){
            cur.push_back('(');
            trace_back(ans, cur, start + 1, end, n);
            cur.pop_back();
        }
        if( end < start ){
            cur.push_back(')');
            trace_back(ans, cur, start, end + 1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        trace_back( result, current, 0, 0, n );
        return result;
    }
};