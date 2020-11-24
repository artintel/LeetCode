class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        if (nums.size() == 0) return 0;
        if (nums[nums.size() - 1] < target) return nums.size();

        int left = 0, right = n - 1;
        while (left != right) {
            int mid = ((right + left) >> 1);
            if (target <= nums[mid]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};