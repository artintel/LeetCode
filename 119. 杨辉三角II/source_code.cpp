class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i = 0; i <= rowIndex; i++){
            temp.resize(0);
            int size = 0;
            while(size < i + 1){
                if(size == 0 || size == i) temp.emplace_back(1);
                else{
                    temp.emplace_back(ans[i - 1][size - 1] + ans[i - 1][size]);
                }
                size++;
            }
            ans.emplace_back(temp);
        }
        return temp;
    }
};

# 优化
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }

        return dp;
    }
};
作者：jyj407
链接：https://leetcode-cn.com/problems/pascals-triangle-ii/solution/zhong-gui-zhong-ju-dong-tai-gui-hua-kong-jian-bu-y/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。