class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxnum = nums[0];
        int minnum = nums[n - 1];
        int left = -1;
        int right = -1;
        for(int i = 1; i < n; i++){
            if(nums[i] < maxnum){
                right = i + 1;
            }
            maxnum = max(maxnum, nums[i]);
        }
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] > minnum){
                left = i;
            }
            minnum = min(minnum, nums[i]);
        }
        // cout << right << " " << left << endl;
        return right - left;
    }
};