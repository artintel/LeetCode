class Solution {
public:
    int MIN(int a, int b){
        int A, B;
        A = a < 0 ? -a : a;
        B = b < 0 ? -b : b;
        return A < B ? a : b;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = INT_MAX;
        for(int first = 0; first < nums.size(); first++){
            if(result == 0) break;
            if(first > 0 && nums[first - 1] == nums[first]) continue;
            for(int third = nums.size() - 1; third > first + 1; third--){
                if (result == 0) break;
                if(third != nums.size() - 1 && nums[third + 1] == nums[third]) continue;
                int second = first + 1;
                while(second < third){
                    result = MIN(target - (nums[first] + nums[second] + nums[third]), result);
                    second++;
                }
            }
        }
        return target - result;
    }
};