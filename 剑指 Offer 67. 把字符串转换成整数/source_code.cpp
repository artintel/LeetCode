class Solution {
public:
    int strToInt(string str) {
        long num = 0;
        int flag = 1;
        int int_neg = 1;
        int n = str.size();
        for(int i = 0; i < n; i++){
            if( str[i] == '+' || str[i] == '-' ){
                if( flag == 0 ) break;
                else if( str[i] == '-' ){
                    if( int_neg == 1 ) {
                        int_neg = 0;
                    }
                    else break;
                }
                flag = 0;
            }
            else if( str[i] <= '9' && str[i] >= '0' ){
                flag = 0;
                num = num * 10 + ( str[i] - '0' );
                if( int_neg == 0 ){
                    if( -num < INT_MIN ) return INT_MIN;
                }
                else if( num > INT_MAX ) return INT_MAX;
            }
            else if( str[i] == ' ' ){
                if( flag == 1 ) continue;
                else break;
            }
            else break;
        }
        num = ( int_neg == 0 ) ? -num : num;
        if( num > INT_MAX ) return INT_MAX;
        else if( num < INT_MIN ) return INT_MIN;
        else return (int)num; 
    }
};