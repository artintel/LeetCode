/*
 * @Author: Mayc
 * @Date: 2021-02-04 13:24:58
 * @LastEditTime: 2021-02-04 13:25:06
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 51. 数组中的逆序对\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    void count_P(vector<int>& nums, vector<int>& ans, int left, int mid, int right, int& count){
        int i = mid, j = right;
        int index = j;
        while( i >= left && j > mid ){
            if( nums[i] > nums[j] ){
                count += j - mid;
                ans[index--] = nums[i--];
            }
            else if( nums[i] <= nums[j] ){
                ans[index--] = nums[j--];
            }
        }
        while( i >= left ){
            ans[index--] = nums[i--];
        }
        while( j > mid ){
            ans[index--] = nums[j--];
        }
        for(int k = right; k >= left; k--){
            nums[k] = ans[k];
        }

        cout << endl;
        return;
    }

    void count_pairs( vector<int>& nums, vector<int>& ans, int left, int right, int& count){
        if(left == right) return;
        int mid = ( left + right ) / 2;
        count_pairs(nums, ans, left, mid, count);
        count_pairs(nums, ans, mid + 1, right, count);
        count_P(nums, ans, left, mid, right, count);
        return;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> ans(nums);
        int count = 0;
        int mid = n / 2;
        count_pairs(nums, ans, 0, n - 1, count);
        for(auto elem : nums){
            cout << elem << " ";
        }
        cout << endl;
        return count;
    }
};