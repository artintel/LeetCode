/*
 * @Author: Mayc
 * @Date: 2021-02-05 13:11:55
 * @LastEditTime: 2021-02-05 13:12:01
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 53 - I. 在排序数组中查找数字\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if( nums[mid] >= target ){
                j = mid - 1;
            }
            else i = mid + 1;
        }
        int count = 0;
        for(int k = i; k < n; k++){
            if( nums[k] == target ){
                count++;
                continue;
            }
            if( nums[k] > target ) break;
        }
        return count;
    }
};