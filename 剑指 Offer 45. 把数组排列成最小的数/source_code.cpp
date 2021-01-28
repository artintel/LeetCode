/*
 * @Author: Mayc
 * @Date: 2021-01-28 13:17:09
 * @LastEditTime: 2021-01-28 13:17:51
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 45. 把数组排列成最小的数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class cmp
{
public:
    bool operator() (const string &a, const string &b)
    {
        return a + b < b + a; // <= 报错 ？ 为什么
    }
};
class Solution {
private:
    vector<string> ans;
public:
    string minNumber(vector<int>& nums) {
        ans.resize(nums.size());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ans[i] = to_string(nums[i]);
        }
        sort(ans.begin(), ans.end(), cmp());
        string result = "";
        for(auto elem : ans){
            result += elem;
        }
        return result;
    }
};