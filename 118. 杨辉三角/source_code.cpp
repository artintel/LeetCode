class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> temp;
        for(int i = 0; i < numRows; i++){
            temp.resize(0);
            int cur = 0;
            while(cur <= i){
                if(cur == 0 || cur == i){
                    temp.emplace_back(1);
                    cur++;
                }
                else{
                    temp.emplace_back(ans[i - 1][cur - 1] + ans[i - 1][cur]);
                    cur++;
                }
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};