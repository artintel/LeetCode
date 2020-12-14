class Solution {
public:
    int binarysearch_min(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] >= target) right = mid;
        }
        if(nums[left] == target) return left;
        else return -1;
    }

    int binarysearch_max(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        if(left == right) return left;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
        }
        return nums[left] == target ? left : left - 1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size() == 0) return ans;
        ans[0] = binarysearch_min(nums, target);
        if(ans[0] == -1) return ans;
        ans[1] = binarysearch_max(nums, target);
        return ans;
    }
};