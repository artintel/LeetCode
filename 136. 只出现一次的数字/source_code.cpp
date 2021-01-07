/*
 * @Author: Mayc
 * @Date: 2021-01-07 08:28:39
 * @LastEditTime: 2021-01-07 08:33:35
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\136. 只出现一次的数字\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i += 2){
            if(nums[i] != nums[i - 1]) return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};

// 位运算
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++ ) nums[i] ^= nums[i - 1];
        return nums[nums.size() - 1];
    }
};