class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int temp;
        int n = nums.size();
        int i = 0;
        while( i < n ){
            while( nums[i] != i + 1 ){
                if(nums[i] == nums[nums[i] - 1]) return nums[i];
                temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
            i++;
        }
        return 0;
    }
};