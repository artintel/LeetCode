/*
 * @Author: Mayc
 * @Date: 2021-02-20 13:54:57
 * @LastEditTime: 2021-02-20 13:55:05
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 60. n 个骰子的点数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
private:
    int g_maxValue = 6;
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> pProbabilities(n * g_maxValue + 1, vector<int>(n * g_maxValue + 1, 0));
        int flag = 0;
        for(int i = 1; i <= g_maxValue; i++){
            pProbabilities[flag][i] = 1;
        }
        for(int k = 2; k <= n; ++k){
            for(int i = 0; i < k; ++i){
                pProbabilities[1 - flag][i] = 0;
            }
            for(int i = k; i <= g_maxValue * k; i++){
                pProbabilities[1 - flag][i] = 0;
                for(int j = 1; j <= i && j <= g_maxValue; ++j){
                    pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
                }
            }
            flag = 1 - flag;
        }
        double total = pow((double)g_maxValue, n);
        vector<double> ans;
        int num = 0;
        for(auto elem : pProbabilities[flag]){
            if( num == n)
                ans.emplace_back((double)elem);
            else num++;
        }
        // vector<double> ans(pProbabilities[flag]);
        
        for(auto& elem : ans){
            elem = elem / (double)total;
        }
        return ans;
    }
};