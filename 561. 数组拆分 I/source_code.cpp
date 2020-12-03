class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i += 2){
            count += nums[i];
        }
        return count;
    }
};