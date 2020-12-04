class Solution {
public:
    bool isUnique(string astr) {
        int zero = 0;
        int one = 1;
        int temp = zero;
        for(auto elem : astr){
            temp = temp ^ (one << ((elem - 'a') % 26));
            if (temp < zero) return false;
            zero = temp;
        }
        return true;
    }
};