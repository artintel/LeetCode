class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> S1(26, 0);
        vector<int> S2(26, 0);
        for(auto elem : s1){
            S1[elem - 'a']++;
        }
        for(auto elem : s2){
            S2[elem - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(S1[i] != S2[i]) return false;
        }
        return true;
    }
};