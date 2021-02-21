class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) return 0;
        vector<int> dp(n, 1);
        int max_length = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if( nums[i] > nums[j] ){
                    dp[i] = max( dp[i], dp[j] + 1 );
                    max_length = max( dp[i], max_length );
                }
            }
        }
        return max_length;
    }
};