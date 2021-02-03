class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDictSet = unordered_set<string>();
        for(auto elem : wordDict){
            wordDictSet.insert(elem);
        }

        auto dp = vector<int>( s.size() + 1 );
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if( dp[j] && wordDictSet.find( s.substr(j, i - j) ) != wordDictSet.end() ){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
