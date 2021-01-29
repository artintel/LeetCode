/*
 * @Author: Mayc
 * @Date: 2021-01-29 09:46:15
 * @LastEditTime: 2021-01-29 09:48:56
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\215. 数组中的第 K 个最大元素\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    int partition( vector<int>& nums, int start, int end, const int& k, const int& n ){
        int left = start, right = end;
        int temp = nums[left];
        while( left < right ){
            while( left < right && nums[right] >= temp ){
                right--;
            }
            if( left < right ){
                nums[left] = nums[right];
                left++;
            }
            while( left < right && nums[left] < temp ){
                left++;
            }
            if( left < right ){
                nums[right] = nums[left];
                right--;
            }
        }
        nums[left] = temp;
        if( left + k == n )
            return nums[left];
        else if( left + k < n ){
            return partition( nums, left + 1, end, k, n );
        }
        else return partition( nums, start, left - 1, k, n );
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if( n <= 0 || k > n ) return -1;
        int start = 0, end = n - 1;
        return partition(nums, start, end, k, n );
    }
};