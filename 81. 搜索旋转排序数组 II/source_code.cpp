/*
 * @Author: Mayc
 * @Date: 2020-12-30 10:27:18
 * @LastEditTime: 2020-12-30 10:27:27
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\81. 搜索旋转排序数组 II\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right){ 
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            if(nums[left] == nums[mid]) {
                left++;
                continue;
            }
            if(nums[right] == nums[mid]){
                right--;
                continue;
            }
            if (nums[left] < nums[mid]) {
                if (nums[mid] > target && nums[left] <= target) right = mid - 1;
                else left = mid + 1;
            } 
            else {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};