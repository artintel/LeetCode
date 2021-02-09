class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ans(32, 0);
        for(int i = 0; i < nums.size(); i++){
            long bitmap = 1;
            for(int j = 31; j >= 0; j--){
                int bit = nums[i] & bitmap;
                if( bit ) ans[j] += 1;
                bitmap = bitmap << 1;
            }
        }
        int result = 0;
        for(int i = 0; i < 32; i++){
            result <<= 1;
            result += ans[i] % 3;
        }
        return result;
    }
};