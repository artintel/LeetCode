class Solution {
public:
    int Sum(int len){
        return (len * (len + 1) / 2);
    }
    int missingNumber(vector<int>& nums) {
        int n = 0;
        int sum = 0;
        for(int elem : nums){
            n++;
            sum += elem;
        }
        return (Sum(n) - sum);
    }
};