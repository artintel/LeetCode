class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k == 0) return false;
        unordered_set<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(ans.find(nums[i]) == ans.end()){
                if(ans.size() < k)
                    ans.insert(nums[i]);
                else if(ans.size() == k){
                    ans.erase(nums[i - k]);
                    ans.insert(nums[i]);
                }
            }
            else return true;
        }
        return false;
    }
};