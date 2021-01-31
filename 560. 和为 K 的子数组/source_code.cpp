/*
 * @Author: Mayc
 * @Date: 2021-01-31 11:28:38
 * @LastEditTime: 2021-01-31 11:28:46
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\560. 和为 K 的子数组\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for( auto& elem : nums ){
            pre += elem;
            if( mp.find(pre - k) != mp.end() ){
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};