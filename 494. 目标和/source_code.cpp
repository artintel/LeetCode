class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if( n <= 0 ) return 0;
        vector<int> dp(2001, 0);
        dp[nums[0] + 1000] = 1;
        dp[-nums[0] + 1000] += 1;
        for(int i = 1; i < n; i++){
            vector<int> next(2001, 0);
            for(int sum = -1000; sum <= 1000; sum++){
                if(dp[sum + 1000] > 0){
                    next[sum + 1000 + nums[i]] += dp[sum + 1000];
                    next[sum + 1000 - nums[i]] += dp[sum + 1000];
                }
            }
            dp = next;
        }
        return S > 1000 ? 0 : dp[S + 1000];
    }
};