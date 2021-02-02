/*
 * @Author: Mayc
 * @Date: 2021-02-02 13:08:52
 * @LastEditTime: 2021-02-02 13:14:16
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\238. 除自身以外数组的乘积\source_code.cpp
 * @这是一个漂亮的注释头
 */

// 时间复杂度 O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int temp = 1;
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n ,1);
        for(int i = 0; i < n; i++){
            left[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for(int i = n - 1; i >= 0; i--){
            right[i] = temp;
            temp *= nums[i];
        }
        for(int i = 0; i < n; i++){
            output.emplace_back( left[i] * right[i] );
        }
        return output;
    }
};

// 空间夫再度 O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        int n = nums.size();
        vector<int> output(n);
        for(int i = 0; i < n; i++){
            output[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for(int i = n - 1; i >= 0; i--){
            output[i] = temp * output[i];
            temp *= nums[i];
        }
        return output;
    }
};