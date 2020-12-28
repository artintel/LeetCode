class Solution {
public:
    double pow(double x, int n){
        if(n == 1) return x;
        if(n == -1) return 1 / x;
        if(n > 0){
            if( n % 2 == 1) return x * pow(x, n - 1);
            else return pow(x * x, n / 2);
        }
        else {
            if(n % 2 == -1) {
                n += 1;
                n = -n;
                return 1 / (x * pow(x, n));
            }
            else {
                n /= 2;
                n = -n;
                return 1 / (pow(x * x, n));
            }
        }
    }

    double myPow(double x, int n) {
        if(n == 0) return 1.0000;
        if(x == 0.00000 || x == 1.00000) return x;
        x = pow(x, n);
        return x;
    }
};