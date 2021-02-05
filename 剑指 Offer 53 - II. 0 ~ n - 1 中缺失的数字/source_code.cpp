class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while( left <= right ){
            int mid = left + (( right - left ) >> 1);
            if( nums[mid] == mid ){
                left = mid + 1;
            }
            else if( nums[mid] > mid ){
                right = mid - 1;
            }
        }
        return left;
    }
};