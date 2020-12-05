class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        int max_real = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i < 2) {
                dp.emplace_back(nums[i]);
                max_real = max(max_real, nums[i]);
                continue;
            }
            int max_temp = 0;
            for(int j = 0; j < i - 1; j++){
                max_temp = max(max_temp, dp[j]);
            }
            dp.emplace_back(max_temp + nums[i]);
            max_real = max(max_real, dp[i]);
        }
        return max_real;
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};