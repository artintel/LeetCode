/*
 * @Author: Mayc
 * @Date: 2021-01-01 13:33:29
 * @LastEditTime: 2021-01-01 13:47:49
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 14 - I. 剪绳子\source_code.cpp
 * @这是一个漂亮的注释头
 */

// 动态规划
class Solution {
public:
    int cuttingRope(int n) {
        if( n < 2 ) return 0;
        if( n == 2 ) return 1;
        if( n == 3 ) return 2;

        vector<int> products(n + 1, 0);
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        int max;
        for(int i = 4; i <= n; i++){
            max = 0;
            for( int j = 1; j <= i / 2; j++ ){
                int product = products[j] * products[i - j];
                if(max < product) max = product;
                products[i] = max;
            }
        }

        max = products[n];
        return max;
    }
};

// 贪心算法
class Solution {
public:
    int cuttingRope(int n) {
        if ( n < 2 ) return 0;
        if ( n == 2 ) return 1;
        if ( n == 3 ) return 2;
        int timersOf3 = n / 3;
        if(n - timersOf3 * 3 == 1) timersOf3 -= 1;
        int timersOf2 = ( n - timersOf3 * 3 ) / 2;
        return (int)(pow(3, timersOf3)) * (int)(pow(2, timersOf2));
    }
};