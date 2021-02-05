/*
 * @Author: Mayc
 * @Date: 2021-02-05 11:19:59
 * @LastEditTime: 2021-02-05 11:23:01
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\739. 每日温度\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            int j = i + 1;
            while(j < n){
                if( T[i] < T[j] ){
                    dp[i] = j - i;
                    break;
                }
                if( dp[j] != 0 ) j = j + dp[j];
                else break;
            }
            if( dp[i] == -1 ) dp[i] = 0;
        }
        return dp;
    }
};

// 栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};