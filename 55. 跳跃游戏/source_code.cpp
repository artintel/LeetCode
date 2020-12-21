class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 && nums[0] < 0) return false;
        else if(n == 0 || (n == 1 && nums[0] > 0)) return true;
        int end_of_position = nums[0];
        for(int i = 0; i <= end_of_position && i < n; i++){
            if(end_of_position >= n - 1) return true;
            if(i + nums[i] > end_of_position){
                end_of_position = i + nums[i];
            }
        }
        return false;
    }
};