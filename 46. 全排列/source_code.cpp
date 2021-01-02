/*
 * @Author: Mayc
 * @Date: 2021-01-02 10:43:56
 * @LastEditTime: 2021-01-02 10:44:33
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\46. 全排列\source_code.cpp
 * @这是一个漂亮的注释头
 */

// dfs
class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& ans,vector<bool>& flag, vector<int>& temp, int length, int depth){
        if( depth == length ) {
            ans.emplace_back(temp);
            return;
        }
        for(int i = 0; i < length; i++){
            if( flag[i] == true ) continue;
            temp.emplace_back(nums[i]);
            flag[i] = true;
            dfs(nums, ans, flag, temp, length, depth + 1);
            temp.pop_back();
            flag[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int length = nums.size();
        vector<bool> flag(length, false);
        dfs(nums, ans, flag, temp, length, 0);
        return ans;
    }
};

// 回溯
class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。