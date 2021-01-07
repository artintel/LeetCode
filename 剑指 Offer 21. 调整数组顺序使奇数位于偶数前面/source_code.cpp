/*
 * @Author: Mayc
 * @Date: 2021-01-07 12:39:03
 * @LastEditTime: 2021-01-07 12:39:11
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 21. 调整数组顺序使奇数位于偶数前面\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int temp;
        int start = 0, end = nums.size() - 1;
        while(start < end){
            while(start < end && ( nums[start] & 0x01 ) == 1 ) start++;
            while(start < end && ( nums[end] & 0x01 ) == 0 ) end--;
            if( start < end ) swap(nums[start], nums[end]);
        }
        return nums;
    }
};