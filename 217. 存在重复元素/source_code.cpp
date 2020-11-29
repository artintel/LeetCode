class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ans;
        for(int elem : nums){
            if(ans.find(elem) == ans.end()){
                ans.insert(elem);
            }
            else return true;
        }
        return false;
    }
};