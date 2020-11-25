class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp = 1;
        vector<int> ans;
        for(int i = digits.size() - 1; i >= 0; i--){
            ans.emplace_back((digits[i] + temp) % 10);
            temp = (digits[i] + temp) / 10;
        }
        if(temp != 0) ans.emplace_back(temp);
        vector<int> Digits;
        for(int i = ans.size() - 1; i>=0; i--){
            Digits.emplace_back(ans[i]);
        }
        return Digits;
    }
};

# 2
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--){
            digits[i]++;
            digits[i] = digits[i] % 10;
            if(digits[i] != 0) return digits;
        }
        vector<int> Digits;
        Digits.emplace_back(1);
        for(const auto& elem : digits){
            Digits.emplace_back(elem);
        }
        return Digits;
    }
};