/*
 * @Author: Mayc
 * @Date: 2021-01-26 09:57:19
 * @LastEditTime: 2021-01-26 10:03:36
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\461. 汉明距离\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int hammingDistance(int x, int y) {
        long n = x ^ y;
        long temp = 1;
        int count = 0;
        while( temp <= max(x, y)){
            if( (temp & n) ){
                count++;
            }
            temp <<= 1;
        }
        return count;
    }
};

// 优化
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int temp;
        int count = 0;
        while( n > 0 ){
            temp = n >> 1;
            if( (temp << 1) != n ) count++;
            n >>= 1;
        }
        return count;
    }
};