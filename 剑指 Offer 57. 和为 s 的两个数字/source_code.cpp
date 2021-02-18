/*
 * @Author: Mayc
 * @Date: 2021-02-18 14:08:23
 * @LastEditTime: 2021-02-18 14:08:34
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 57. 和为 s 的两个数字\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> ans;
        while( i < j ){
            if( nums[i] + nums[j] == target ) {
                ans.emplace_back( nums[i] );
                ans.emplace_back( nums[j] );
                return ans;
            }
            if( nums[i] + nums[j] > target ) j--;
            else i++;
        }
        return ans;
    }
};