/*
 * @Author: Mayc
 * @Date: 2021-01-12 09:25:14
 * @LastEditTime: 2021-01-12 09:55:59
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\89. 格雷编码\source_code.cpp
 * @这是一个漂亮的注释头
 */
// 回溯
class Solution1 {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        unordered_set<int> st;
        st.insert(0);
        int N = pow(2, n);
        dfs(n, N, res, st);
        return res;
    }

private:
    bool dfs(int n, int N, vector<int>& res, unordered_set<int>& st) {
        if (res.size() == N) {
            return true;
        }

        auto last = res.back();
        for (int i = 0; i < n; i++) {
            auto next = last;
            next ^= (0x1 << i);
            if (st.count(next)) {
                continue;
            }
            res.push_back(next);
            st.insert(next);
            if (dfs(n, N, res, st)) {
                return true;
            }
        }

        return false;
    }

};

作者：jyj407
链接：https://leetcode-cn.com/problems/gray-code/solution/zhong-gui-zhong-ju-hui-su-suan-fa-by-jyj407-4/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 公式
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.emplace_back(0);
        int head = 1;
        for (int i = 0; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(head + res[j]);
            head <<= 1;
        }
        return res;
    }
};

作者：jyd
链接：https://leetcode-cn.com/problems/gray-code/solution/gray-code-jing-xiang-fan-she-fa-by-jyd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。