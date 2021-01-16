/*
 * @Author: Mayc
 * @Date: 2021-01-16 09:20:27
 * @LastEditTime: 2021-01-16 09:20:36
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\1688. 比赛中的配对此处\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int trace_back(const int& n ){
        if( n <= 2 ) return 1;
        if( n % 2 == 1 ){
            return n / 2 + trace_back( n / 2 + 1);
        }
        else return n / 2 + trace_back( n / 2 );
    }

    int numberOfMatches(int n) {
        if(n <= 1) return 0;
        return trace_back( n );
    }
};