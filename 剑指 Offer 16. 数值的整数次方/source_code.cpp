/*
 * @Author: Mayc
 * @Date: 2021-01-03 15:29:27
 * @LastEditTime: 2021-01-03 15:29:35
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 16. 数值的整数次方\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    double Pow(double x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        double result;
        result = Pow(x, n >> 1);
        result *= result;
        if( (n & 0x1) == 1 )
            result *= x;
        return result;
    }
    double myPow(double x, int n) {
        double abs_x = x;
        int flag_x = 0;
        if(x < 0) {
            abs_x = -x;
            flag_x = 1;
        }
        long long abs_n = n;
        int flag_n = 0;
        if(abs_n < 0) {
            abs_n = -abs_n;
            flag_n = 1;
        }
        double result = Pow(abs_x, abs_n);
        if(flag_x == 1 && (n & 0x1) == 1) result = -result;
        if(flag_n == 1) result = 1.0 / result;
        return result;
    }
};