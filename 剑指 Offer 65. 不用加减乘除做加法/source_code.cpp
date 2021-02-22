/*
 * @Author: Mayc
 * @Date: 2021-02-22 13:56:19
 * @LastEditTime: 2021-02-22 13:56:31
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 65. 不用加减乘除做加法\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int add(int a, int b) {
        int sum, carray;
        do{
            sum = a ^ b;
            carray = ( a & b ) << 1;
            a = sum;
            b = carray;
        }while( b != 0 );
        return a;
    }
};
