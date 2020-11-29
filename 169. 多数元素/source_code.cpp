class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ans;
        int max_elem;
        int max = 0;
        for(auto elem : nums){
            if(ans.find(elem) == ans.end()){
                ans[elem] = 1;
            }
            else{
                ans[elem] += 1;
            }
            if(ans[elem] > max){
                max = ans[elem];
                max_elem = elem;
                if(max > (nums.size() >> 1 )) break;
            }
        }
        return max_elem;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() >> 1];
    }
};