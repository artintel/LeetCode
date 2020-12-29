/*
 * @Author: Mayc
 * @Date: 2020-12-29 08:23:27
 * @LastEditTime: 2020-12-29 08:24:26
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\69. x的平方根\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        if(x == 0) return x;
        int i = 0, j = x;
        long long mid;
        while(j - i > 1){
            mid = (i + j) / 2;
            if( mid * mid == x) return mid;
            else if(mid * mid > x){
                j = mid;
            }
            else i = mid;
        }
        return i;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        if(x == 0) return x;
        int i = 0, j = x;
        long long mid;
        while(i <= j){
            mid = (i + j) / 2;
            if( mid * mid == x) return mid;
            else if(mid * mid > x){
                j = mid - 1;
            }
            else i = mid + 1;
        }
        return j;
    }
};