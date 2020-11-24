class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int pre = 0, behind = 0;
        while(behind < nums.size()){
            if(nums[behind] != val) 
                nums[pre++] = nums[behind];
            behind++;
        }
        // nums.resize(pre);
        return pre;
    }
};