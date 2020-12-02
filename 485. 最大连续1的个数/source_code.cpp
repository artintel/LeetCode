#define ONE true
#define ZERO false
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int temp_count = 0;
        bool status = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 1){
                if(status == ZERO){
                    continue;
                }
                else if (status == ONE){
                    max_count = max(max_count, temp_count);
                    temp_count = 0;
                    status = ZERO;
                }
            }
            else if (status == ZERO){
                temp_count += 1;
                status = ONE;
            }
            else if (status == ONE){
                temp_count += 1;
            }
        }
        return max(max_count, temp_count);
    }
};