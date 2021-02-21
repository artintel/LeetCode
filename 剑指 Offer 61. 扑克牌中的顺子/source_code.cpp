/*
 * @Author: Mayc
 * @Date: 2021-02-21 20:03:24
 * @LastEditTime: 2021-02-21 20:06:18
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 61. 扑克牌中的顺子\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int n = nums.size();
        if( n <= 1 ) return true;
        int count_zero = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if( nums[i] == 0 ) {
                count_zero++;
                continue;
            }
            if( i > 0 && nums[i] != nums[i - 1] + 1 && nums[i - 1] != 0 ){
                while( count_zero > 0 && nums[i] != nums[i - 1] + 1 ){
                    nums[i - 1] += 1;
                    count_zero--;
                }
                if( count_zero == 0 && nums[i] != nums[i - 1] + 1 ) return false;
            }
            if( i > 0 && nums[i] == nums[i - 1] ) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int n = nums.size();
        if( n <= 1 ) return true;
        int count_zero = 0;
        int gap_zero = 0;
        sort(nums.begin(), nums.end());
        if( nums[0] == 0 ) count_zero++;
        for(int i = 1; i < n; i++){
            if( nums[i] == 0 ) {
                count_zero++;
                continue;
            }
            if( nums[i] == nums[i - 1] ) return false;

            if( nums[i - 1] != 0 && nums[i - 1] + 1 != nums[i] ){
                gap_zero = nums[i] - nums[i - 1] - 1;
                if( gap_zero > count_zero ) return false;
                else {
                    count_zero -= gap_zero;
                    gap_zero = 0;
                }
            }
        }
        return true;
    }
};