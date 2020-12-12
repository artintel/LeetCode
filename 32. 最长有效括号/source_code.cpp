class Solution {
public:
    bool match(int first, int second, string s) {
        stack<char> ans;
        for (int i = first; i <= second; i++) {
            if (s[i] == '(') ans.push('(');
            else {
                if (!ans.empty()) {
                    ans.pop();
                }
                else return false;
            }
        }
        
        return ans.empty() ? true : false;
    }
    int longestValidParentheses(string s) {
        int MAX = 0;
        int first = 0, len = s.length(), second;
        if (len % 2 == 0) {
            second = len - 1;
        }
        else second = len - 2;
        while (second - first > 0) {
            int SECOND = second;
            int FIRST = first;
            while (SECOND < len) {
                if (match(FIRST, SECOND, s) == true) {
                    MAX = SECOND - FIRST + 1;
                    break;
                }
                FIRST += 1;
                SECOND += 1;
            }
            if (MAX != 0) break;
            second -= 2;
        }
        return MAX;
    }
};

#DP动态规划
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length() + 1, 0);
        for(int i = 1; i <= s.length(); i++){
            if(s[i - 1] == ')' && (i - dp[i - 1] - 2) >= 0){
                if(s[i - dp[i - 1] - 2] == '('){
                    dp[i] = 2 + dp[i - 1] + dp[i - dp[i - 1] - 2];
                }
            }
        }
        int Max = -1;
        for(auto elem : dp){
            Max = max(Max, elem);
        }
        return Max;
    }
};

#stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> ans;
        ans.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                ans.push(i);
            } else {
                ans.pop();
                if (ans.empty()) {
                    ans.push(i);
                } else {
                    maxans = max(maxans, i - ans.top());
                }
            }
        }
        return maxans;
    }
};