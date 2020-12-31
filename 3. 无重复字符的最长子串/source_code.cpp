/*
 * @Author: Mayc
 * @Date: 2020-12-31 09:01:20
 * @LastEditTime: 2020-12-31 09:01:30
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\3. 无重复字符的最长子串\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        vector<int> dp(n + 1, 1);
        int MAX = 0;
        for(int i = 1; i <= n ; i++){
            if( i == 1 ) {
                MAX = max(MAX, dp[i]);
                continue;
            }
            int interval = dp[i - 1];
            int j = i - 1;
            while(interval > 0){
                if(s[i - 1] != s[j - 1]){
                    j--;
                    interval--;
                }
                else break;
            }
            if(interval == 0) dp[i] = dp[i - 1] + 1;
            else dp[i] = dp[i - 1] - interval + 1;
            MAX = max(MAX, dp[i]);
        }
        return MAX;
    }
};