class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = (int)nums.size();
        int left = 0, right = len - 1;
        if(!len) return -1;
        else if(len == 1) return target == nums[0] ? 0 : -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if(nums[0] <= nums[mid]){
                if(nums[0] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else left = mid + 1;
            }
            else{
                if(target <= nums[len - 1] && nums[mid] < target){
                    left = mid + 1;
                }
                else right = mid - 1;
            }
        }
        return -1;
    }
};
