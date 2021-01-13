/*
 * @Author: Mayc
 * @Date: 2021-01-13 09:38:10
 * @LastEditTime: 2021-01-13 09:38:20
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\90. 子集 II\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    void trace_back(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, vector<bool>& flag, int start, int& length){
        if(start == length) return;
        for(int i = start; i < length; i++){
            if( (i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == false) || flag[i] == true ) continue;
            else if( flag[i] == false ){
                flag[i] = true;
                temp.emplace_back(nums[i]);
                ans.emplace_back(temp);
                trace_back(ans, temp, nums, flag, i + 1, length);
                flag[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.emplace_back(temp);
        int n = nums.size();
        if(n == 0) return ans;
        vector<bool> flag(n, false);
        sort(nums.begin(), nums.end());
        trace_back(ans, temp, nums, flag, 0, n);
        return ans;
    }
};