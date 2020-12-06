class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        stack<char> S;
        for(char elem : s){
            S.push(elem);
        }
        for(int i = t.length() - 1; i >= 0; i--){
            if(t[i] == S.top()){
                S.pop();
                if(S.size() == 0) break;
            }
        }
        return S.size() == 0;
    }
};


# dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= t.length(); j++){
                if(s[i - 1] != t[j - 1]){
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                else dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
        return dp[s.length()][t.length()] == s.length();
    }
};