/*
 * @Author: Mayc
 * @Date: 2021-02-21 21:03:01
 * @LastEditTime: 2021-02-21 21:03:19
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 62. 圆圈中最后剩下的数字\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int lastRemaining(int n, int m) {
        if( n < 1 || m < 1 ) return -1;
        int last = 0;
        for(int i = 2; i <= n;i++){
            last = ( last + m ) % i;
        }
        return last;
    }
};