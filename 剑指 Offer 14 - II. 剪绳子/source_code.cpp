/*
 * @Author: Mayc
 * @Date: 2021-01-01 14:06:20
 * @LastEditTime: 2021-01-01 14:07:39
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 14 - II. 剪绳子\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int cuttingRope(int n) {
        if( n < 2 ) return 0;
        if( n == 2 ) return 1;
        if( n == 3 ) return 2;
        int timesOf3 = n / 3;

        if( n - timesOf3 * 3 == 1 ) timesOf3--;

        int timesOf2 = ( n - timesOf3 * 3 ) / 2;
        long long result_3 = 1;
        long long result_2 = 1;
        for(int i = 1; i <= timesOf3; i++){
            result_3 = 3 * result_3 % 1000000007;
        }
        for(int j = 1; j <= timesOf2; j++){
            result_2 = 2 * result_2 % 1000000007;
        }

        return (int)result_2 * result_3 % 1000000007;
    }
};