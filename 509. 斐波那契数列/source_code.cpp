class Solution {
public:
    int fib(int N) {
        if( N == 0) return 0;
        int f = 0, g = 1;
        while( 0 < --N ){
            g = g + f;
            f = g - f;
        }
        return g;
    }
};