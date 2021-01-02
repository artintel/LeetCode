class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0, b = 0;
        int target = 0;
        int n = nums.size();
        for(int elem : nums){
            target ^= elem;
        }
        int flag = 1;
        while((target & flag) == 0){
            flag <<= 1;
        }
        for(int elem : nums){
            if( elem & flag ) a ^= elem;
            else b ^= elem;
        }
        return vector<int>{a, b};
    }
};
