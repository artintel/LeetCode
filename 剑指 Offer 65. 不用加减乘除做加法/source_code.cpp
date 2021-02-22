/*
 * @Author: Mayc
 * @Date: 2021-02-22 13:56:19
 * @LastEditTime: 2021-02-22 14:07:04
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 65. 不用加减乘除做加法\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int add(int a, int b) {
        int sum = 0, carray = 0;
        while( b != 0 ){
            carray = (unsigned int)( a & b ) << 1;
            sum = a ^ b;
            a = sum;
            b = carray;
        }
        return a;
    }
};
