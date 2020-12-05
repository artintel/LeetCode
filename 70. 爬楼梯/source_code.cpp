class Solution {
public:
    int climbStairs(int n) {
        int low = 1, high = 2;
        if( n == low ) return low;
        while(--n > 1){
            high = low + high;
            low = high - low;
        }
        return high;
    }
};