class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.emplace_back(i + 1);
            }
        }
        return ans;
    }
};