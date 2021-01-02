/*
 * @Author: Mayc
 * @Date: 2021-01-02 14:47:02
 * @LastEditTime: 2021-01-02 14:47:16
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 15. 二进制中 1 的个数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int count = 0;
        while(flag){
            if( n & flag ) count++;
            flag <<= 1;
        }
        return count;
    }
};