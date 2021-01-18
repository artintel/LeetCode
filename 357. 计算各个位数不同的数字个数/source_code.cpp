/*
 * @Author: Mayc
 * @Date: 2021-01-18 08:49:40
 * @LastEditTime: 2021-01-18 09:33:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\357. 计算各个位数不同的数字个数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void trace_back(vector<int>& flag, int start, int& count, const int& n) {
        if (start == n) {
            count++;
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (flag[i] == 1) continue;
            flag[i] = 1;
            trace_back(flag, start + 1, count, n);
            flag[i] = 0;
        }
        return;
    }

    int countNumbersWithUniqueDigits(int n) {
        vector<int> flag(10, 0);
        if (n == 0) return 1;
        int count = 10;
        int N = n - 1;
        while (N--) {
            for (int i = 1; i < 10; i++) {
                flag[i] = 1;
                trace_back(flag, N + 1, count, n);
                flag[i] = 0;
            }
        }
        return count;
    }
};

//组合数学
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n == 0 ) return 1;
        if( n == 1 ) return 10;
        vector<int> dp(n, 0);
        dp[0] = 9;
        for(int i = 1; i < n; i++){
            if(i == 1)
                dp[i] = dp[i - 1] * (10 - i) + dp[i - 1];
            else dp[i] = (dp[i - 1] - dp[i - 2]) * (10 - i) + dp[i - 1];
        }
        return dp[n - 1] + 1;
    }
};