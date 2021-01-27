/*
 * @Author: Mayc
 * @Date: 2021-01-27 16:06:00
 * @LastEditTime: 2021-01-27 16:06:10
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 43. 1~n整数中1出现的次数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1;
        int res = 0;
        int high = n / 10, cur = n % 10, low = 0;
        while( high != 0 || cur != 0 ){
            if( cur == 0 ) res += high * digit;
            else if( cur == 1 ) res += high * digit + low + 1;
            else res += (high + 1) * digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};
