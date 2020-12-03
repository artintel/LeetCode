class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if((n * m) < (r * c)) return nums;
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> cur;
        for(vector<vector<int>>::iterator it = nums.begin(); it != nums.end(); it++){
            for(int elem : *it){
                cur.emplace_back(elem);
            }
        }
        int k = 0;
        for(int i = 0; i < r; i++){
            temp.resize(0);
            for(int j = 0; j < c; j++){
                temp.emplace_back(cur[k++]);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};