/*
 * @Author: Mayc
 * @Date: 2021-01-08 11:16:20
 * @LastEditTime: 2021-01-20 12:35:42
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\78. 子集\source_code.cpp
 * @这是一个漂亮的注释头
 */
// 字典序
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); mask++){
            temp.clear();
            for(int i = 0; i < n; i++){
                if( mask & (1 << i) ) {
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// 递归
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。