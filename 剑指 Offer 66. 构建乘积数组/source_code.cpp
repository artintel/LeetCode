/*
 * @Author: Mayc
 * @Date: 2021-02-22 14:14:21
 * @LastEditTime: 2021-02-22 14:14:36
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 66. 构建乘积数组\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        if( n <= 0 ) return ans;
        ans.resize(n, 0);
        vector<int> left(n,1);
        vector<int> right(n, 1);
        for(int i = 1; i < n; i++){
            left[i] = a[i - 1] * left[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            right[i] = a[i + 1] * right[i + 1];
        }
        for(int i = 0; i < n; i++){
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};