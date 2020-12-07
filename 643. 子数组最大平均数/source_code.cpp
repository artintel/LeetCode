class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        int Max = sum;
        for(int i = k; i < nums.size(); i++){
            Max = Max - nums[i - k] + nums[i];
            sum = max(Max, sum);
        }
        return (double)sum / k;
    }
};