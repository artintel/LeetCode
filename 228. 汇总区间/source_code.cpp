class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int pre = 0, cur = 0;
        vector<string> ans;
        if(nums.size() == 0) return ans;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                cur = i;
            }
            else{
                if(cur != pre){
                    ans.emplace_back(to_string(nums[pre]) + "->" + to_string(nums[cur]));
                }
                else{
                    ans.emplace_back(to_string(nums[pre]));
                }
                pre = i;
                cur = i;
            }
        }
        if(pre == cur) ans.emplace_back(to_string(nums[pre]));
        else ans.emplace_back(to_string(nums[pre]) + "->" + to_string(nums[cur]));
        return ans;
    }
};