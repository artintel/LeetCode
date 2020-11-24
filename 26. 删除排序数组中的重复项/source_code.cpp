class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        int left = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[left] != nums[i]) {
                nums[left + 1] = nums[i];
                left++;
            }
        }
        nums.resize(left + 1);
        return left + 1;
    }
};