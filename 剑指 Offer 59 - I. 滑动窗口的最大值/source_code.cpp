/*
 * @Author: Mayc
 * @Date: 2021-02-19 13:59:44
 * @LastEditTime: 2021-02-19 13:59:55
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 59 - I. 滑动窗口的最大值\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        if(n == 0) return ans;
        deque<int> temp;
        for(int i = 0; i < k && i < n; i++){
            while(!temp.empty() && nums[i] >= nums[temp.back()]){
                temp.pop_back();
            }
            temp.push_back(i);
        }
        for(int i = k; i < n; i++){
            ans.push_back(nums[temp.front()]);
            while(!temp.empty() && nums[i] >= nums[temp.back()]){
                temp.pop_back();
            }
            if( !temp.empty() && temp.front() <= (i - k) ){
                temp.pop_front();
            }
            temp.push_back(i);
        }
        ans.push_back(nums[temp.front()]);
        return ans;
    }
};