/*
 * @Author: Mayc
 * @Date: 2020-12-28 11:24:17
 * @LastEditTime: 2020-12-28 11:28:02
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\50. Pow(x, n)\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    double pow(double x, int n){
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        if(n > 0){
            if( n % 2 == 1) return x * pow(x, n - 1);
            else return pow(x * x, n / 2);
        }
        else {
            if(n % 2 == -1) {
                n += 1;
                n = -n;
                return 1 / (x * pow(x, n));
            }
            else {
                n /= 2;
                n = -n;
                return 1 / (pow(x * x, n));
            }
        }
    }

    double myPow(double x, int n) {
        if(n == 0) return 1.0000;
        if(x == 0.00000 || x == 1.00000) return x;
        x = pow(x, n);
        return x;
    }
};

# 官方快速幂 + 递归
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

# 官方快速幂 + 迭代
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。