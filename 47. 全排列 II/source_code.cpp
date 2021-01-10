/*
 * @Author: Mayc
 * @Date: 2021-01-10 12:01:21
 * @LastEditTime: 2021-01-10 12:01:29
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\47. 全排列 II\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, vector<bool>& flag, int n, int depth){
        if( depth == n ) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if( flag[i] == true || i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == false ) continue;
            temp.push_back(nums[i]);
            flag[i] = true;
            dfs(nums, ans, temp, flag, n, depth + 1);
            temp.pop_back();
            flag[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        vector<bool> flag(n, false);
        dfs(nums, ans, temp, flag, n, 0);
        return ans;
    }
};