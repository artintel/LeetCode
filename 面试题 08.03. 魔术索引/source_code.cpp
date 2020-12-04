class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == i) return i;
            if(nums[i] < i) i++;
            else i = nums[i];
        }
        return -1;
    }
};