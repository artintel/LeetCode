/*
 * @Author: Mayc
 * @Date: 2021-02-02 15:18:07
 * @LastEditTime: 2021-02-02 15:18:15
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\剑指 Offer 49. 丑数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:

    int MIN(const int& a, const int& b, const int& c){
        return min(a, min(b, c));
    }

    int nthUglyNumber(int n) {
        vector<int> result(n, 1);
        vector<int>::iterator r_two = result.begin();
        vector<int>::iterator r_three = result.begin();
        vector<int>::iterator r_five = result.begin();
        int count = 1;
        while( count < n ){
            int min = MIN( (*r_two) * 2, (*r_three) * 3, (*r_five) * 5 );
            result[count++] = min;
            while( (*r_two) * 2 <= min ){
                r_two++;
            }
            while( (*r_three) * 3 <= min ){
                r_three++;
            }
            while( (*r_five) * 5 <= min ){
                r_five++;
            }
        }
        return result[n - 1];
    }
};