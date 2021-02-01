/*
 * @Author: Mayc
 * @Date: 2021-02-01 13:58:29
 * @LastEditTime: 2021-02-01 14:18:10
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 48. 最长不含重复子字符串\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if( n == 0 ) return 0;
        vector<int> dp(n, 1);
        int MAX = 1;
        for(int i = 1; i < n; i++){
            int j = i - 1;
            for(; j >= 0 && j >= i - dp[i - 1]; j-- ){
                if( s[j] == s[i] ) break;
            }
            if( j < i - dp[i - 1] ) dp[i] = dp[i - 1] + 1;
            else{
                dp[i] = i - j;
            }
            MAX = max( MAX, dp[i] );
        }
        return MAX;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curLength = 0;
        int maxLength = 0;
        int n = s.size();
        if( n == 0 ) return 0; 
        unordered_map<char, int> dp;
        for(int i = 0; i < n; i++){
            if( dp[s[i]] == 0 || i - dp[s[i]] + 1 > curLength ){
                curLength++;
            }
            else{
                if( curLength > maxLength ){
                    maxLength = curLength;
                }
                curLength = i - dp[s[i]] + 1;
            }
            dp[s[i]] = i + 1; // 因为初始化为0, 通过 +1 操作避免 0 位置的误判
        }
        maxLength = curLength > maxLength ? curLength : maxLength;
        return maxLength;
    }
};