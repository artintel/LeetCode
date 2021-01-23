/*
 * @Author: Mayc
 * @Date: 2021-01-23 17:13:32
 * @LastEditTime: 2021-01-23 17:17:01
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 39. 数组中出现次数超过一半的数字\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, votes = 0, count = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 验证 x 是否为众数
        for(int num : nums)
            if(num == x) count++;
        return count > nums.size() / 2 ? x : 0; // 当无众数时返回 0
    }
};