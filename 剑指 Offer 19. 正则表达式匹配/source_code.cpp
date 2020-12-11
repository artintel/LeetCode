class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s.size(); i++){
            for(int j = 1; j <= p.size(); j++){
                if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2];
                    if(i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')){
                        dp[i][j] = (dp[i - 1][j] | dp[i][j]);
                    }
                }
                else if(p[j - 1] != '*'){
                    if(i != 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')){
                        dp[i][j] = (dp[i - 1][j - 1] | dp[i][j]);
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};